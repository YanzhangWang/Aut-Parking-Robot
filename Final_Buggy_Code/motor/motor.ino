const byte ENA=6;
const byte ENB=7;
const byte IN1=5;
const byte IN2=2;
const byte IN3=3;
const byte IN4=4;

int MAspeed = 00;
int MBspeed = 00;

void MAclock(){
  analogWrite(ENA, MAspeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

void MAanticlock(){
  analogWrite(ENA, MAspeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void MBclock(){
  analogWrite(ENB, MBspeed);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}


void MBanticlock(){
  analogWrite(ENB, MBspeed);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void forward(){
  MBclock();
  MAanticlock();
}

void backward(){
  MAclock();
  MBanticlock();
}


void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  forward();
}
