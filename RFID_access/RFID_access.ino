
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN 9
#define SS_PIN 10
MFRC522 mfrc522(SS_PIN, RST_PIN);

byte LecturaUID[4];
byte Usuario1[4] = { 0xEB, 0x74, 0x2F, 0x21}; //Tarjeta
byte Usuario2[4] = { 0xDB, 0xB9, 0xA7, 0x1B}; //Llavero

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();

}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent())
    return;

  if (!mfrc522.PICC_ReadCardSerial())
    return;

  Serial.print("UID:");
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    if (mfrc522.uid.uidByte[i] < 0x10) {
      Serial.print(" 0");
    } else {
      Serial.print(" ");
    }
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    LecturaUID[i] = mfrc522.uid.uidByte[i];
  }
  Serial.println();
  if(comparaUID(LecturaUID, Usuario1)) {
    Serial.println("Bienvenido Usuario 1");
  } else if(comparaUID(LecturaUID, Usuario2)) {
    Serial.println("Bienvenido Usuario 2");
  } else {
    Serial.println("No te conozco");
  }
  mfrc522.PICC_HaltA();
}

boolean comparaUID(byte lectura[], byte usuario[]) {
  for(byte i=0; i < mfrc522.uid.size; i++){
    if(lectura[i] != usuario[i]) {
      return(false);
    }
  }
  return(true);
}
