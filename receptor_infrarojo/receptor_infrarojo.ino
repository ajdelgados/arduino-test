#include <IRremote.h>
#define boton_pulsar 0xE0E0F20D // pulsar
#define boton_subir 0xE0E048B7 // subir canal
#define boton_bajar 0xE0E008F7 // bajar canal
#define boton_colores 0xE0E0738C

int SENSOR = 8;
IRrecv irrecv(SENSOR);
decode_results codigo;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  if(irrecv.decode(&codigo)) {
    Serial.println(codigo.value, HEX);
    if(codigo.value == boton_pulsar) {
      digitalWrite(13, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
    } else if(codigo.value == boton_subir) {
      digitalWrite(13, LOW);
      digitalWrite(12, HIGH);
      digitalWrite(11, LOW);
    } else if(codigo.value == boton_bajar) {
      digitalWrite(13, LOW);
      digitalWrite(12, LOW);
      digitalWrite(11, HIGH);
    } else if(codigo.value == boton_colores) {
      digitalWrite(13, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(11, HIGH);
    }
    irrecv.resume();
  }
  delay(100);
}
