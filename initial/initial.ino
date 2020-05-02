int red = 13;
int green = 8;
int ms = 1000;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop () {
  digitalWrite(red, HIGH);
  digitalWrite(green, LOW);
  delay(ms);
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
  delay(ms);
}
