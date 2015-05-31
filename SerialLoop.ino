#define EXTSERIAL_BAUDS 9600
#define INTSERIAL_BAUDS 9600

//Arduino
//#define EXTSERIAL_DEV Serial
//SoftwareSerial INTSERIAL_DEV(10, 11); // RX, TX

//Maple
#define EXTSERIAL_DEV Serial2
#define INTSERIAL_DEV Serial



void setup() {
  delay(4000);
  INTSERIAL_DEV.begin(INTSERIAL_BAUDS);
  EXTSERIAL_DEV.begin(EXTSERIAL_BAUDS);
 
}

void loop() {
  char c;
  while (Serial.available()) {
    c = INTSERIAL_DEV.read();
    EXTSERIAL_DEV.print(c);
  }
  while (EXTSERIAL_DEV.available()) {
    c = EXTSERIAL_DEV.read();
    INTSERIAL_DEV.print(c);
  }
  
}
 
