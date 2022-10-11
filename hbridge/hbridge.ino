

//H브리지로 모터 제어
const int EN=9;   //H 브리지 사용하는 EN에 상수 9 정의.
const int MC1=3;  //모터를 컨트롤하는 MC1에 상수 3 정의.
const int MC2=2;  //모터를 컨트롤하는 MC2에 상수 2 정의.
const int POT=0;  //가변저항을 컨트롤하는 POT에 상수 0 정의.

int val = 0;      //가변저항값을 저장하는 val 변수를 선언하고 초기값 0.
int velocity = 0; //모터 속도를 저장하는 velocity 변수를 선언하고 초기값 0.

void setup()
{
    pinMode(EN, OUTPUT); //EN(9)를 출력핀번호로 지정.
    pinMode(MC1, OUTPUT);
    pinMode(MC2, OUTPUT);
    brake(); //모터를 정지하는것으로 초기화
}

void loop()
{
    val = analogRead(POT); //가변저항값을 0~1023 의 val로 저장.
 
    //정회전
    if (val > 562)
    {
        velocity = map(val, 563, 1023, 0, 255);
        forward(velocity); //velocity 를 인수로하는 forward 함수 지정.
    }
 
    //go backward
    else if (val < 462)
    {
        velocity = map(val, 461, 0, 0, 255);
        reverse(velocity); //velocity 를 인수로하는 reverse 함수 지정.
    }
 
    //brake
    else
    {
        brake(); //정지함수 brake 정의.
    }
}

//0~255 사이의 지정된 속도로 모터 정회전
void forward (int rate) //앞서 정의한 forward 함수에서 인수 rate를 정의함. velocity 를 사용.
{
    digitalWrite(EN, LOW);
    digitalWrite(MC1, HIGH);
    digitalWrite(MC2, LOW);
    analogWrite(EN, rate);
}

//역회전
void reverse (int rate)
{
    digitalWrite(EN, LOW);
    digitalWrite(MC1, LOW);
    digitalWrite(MC2, HIGH);
    analogWrite(EN, rate);
}

//정지
void brake ()
{
    digitalWrite(EN, LOW);
    digitalWrite(MC1, LOW);
    digitalWrite(MC2, LOW);
    digitalWrite(EN, HIGH);
}
