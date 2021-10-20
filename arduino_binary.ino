int potPin = 0; // value of the analog port to read from
int val = 0; // analog value from the potentiometer
int timer = 0; // timer for incrementing the bits

void setup() {
  // initialize output pins and begin serial use
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // get the analog value from potPin
  val = analogRead(potPin);

  // increment the timer
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

  // set the timer back to 0 every so often, so it doesn't eventually overflow
  if (timer > 63)
  {
    timer = 0;
  }

  // delay based on the potentiometer
  delay(750 - (val / 2));
}
