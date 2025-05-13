#include <AFMotor.h> // Motor shield library

#define MAX_SPEED 160
#define MAX_SPEED_OFFSET 40

// Define the motors using the Adafruit Motor Shield
AF_DCMotor leftMotor1(1, MOTOR12_1KHZ);
AF_DCMotor leftMotor2(2, MOTOR12_1KHZ);
AF_DCMotor rightMotor1(3, MOTOR34_1KHZ);
AF_DCMotor rightMotor2(4, MOTOR34_1KHZ);

String motorSet = "";  // To keep track of motor direction
char state;            // To store the received Bluetooth command
int speedSet = 0;      // Speed variable

void setup() {
  Serial.begin(9600);  // Start serial communication at 9600 baud
}

void loop() {
  // Check if there are any available commands from Bluetooth
  while (Serial.available() > 0) {
    state = Serial.read(); // Read the Bluetooth command
    Serial.println(state);  // Print the received command (optional for debugging)
  }

  //-------- MOVE FORWARD ---------
  if (state == 'f') {
    motorSet = "FORWARD";
    moveForward();
  }
  //-------- MOVE BACKWARD ---------
  else if (state == 'b') {
    motorSet = "BACKWARD";
    moveBackward();
  }
  //-------- TURN RIGHT ---------
  else if (state == 'r') {
    motorSet = "RIGHT";
    turnRight();
  }
  //-------- TURN LEFT ---------
  else if (state == 'l') {  // Changed '1' to 'l' for clarity
    motorSet = "LEFT";
    turnLeft();
  }
  //-------- STOP ---------
  else if (state == 's') {
    motorSet = "STOP";
    stopMotors();
  }
}

// Function to move the car forward
void moveForward() {
  leftMotor1.run(FORWARD);
  leftMotor2.run(FORWARD);
  rightMotor1.run(FORWARD);
  rightMotor2.run(FORWARD);

  for (speedSet = 0; speedSet < MAX_SPEED; speedSet += 2) {
    leftMotor1.setSpeed(speedSet);
    leftMotor2.setSpeed(speedSet);
    rightMotor1.setSpeed(speedSet);
    rightMotor2.setSpeed(speedSet);
    delay(5);  // Small delay to prevent overloading
  }
}

// Function to move the car backward
void moveBackward() {
  leftMotor1.run(BACKWARD);
  leftMotor2.run(BACKWARD);
  rightMotor1.run(BACKWARD);
  rightMotor2.run(BACKWARD);

  for (speedSet = 0; speedSet < MAX_SPEED; speedSet += 2) {
    leftMotor1.setSpeed(speedSet);
    leftMotor2.setSpeed(speedSet);
    rightMotor1.setSpeed(speedSet);
    rightMotor2.setSpeed(speedSet);
    delay(5);  // Small delay to prevent overloading
  }
}

// Function to turn the car right
void turnRight() {
  leftMotor1.run(FORWARD);
  leftMotor2.run(FORWARD);
  rightMotor1.run(BACKWARD);
  rightMotor2.run(BACKWARD);

  rightMotor1.setSpeed(speedSet + MAX_SPEED_OFFSET);
  rightMotor2.setSpeed(speedSet + MAX_SPEED_OFFSET);
  delay(1500);  // Turn for 1.5 seconds

  // Move forward after turning
  leftMotor1.run(FORWARD);
  leftMotor2.run(FORWARD);
  rightMotor1.run(FORWARD);
  rightMotor2.run(FORWARD);
}

// Function to turn the car left
void turnLeft() {
  leftMotor1.run(BACKWARD);
  leftMotor2.run(BACKWARD);
  rightMotor1.run(FORWARD);
  rightMotor2.run(FORWARD);

  leftMotor1.setSpeed(speedSet + MAX_SPEED_OFFSET);
  leftMotor2.setSpeed(speedSet + MAX_SPEED_OFFSET);
  delay(1500);  // Turn for 1.5 seconds

  // Move forward after turning
  leftMotor1.run(FORWARD);
  leftMotor2.run(FORWARD);
  rightMotor1.run(FORWARD);
  rightMotor2.run(FORWARD);
}

// Function to stop all motors
void stopMotors() {
  leftMotor1.run(RELEASE);
  leftMotor2.run(RELEASE);
  rightMotor1.run(RELEASE);
  rightMotor2.run(RELEASE);
}
