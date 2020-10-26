#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SoftwareSerial.h>
SoftwareSerial PRO(D1,D0);

char auth[] = "GnloGqTqM4cAXWFcU41QctuuG4dpxYR4";
char ssid[] = "Nior";
char pass[] = "junior11";
int i=1,j=1,k=0,m=1;
char DIR = 'R',DI;
WidgetLED DOCA(V0);
WidgetLED DOCB(V1);
WidgetLED UP(V2);
WidgetLED DOWN(V3);
WidgetLED RUN(V4);
WidgetLED STOP(V5);
WidgetLED STAA(V6);
WidgetLED STAB(V7);
// DOCA
BLYNK_WRITE(V8){
  if(param.asInt() == 1){
    if (i == 1) {
    Serial.println('K');
    DOCA.on();
    i = i-1;
    }
    else if (i == 0) {
    DOCA.off();
    Serial.println('B');
    i = i+1;
    }
  }
}
// DOCB
BLYNK_WRITE(V9){
  if(param.asInt() == 1){
    if (j == 1) {
    Serial.println('C');
    DOCB.on();
    j = j-1;
    }
    else if (j == 0) {
    DOCB.off();
    Serial.println('D');
    j = j+1;
    }
  }
}
// UP
BLYNK_WRITE(V10){
  if(param.asInt() == 1){
    Serial.println('E');
    UP.on();
    DOWN.off();
    DIR = 'U';
    PRO.write(DIR);
  }
}
// DOWN
BLYNK_WRITE(V11){
  if(param.asInt() == 1){
    UP.off();
    DOWN.on();
    DIR = 'D';
    PRO.write(DIR);
    Serial.println('F');
    }
  }
// RUN/STOP
BLYNK_WRITE(V12){
  if(param.asInt() == 1){
    Serial.println('G');
    RUN.off();
    STOP.on();
    k = 1;
  }
  else {
    RUN.on();
    STOP.off();
    Serial.println('H');
    k = 0;
    DIR = 'R';
    PRO.write(DIR);
  }
}
// SEND/RECEIVE
BLYNK_WRITE(V13){
  if(param.asInt() == 1){
    DIR = 'B';
    PRO.write(DIR);
//    if(PRO.available()>0)
//    {
//    DI = PRO.read();
//    Serial.println(DI);
//    if (m == 1 && DI == 'A') {
//      Serial.println('I');
//      STAA.on();
//      STAB.off();
//      m = m-1;
//    }
//    else if (m == 0 && DI == 'Z') {
//      STAA.off();
//      STAB.on();
//      Serial.println('J');
//      m = m+1;
//    }
//    }
  }
}
void setup()
{
  Serial.begin(9600);
  WiFi.begin(ssid, pass);
  Blynk.begin(auth, ssid, pass);
  PRO.begin(4800);
}

void loop()
{
 Blynk.run();
 if(k == 1) {
  DIR = 'S';
  PRO.write(DIR);
 }
 if(PRO.available()>0)
    {
    DI = PRO.read();
    Serial.println(DI);
    if (DI == 'A') {
      Serial.println('I');
      STAA.on();
      STAB.off();
    }
    else if (DI == 'Z') {
      STAA.off();
      STAB.on();
      Serial.println('J');
    }
    }
}
