int potPin = 0;
int val = 0;
int timer = 0;
int subTimer = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(potPin);
  //Serial.println(val);
  //delay(200);
  timer++;
  Serial.println(timer);

  // handle the first bit
  if ((timer % 2) == 1)
  {
    digitalWrite(7, HIGH);
  }
  else
  {
    digitalWrite(7, LOW);
  }

  // handle the second bit
  if ((timer % 4) == 2)
  {
    digitalWrite(8, HIGH);
  }
  else if ((timer % 4) == 0)
  {
    digitalWrite(8, LOW);
  }

  // handle the third bit
  if ((timer % 8) == 4)
  {
    digitalWrite(9, HIGH);
  }
  else if ((timer % 8) == 0)
  {
    digitalWrite(9, LOW);
  }

  // handle the fourth bit
  if ((timer % 16) == 8)
  {
    digitalWrite(10, HIGH);
  }
  else if ((timer % 16) == 0)
  {
    digitalWrite(10, LOW);
  }

  // handle the fifth bit
  if ((timer % 32) == 16)
  {
    digitalWrite(11, HIGH);
  }
  else if ((timer % 32) == 0)
  {
    digitalWrite(11, LOW);
  }

  // delay based on the potentiometer
  delay(750 - (val / 2));
}
