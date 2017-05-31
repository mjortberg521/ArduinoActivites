int openLimit;
int closeLimit;
int openButton;
int closeButton;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT); //Open limit
  pinMode(3, INPUT); //Close limit
  pinMode(6, INPUT); //Open button
  pinMode(7, INPUT); //Close button

  pinMode(9, OUTPUT); //LED PIN
  pinMode(10, OUTPUT); //MOTOR OPEN
  pinMode(11, OUTPUT); //MOTOR CLOSE
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  openLimit = digitalRead(2);
  closeLimit = digitalRead(3);
  openButton = digitalRead(6);
  closeButton = digitalRead(7);

  //digitalWrite(10, LOW);
  //digitalWrite(11, LOW);
  digitalWrite(9, HIGH);


  if (openButton == HIGH)
  {
    while (digitalRead(2) == LOW) { //while it is not open
      digitalWrite(10, HIGH); //activate openMotor
      digitalWrite(9, LOW); //Keep LED off until it hits the openLimit
    }
    while (digitalRead(2) == HIGH) { //while it is open
      digitalWrite(10, LOW); //activate openMotor
      digitalWrite(9, HIGH); //Keep LED off until it hits the openLimit
    }

  }

  else
  {
    digitalWrite(10, LOW);
  }

  if (closeButton == HIGH)
  {
    while (digitalRead(3) == LOW) {
      digitalWrite(11, HIGH);
      digitalWrite(9, LOW);
    }
    while (digitalRead(3) == HIGH) {
      digitalWrite(11, LOW);
      digitalWrite(9, HIGH);
    }
  }

  else
  {
    digitalWrite(11, LOW);
  }

}
