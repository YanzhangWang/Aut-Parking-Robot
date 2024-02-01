const int TrigPin=6;           //Set pin 6 as the launching pin position
const int EchoPin=7;           //Set pin 7 as the receiving pin position
float cm;                 

void setup() {
Serial.begin(9600);
pinMode(TrigPin,OUTPUT);
pinMode(EchoPin,INPUT);
}

void loop() {
digitalWrite(7, LOW);


digitalWrite(TrigPin,LOW);        //Send level pulses to the Trigpin pins in low and high order
delayMicroseconds(2);             //Delay time
digitalWrite(TrigPin,HIGH);
delayMicroseconds(10);
digitalWrite(TrigPin,LOW);
cm=pulseIn(EchoPin,HIGH)/58.0;    //Read the pulse width and convert it to centimeters
Serial.print(cm);
if(cm<=40.0){
  digitalWrite(7, HIGH);
}
Serial.println(); 

delay(1000);
}



