int VaneValue;
int Direction;
int CalDirection;
int LastValue;

#define Offset 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Vane Value \t Direction");
}

void loop() {
  VaneValue = analogRead(A4);
  Direction = map(VaneValue, 0, 1023, 0, 360);
  CalDirection = Direction + Offset;

  if (CalDirection > 360) 
    CalDirection = CalDirection - 360; 

  if (CalDirection < 0) 
    CalDirection = CalDirection + 360; 

  Serial.print(VaneValue);
  Serial.print("\t");
  Serial.println(CalDirection);

  /*if (abs(CalDirection - LastValue) > 5) { 
    Serial.print(VaneValue);
    Serial.print("\t");
    Serial.println(CalDirection);
    LastValue = CalDirection;
  }*/
  delay(500);
}

//http://cactus.io/hookups/weather/anemometer/davis/hookup-arduino-to-davis-anemometer

