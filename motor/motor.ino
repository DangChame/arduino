

//모터 속도 자동제어

const int MOTOR=9;    //모터 속도를 제어하는 MOTOR 라는 상수를 9로 정의.

void setup()
{
    pinMode (MOTOR, OUTPUT); //앞서 정의한 MOTOR(9)를 출력핀번호로 지정
}

void loop()
{
    for (int i=0; i<256; i++) //변수 i의 초기값 0, 255까지 1씩 증가
    {
        analogWrite(MOTOR, i); //2.01초마다 모터 속도 증가
        delay(10);
    }
    delay(2000);
    for (int i=255; i>=0; i--) //변수 i의 초기값 255, 0까지 1씩 감소
    {
        analogWrite(MOTOR, i); //2.01초마다 모터 속도 감소
        delay(10);
    }
    delay(2000);
}
