// Motor A connections
int enA = 9;
int in1 = 7;
int in2 = 8;
// Motor B connections
int enB = 3;
int in3 = 4;
int in4 = 5;

int fast = 200;
int slow = 100;

unsigned long previous_time = 0;  // store previous timestamp
unsigned long current_time = 0;   // store current timestamp
unsigned long time_elapsed = 0;

//ultrasound sensor
// include newping library
#include "NewPing.h"
// define trigger and echo pins
#define TRIG_PIN 12
#define ECHO_PIN 13
// max distance to ping for (cm)
#define MAX_DISTANCE 50
int distance = 0;
// set up newping object 
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);
bool detected = 0;

void setup() {
	// Set all the motor control pins to outputs
	pinMode(enA, OUTPUT);
	pinMode(enB, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);
	
	// Turn off motors - Initial state
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);

  // for debugging
  Serial.begin(9600);
  // Serial.println("test"); to print data

  previous_time = millis();
  delay(1000);

}//setup

void forward() {
  //Motor speed
  analogWrite(enA, fast);
  analogWrite(enB, fast); 
  //eng 1
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  //eng 2
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}//forward

void back() {
  //Motor speed
  analogWrite(enA, slow);
  analogWrite(enB, slow); 
  //eng 1
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  //eng 2
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}//back

void right() {
  //Motor speed
  analogWrite(enA, slow);
  analogWrite(enB, slow); 
  //eng 1
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  //eng 2
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}//right

void left() {
  //Motor speed
  analogWrite(enA, slow);
  analogWrite(enB, slow); 
  //eng 1
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  //eng 2
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}//forward

void stop() {
  //Motor speed
  analogWrite(enA, slow);
  analogWrite(enB, slow); 
  //eng 1
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  //eng 2
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}//stop

int sight() {
  distance = sonar.ping_cm();
/*   Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(500); */

  if (distance == 0){
    detected = 0;
  }else{
    detected = 1;
  }

  return detected;
  // 1 means it detects object 
} //sight

void loop() {
  //utrasound
  detected = sight();

  //set current time 
  current_time = millis();
  time_elapsed = current_time - previous_time;

  //start
  if (detected == 0) {
    left();
  }
  else {
    forward();
    delay(250);

  }

  delay(15);

}//loop



