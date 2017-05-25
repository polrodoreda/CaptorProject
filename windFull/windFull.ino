#include <math.h>

volatile unsigned long Rotations;
volatile unsigned long ContactBounceTime;

float WindSpeed;
int VaneValue;
int Direction;
int CalDirection;

#define Offset 0;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), isr_rotation, FALLING);

  Serial.flush();
}

void loop() {
  //Direction
  VaneValue = analogRead(A4);
  Direction = map(VaneValue, 0, 1023, 0, 360);
  CalDirection = Direction + Offset;

  if (CalDirection > 360) 
    CalDirection = CalDirection - 360; 

  if (CalDirection < 0) 
    CalDirection = CalDirection + 360; 

  //Speed
  Rotations = 0;

  sei();
  delay(1000);
  cli();

  WindSpeed = (3.621024/1) * Rotations;
  
  Serial.print(CalDirection);
  Serial.print("\t");
  Serial.println(WindSpeed);
}

void isr_rotation() {
  if ((millis() - ContactBounceTime) > 15) {
    Rotations++;
    ContactBounceTime = millis();
  }
}
