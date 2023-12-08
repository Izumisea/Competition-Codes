// motor one
int enA = 10;
int in1 = 9;
int in2 = 8;
// motor two
int enB = 5;
int in3 = 7;
int in4 = 6;

void slowforward ()
{
 
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 100);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 150);
}

void forward ()
{
  digitalWrite(in1, HIGH);   
  digitalWrite(in2, LOW);
  analogWrite(enA, 200);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 200);
}
void backward ()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 100);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 100);
}

void left ()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 75);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 75);
}

void right ()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 75);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 75);
}

void fastRight ()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 75);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 75);
}

void fastLeft ()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 155);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 155);
}


void setup() {
delay(300);
  // put your setup code here, to run once:
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    int IR_LL = digitalRead(A0); //far left
    int IR_L = digitalRead(A1); //close left
    int IR_M = digitalRead(A2); //middle
    int IR_R = digitalRead(A3); //close right sensor
    int IR_RR = digitalRead(A4); //far right sensor
//White = 1
//Black = 0

//middle sensor 
if (IR_M == 0){
  if (IR_L == 1 && IR_R == 1){
    forward();
  }
  else{
    slowforward();
  }
}
//left sensor
else if (IR_LL == 0 || IR_L == 0){
  if (IR_LL == 0 && IR_L == 1){
    fastright();
  }
  else if (IR_LL == 1 && IR_L == 0){
    right();
  }
  else{
    right();
  }
}
//right sensor
else if (IR_RR == 0 || IR_R == 0){
  if (IR_RR == 0 && IR_R == 1){
    fastleft();
  }
  else if (IR_RR == 1 && IR_R == 0){
    left();
  }
  else{
    left();
  }
}






}