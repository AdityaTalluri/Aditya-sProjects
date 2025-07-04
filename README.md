# 🤖 Arduino Smart Lid with Ultrasonic Sensor & Servo

This project uses an Arduino Uno, an ultrasonic distance sensor (HC-SR04), and a servo motor to create a **smart lid system**. When an object (like your hand) is detected within a certain range, the servo opens the lid. If nothing is detected, it automatically closes.

## 📦 Components Required

- Arduino Uno
- HC-SR04 Ultrasonic Sensor
- Servo Motor (SG90 or similar)
- Jumper Wires
- Breadboard (optional)
- USB cable (for power + uploading code)

## 🔌 Pin Connections

| Component         | Arduino Pin |
|------------------|-------------|
| Ultrasonic Trigger | D9          |
| Ultrasonic Echo    | D10         |
| Servo Signal       | D11         |
| VCC (All)          | 5V          |
| GND (All)          | GND         |

## 🧠 How It Works

1. The ultrasonic sensor checks for nearby objects.
2. If an object is within **20 cm**, the servo rotates to **70°**, opening the lid.
3. If no object is detected, the servo rotates to **0°**, closing the lid.
4. Distance is printed to the **Serial Monitor** for debugging.

## 🖥️ Arduino Code

```cpp
#include <Servo.h>

#define TRIGGER_PIN  9
#define ECHO_PIN     10
#define SERVO_PIN    11
#define MAX_DISTANCE 20

Servo servo;

void setup() {
  Serial.begin(9600);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  servo.attach(SERVO_PIN);
}

void loop() {
  long duration, distance;
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration / 2) / 29.1;

  if (distance <= MAX_DISTANCE) {
    servo.write(70); // Open
    delay(1000);
  } else {
    servo.write(0); // Close
  }

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(10);
}



