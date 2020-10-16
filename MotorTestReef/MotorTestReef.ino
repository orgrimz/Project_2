  int en1 = 11,
      en2 = 9,
      in1 = 12,
      in2 = 13,
      in3 = 10,
      in4 = 8;

void setup() {
  
  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
}

void loop() {

  int i = 75;
  int j = 100;
  
  i = map(i, 0, 100, 0, 255);
  j = map(j, 0, 100, 0, 255);

  //Right wheel
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(en1, i);

  //Left wheel
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(en2, j);
}
