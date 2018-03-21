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
*/

int pin[] = {2, 3, 4, 5, 6, 7, 8, 9};
int numbers[] = { 63, 6, 91, 79, 102, 109, 125, 7, 127, 111};
int randValue;

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(pin[i], OUTPUT);
    digitalWrite(pin[i], 1);
  }
  randomSeed(analogRead(0));
}

void loop() {
  int b;
  int display;
  
  // generisi slucajan broj 0-9
  randValue = random(10);
  
  // pronadji zapis koji se prikazuje
  display = numbers[randValue];
  
  // upali/ugasi svaki od 8 segmenata
  for (int i = 0; i < 8; i++) {
    
    // nadji poslednji bit koji treba da se upali/ugasi
    b = display & 1;
	  
    // upali/ugasi segment
    if (b==1){
    digitalWrite(pin[i], LOW);
      } 
    else 
      {
      digitalWrite(pin[i], HIGH);
      }
    
    // nadji sledeci bit
    display = display >> 1;
  }
  delay(300);
}
