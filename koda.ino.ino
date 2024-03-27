const int naprejTipkaPin = 2;
const int nazajTipkaPin = 5;
const int izklopTipkaPin = 3;
const int izklopNazajTipkaPin = 4;
const int naprejLedPin = 10;
const int nazajLedPin = 11;
const int dodatenLedPin = 12;
void setup() {
  pinMode(naprejTipkaPin, INPUT);
  pinMode(nazajTipkaPin, INPUT);
  pinMode(izklopTipkaPin, INPUT);
  pinMode(izklopNazajTipkaPin, INPUT);
  pinMode(naprejLedPin, OUTPUT);
  pinMode(nazajLedPin, OUTPUT);
  pinMode(dodatenLedPin, OUTPUT);
}
void loop() {
  int naprejStanje = digitalRead(naprejTipkaPin);
  int nazajStanje = digitalRead(nazajTipkaPin);
  if (naprejStanje == HIGH && nazajStanje == HIGH) {
    digitalWrite(naprejLedPin, LOW);
    digitalWrite(nazajLedPin, LOW);
    digitalWrite(dodatenLedPin, LOW);
  } else {
    if (naprejStanje == HIGH && digitalRead(izklopTipkaPin) == LOW && digitalRead(izklopNazajTipkaPin) == LOW) {
      digitalWrite(naprejLedPin, HIGH);
      digitalWrite(dodatenLedPin, HIGH);
    } else {
      digitalWrite(naprejLedPin, LOW);
      digitalWrite(dodatenLedPin, LOW);
    }
    if (nazajStanje == HIGH && digitalRead(izklopTipkaPin) == LOW && digitalRead(izklopNazajTipkaPin) == LOW) {
      digitalWrite(nazajLedPin, HIGH);
      digitalWrite(dodatenLedPin, HIGH);
    } else {
      digitalWrite(nazajLedPin, LOW);
      digitalWrite(dodatenLedPin, LOW);
    }
  }
}
