#include <IRremote.h>

#define IR_RECEIVE_PIN     A0


int BUTTON1 = 2;
int BUTTON2 = 3;
int BUTTON3 = 4;
int BUTTON4 = 5;


int luzquarto = 0;
int luzspot = 0;
int luzcama = 0;
int led = 0;

int lq = 8;
int ls = 9;
int lc = 10;
int led1 = 11;


int estadolq = 0;
int estadols = 0;
int estadolc = 0;
int estadoled1 = 0;

int auxiliar = 0;

void setup()
{

  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);


  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(BUTTON3, INPUT);
  pinMode(BUTTON4, INPUT);

  pinMode(lq, OUTPUT);
  pinMode(ls, OUTPUT);
  pinMode(lc, OUTPUT);
  pinMode(led1, OUTPUT);


}

void loop()
{
  if (IrReceiver.decode())
  {
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    IrReceiver.resume(); // Receive the next value
    auxiliar = 1;
  }


  if (IrReceiver.decodedIRData.decodedRawData == 0xFC03EF00 and auxiliar == 1) {
    digitalWrite(lq, LOW);
    auxiliar = 0;

  }
  if (IrReceiver.decodedIRData.decodedRawData == 0xFD02EF00 and auxiliar == 1) {
    digitalWrite(lq, HIGH);
    auxiliar = 0;

  }

  if (IrReceiver.decodedIRData.decodedRawData == 0xFE01FF00 and auxiliar == 1) {
    digitalWrite(ls, LOW);
    auxiliar = 0;
  }
  if (IrReceiver.decodedIRData.decodedRawData == 0xF609FF00 and auxiliar == 1) {
    digitalWrite(ls, HIGH);
    auxiliar = 0;
  }
  if (IrReceiver.decodedIRData.decodedRawData == 0xE916FF00 and auxiliar == 1) {
    digitalWrite(lc, LOW);
    auxiliar = 0;
  }
  if (IrReceiver.decodedIRData.decodedRawData == 0xF10EFF00 and auxiliar == 1) {
    digitalWrite(lc, HIGH);
    auxiliar = 0;
  }

  if (IrReceiver.decodedIRData.decodedRawData == 0x7170479F and auxiliar == 1) {
    digitalWrite(led1, LOW);
    auxiliar = 0;

  }
  if (IrReceiver.decodedIRData.decodedRawData == 0x8D2A4BAF and auxiliar == 1) {
    digitalWrite(led1, HIGH);
    auxiliar = 0;

  }


  if (IrReceiver.decodedIRData.decodedRawData == 0x7F806E80 and auxiliar == 1) {

    digitalWrite(lq, HIGH);
    digitalWrite(ls, HIGH);
    digitalWrite(lc, HIGH);
    digitalWrite(led1, HIGH);
    auxiliar = 0;

  }
  if (IrReceiver.decodedIRData.decodedRawData == 0x7E816E80 and auxiliar == 1) {

    digitalWrite(lq, LOW);
    digitalWrite(ls, LOW);
    digitalWrite(lc, LOW);
    digitalWrite(led1, LOW);
    auxiliar = 0;

  }



  if (digitalRead(BUTTON1) != estadolq) {
    estadolq = digitalRead( BUTTON1);
    digitalWrite(lq, !digitalRead(lq));
  }
  if (digitalRead(BUTTON2) != estadols) {
    estadols = digitalRead( BUTTON2);
    digitalWrite(ls, !digitalRead(ls));
  }
  if (digitalRead(BUTTON3) != estadolc) {
    estadolc = digitalRead( BUTTON3);
    digitalWrite(lc, !digitalRead(lc));
  }
  if (digitalRead(BUTTON4) != estadoled1) {
    estadoled1 = digitalRead( BUTTON4);
    digitalWrite(led1, !digitalRead(led1));
  }








  delay(500);
}
