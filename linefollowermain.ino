#include <AFMotor.h>

AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ);


#define R_1 A4

#define R_2 A3
#define R_3 A2
#define R_4 A1
#define R_5 A0

#define B BACKWARD
#define F FORWARD
#define R RELEASE
#define s 130


void setup() {

  pinMode(R_1, INPUT); 

  pinMode(R_2, INPUT); 

  pinMode(R_3, INPUT);

  pinMode(R_4, INPUT);

  pinMode(R_5, INPUT);
  Serial.begin(9600);
  
}

void loop(){
  Serial.print(digitalRead(R_1));
  Serial.print(digitalRead(R_2));
  Serial.print(digitalRead(R_3));
  Serial.print(digitalRead(R_4));
  Serial.println(digitalRead(R_5));
  if((digitalRead(R_1) == 1) && (digitalRead(R_2) == 1) && (digitalRead(R_3) == 1) && (digitalRead(R_4) == 1) && (digitalRead(R_5) == 1)){
    stop();
  }
  else if((digitalRead(R_1) == 1) && (digitalRead(R_2) == 0) && (digitalRead(R_3) == 1) && (digitalRead(R_4) == 1) && (digitalRead(R_5) == 1)){
    partialleft();
  }
  else if((digitalRead(R_1) == 1) && (digitalRead(R_2) == 1) && (digitalRead(R_3) == 1) && (digitalRead(R_4) == 0) && (digitalRead(R_5) == 1)){
    partialright();
  }
  else if((digitalRead(R_1) == 1) && (digitalRead(R_2) == 0) && (digitalRead(R_3) == 0) && (digitalRead(R_4) == 1) && (digitalRead(R_5) == 1)){
    partialleft();
  }
  else if((digitalRead(R_1) == 1) && (digitalRead(R_2) == 1) && (digitalRead(R_3) == 0) && (digitalRead(R_4) == 0) && (digitalRead(R_5) == 1)){
    partialright();
  }
 
  else if((digitalRead(R_1) == 0) && (digitalRead(R_2) == 0) && (digitalRead(R_3) == 0) && (digitalRead(R_4) == 0) && (digitalRead(R_5) == 0)){
    stop();
  }
  else if((digitalRead(R_1) == 1) && (digitalRead(R_2) == 1) && (digitalRead(R_3) == 0) && (digitalRead(R_4) == 1) && (digitalRead(R_5) == 1)){
    forward();
  }
  else if((digitalRead(R_1) == 0) && (digitalRead(R_2) == 1) && (digitalRead(R_3) == 1) && (digitalRead(R_4) == 1) && (digitalRead(R_5) == 1)){
    left();
  }
  
  else if((digitalRead(R_1) == 1) && (digitalRead(R_2) == 1) && (digitalRead(R_3) == 1) && (digitalRead(R_4) == 1) && (digitalRead(R_5) == 0)){
    right();
  }
  else if((digitalRead(R_1) == 0) && (digitalRead(R_2) == 0) && (digitalRead(R_3) == 1) && (digitalRead(R_4) == 1) && (digitalRead(R_5) == 1)){
    left();
  }
  
  else if((digitalRead(R_1) == 1) && (digitalRead(R_2) == 1) && (digitalRead(R_3) == 1) && (digitalRead(R_4) == 0) && (digitalRead(R_5) == 0)){
    right();
  }
  else if((digitalRead(R_1) == 0) && (digitalRead(R_2) == 0) && (digitalRead(R_3) == 0) && (digitalRead(R_4) == 1) && (digitalRead(R_5) == 1)){
    left();
  }
  else if((digitalRead(R_1) == 1) && (digitalRead(R_2) == 0) && (digitalRead(R_3) == 0) && (digitalRead(R_4) == 0) && (digitalRead(R_5) == 1)){
    forward();
  }
  else if((digitalRead(R_1) == 1) && (digitalRead(R_2) == 1) && (digitalRead(R_3) == 0) && (digitalRead(R_4) == 0) && (digitalRead(R_5) == 0)){
    right();
  }
  else if((digitalRead(R_1) == 0) && (digitalRead(R_2) == 0) && (digitalRead(R_3) == 0) && (digitalRead(R_4) == 0) && (digitalRead(R_5) == 1)){
    left();
  }
  else if((digitalRead(R_1) == 1) && (digitalRead(R_2) == 0) && (digitalRead(R_3) == 0) && (digitalRead(R_4) == 0) && (digitalRead(R_5) == 0)){
    right();
  }
  else{
    forward();
  }
}


void partialright(){
  //main
  motor2.run(R);
  motor2.setSpeed(0);
  motor1.run(B);
  motor1.setSpeed(s);
}

void partialleft(){
  // main
  motor1.run(R);
  motor1.setSpeed(0);
  motor2.run(B);
  motor2.setSpeed(s);
}

void right(){
  // main
  motor1.run(B);
  motor1.setSpeed(s);
  motor2.run(F);
  motor2.setSpeed(255);
  delay(400);
}

void left(){
  //main
  motor1.run(F);
  motor1.setSpeed(255);
  motor2.run(B);
  motor2.setSpeed(s);
  delay(400);
}

void forward(){
  //main
  motor1.run(B);
  motor1.setSpeed(s);
  motor2.run(B);
  motor2.setSpeed(s);

  
}

void stop(){
  motor1.run(RELEASE);
  motor1.setSpeed(0);
  motor2.run(RELEASE);
  motor2.setSpeed(0);
}
