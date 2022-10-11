
//가변저항으로 서보모터 제어

#include <Servo.h> //내장 라이브러리 사용. (자주쓰는 유용한 코드 모음)

const int SERVO=9; //서보모터를 쓰는 SERVO 상수를 9로 정의.
const int POT=0;    //가변저항을 쓰는 POT 상수를 0으로 정의.

Servo myServo;
int val = 0;     //가변저항 값을 저장하는 val 변수 선언하고 초기값 0.

void setup()
{
    myServo.attach(SERVO); // attach 함수로 9번 핀에 연결
}

void loop()
{
    val = analogRead(POT);           //가변저항 값을 읽어 0~1023 사이의 변수 val로 저장
    val = map(val, 0, 1023, 0, 179); //val 값을 서보의 범위 0~180도 사이 값으로 매핑
    myServo.write(val);              // 지정값으로 servo 이동 
    delay(15);                       // 15ms 만큼 대기
}
