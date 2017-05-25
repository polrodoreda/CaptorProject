int VaneValue;
int Direction;
int CalDirection;

#define Offset 0;

void setup() {
  Serial.begin(9600);
  
  Serial.flush();
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
  
  delay(500);
}

