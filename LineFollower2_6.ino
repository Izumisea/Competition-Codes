  /*
                                  Line following Code
by Insii(Rodjaym D. Nomorosa), Izumisea(Paul Marasigan), Ralph Narcisso Sept - Nov 2023
*/

// right motor
int enA = 10;
int in1 = 9;
int in2 = 8;
// left motor
int enB = 5;
int in3 = 7;
int in4 = 6;

void forward ()
{
  digitalWrite(in1, HIGH);   
  digitalWrite(in2, LOW);
  analogWrite(enA, 160);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 160);
}
void backward ()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 255);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 255);
}

void left ()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 120);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 85);
}

void right ()
{
   digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 85);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 120);
}

void fastright ()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 75);
  digitalWrite(in4, LOW);
  analogWrite(enB, 145);
}

void fastleft ()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 145);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 70);
}

void slowforward ()
{
 
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 190); 
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 170);
}

void stop ()
{
 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0); 
  digitalWrite(in3, 0);
  digitalWrite(in4, LOW);
  analogWrite(enB, LOW);
}

void setup() {
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
    int IR_fl = digitalRead(A0); //far left
    int IR_cl = digitalRead(A1); //close left
    int IR_c = digitalRead(A2); //middle
    int IR_cr = digitalRead(A3); //close right sensor
    int IR_fr = digitalRead(A4); //far right sensor
              // int IR_6 = digitalRead(A5); ---

//Black = 0
//White = 1

if(IR_c == 0){
  slowforward();
}
else if(IR_fl == 0){
  fastleft();
}
else if(IR_fr == 0){
  fastright();
}
else if(IR_cr == 0 && IR_cl == 1){
  fastright();
}
else if(IR_cl == 0 && IR_cr == 1){
  fastleft();
}
else if(IR_c == 1 && IR_cl == 1 && IR_fl == 0){
  fastleft();
}
else if(IR_c == 1 && IR_cr == 1 && IR_fr == 0){
  fastright();
}
else if(IR_c == 0 && IR_cr == 1 && IR_fr == 0){
  fastright();
}
else if(IR_c == 0 && IR_cl == 1 && IR_fl == 1){
  fastleft();
}
else if(IR_c == 1 && IR_cl == 1 && IR_fl == 1 && IR_cr == 0){
  fastright();
}
else if(IR_c == 1 && IR_cr == 1 && IR_fr == 1 && IR_cl == 0){
  fastleft();
}
else if(IR_c == 1 && IR_cr == 1 && IR_fr == 1 && IR_cl == 0 && IR_fl == 0){
  fastleft();
}
else if(IR_c == 1 && IR_cl == 1 && IR_fl == 1 && IR_cr == 0 && IR_fr == 0){
  fastright();
}
}