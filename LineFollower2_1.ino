  /*
                                  Line following Code
by Insii(Rodjaym D. Nomorosa), Izumisea(Paul Marasigan), Ralph Narcisso Sept - Nov 2023
*/

// motor one
int enA = 10;
int in1 = 9;
int in2 = 8;
// motor two
int enB = 5;
int in3 = 7;
int in4 = 6;

void forward ()
{
  digitalWrite(in1, HIGH);   
  digitalWrite(in2, LOW);
  analogWrite(enA, 235);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 255);
}
void backward ()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 200);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 255);
}

void left ()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 55);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 35);
}

void right ()
{
   digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 35);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 55);
}

void fastRight ()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 125);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 145);
}

void fastLeft ()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 145);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 125);
}

void slowforward ()
{
 
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 130);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 150);
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
    int IR_1 = digitalRead(A0); //far left
    int IR_2 = digitalRead(A1); //close left
    int IR_3 = digitalRead(A2); //middle
    int IR_4 = digitalRead(A3); //close right sensor
    int IR_5 = digitalRead(A4); //far right sensor
              // int IR_6 = digitalRead(A5); ---

if (IR_3 == 0){ 
  slowforward();  
}
else if (IR_2 == 1 && IR_4 == 0){
  //delay(2); //marked
  right();
}
else if (IR_5 == 0){
  if(IR_4 == 0){
    delay(2);
    fastLeft();
  }
  else{
    fastRight();
  }
}
else if (IR_2 == 0 && IR_4 == 1){
  ///delay(2); //marked
  left();
}
else if (IR_1 == 0){
  if(IR_2 == 0){
    delay(2);
    fastRight();
  }else{
    fastLeft();
  }
}
else if (IR_5 == 0 && IR_3 == 1 && IR_4 == 1){
  delay(1);
  fastRight();
} 
else if (IR_1 == 0 && IR_3 == 1 && IR_2 == 1){
  delay(1);
  fastLeft();
} 
else if (IR_3 == 1 && IR_2 == 1 && IR_4 == 0){
  //delay(2); //marked
  right();
}else if (IR_3 == 1 && IR_2 == 0 && IR_4 == 1){
  //delay(2); //marked
  left();
}else if (IR_3 == 0 && IR_2 == 1 && IR_4 == 0){
  //delay(2); //marked
  right();
}else if (IR_3 == 0 && IR_2 == 0 && IR_4 == 1){
  //delay(2); //marked  
  left();
}
else if (IR_2 == 0 && IR_4 == 0){
  backward();
}
else if (IR_4 == 0){
  right();
}
}

