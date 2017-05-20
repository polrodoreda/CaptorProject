#include <math.h>

volatile unsigned long Rotations;
volatile unsigned long ContactBounceTime;

float WindSpeed;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), isr_rotation, FALLING);

  Serial.println("Wind Velocity");
  Serial.println("Rotacions \t km/h");
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
  if ((millis() - ContactBounceTime) > 15) {
    Rotations++;
    ContactBounceTime = millis();
  }
}

//http://cactus.io/hookups/weather/anemometer/davis/hookup-arduino-to-davis-anemometer-wind-speed
