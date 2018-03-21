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
  byte b;
  int display;
  randValue = random(5);
  Serial.println(randValue);
  display = numbers[randValue];
  Serial.println("display");
  Serial.println(display);
  for (int i = 0; i < 6; i++) {
    b = display & 1;
    //b = 1 - b;
    Serial.println("b=");
    Serial.println(b);
    Serial.println("display pre");
    Serial.println(display);
    if (b==1){
    digitalWrite(pin[i], HIGH);
    } else {
      digitalWrite(pin[i], LOW);
      }
    display = display >> 1;
    Serial.println("display posle");
    Serial.println(display);
    Serial.println("#");
  }
  delay(1000);
}
