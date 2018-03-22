/*
anodni - 7 segmentni display
    a
   ---      | | | | |
  |   |     g f + a b
 f|   |b
  | g |     
   ---
  |   |
 e|   |c
  |   |		  | | | | |
   ---	.	  e d + c dp
    d	dp
	
    hgfedcba   dec
0 = 00111111 =  63
1 = 00000110 =   6
2 = 01011011 =  91
3 = 01001111 =  79
4 = 01100110 = 102
5 = 01101101 = 109
6 = 01111101 = 125
7 = 00000111 =   7
8 = 01111111 = 127
9 = 01101111 = 111
  = 00000000 =   0
. = 10000000 = 128
*/

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


