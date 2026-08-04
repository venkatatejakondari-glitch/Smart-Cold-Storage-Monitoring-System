#  Smart Cold Storage Monitoring System

An IoT-based Smart Cold Storage Monitoring System developed using **ESP32**, **DHT22**, **OLED Display**, **Buzzer**, and **ThingSpeak Cloud** for real-time environmental monitoring.

---

##  Project Overview

Cold storage facilities are used to preserve food, medicines, vaccines, and other temperature-sensitive products. Maintaining the correct temperature and humidity is essential to prevent spoilage and ensure product quality.

This project continuously monitors the storage environment using a DHT22 sensor. The ESP32 processes the sensor data, displays the readings on an OLED display, uploads them to ThingSpeak for remote monitoring, and activates a buzzer whenever the temperature goes outside the safe operating range.

---

##  Features

-  Real-time Temperature Monitoring
-  Real-time Humidity Monitoring
-  Live OLED Display
-  Buzzer Alert for abnormal temperature
-  Wi-Fi Connectivity using ESP32
-  Cloud Data Logging with ThingSpeak
-  Real-time Temperature and Humidity Graphs
-  Serial Monitor Debugging

---

##  Hardware Components

| Component | Quantity |
|-----------|----------|
| ESP32 Development Board | 1 |
| DHT22 Temperature & Humidity Sensor | 1 |
| SSD1306 OLED Display (128×64) | 1 |
| Active Buzzer | 1 |
| Breadboard | 1 |
| Jumper Wires | As required |

---

##  Software Used

- Arduino IDE
- Wokwi Simulator
- ThingSpeak
- GitHub

---

##  Circuit Connections

| Component | ESP32 Pin |
|-----------|-----------|
| DHT22 Data | GPIO 4 |
| OLED SDA | GPIO 21 |
| OLED SCL | GPIO 22 |
| Buzzer | GPIO 19 |
| VCC | 3.3V |
| GND | GND |

---

##  Temperature Status

| Temperature | Status |
|-------------|--------|
| Below 2°C | 🔵 TOO COLD |
| 2°C – 8°C | 🟢 SAFE |
| Above 8°C | 🔴 TOO HOT |

---

#  Project Images

## Wokwi Circuit Block Diagram

![Wokwi Circuit Block Diagram](Images/Wokwi%20circuit%20Block%20diagram%20.jpeg)

---

## Wokwi Simulation

![Wokwi Simulation](Images/Wokwi%20simulation.jpeg)

---

## ThingSpeak Dashboard

![ThingSpeak Dashboard](Images/Thingspeak%20charts%20.jpeg)

---

## ☁️ ThingSpeak Integration

The ESP32 uploads sensor data to ThingSpeak every **20 seconds**.

### Fields Used

| Field | Description |
|-------|-------------|
| Field 1 | Temperature |
| Field 2 | Humidity |
| Field 3 | Storage Status |

---

## 📂 Repository Structure

```text
Smart-Cold-Storage-Monitoring-System
│
├── README.md
├── LICENSE
├── Libraries.txt
│
├── Source_Code
│   └── Smart_Cold_Storage_Monitoring_System.ino
│
├── Images
│   ├── Wokwi_Circuit_Block_Diagram.jpeg
│   ├── Wokwi_Simulation.jpeg
│   └── ThingSpeak_Charts.jpeg
│
└── Documentation
    └── Project_Report.pdf
```

---

##  Libraries Used

- Adafruit GFX Library
- Adafruit SSD1306
- Adafruit Unified Sensor
- DHT Sensor Library
- ThingSpeak
- WiFi (ESP32 Built-in)
- Wire Library

---

##  How to Run

1. Open the project in Arduino IDE or Wokwi.
2. Install all required libraries.
3. Update the Wi-Fi credentials and ThingSpeak API Key if required.
4. Upload the code to the ESP32.
5. Monitor the OLED display and ThingSpeak dashboard.

---

## Applications
- Cold Storage Warehouses
- Vaccine Storage Monitoring
- Food Preservation
- Pharmaceutical Storage
- Smart Warehouses
- IoT-Based Environmental Monitoring

---

##  Future Improvements

- SMS and Email Alerts
- Mobile Application Integration
- SD Card Data Logging
- Multiple Sensor Support
- Relay-Based Cooling Control

---

##  Author

**Kondari Venkata Teja**

B.Tech – Electronics & Instrumentation Engineering

National Institute of Technology Nagaland

---

## ⭐ Support

If you found this project useful, please consider giving this repository a ⭐ on GitHub.
