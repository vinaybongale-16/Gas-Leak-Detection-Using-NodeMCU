# 🛠 Components Used

This project uses the following hardware components to detect gas leakage, provide real-time alerts, and activate safety mechanisms.

| S.No | Component | Quantity | Purpose |
|:---:|-----------|:-------:|---------|
| 1 | NodeMCU ESP8266 | 1 | Main microcontroller with built-in Wi-Fi connectivity |
| 2 | MQ-2 Gas Sensor | 1 | Detects LPG, methane, smoke, and other combustible gases |
| 3 | 16×2 I2C LCD Display | 1 | Displays gas level and system status |
| 4 | Servo Motor (SG90) | 1 | Simulates automatic gas valve control |
| 5 | 1-Channel Relay Module | 1 | Controls the DC exhaust fan |
| 6 | DC Fan (5V) | 1 | Removes leaked gas from the surrounding area |
| 7 | Active Buzzer | 1 | Provides an audible alarm during gas leakage |
| 8 | Red LED | 1 | Indicates gas leak condition |
| 9 | Green LED | 1 | Indicates safe operating condition |
| 10 | Breadboard | 1 | Used for circuit prototyping |
| 11 | Jumper Wires | As Required | Establishes electrical connections |
| 12 | USB Cable | 1 | Powers and programs the NodeMCU |

---

# 💻 Software Requirements

- Arduino IDE
- ESP8266 Board Package
- Blynk IoT Platform
- Embedded C++
- Required Arduino Libraries:
  - Blynk
  - ESP8266WiFi
  - LiquidCrystal_I2C
  - Servo
  - Wire

---

# 📌 Optional Components (Future Enhancements)

The following components can be added to enhance the project functionality:

- GSM Module (SIM800L) – SMS Alerts
- ESP32-CAM – Live Video Monitoring
- Flame Sensor – Fire Detection
- Temperature & Humidity Sensor (DHT11/DHT22)
- Solenoid Gas Valve – Automatic Gas Supply Shutdown
- Cloud Database (Firebase/MQTT)
- Rechargeable Battery Backup
