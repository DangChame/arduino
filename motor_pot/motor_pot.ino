//가변저항으로 모터 속도 제어

const int MOTOR=9;  //모터 속도를 조절하는 MOTOR 라는 상수를 9로 정의.
const int POT=0;    //가변저항을 조절하는 POT 라는 상수를 0으로 정의.

int val = 0;

void setup()
{
    pinMode (MOTOR, OUTPUT); //MOTOR(9)를 출력핀번호로 지정.
}

void loop()
{
    val = analogRead(POT); //가변저항값을 읽어서 0~1023 사이의 val 라는 변수로 저장
    val = map(val, 0, 1023, 0, 255); //0~1023 사이의 val 값을 0~255 사이로 mapping
    analogWrite(MOTOR, val); //mapping 한 val 값으로 모터 속도 조절
}
