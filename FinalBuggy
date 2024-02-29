// Define all pin connections
#define speedPinR 6    //  RIGHT PWM pin connect MODEL-X ENA
#define RightMotorDirPin1  7    //Right Motor direction pin 1 to MODEL-X IN1 
#define RightMotorDirPin2  4    //Right Motor direction pin 2 to MODEL-X IN2
#define speedPinL 5    // Left PWM pin connect MODEL-X ENB
#define LeftMotorDirPin1  3    //Left Motor direction pin 1 to MODEL-X IN3 
#define LeftMotorDirPin2  2   //Left Motor direction pin 1 to MODEL-X IN4 
#define EchoPin    9   // Ultrasonic Echo pin connect to D2
#define TrigPin    8   // Ultrasonic Trig pin connect to D3

const int trct500Pin = A0; // 假设TRCT500连接到模拟输入A0


/*motor control*/
void go_Advance(void)  //Forward
{
  digitalWrite(RightMotorDirPin1, LOW);
  digitalWrite(RightMotorDirPin2,HIGH);
  digitalWrite(LeftMotorDirPin1,HIGH);
  digitalWrite(LeftMotorDirPin2,LOW);
  analogWrite(speedPinL,140);
  analogWrite(speedPinR,140);
}
void go_Left(int t=0)  //Turn left
{
  digitalWrite(RightMotorDirPin1,LOW );
  digitalWrite(RightMotorDirPin2,HIGH);
  digitalWrite(LeftMotorDirPin1,HIGH);
  digitalWrite(LeftMotorDirPin2,LOW);
  analogWrite(speedPinL,80);
  analogWrite(speedPinR,150);
  delay(t);
}
void go_Right(int t=0)  //Turn right
{
  digitalWrite(RightMotorDirPin1,LOW);
  digitalWrite(RightMotorDirPin2,HIGH);
  digitalWrite(LeftMotorDirPin1,HIGH);
  digitalWrite(LeftMotorDirPin2,LOW);
  analogWrite(speedPinL,150);
  analogWrite(speedPinR,80);
  delay(t);
}
void go_Back(int t=0)  //Reverse
{
  digitalWrite(RightMotorDirPin1,HIGH);
  digitalWrite(RightMotorDirPin2,LOW);
  digitalWrite(LeftMotorDirPin1,LOW);
  digitalWrite(LeftMotorDirPin2,HIGH);
  analogWrite(speedPinL,120);
  analogWrite(speedPinR,120);
  delay(t);
}
void stop_Stop()    //Stop
{
  digitalWrite(RightMotorDirPin1, LOW);
  digitalWrite(RightMotorDirPin2,LOW);
  digitalWrite(LeftMotorDirPin1,LOW);
  digitalWrite(LeftMotorDirPin2,LOW);
}

void go_Park(int t=0)
{
  digitalWrite(RightMotorDirPin1,LOW );
  digitalWrite(RightMotorDirPin2,HIGH);
  digitalWrite(LeftMotorDirPin1,HIGH);
  digitalWrite(LeftMotorDirPin2,LOW);
  analogWrite(speedPinL,0);
  analogWrite(speedPinR,150);
  delay(t);
}

void setup()
{
   
  pinMode(RightMotorDirPin1, OUTPUT); 
  pinMode(RightMotorDirPin2, OUTPUT); 
  pinMode(speedPinL, OUTPUT);  
 
  pinMode(LeftMotorDirPin1, OUTPUT);
  pinMode(LeftMotorDirPin2, OUTPUT); 
  pinMode(speedPinR, OUTPUT); 
  
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  pinMode(trct500Pin, INPUT);
  Serial.begin(9600);   // initialize serial for debugging

}


void loop()
{ 
  int data = analogRead(trct500Pin);

    // Ultrasonic Sensor
  digitalWrite(9, LOW);
  digitalWrite(TrigPin,LOW);        //Send level pulses to the Trigpin pins in low and high order
  delayMicroseconds(2);             //Delay time
  digitalWrite(TrigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin,LOW);
  double cm=pulseIn(EchoPin,HIGH)/58.0;    //Read the pulse width and convert it to centimeters
  Serial.print(cm);
    Serial.print("读取到的数据: ");
  Serial.println(data);
  // the lower the voltage, the brighter it is
if(cm<30){
    if (data >= 1000 ) {
    go_Left();
    Serial.print("go left");
  } else  {
    go_Right();
        Serial.print("go right");
  }
}
else{
  go_Park();
  delay(2000);
  stop_Stop;
  delay(1000000);
}

} //end of loop
