#include <Wire.h>
int temp_address = 72; ///온도센서 주소로 이진수 1001000에 해당한댕

const int SER = 8;
const int LATCH = 9;
const int CLK = 10;



int vals[8] = {1, 3, 7, 15, 31, 63, 127, 255};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
  pinMode(SER, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLK, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(temp_address);
  Wire.write(0);
  Wire.endTransmission();
  ///에러방어
  int returned_bytes = Wire.requestFrom(temp_address, 1);
  
  if(returned_bytes == 0)
  {
    Serial.print("Err, Err.");
    while(1);
  }
  
  int c = Wire.read();

  int graph = map(c, 19, 23, 0, 7);
  graph = constrain(graph, 0, 7);

  digitalWrite(LATCH, LOW);

  shiftOut(SER, CLK, MSBFIRST, vals[graph]);
  digitalWrite(LATCH, HIGH);
  int f = round(c * 9.0 / 5.0 + 32.0);

  Serial.print(c);
  Serial.print("C ");
  Serial.print(f);
  Serial.println("F");

  delay(500);

}