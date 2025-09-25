# 🚗 Car Parking Sensor Using ATmega32, Ultrasonic Sensor, LCD, LEDs, and Buzzer

## 📖 Objective
The aim of this project is to design a **car parking sensor system** that helps drivers detect obstacles and avoid collisions while parking.  
The system uses an **ultrasonic sensor** to measure distance, displays results on an **LCD**, and provides **visual (LEDs) and auditory (buzzer)** warnings based on the proximity of obstacles.

---

## 🌟 Features
- **Ultrasonic Distance Measurement:** Measures distance between the car and objects.  
- **LCD Display:** Shows distance in centimeters; displays **"STOP"** when ≤ 5 cm.  
- **LED Indicators:** Red, Green, and Blue LEDs light up according to object proximity.  
- **Buzzer Alert:** Sounds when an object is closer than 5 cm.  
- **Dynamic LED Behavior:** LEDs change states depending on the detected distance.  

---

## 🔧 Hardware Components
- ATmega32 Microcontroller  
- HC-SR04 Ultrasonic Sensor  
- 16x2 LCD Display (4-bit mode)  
- Red, Green, and Blue LEDs  
- Buzzer  

---
## 📟 Pin Connections

### ATmega32 → Peripheral Mapping
| Port | Pin   | Connected To                   |
|------|-------|--------------------------------|
| PA1  |       | LCD RS Pin                     |
| PA2  |       | LCD Enable (E) Pin             |
| PA3  |       | LCD D4                         |
| PA4  |       | LCD D5                         |
| PA5  |       | LCD D6                         |
| PA6  |       | LCD D7                         |
| PC0  |       | Red LED                        |
| PC1  |       | Green LED                      |
| PC2  |       | Blue LED                       |
| PC5  |       | Buzzer (via transistor driver) |
| PD6  |       | Ultrasonic Echo Pin            |
| PD7  |       | Ultrasonic Trigger Pin         |

### Ultrasonic Sensor (HC-SR04)
- **Echo → PD6**  
- **Trigger → PD7**

### LCD Display (16x2 in 4-bit mode)
- **RS → PA1**  
- **RW → GND**  
- **E → PA2**  
- **D4 → PA3**  
- **D5 → PA4**  
- **D6 → PA5**  
- **D7 → PA6**

### LEDs
- **Red LED → PC0**  
- **Green LED → PC1**  
- **Blue LED → PC2**

### Buzzer
- **PC5 (via transistor)**  


---

## ⚙️ Operation Description
1. The **ultrasonic sensor** emits a wave and listens for its reflection.  
2. The **ATmega32** calculates distance based on wave travel time.  
3. Distance is displayed in **cm on the LCD**.  
4. LEDs and buzzer react dynamically:  

| Distance Range | LED Behavior | Buzzer | LCD Display |
|----------------|-------------|--------|-------------|
| ≤ 5 cm        | All LEDs flash | ON | "STOP" |
| 6–10 cm       | All LEDs ON | OFF | Distance in cm |
| 11–15 cm      | Red + Green ON | OFF | Distance in cm |
| 16–20 cm      | Red ON only | OFF | Distance in cm |
| > 20 cm       | All OFF | OFF | Distance in cm |

---

## 🖥️ System Requirements
- **Microcontroller:** ATmega32  
- **System Frequency:** 16 MHz  
- **Architecture:** Layered model (Application Layer, Drivers Layer)  

<img width="851" height="375" alt="Image" src="https://github.com/user-attachments/assets/a030df14-da10-42d0-b4e6-81e9f895d800" />
---

## 📂 Drivers Requirements

### GPIO Driver
- Use the same GPIO driver implemented in the course.  

### ICU Driver
- Frequency: `F_CPU/8`  
- First edge: Rising  
- Functions: `ICU_init`, `ICU_setCallBack` (inside `Ultrasonic_init`).  

### Buzzer Driver
- **Functions:**
  - `Buzzer_init()` → Initialize buzzer pin, set OFF.  
  - `Buzzer_on()` → Activate buzzer.  
  - `Buzzer_off()` → Deactivate buzzer.  
- Pin should be configurable.  

### LCD Driver
- 16x2 LCD in **4-bit mode**.  
- Display **distance in cm** or **"STOP"** when ≤ 5 cm.  

### Ultrasonic Driver
- Implemented using ATmega32 **ICU driver**.  
- **Functions:**
  - `Ultrasonic_init()` → Initialize ICU, set callback, configure trigger pin.  
  - `Ultrasonic_Trigger()` → Send trigger pulse.  
  - `Ultrasonic_readDistance()` → Trigger + measure distance (returns cm).  
  - `Ultrasonic_edgeProcessing()` → Callback to calculate high time (pulse duration).  
- Trigger pin should be configurable.  

---

## 📐 Circuit Diagram
<img width="1336" height="828" alt="Image" src="https://github.com/user-attachments/assets/e49102a0-4831-4d18-9611-139f67d52a89" />


---

---

## 👤 Author
**Youssef Alaa**  
- GitHub: [@Youssef-Al-eng](https://github.com/Youssef-Al-eng)  
- LinkedIn: [Youssef Alaa](https://www.linkedin.com/in/youssef-alaa-1b9580332/)  
