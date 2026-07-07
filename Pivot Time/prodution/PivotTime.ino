/*
  Relógio de Mesa com Estação Meteorológica
  ------------------------------------------
  Hardware:
    - Wemos D1 Mini (ESP8266)
    - Display GC9A01 1.28" redondo (SPI)

  Ligações:
    GC9A01 VCC  -> 5V (ou 3V3, confira seu módulo)
    GC9A01 GND  -> G (GND)
    GC9A01 RES  -> D4
    GC9A01 DC   -> D2
    GC9A01 CS   -> D8
    GC9A01 SDA  -> D7 (MOSI)
    GC9A01 SCL  -> D5 (SCK)
    GC9A01 BLK  -> 3V3 (backlight sempre ligado)

  Bibliotecas (Library Manager da Arduino IDE):
    - Adafruit GFX Library
    - Adafruit GC9A01A
    - NTPClient (Fabrice Weinberg)
    - ArduinoJson (v6.x)
    - ESP8266WiFi / ESP8266HTTPClient (já vêm com o core do ESP8266)

  Antes de compilar, preencha:
    WIFI_SSID, WIFI_PASSWORD, OWM_API_KEY, CITY_NAME, COUNTRY_CODE
*/

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_GC9A01A.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <NTPClient.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>

// ---------- CONFIGURAÇÕES DO USUÁRIO ----------
const char* WIFI_SSID     = "SEU_WIFI_AQUI";
const char* WIFI_PASSWORD = "SUA_SENHA_AQUI";

const char* OWM_API_KEY   = "SUA_API_KEY_OPENWEATHERMAP";
const char* CITY_NAME     = "Sao Paulo";
const char* COUNTRY_CODE  = "BR";
const bool  USE_METRIC    = true;

const long  GMT_OFFSET_SEC = -3 * 3600;
const unsigned long WEATHER_UPDATE_INTERVAL = 10UL * 60UL * 1000UL;

// ---------- PINOS DO DISPLAY ----------
#define TFT_CS   D8
#define TFT_DC   D2
#define TFT_RST  D4

Adafruit_GC9A01A tft = Adafruit_GC9A01A(TFT_CS, TFT_DC, TFT_RST);

#define SCREEN_W 240
#define SCREEN_H 240
#define SCREEN_CX (SCREEN_W / 2)
#define SCREEN_CY (SCREEN_H / 2)

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", GMT_OFFSET_SEC, 60000);

String weatherDescription = "Carregando...";
float  temperature = 0.0;
float  feelsLike   = 0.0;
int    humidity    = 0;
unsigned long lastWeatherUpdate = 0;

const char* diasSemana[] = {"Domingo", "Segunda", "Terca", "Quarta", "Quinta", "Sexta", "Sabado"};
const char* meses[] = {"Jan","Fev","Mar","Abr","Mai","Jun","Jul","Ago","Set","Out","Nov","Dez"};

void setup() {
  Serial.begin(115200);
  delay(200);

  tft.begin();
  tft.setRotation(0);
  tft.fillScreen(GC9A01A_BLACK);
  tft.setTextWrap(false);

  showBootScreen();
  connectWiFi();

  timeClient.begin();
  timeClient.update();

  updateWeather();
  lastWeatherUpdate = millis();

  tft.fillScreen(GC9A01A_BLACK);
}

void loop() {
  timeClient.update();

  if (millis() - lastWeatherUpdate >= WEATHER_UPDATE_INTERVAL) {
    updateWeather();
    lastWeatherUpdate = millis();
  }

  drawClockScreen();
  delay(1000);
}

void showBootScreen() {
  printCentered("Relogio de Mesa", 100, 1, GC9A01A_WHITE);
  printCentered("Conectando wi-fi...", 120, 1, GC9A01A_WHITE);
}

void connectWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  int tentativas = 0;
  while (WiFi.status() != WL_CONNECTED && tentativas < 60) {
    delay(500);
    Serial.print(".");
    tentativas++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWi-Fi conectado!");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("\nFalha ao conectar wi-fi. Verifique SSID/senha.");
  }
}

void updateWeather() {
  if (WiFi.status() != WL_CONNECTED) return;

  WiFiClientSecure client;
  client.setInsecure();

  HTTPClient http;
  String units = USE_METRIC ? "metric" : "imperial";
  String url = "https://api.openweathermap.org/data/2.5/weather?q=" +
               String(CITY_NAME) + "," + String(COUNTRY_CODE) +
               "&appid=" + String(OWM_API_KEY) +
               "&units=" + units + "&lang=pt_br";

  http.begin(client, url);
  int httpCode = http.GET();

  if (httpCode == 200) {
    String payload = http.getString();

    DynamicJsonDocument doc(2048);
    DeserializationError error = deserializeJson(doc, payload);

    if (!error) {
      temperature = doc["main"]["temp"];
      feelsLike = doc["main"]["feels_like"];
      humidity = doc["main"]["humidity"];
      weatherDescription = doc["weather"][0]["description"].as<String>();
    } else {
      Serial.println("Erro ao interpretar JSON do clima.");
    }
  } else {
    Serial.print("Erro HTTP ao buscar clima: ");
    Serial.println(httpCode);
  }

  http.end();
}

void printCentered(const String &str, int16_t y, uint8_t size, uint16_t color) {
  int16_t x1, y1;
  uint16_t w, h;

  tft.setTextSize(size);
  tft.getTextBounds(str, 0, 0, &x1, &y1, &w, &h);

  int16_t x = SCREEN_CX - (w / 2) - x1;
  tft.setCursor(x, y);
  tft.setTextColor(color);
  tft.print(str);
}

void drawClockScreen() {
  tft.fillScreen(GC9A01A_BLACK);

  int horas    = timeClient.getHours();
  int minutos  = timeClient.getMinutes();
  int segundos = timeClient.getSeconds();

  char horaStr[9];
  sprintf(horaStr, "%02d:%02d:%02d", horas, minutos, segundos);
  printCentered(horaStr, 68, 3, GC9A01A_CYAN);

  unsigned long epochTime = timeClient.getEpochTime();
  int diaSemana = (epochTime / 86400L + 4) % 7;
  struct tm *ptm = gmtime((time_t *)&epochTime);
  int dia = ptm->tm_mday;
  int mes = ptm->tm_mon;
  int ano = ptm->tm_year + 1900;

  char dataStr[24];
  sprintf(dataStr, "%s, %02d %s %d", diasSemana[diaSemana], dia, meses[mes], ano);
  printCentered(dataStr, 104, 1, GC9A01A_WHITE);

  tft.drawFastHLine(SCREEN_CX - 55, 120, 110, GC9A01A_YELLOW);

  char tempStr[24];
  sprintf(tempStr, "Temp: %.1f%s", temperature, USE_METRIC ? " C" : " F");
  printCentered(tempStr, 132, 1, GC9A01A_GREEN);

  char sensStr[24];
  sprintf(sensStr, "Sensacao: %.1f", feelsLike);
  printCentered(sensStr, 150, 1, GC9A01A_GREEN);

  char humStr[20];
  sprintf(humStr, "Umidade: %d%%", humidity);
  printCentered(humStr, 168, 1, GC9A01A_GREEN);

  printCentered(weatherDescription, 192, 1, GC9A01A_ORANGE);
}