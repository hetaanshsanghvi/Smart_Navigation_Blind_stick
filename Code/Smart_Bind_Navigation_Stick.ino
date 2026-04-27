#include "DFRobotDFPlayerMini.h"
#include <ESP32Servo.h>

// DFPlayer
HardwareSerial mySerial(2);
DFRobotDFPlayerMini myDFPlayer;

// Ultrasonic
#define TRIG 5
#define ECHO 18

// Servo
Servo myServo;
#define SERVO_PIN 19

long duration;
int distLeft, distCenter, distRight;

void setup() {
  Serial.begin(115200);

  // DFPlayer
  mySerial.begin(9600, SERIAL_8N1, 16, 17);
  if (!myDFPlayer.begin(mySerial)) {
    Serial.println("DFPlayer failed");
  } else {
    myDFPlayer.volume(30);
  }

  // Ultrasonic
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  // Servo
  myServo.setPeriodHertz(50);
  myServo.attach(SERVO_PIN, 500, 2400);

  Serial.println("System Ready...");
}

// Function to measure distance
int getDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH);
  return duration * 0.034 / 2;
}

void loop() {

  // 🔄 LEFT
  myServo.write(150);
  delay(400);
  distLeft = getDistance();

  // 🔄 CENTER
  myServo.write(90);
  delay(400);
  distCenter = getDistance();

  // 🔄 RIGHT
  myServo.write(30);
  delay(400);
  distRight = getDistance();

  // 🎯 Find nearest object
  int minDist = min(distLeft, min(distCenter, distRight));

  if (minDist < 30) { // threshold

    if (minDist == distLeft) {
      Serial.println("LEFT");
      myDFPlayer.play(1); // 0001.mp3
    } 
    else if (minDist == distCenter) {
      Serial.println("CENTER");
      myDFPlayer.play(2); // 0002.mp3
    } 
    else {
      Serial.println("RIGHT");
      myDFPlayer.play(3); // 0003.mp3
    }

    delay(2000); // wait for audio
  }

  delay(300);
}