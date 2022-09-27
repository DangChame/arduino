 
  //올려주신 강의자료 참고해야함, led와 코드가 setMode 함수가 다르다., 설계도 또한 다름.
  
  const int BLED = 9;
  const int GLED = 10;
  const int RLED = 11;
  const int button = 2;

  boolean lastbutton = LOW;
  boolean currentbutton = LOW;
  int ledmode = 0;
  
void setup() {
  // put your setup code here, to run once:
  pinMode(BLED,OUTPUT);
  pinMode(GLED,OUTPUT);
  pinMode(RLED,OUTPUT);
  pinMode(button,INPUT);
}

boolean debounce(boolean last)
{
  boolean current = digitalRead(button);
  if (last != current)
  {
    delay(5);
    current = digitalRead(button);
    
  }
  return (current);
  
}


void setMode(int mode)
{
  //RED
  if (mode == 1)
  {
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, HIGH);
  }
  //GREEN
   else if (mode == 2)
  {
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, HIGH);
  }
    //BLUE
   else if (mode == 3)
  {
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, LOW);
  }
  //PURPLE(RED+BLUE)
  else if (mode == 4)
  {
    analogWrite(RLED, 0);
    analogWrite(GLED, 127);
    analogWrite(BLED, 0);
  }
    //TEAL (BLUE+GREEN)
  else if (mode == 5)
  {
    analogWrite(RLED, 127);
    analogWrite(GLED, 0);
    analogWrite(BLED, 0);
  }
    //ORANGE (GREEN+RED)
  else if (mode == 6)
  {
    analogWrite(RLED, 0);
    analogWrite(GLED, 0);
    analogWrite(BLED, 127);
  }
    //WRITE(GREEN+RED+BLUE)
  else if (mode == 7)
  {
    analogWrite(RLED, 0);
    analogWrite(GLED, 0);
    analogWrite(BLED, 0);
  }
    //OFF
  else if (mode == 0)
  {
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, HIGH);
  }
}
void loop() {
  // put your main code here, to run repeatedly:
  currentbutton = debounce(lastbutton);
  if (lastbutton == LOW && currentbutton == HIGH)
  {
    ledmode++;
  }
  lastbutton = currentbutton;
  if (ledmode ==8)
    ledmode = 0;
  setMode(ledmode);

}
