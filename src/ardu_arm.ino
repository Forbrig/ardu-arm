#include <Servo.h>

// pins
const int basePin = 8;
const int shoulderPin = 9;
const int elbowPin = 10;
const int clawPin = 11;

const int joystick1LeftPin = A0;
const int joystick1RightPin = A1;

const int joystick2LeftPin = A5;
const int joystick2RightPin = A4;

Servo baseServo;
Servo shoulderServo;
Servo elbowServo;
Servo clawServo;

const int defaultAngle = 90;
const int angleStrength = 2;

void setup() {
  // attach pins to servos
  baseServo.attach(basePin);
  shoulderServo.attach(shoulderPin);
  elbowServo.attach(elbowPin);
  clawServo.attach(clawPin);

  // reset angles
  baseServo.write(defaultAngle);
  shoulderServo.write(defaultAngle);
  elbowServo.write(defaultAngle);
  clawServo.write(defaultAngle);
}

void loop() {
  int x1Value = analogRead(joystick1LeftPin);
  int y1Value = analogRead(joystick1RightPin);

  int x2Value = analogRead(joystick2LeftPin);
  int y2Value = analogRead(joystick2RightPin);

  int currentBaseAngle = baseServo.read();
  if (y1Value > 700 && currentBaseAngle < 180) {
    baseServo.write(currentBaseAngle + angleStrength);
  } else if (y1Value < 400 && currentBaseAngle > 0) {
    baseServo.write(currentBaseAngle - angleStrength);
  }

  int currentShoulderAngle = shoulderServo.read();
  if (x1Value > 700 && currentShoulderAngle > 0) {
    shoulderServo.write(currentShoulderAngle - angleStrength);
  } else if (x1Value < 400 && currentShoulderAngle < 180) {
    shoulderServo.write(currentShoulderAngle + angleStrength);
  }

  int currentElbowAngle = elbowServo.read();
  if (x2Value > 700 && currentElbowAngle > 0) {
    elbowServo.write(currentElbowAngle - angleStrength);
  } else if (x2Value < 400 && currentElbowAngle < 180) {
    elbowServo.write(currentElbowAngle + angleStrength);
  }

  int currentClawAngle = clawServo.read();
  if (y2Value > 700 && currentClawAngle > 0) {
    clawServo.write(currentClawAngle - angleStrength);
  } else if (y2Value < 400 && currentClawAngle < 180) {
    clawServo.write(currentClawAngle + angleStrength);
  }

  delay(50);
}