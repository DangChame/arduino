#include <Wire.h>
int temp_address = 72; ///온도센서 주소로 이진수 1001000에 해당한댕




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
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
    Serial.println("I2C Error");
    while(1);
  }
  
  int c = Wire.read();
  int f = round(c * 9.0 / 5.0 + 32.0);

  Serial.print(c);
  Serial.print("C ");
  Serial.print(f);
  Serial.println("F");

  delay(500);

}
