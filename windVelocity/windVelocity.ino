#include <math.h>

volatile unsigned long Rotations;
volatile unsigned long ContactBounceTime;

float WindSpeed;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), isr_rotation, FALLING);

  Serial.flush();
}

void loop() {
  Rotations = 0;

  sei();
  delay(1000);
  cli();

  WindSpeed = (3.621024/1) * Rotations;
  Serial.print(Rotations);
  Serial.print("\t");
  Serial.println(WindSpeed);
}

void isr_rotation() {
  unsigned long start = micros();
  if ((millis() - ContactBounceTime) > 15) {
    Rotations++;
    ContactBounceTime = millis();
  }
  unsigned long end = micros();
  unsigned long delta = end - start;
  Serial.println(delta);
}
