# Plant_Monitor

This projects enables you to monitor the well being and related parameters of your plants via a simple mail notification and reminds you to water the plant if neccessary.

It uses capacitive sensors to read the moisture level of the soil which are collected by a battery powered STM32 and transmitted va bluetooth to an ESP32 where an E-Mail alert is sent in case of low moisture levels.

![image](https://github.com/SterzerA/Plant_Monitor/assets/103459031/c48420ad-6e6e-4fb5-9a71-fb840b307359)

## Hardware
[NUCLEO-WB55RG](https://www.st.com/en/evaluation-tools/nucleo-wb55rg.html)  

[ESP32 D1 Mini](https://www.az-delivery.de/en/products/esp32-d1-mini)  

[Capacitive Soil Moisture Sensor](https://www.amazon.de/gp/product/B07HJ6N1S4/ref=ppx_yo_dt_b_asin_title_o00_s00?ie=UTF8&th=1)

## Resources
The STM32 BLE configuration was done with STM32 CubeMX. For more info how to setup your own custom BLE service on STM32WB55 please check out [STM32WB_BLE_STM32CubeMX](https://wiki.st.com/stm32mcu/wiki/Connectivity:STM32WB_BLE_STM32CubeMX).  

The ESP32 mail sending function is a modified version of [this tutorial](https://draeger-it.blog/senden-von-e-mails-mit-dem-esp32-via-arduino-ide/).

# STM32 Program Flow

![image](https://github.com/SterzerA/Plant_Monitor/blob/main/Diagrams/STM32_Program_Flow.drawio.svg)

# ESP32 Program Flow

![image](https://github.com/SterzerA/Plant_Monitor/blob/main/Diagrams/ESP32_Program_Flow.drawio.svg)

