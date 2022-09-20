// page 52
const int LED = 9;
const int button = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(button, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(button) == LOW)
  {
    digitalWrite(LED, LOW);
  }
  else
  {
    digitalWrite(LED, HIGH);
  }
}
