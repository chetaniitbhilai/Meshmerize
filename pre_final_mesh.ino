#define F BACKWARD 
#define B FORWARD
#define R RELEASE

#define in3 3
#define in5 5
#define in6 9
#define in9 6

int v[3];
int cnt=0;
int val;
float fkd=10,fkp=75;

int P, D, I, perror, PID_VAL, error;
int left_sp, right_sp,negright_sp,negleft_sp;
int lfspeed = 150;
int Sensors[] = {A5,A0, A1, A2, A3, A4}; 

float Kp = 0;
float Kd = 0;
float Ki = 0;

int threshold[6]={0,350,400,350,300,360};



void setup()
{
  Serial.begin(9600);
}


void loop()
{
  if (Serial.available()) {
    while(Serial.available() == 0);
    valuesread();
    processing();
  }

  while (1)
  {
    if (analogRead(Sensors[1]) < threshold[1] && analogRead(Sensors[5]) > threshold[5] )
    {
      left_sp = 0; right_sp = lfspeed;
      analogWrite(in3, 0);
      analogWrite(in5,lfspeed);
      analogWrite(in6,0);
      analogWrite(in9,lfspeed);
    }

    else if (analogRead(Sensors[5]) < threshold[5] && analogRead(Sensors[1]) > threshold[1])
    {
      left_sp = lfspeed; right_sp = 0;
      analogWrite(in3,lfspeed);
      analogWrite(in5,0);
      analogWrite(in6,lfspeed);
      analogWrite(in9,0);
    }
    else if (analogRead(Sensors[3]) < threshold[3])
    {
      Kp = 0.00075 * (700 - analogRead(Sensors[3]));
      Kd = 10 * Kp;
      linefollow();
    }
  }
}

void linefollow()
{
  int error = (analogRead(Sensors[2])) - (analogRead(Sensors[4]));

  P = error;
  I = I + error;
  D = error - perror;

  PID_VAL = (Kp * P) + (Ki * I) + (Kd * D);
  perror = error;

  left_sp = lfspeed - PID_VAL;
  right_sp = lfspeed + PID_VAL;
  negleft_sp = -1*left_sp;
  negright_sp = -1*right_sp;

  if (left_sp > 255) {
    left_sp = 255;
  }
  if (negleft_sp > 255) {
    negleft_sp = 255;
  }
  if (right_sp > 255) {
    right_sp = 255;
  }
  if (negright_sp > 255) {
    negright_sp =255;
  }
  if(right_sp>0 && left_sp>0){
    analogWrite(in3,0);
    analogWrite(in5,left_sp);
    analogWrite(in6,right_sp);
    analogWrite(in9,0);
  }
  if(right_sp>0 && left_sp<0){
    analogWrite(in3,negleft_sp);
    analogWrite(in5,0);
    analogWrite(in6,right_sp);
    analogWrite(in9,0);
  }
  if(right_sp<0 && left_sp>0){
    analogWrite(in3,0);
    analogWrite(in5,left_sp);
    analogWrite(in6,0);
    analogWrite(in9,negright_sp);
  }
  if(right_sp<0 && left_sp<0){
    analogWrite(in3,negleft_sp);
    analogWrite(in5,0);
    analogWrite(in6,0);
    analogWrite(in9,negright_sp);
  }
}

void valuesread() {
  val = Serial.read();
  cnt++;
  v[cnt] = val;
  if (cnt == 2)
    cnt = 0;
}

void processing() {
  int a = v[1];
  if (a == 1) {
    fkp = v[2];
  }
  if (a == 2) {
    fkd = v[2];
  }
}