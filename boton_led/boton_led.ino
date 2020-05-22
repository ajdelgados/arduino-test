void setup() {
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  if(digitalRead(2)== HIGH) {
    for(int i = 0; i < 5; i++) {
      digitalWrite(13, !digitalRead(13));
      digitalWrite(8, HIGH);
      delay(500);
      digitalWrite(8, LOW);
      delay(500);
    }
  }
}
