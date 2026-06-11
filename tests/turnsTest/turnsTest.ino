#include "src.ino"
#include "motors.h"
#include "main2alt.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Starting");
  setupMotors();
  setupMain2();
  startMain2();
}

void loop(){
  delay(1000);
  turnLeft();
  delay(1000);
  turnRight();
  delay(1000);
  forward(0,0);
}
