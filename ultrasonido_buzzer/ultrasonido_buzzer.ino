int TRIG = 10;
int ECO = 9;
int LED = 13;
int BUZZER = 8;
int DURACION;
int DISTANCIA;

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECO, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIG, HIGH);
  delay(1);
  digitalWrite(TRIG, LOW);
  DURACION = pulseIn(ECO, HIGH);
  DISTANCIA = DURACION / 58.2;
  Serial.println(DISTANCIA);
  delay(100);
  if(DISTANCIA < 50 && DISTANCIA > 0) {
      digitalWrite(13, HIGH);
      digitalWrite(8, HIGH);
      delay(DISTANCIA * 10);
      digitalWrite(13, LOW);
      digitalWrite(8, LOW);
  }
}
