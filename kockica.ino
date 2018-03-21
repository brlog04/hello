int pin[] = {2, 3, 4, 5, 6, 7, 8, 9};
int numbers[] = {119, 36, 93, 53, 46, 107};
int randValue;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 8; i++) {
    pinMode(pin[i], OUTPUT);
    digitalWrite(pin[i], 1);
  }
  randomSeed(analogRead(0));
}

void loop() {
  int b;
  int display;
  
  // generisi slucajan broj 0-5
  randValue = random(5);
  Serial.println(randValue);
  
  // pronadji zapis koji se prikazuje
  display = numbers[randValue];
  Serial.println("display");
  Serial.println(display);
  
  // upali/ugasi svaki od 8 segmenata
  for (int i = 0; i < 8; i++) {
    
    // nadji poslednji bit koji treba da se upali/ugasi
    b = display & 1;
    //b = 1 - b;
    Serial.println("b=");
    Serial.println(b);
    Serial.println("display pre");
    Serial.println(display);
    
    // upali/ugasi segment
    if (b==1){
    digitalWrite(pin[i], HIGH);
      } 
    else 
      {
      digitalWrite(pin[i], LOW);
      }
    
    // nadji sledeci bit
    display = display >> 1;
    Serial.println("display posle");
    Serial.println(display);
    Serial.println("#");
  }
  delay(1000);
}
