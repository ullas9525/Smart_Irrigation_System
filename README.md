# 🌱 Smart Irrigation System 💧

A low-cost, Arduino-based irrigation system that waters your plants only when they need it. It monitors soil moisture in real-time and controls a motor (pump) based on soil dryness. Built for efficiency, minimal water use, and full automation.

## ⚙️ Features

- 🌿 Soil moisture sensor to detect dryness
- 🔁 Auto ON/OFF motor control using a relay
- 📲 Bluetooth (HC-05) updates via Serial
- 🟢 Green LED: Soil is moist (Motor OFF)
- 🔴 Red LED: Soil is dry (Motor ON)
- 🔇 Non-repetitive serial messages to avoid spamming
- 🧠 Smart logic with change detection

## 🧰 Components

- Arduino Uno
- Soil Moisture Sensor
- Relay Module
- HC-05 Bluetooth Module
- 12V Water Pump / Motor
- Red & Green LEDs
- Jumper Wires, Breadboard

## 🔌 How It Works

1. Reads analog moisture value.
2. Converts to percentage using `map()`.
3. Compares with a threshold (default: 800).
4. If soil is dry → motor ON + red LED + BT update.
5. If soil is wet → motor OFF + green LED + BT update.
6. Only sends updates when moisture or motor state changes.

## 🖥️ Serial Output Example

