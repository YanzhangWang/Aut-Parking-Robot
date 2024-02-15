#define speedPinR 5    // RIGHT PWM pin connect MODEL-X ENA
#define RightMotorDirPin1  7    //Right Motor direction pin 1 to MODEL-X IN1 
#define RightMotorDirPin2  8    //Right Motor direction pin 2 to MODEL-X IN2
#define speedPinL 6    // Left PWM pin connect MODEL-X ENB
#define LeftMotorDirPin1  9    //Left Motor direction pin 1 to MODEL-X IN3 
#define LeftMotorDirPin2  10   //Left Motor direction pin 1 to MODEL-X IN4 
#define Echo_PIN    2   // Ultrasonic Echo pin connect to D2
#define Trig_PIN    3   // Ultrasonic Trig pin connect to D3

// Line Following Sensor Pins
#define LFSensor_0 A0
#define LFSensor_1 A1
#define LFSensor_2 A2
#define LFSensor_3 A3
#define LFSensor_4 A4

#define FAST_SPEED 40
#define MID_SPEED 20
#define SLOW_SPEED  10

unsigned long timeOver25mmStart = 0; // Track when distance first exceeds 25mm
boolean isOver25mm = false; // Flag to start tracking when distance is over 25mm

// Function prototypes
float measureDistance();
void go_Advance(void);
void go_Left(int t=0);
void go_Right(int t=0);
void go_Back(int t=0);
void stop_Stop(void);
void set_Motorspeed(int speed_L,int speed_R);
String read_sensor_values();
void auto_tracking();

void setup() {
  pinMode(RightMotorDirPin1, OUTPUT); 
  pinMode(RightMotorDirPin2, OUTPUT); 
  pinMode(speedPinL, OUTPUT);  
  pinMode(LeftMotorDirPin1, OUTPUT);
  pinMode(LeftMotorDirPin2, OUTPUT); 
  pinMode(speedPinR, OUTPUT);
  stop_Stop(); // Stop movement  
  pinMode(Trig_PIN, OUTPUT);
  pinMode(Echo_PIN, INPUT);
  Serial.begin(9600); // Initialize serial for debugging
}

void loop() {
  float currentDistance = measureDistance(); // Get current distance
  if (currentDistance > 25) {
    if (!isOver25mm) { // If this is the first time exceeding 25mm
      isOver25mm = true;
      timeOver25mmStart = millis(); // Start timing
    } else if (millis() - timeOver25mmStart > 1500) { // If it has been over 1.5 seconds
      go_Right(1500); // Execute a right turn, adjust the duration as needed
      isOver25mm = false; // Reset condition to avoid continuous turning
    }
  } else {
    isOver25mm = false; // If distance does not exceed 25mm, reset condition
  }

  auto_tracking(); // Continue with the original tracking logic
}

// Measure distance using ultrasonic sensor
float measureDistance() {
  digitalWrite(Trig_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig_PIN, LOW);
  return pulseIn(Echo_PIN, HIGH) * 0.034 / 2;
}

// Original motor control functions...
void go_Advance(void) {
  // Implementation remains the same
}

void go_Left(int t=0) {
  // Implementation remains the same
}

void go_Right(int t=0) {
  // Implementation remains the same
}

void go_Back(int t=0) {
  // Implementation remains the same
}

void stop_Stop() {
  // Implementation remains the same
}

void set_Motorspeed(int speed_L,int speed_R) {
  // Implementation remains the same
}

String read_sensor_values() {
  // Implementation remains the same
}

void auto_tracking() {
  // Implementation remains the same
}
