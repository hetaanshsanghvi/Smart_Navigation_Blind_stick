# 🚶 Smart Blind Navigation Stick (ESP32)

A smart assistive system that helps visually impaired users detect obstacles and navigate using audio, vibration, and buzzer alerts.

---

## 🔧 Components Used
- ESP32 DevKit V1
- HC-SR04 Ultrasonic Sensor
- DFPlayer Mini + Speaker
- Servo Motor (SG90)
- Buzzer
- Vibration Motor
- External 5V Supply

---

## ⚙️ Features
- Detects obstacle direction (Left / Center / Right)
- Voice alerts:
  - "Obstacle ahead"
  - "Turn left"
  - "Turn right"
- Multi-feedback system:
  - 🔊 Audio
  - 🔔 Buzzer
  - 📳 Vibration

---

## 🔌 Circuit Diagram
![Circuit Diagram](circuit/circuit_diagram.png)

---

## 🎵 Audio Files
| File | Function |
|------|--------|
| 0001.mp3 | Obstacle ahead |
| 0002.mp3 | Turn left |
| 0003.mp3 | Turn right |

---

## 🚀 How It Works
1. Servo scans Left → Center → Right
2. Ultrasonic sensor measures distance
3. If obstacle detected:
   - Plays voice alert
   - Activates buzzer & vibration
4. Suggests safest direction

---

## ▶️ How to Run
1. Upload code to ESP32 using Arduino IDE
2. Insert SD card with audio files in DFPlayer
3. Power the system
4. System starts detecting obstacles

---

## 📄 Future Improvements
- Bluetooth navigation
- GPS integration
- AI-based path detection

---

## 👨‍💻 Author
Hetaansh
