/*
 3 diode zakacene napinove 2,4,6
 random se pale i svetle 1 sekundu
 */
int randomNumber;
int dioda1;
int dioda2;
int dioda0;
int pinDioda0 = 2;
int pinDioda1 = 4;
int pinDioda2 = 6;

void setup()
{
  Serial.begin(9600);
  randomSeed(analogRead(0));
  pinMode(pinDioda0, OUTPUT);
  pinMode(pinDioda1, OUTPUT);
  pinMode(pinDioda2, OUTPUT);
  Serial.println("start");

}

void loop()
{
  randomNumber = random(7);
  Serial.println(randomNumber);
  dioda0 = bitRead(randomNumber, 0);
  Serial.println(dioda0);
  dioda1 = bitRead(randomNumber, 1);
  Serial.println(dioda1);
  dioda2 = bitRead(randomNumber, 2);
  Serial.println(dioda2);
  Serial.println("#");

  if (dioda0 == 1) {
    digitalWrite(pinDioda0, HIGH);
  } else {
    digitalWrite(pinDioda0, LOW);
  }

  if (dioda1 == 1) {
    digitalWrite(pinDioda1, HIGH);
  } else {
    digitalWrite(pinDioda1, LOW);
  }

  if (dioda2 == 1) {
    digitalWrite(pinDioda2, HIGH);
  } else {
    digitalWrite(pinDioda2, LOW);
  }

  delay(1000);
}
