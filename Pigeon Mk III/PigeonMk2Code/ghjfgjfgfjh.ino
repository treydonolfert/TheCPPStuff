int motor1_pin1 = 4;

int motor1_pin2 = 5;

int motor2_pin1 = 6;

int motor2_pin2 = 7;

int x = 255;

int linesensorleft = 9;

int linesensorright = 8;

int proximitysensorleft = 3;

int proximitysensorright = 13;

void forward() {
  digitalWrite(motor1_pin1, LOW);
  digitalWrite(motor1_pin2, HIGH);
  digitalWrite(motor2_pin1, LOW);
  digitalWrite(motor2_pin2, HIGH);
  x = 255;
}

void backward() {
  digitalWrite(motor1_pin1, HIGH);
  digitalWrite(motor1_pin2, LOW);
  digitalWrite(motor2_pin1, HIGH);
  digitalWrite(motor2_pin2, LOW);
  x = 100;
}

void left() {
  digitalWrite(motor1_pin1, LOW);
  digitalWrite(motor1_pin2, HIGH);
  digitalWrite(motor2_pin1, HIGH);
  digitalWrite(motor2_pin2, LOW);
  x = 255;
}

void right() {
  digitalWrite(motor1_pin1, HIGH);
  digitalWrite(motor1_pin2, LOW);
  digitalWrite(motor2_pin1, LOW);
  digitalWrite(motor2_pin2, HIGH);
  x = 255;
}

void stop() {
  digitalWrite(motor1_pin1, LOW);
  digitalWrite(motor1_pin2, LOW);
  digitalWrite(motor2_pin1, LOW);
  digitalWrite(motor2_pin2, LOW);
}

void setup()
{
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, INPUT);
  pinMode(linesensorleft, INPUT);
  pinMode(linesensorright, INPUT);
  pinMode(proximitysensorleft, INPUT);
  pinMode(proximitysensorright, INPUT);
  pinMode(0, OUTPUT);
  Serial.begin(9600);
delay(3500);
analogWrite(A0, x);
analogWrite(A1, x);
left();
delay(200);
}


void loop()
{
if (digitalRead(linesensorleft) == 1) { //revisit, 0 might be wrong
  forward();
  delay(750);
  left();
  delay(200);
}
if (digitalRead(linesensorright) == 1) {
  forward();
  delay(750);
  right();
  delay(200);
}
while (digitalRead(proximitysensorright) == 0 && digitalRead(linesensorright) == 0 && digitalRead(linesensorleft) == 0) {
  left();
}
while (digitalRead(proximitysensorleft) == 0 && digitalRead(linesensorright) == 0 && digitalRead(linesensorleft) == 0) {
  right();
}
backward();
  //if (Sonic_Timing()/29/2 < 3) {
  //  backward();
 //   x = 255;
 //   analogWrite(A0, x);
 //   analogWrite(A1, x);

  } //else {
    //stop();
