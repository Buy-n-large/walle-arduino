#include <Servo.h>
#include <Stepper.h>

Servo myServo;

#define STEPS 2048
Stepper myStepper(STEPS, 2, 4, 3, 5);

#define PIN_R 11
#define PIN_G 9
#define PIN_B 10

void setColor(int r, int g, int b) {
  analogWrite(PIN_R, 255 - r);
  analogWrite(PIN_G, 255 - g);
  analogWrite(PIN_B, 255 - b);
}

void setup() {
  pinMode(PIN_R, OUTPUT);
  pinMode(PIN_G, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  myServo.attach(6);
  myStepper.setSpeed(15);
  Serial.begin(9600);
  Serial.println("READY");
}

void loop() {
  if (Serial.available()) {
    String line = Serial.readStringUntil('\n');
    line.trim();

    if (line.startsWith("LED")) {
      int r, g, b;
      sscanf(line.c_str(), "LED %d %d %d", &r, &g, &b);
      setColor(r, g, b);
      Serial.println("OK LED");

    } else if (line.startsWith("SERVO")) {
      int angle;
      sscanf(line.c_str(), "SERVO %d", &angle);
      angle = constrain(angle, 0, 180);
      myServo.write(angle);
      Serial.println("OK SERVO");

    } else if (line.startsWith("STEPPER")) {
      int steps;
      sscanf(line.c_str(), "STEPPER %d", &steps);
      Serial.println("OK STEPPER");
      myStepper.step(steps);
      Serial.println("DONE STEPPER");

    } else {
      Serial.print("UNKNOWN: ");
      Serial.println(line);
    }
  }
}
