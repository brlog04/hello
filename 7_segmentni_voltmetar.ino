int pin[] = {2, 3, 4, 5, 6, 7, 8, 9};
int numbers[] = { 63, 6, 91, 79, 102, 109, 125, 7, 127, 111, 0, 128 };
int randValue;

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(pin[i], OUTPUT);
    digitalWrite(pin[i], 1);
  }
}

void loop() {

  // procitaj vrednost sa ulaza (treba da bude 0 - 9,9V)
  int analVal1;
  analVal1 = analogRead(0);
  analVal1 = map(analVal1, 0, 1023, 0, 99);

  // kreiraj celobrojnu i decimalnu vrednost
  int analLow = analVal1%10;
  int analHigh = analVal1/10; 

  // prikazi cifre
  showNumber(analHigh,500);
  showNumber(11,""); // tacka
  showNumber(analLow,500);
  showNumber(10,900);// prazno
  
}

void showNumber(int number, int delmil){
  if (delmil == ""){
    delmil = 300;
  }
  int b;
  int display;
  display = numbers[number];
  for (int i = 0; i < 8; i++) {
    b = display & 1;
    b = 1 - b;
    digitalWrite(pin[i], b);
    display = display >> 1;
  }
  delay(delmil);
}


