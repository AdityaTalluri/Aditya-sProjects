//Hello there, and welcome to my code! My name is Aditya, and I have made a smart dustbin's code in C++ and have used an Arduino Uno Board. This is a very simple code,
  in which you will find everything you need to operate a smart dustbin, and you can change and edit your code (Not Here!)
  In this code, you will find:

//1. Which Arduino pin is to be connected to the trigger pin of ultrasonic sensor
//2. Which Arduino pin is connected to the echo pin of the ultrasonic sensor
//3. What is the Arduino pin connected to the signal pin of servo motor
//4. What is the Maximum distance threshold for triggering servo (in centimeters).

//IMPORTANT: You will not be able to see any preview (Sorry for the inconvenience) because you will need to use ARDUINO IDE and upload it to your servo motor and ARDUINO UNO.
 I will post where you can find it in another document. But if you would like to use a guide, you can go to www.roboarmy.in and you can also get a kit. 

#include <Servo.h>

#define TRIGGER_PIN  9 // Arduino pin connected to the trigger pin of ultrasonic sensor
#define ECHO_PIN     10 // Arduino pin connected to the echo pin of ultrasonic sensor
#define SERVO_PIN    11 // Arduino pin connected to the signal pin of servo motor
#define MAX_DISTANCE 20 // Maximum distance threshold for triggering servo (in centimeters)

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
  distance = (duration / 2) / 20.1; // Calculate distance in centimeters
  
  if (distance <= MAX_DISTANCE) {
    // If object is within range, open the lid
    servo.write(80); // 70 degrees position (adjust as needed)
    delay(1000); // Wait for 1 second
  } else {
    // If no object is detected, close the lid
    servo.write(0); // 0 degrees position (adjust as needed)
  }
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  delay(10); // Wait for 10 milliseconds before taking the next reading 
}




