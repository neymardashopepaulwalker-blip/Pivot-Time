# Pivot Time

A custom-built round desktop clock with live weather, powered by an ESP8266 and designed end-to-end — schematic, PCB, enclosure, and firmware — as a hands-on way to learn embedded hardware design.

---

## Overview

Pivot Time started as a simple question: *could I build a clock that looks like a tiny smartwatch sitting on my desk?*

What began as a single round display turned into a full project spanning three disciplines I wanted to get better at: **PCB design in KiCad**, **enclosure modeling in Fusion 360**, and **embedded firmware in C++/Arduino**. Along the way it grew a battery, a charging circuit, a power switch, and a live weather feed — and became a real, physical object I designed from a blank schematic sheet to a finished, wearable-style desk piece.

---

## Features

| Feature | Description |
|---|---|
|  Live clock | Synced automatically over Wi-Fi via NTP — never needs manual setting |
|  Live weather | Temperature, "feels like," humidity, and conditions pulled from OpenWeatherMap |
|  Battery powered | Rechargeable Li-ion cell, no cable needed once charged |
|  USB rechargeable | Charge through the onboard Micro USB charging module |
|  Physical power switch | Full hardware on/off, no standby drain |
|  Round display | 1.28" circular IPS screen for a modern, watch-face aesthetic |
|  Custom enclosure | Designed in Fusion 360 around the real PCB footprint |

---

## Tech Stack

| Layer | Tool |
|---|---|
| Schematic & PCB | KiCad |
| Enclosure / CAD | Fusion 360 |
| Firmware | Arduino (C++) on ESP8266 |
| Display driver | Adafruit GC9A01A / Adafruit GFX |
| Time sync | NTPClient |
| Weather data | OpenWeatherMap API |

---

## Bill of Materials (BOM)

| Component | Spec / Notes | Qty | Buy |
|---|---|---|---|
| Microcontroller | Wemos D1 Mini (ESP8266) | 1x | https://pt.aliexpress.com/item/1005009637687874.html?src=google&traffic_server_nav=true&src=google&albch=shopping&acnt=768-202-3196&isdl=y&slnk=&plac=&mtctp=&albbt=Google_7_shopping&aff_platform=google&aff_short_key=UneMJZVf&gclsrc=aw.ds&albagn=888888&ds_e_adid=&ds_e_matchtype=&ds_e_device=c&ds_e_network=x&ds_e_product_group_id=&ds_e_product_id=pt1005009637687874&ds_e_product_merchant_id=5620899455&ds_e_product_country=BR&ds_e_product_language=pt&ds_e_product_channel=online&ds_e_product_store_id=&ds_url_v=2&albcp=21106536414&albag=&isSmbAutoCall=false&needSmbHouyi=false&gad_source=1&gad_campaignid=21106537179&gbraid=0AAAAAC_WlP9dWsCpw3mdLYf0wY9VNNrPC&gclid=CjwKCAjwpK3SBhASEiwAtV1SPCxNX1m0JQZNIvctKCdWJCnciscyqsnBPot91nrCH4TkRrtFpgXAGhoCzeoQAvD_BwE |
| Display | GC9A01, 1.28" round, SPI, 240×240 | 1x | https://pt.aliexpress.com/item/1005006111616872.html?src=google&src=google&albch=apprmkt&albagn=182499396&albcp=20758697517&albag=&albad=&aff_short_key=_oFgTQeV&isdl=y&aff_platform=true&traffic_server_nav=true&gad_source=1&gad_campaignid=20758707111&gbraid=0AAAAADC-j-WYlRQ1jnBHVbIollGMJJFYE&gclid=CjwKCAjwmJjSBhB-EiwAkZgxizNx1ujjDmJNuxW2sVMbbFvtEcwXff9obhsc6-GRRD8dGXXwtIJxFRoCMf0QAvD_BwE |
| Battery | Li-ion/LiPo 3.7V, 500–1000mAh, JST-PH 2.0mm connector | 1x |  https://www.mercadolivre.com.br/bat-37v-1000mah-lp703040-retangular-energy-power/p/MLB2083847514?pdp_filters=item_id:MLB1952744649#polycard_client=recommendations_pdp-pads-up&wid=MLB1952744649&sid=recos&reco_backend=recomm_platform_base_pads_rfa_MERGE&reco_model=search_recos_backend_merge&reco_client=pdp-pads-up&reco_item_pos=0&reco_backend_type=low_level&reco_id=54ce624d-b36a-42cb-8c79-46f6816b7508&is_advertising=true&ad_domain=PDPDESKTOP_UP&ad_position=1&ad_click_id=MWJkZDVjZDgtNWM4Zi00MTZiLWI5NjItYzQwNGNmZThmNmUy|
| Charger + boost module | TP4056 charger + protection + 5V step-up, Micro USB input | 1x | https://pt.aliexpress.com/item/1005007973210640.html?src=google&traffic_server_nav=true&src=google&albch=shopping&acnt=768-202-3196&isdl=y&slnk=&plac=&mtctp=&albbt=Google_7_shopping&aff_platform=google&aff_short_key=UneMJZVf&gclsrc=aw.ds&albagn=888888&ds_e_adid=&ds_e_matchtype=&ds_e_device=c&ds_e_network=x&ds_e_product_group_id=&ds_e_product_id=pt1005007973210640&ds_e_product_merchant_id=468290305&ds_e_product_country=BR&ds_e_product_language=pt&ds_e_product_channel=online&ds_e_product_store_id=&ds_url_v=2&albcp=21106536414&albag=&isSmbAutoCall=false&needSmbHouyi=false&gad_source=1&gad_campaignid=21106537179&gbraid=0AAAAAC_WlP9dWsCpw3mdLYf0wY9VNNrPC&gclid=CjwKCAjwpK3SBhASEiwAtV1SPGHpn1VxUvdqMDD4HuXrelhn9mrxf8GA8yoKNi_wy1Eh1Z78mToxeRoCskQQAvD_BwE |
| Power switch | SPDT slide switch (Würth 450301014042 or equivalent) | 1x | https://pt.aliexpress.com/item/1005007162182882.html?spm=a2g0o.productlist.main.17.2a3d5b34s0xmdK&algo_pvid=c5215cdd-ebed-4ff6-9f1a-86febd9e359c&algo_exp_id=c5215cdd-ebed-4ff6-9f1a-86febd9e359c-16&pdp_ext_f=%7B%22order%22%3A%222412%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21BRL%2111.37%2111.09%21%21%212.03%211.98%21%40210319b017833744813767076e7eb3%2112000039660071095%21sea%21BR%216086636243%21X%211%210%21n_tag%3A-29919%3Bd%3A922f760c%3Bm03_new_user%3A-29895&curPageLogUid=18LSKybKVk1D&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005007162182882%7C_p_origin_prod%3A |
| Battery connector | JST-PH 2.0mm (if not included with battery) | 1x | https://pt.aliexpress.com/item/1005008779637156.html?spm=a2g0o.detail.pcDetailTopMoreOtherSeller.10.410cyyvkyyvkTg&gps-id=pcDetailTopMoreOtherSeller&scm=1007.40050.354490.0&scm_id=1007.40050.354490.0&scm-url=1007.40050.354490.0&pvid=039df86d-bb3a-440f-9bc5-2eeefd492230&_t=gps-id%3ApcDetailTopMoreOtherSeller%2Cscm-url%3A1007.40050.354490.0%2Cpvid%3A039df86d-bb3a-440f-9bc5-2eeefd492230%2Ctpp_buckets%3A668%232846%238108%231977&pdp_ext_f=%7B%22order%22%3A%222863%22%2C%22eval%22%3A%221%22%2C%22sceneId%22%3A%2230050%22%2C%22fromPage%22%3A%22recommend%22%7D&pdp_npi=6%40dis%21BRL%218.63%218.01%21%21%211.54%211.43%21%402101d33417833838651802402e0f1d%2112000046661045527%21rec%21BR%216086636243%21X%211%210%21n_tag%3A-29919%3Bd%3A922f760c%3Bm03_new_user%3A-29895&utparam-url=scene%3ApcDetailTopMoreOtherSeller%7Cquery_from%3A%7Cx_object_id%3A1005008779637156%7C_p_origin_prod%3A |
| solder place for screws | metal kit | — | https://pt.aliexpress.com/item/1005005043279413.html?spm=a2g0o.productlist.main.2.3360De5IDe5IY7&algo_pvid=cedd99ba-a683-4aa1-9cd6-507a28e9b398&algo_exp_id=cedd99ba-a683-4aa1-9cd6-507a28e9b398-1&pdp_ext_f=%7B%22order%22%3A%223067%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21BRL%2135.93%2131.88%21%21%2143.61%2138.70%21%402101eee917833760049791360ea505%2112000031429968391%21sea%21BR%216086636243%21X%211%210%21n_tag%3A-29919%3Bd%3A922f760c%3Bm03_new_user%3A-29895%3BpisId%3A5000000210965663&curPageLogUid=EA3bhRUOybDz&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005005043279413%7C_p_origin_prod%3A |
| Mounting screws | M3 × length TBD, per enclosure design | 2x | https://pt.aliexpress.com/item/1005004157607945.html?src=google&traffic_server_nav=true&src=google&albch=shopping&acnt=768-202-3196&isdl=y&slnk=&plac=&mtctp=&albbt=Google_7_shopping&aff_platform=google&aff_short_key=UneMJZVf&gclsrc=aw.ds&albagn=888888&ds_e_adid=&ds_e_matchtype=&ds_e_device=c&ds_e_network=x&ds_e_product_group_id=&ds_e_product_id=pt1005004157607945&ds_e_product_merchant_id=557532880&ds_e_product_country=BR&ds_e_product_language=pt&ds_e_product_channel=online&ds_e_product_store_id=&ds_url_v=2&albcp=21106536414&albag=&isSmbAutoCall=false&needSmbHouyi=false&gad_source=1&gad_campaignid=21106537179&gbraid=0AAAAAC_WlP9dWsCpw3mdLYf0wY9VNNrPC&gclid=CjwKCAjwpK3SBhASEiwAtV1SPCt5M8-RlyOnh4bzRXGwgLoWKu65YmWR1ewvB_Uc_DGucmw57jSwXRoCpwEQAvD_BwE |

---

## Wiring

**Power path:** Battery → Charger/boost module → Switch → Wemos D1 Mini → Display

| From | To |
|---|---|
| Battery `+` | Charger module `BAT+` |
| Battery `−` | Charger module `BAT-` |
| Charger module `Out+` (5V) | Switch, common pin |
| Switch, normally-open pin | Wemos D1 Mini `5V` |
| Charger module `Out-` | Wemos D1 Mini `G` (GND) |

| Display (GC9A01) | Wemos D1 Mini |
|---|---|
| VCC | 5V |
| GND | G |
| RST | D4 |
| DC | D2 |
| CS | D8 |
| SDA (MOSI) | D7 |
| SCL (SCK) | D5 |

---

## Repository Structure

```
PivotTime/
├── README.md
├── CAD/
│   ├── Bottom.STEP
│   ├── Top.STEP
│   └── PCB.STEP
├── PCB/
│   ├── PivotTime.kicad_pro
│   ├── PivotTime.kicad_sch
│   └── PivotTime.kicad_pcb
├── Firmware/
│   └── pivot_time.ino
└── production/
    ├── gerbers.zip
    ├── Top.STEP
    ├── Bottom.STEP
    └── pivot_time.ino
```

---

## Screenshots

### Schematic
<img width="586" height="401" alt="image" src="https://github.com/user-attachments/assets/79a3356e-cbe4-4dd3-a8cc-a53365b4067a" />

### PCB Layout
<img width="1282" height="813" alt="image" src="https://github.com/user-attachments/assets/23986d4f-8d48-4ecb-879c-19fa2330c216" />

### Finished Build
<img width="1600" height="795" alt="image" src="https://github.com/user-attachments/assets/e1e719f9-cdb2-4e15-9abf-a7ad8fbfca9f" />


---

## Firmware Setup

1. Install the **ESP8266 board package** in the Arduino IDE (via Boards Manager).
2. Install the required libraries through the Library Manager:
   - `Adafruit GFX Library`
   - `Adafruit GC9A01A`
   - `NTPClient`
   - `ArduinoJson` (v6.x)
3. Open `Firmware/pivot_time.ino` and fill in:
   - Wi-Fi SSID and password
   - OpenWeatherMap API key, city, and country code
4. Select board **"LOLIN(WEMOS) D1 R2 & mini"**, choose the correct COM port, and upload.

---

## What I Learned

- Designing a schematic and routing a two-sided PCB from scratch in KiCad
- Creating custom symbols and footprints for modules without off-the-shelf library parts
- Reading and resolving DRC violations, including intentional courtyard overlaps for stacked components
- Modeling an enclosure in Fusion 360 around a real, imported PCB (via STEP export)
- Writing ESP8266 firmware that connects to Wi-Fi, syncs time over NTP, and consumes a REST weather API
- Centering and laying out UI content for a **circular** display, where content near the corners gets clipped by the glass

---

## Roadmap

- [ ] Battery level indicator on-screen
- [ ] Sleep/wake on motion or button press to save power
- [ ] Swappable watch-face styles
- [ ] 3D-printable enclosure files published as STL

---

## Acknowledgments

Inspired by the general concept of a small networked desk clock with a weather readout, adapted into a fully custom round-display build with original PCB, enclosure, and firmware.

---

## Author

https://github.com/neymardashopepaulwalker-blip
