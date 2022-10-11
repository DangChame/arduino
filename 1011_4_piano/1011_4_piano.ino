#define NOTE_C 262
#define NOTE_D 294
#define NOTE_E 330
#define NOTE_G 392
#define NOTE_A 440

const int spk = 9;
const int but_c = 7;
const int but_d = 6;
const int but_e = 5;
const int but_g = 4;
const int but_a = 3;
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  while (digitalRead(but_c))
    tone(spk, NOTE_C);
  while (digitalRead(but_d))
    tone(spk, NOTE_D);
  while (digitalRead(but_e))
    tone(spk, NOTE_E);
  while (digitalRead(but_g))
    tone(spk, NOTE_G);
  while (digitalRead(but_a))
    tone(spk, NOTE_A);
  noTone(spk);
}
