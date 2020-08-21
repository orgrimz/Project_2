void setup() 
{ Serial.begin(9600); 
 pinMode(10,OUTPUT);
 pinMode(9,OUTPUT);
 pinMode(2,OUTPUT);
 pinMode(3,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(6,OUTPUT);
 pinMode(7,OUTPUT);
 pinMode(8,INPUT);
 pinMode(12,OUTPUT);
 pinMode(13,OUTPUT);
 pinMode(A0,INPUT);
 pinMode(A1,INPUT);
 Serial.println("Config Ready"); 
}

void loop() {  
    char DIR;
    int SPD,SCA;
    long duration, distance;
  digitalWrite(12, LOW); 
  delayMicroseconds(2);
  digitalWrite(12, HIGH);
  delayMicroseconds(10);
  digitalWrite(12, LOW);
  duration = pulseIn(8,HIGH);
  distance = (duration/2) / 29.1;
   if (distance >= 300) {
     digitalWrite(13, LOW);
     //Serial.print(distance);
     //Serial.println(" cm");
     delay(10);
    }

  else if (distance >= 150 && distance < 300) {
     digitalWrite(13, HIGH);
     delay(1000);
     digitalWrite(13, LOW);
     delay(1000);
     //Serial.print(distance);
     //Serial.println(" cm");
     delay(1000);
    }
   else if (distance >= 50 && distance < 150) {
     digitalWrite(13,HIGH);
     delay(300);
     digitalWrite(13,LOW);
     delay(300);
     //Serial.print(distance);
     //Serial.println(" cm");
     delay(300);
    }
  else {
     digitalWrite(13,HIGH);
     delay(300);
     //Serial.print(distance);
     //Serial.println(" cm");
     delay(300);
    }

  //////// DC MOTOR /////////
    if(Serial.available()>0) {  
      DIR = Serial.read();
      SPD = Serial.parseInt();
      SCA = map(SPD,0,100,0,255);
        if (DIR == 'R') {
            analogWrite(9,SCA);
            digitalWrite(2,HIGH);
            digitalWrite(3,LOW);
                digitalWrite(4,HIGH);
            digitalWrite(5,LOW);
            Serial.print("TURN RIGHT ");
            Serial.print(SPD);
            Serial.println("%");
        }
        else if (DIR == 'L') {
            analogWrite(9,SCA);
            digitalWrite(2,LOW);
            digitalWrite(3,HIGH);
                digitalWrite(4,LOW);
            digitalWrite(5,HIGH);
            Serial.print("TURN LEFT ");
            Serial.print(SPD);
            Serial.println("%");  
        }
          else if (DIR == 'U') {
            analogWrite(10,100);
            digitalWrite(6,HIGH);
            digitalWrite(7,LOW);
            Serial.println("LIFT UP ");
                delay(5000);
                analogWrite(10,0);
            }
            else if (DIR == 'D') {
            analogWrite(10,100);
            digitalWrite(6,LOW);
            digitalWrite(7,HIGH);
            Serial.println("LIFT DOWN ");
                delay(5000);
                analogWrite(10,0);
            }
        else {
            analogWrite(9,0);
            Serial.println("INPUT ERROR");
        }
  } 
}
