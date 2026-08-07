# 🚨 Gas Leak Detection Using NodeMCU

![Arduino](https://img.shields.io/badge/Arduino-ESP8266-blue)
![IoT](https://img.shields.io/badge/IoT-Blynk-green)
![License](https://img.shields.io/badge/License-MIT-yellow)

An IoT-based Gas Leak Detection System developed using **NodeMCU (ESP8266)** and an **MQ-2 Gas Sensor**. The system continuously monitors gas levels and automatically alerts users while activating safety mechanisms such as a buzzer, exhaust fan, and servo-controlled gas valve.

---

## 📌 Features

- Real-time gas leak monitoring
- MQ-2 gas sensor for LPG and combustible gases
- Blynk IoT mobile notifications
- 16x2 I2C LCD display
- Automatic buzzer alarm
- Relay-controlled exhaust fan
- Servo motor for gas valve control
- LED status indication
- Wi-Fi connectivity using ESP8266

---

## 🛠 Hardware Components

| Component | Quantity |
|-----------|----------|
| NodeMCU ESP8266 | 1 |
| MQ-2 Gas Sensor | 1 |
| Relay Module | 1 |
| DC Fan | 1 |
| Servo Motor | 1 |
| 16x2 I2C LCD | 1 |
| Buzzer | 1 |
| LED | 2 |
| Breadboard | 1 |
| Jumper Wires | As required |

---

## 📂 Project Structure

```
Gas-Leak-Detection-Using-NodeMCU
│
├── Code
├── Report
├── Images
├── Circuit_Diagram
└── Components
```

---

## ⚙️ Software Used

- Arduino IDE
- ESP8266 Board Package
- Blynk IoT
- Embedded C++

---

## 🚀 Working Principle

The MQ-2 sensor continuously detects combustible gases.

When the gas concentration exceeds the predefined threshold:

- Buzzer turns ON
- LED changes to RED
- Relay activates the exhaust fan
- Servo motor rotates to simulate closing the gas valve
- LCD displays warning message
- Notification is sent through the Blynk IoT application

When the gas level becomes normal, all outputs return to their safe state.

---

## 📷 Project Images

### Working Model

(Add your project image here)

### Circuit Diagram

(Add your circuit diagram here)

---

## 📄 Project Report

The complete mini project report is available in the **Report** folder.

---

## 🔮 Future Improvements

- SMS Alerts
- Email Notifications
- Cloud Data Logging
- Mobile Dashboard
- AI-based Gas Prediction

---

## 👨‍💻 Authors

- Vinay P Bongale
- Shashank Bevanur
- Shivaraj P Biradar
- Shivaraj U Anantapur

Department of Electronics & Communication Engineering

BLDEA's V.P. Dr. P.G. Halakatti College of Engineering & Technology
