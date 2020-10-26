#include <SoftwareSerial.h>
SoftwareSerial PRO(8,12);
void setup() 
{
 Serial.begin(9600);
 PRO.begin(4800);
 pinMode(11,OUTPUT); // Right Wheel
 pinMode(10,OUTPUT); // Left Wheel
 pinMode(9,OUTPUT);
 pinMode(2,OUTPUT);
 pinMode(3,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(6,OUTPUT);
 pinMode(7,OUTPUT);
 pinMode(A2,INPUT);
 pinMode(A5,OUTPUT);
 pinMode(13,OUTPUT); // RED
 pinMode(A0,INPUT); // RIGHT
 pinMode(A1,INPUT); // LEFT
 pinMode(A3,OUTPUT); // YELLOW
 pinMode(A4,INPUT); // MID
 Serial.println("Config Ready");
 char DIR = 'R';
}
void loop() {  
    char DIR,DI;
    int SPD,SCA;
    long duration, distance;
  digitalWrite(A5, LOW); 
  delayMicroseconds(2);
  digitalWrite(A5, HIGH);
  delayMicroseconds(10);
  digitalWrite(A5, LOW);
  duration = pulseIn(A2,HIGH);
  distance = (duration/2) / 29.1;
   if (distance >= 40) {
     digitalWrite(13,LOW);
     digitalWrite(A3,LOW);
    }
  else if (distance >= 10 && distance < 40) {
     digitalWrite(13,LOW);
     digitalWrite(A3,HIGH);
    }
  //////// DC MOTOR ///////// White! Black
    //if(Serial.available()>0) {
    DIR = PRO.read();
    Serial.println(DIR);
      //DIR = Serial.read();
      //SPD = Serial.parseInt();
      //SCA = map(SPD,0,100,0,255);
       if (!(digitalRead(A1)) && !(digitalRead(A0)) && distance >= 10 && DIR != 'S'){
            Forward(1);
        }
        else if (!(digitalRead(A1)) && digitalRead(A0) && distance >= 10 && DIR != 'S') {
            turnRight(150);
        }
        else if (digitalRead(A1) && !(digitalRead(A0)) && distance >= 10 && DIR != 'S') {
            turnLeft(150);
        }
        else if (digitalRead(A1) && digitalRead(A0) && DIR != 'S' && distance > 15){
            Brake(1);
            BrakeLED(1);
          if (DIR == 'D') {
            liftDOWN(1);
          }
          else if (DIR == 'U') {
            liftUP(1);
          }
          else if (DIR == 'B') {
            Backward(2500);
            turnLeft(2000);
            while (!(digitalRead(A4))) {
            turnLeft(1);
            }
          }
          if(PRO.available()>0) {
            DI = 'A';
            Serial.println(DI);
            PRO.write(DI);
            }
          DIR = 'R';
        }
        else if (digitalRead(A1) && digitalRead(A0) && DIR != 'S' && distance < 15){
            Brake(1);
            BrakeLED(1);
          if (DIR == 'D') {
            liftDOWN(1);
          }
          else if (DIR == 'U') {
            liftUP(1);
          }
          else if (DIR == 'B') {
            Backward(4000);
            turnLeft(2000);
            while (!(digitalRead(A4))) {
            turnLeft(1);
            }
          }
            if(PRO.available()>0) {
            DI = 'Z';
            Serial.println(DI);
            PRO.write(DI);
            }
          DIR = 'R';
        }
        else if (distance < 10 || DIR == 'S') {
            Brake(1);
            BrakeLED(1);
            Serial.println("STOP");
        }
  //} 
}
void Forward (int time)
{        
  analogWrite(10,179); // L
  analogWrite(11,170); //R
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  Serial.println("FRONT");
  delay(time);
}
void turnRight(int time)
{
  analogWrite(10,200);
  analogWrite(11,200);
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  Serial.println("TURN RIGHT");  
  delay(time);
}
void turnLeft(int time)
{
  analogWrite(10,200);
  analogWrite(11,200);
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  Serial.println("TURN LEFT");
  delay(time); 
}
void Brake(int time)
{
  analogWrite(10,0);
  analogWrite(11,0);
  Serial.println("BRAKE");
  delay(time);
}
void liftUP(int time)
{
  analogWrite(9,255);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  Serial.println("LIFT UP");
  delay(13000);
  analogWrite(9,0);
  delay(time);
}
void liftDOWN(int time)
{
  analogWrite(9,255);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  Serial.println("LIFT DOWN");
  delay(7000);
  analogWrite(9,0);
  delay(time);
}
void BrakeLED(int time)
{
  digitalWrite(13,HIGH);
  digitalWrite(A3,LOW);
  Serial.println("RED");
  delay(time);
}
void Backward(int time)
{
  analogWrite(10,155); // L
  analogWrite(11,190); // R
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  Serial.println("BACK");
  delay(time);
}
