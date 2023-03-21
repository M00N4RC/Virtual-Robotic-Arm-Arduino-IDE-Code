/* 2022, Dr. Martin Koch
//This program sends joint position angles (in degrees) via serial com
//as a demo for connecting ROBOTARM_GAME_V4

Final Project
By Ben & Clara

This code utilizes the pre-existing project of the robotic arm in which we were required to alter the exisiting code by creating our own form
of remote in order to contorl the movements and functions of the different setions on the virtual robotic arm via 'Arduino' & 'Processing'.

This project utilizes;
-Buttons with a simple push and hold (debouncing) process
-Joystick to control a speific section of the Virtual robotic arm
-Analog Input
-Digital Input
-Serial Communication

*/

// Define angle variables

float j0_angle = 0;  // the angle we are going to send
float j1_angle = 0;
float j2_angle = 0;
float j3_angle = 0;
float j4_angle = 0;

int SW = 1; //the directions for the joystick (y & x Axis)
int VRx = A0;
int VRy = A1;

int button1 = 2; //declaring the button variables
int button2 = 3;
int button3 = 4;
int button4 = 5;
int button5 = 6;
int button6 = 7;
int button7 = 8;
int button8 = 9;


// Define angle limits
float minrot0 = -360, maxrot0 = 360;
float minrot1 = 30, maxrot1 = 90;
float minrot2 = -120, maxrot2 = -60;
float minrot3 = -360, maxrot3 = 360;
float minrot4 = -60, maxrot4 = 60;

void setup() {
  Serial.begin(115200);  // activate Serial Communication
  
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT);

  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(button5, INPUT);
  pinMode(button6, INPUT);
  pinMode(button7, INPUT);
  pinMode(button8, INPUT);
}

void loop() {
// Joystick, buttons Q(far-right joystick) + A(far-left joystick) to ROTATE base/section 1 of arm
  if(analogRead(VRy) == 1023) { //VRy is the Y-axis of joystick, far right of the joystick is 1023
  j0_angle += 25; //move the robot arm 8 degrees incrementally everytime 1023 (far right joystick) is reached 
  } else {
  if(analogRead(VRy) == 0) { //far left of the joystick is 0
  j0_angle -= 25; //move the robot arm 8 degrees the opposite way incrementally everytime 0 (far left joystick) is reached
  }
  }
    Serial.println("J0_" + String(j0_angle, 3));
    Serial.flush();  // wait for messages to be sent
    delay(50);     // wait for 5 seconds

///////////////////////////////////////

  if (digitalRead(button1) == LOW) {  //buttons W(button1) + S(button2) to control UP + DOWN for section 2 of arm
    j1_angle += 25; 
  } else {
  if (digitalRead(button2) == LOW) {
    j1_angle -= 25;
  }
  }
    Serial.println("J1_" + String(j1_angle, 3));
    Serial.flush();  // wait for messages to be sent
    delay(120);     // wait for 5 seconds

//////////////////////////////////////

  if (digitalRead(button3) == LOW) {  //buttons E(button3) + D(button4) to control UP + DOWN for section 3 of arm
    j2_angle += 25; 
  } else {
  if (digitalRead(button4) == LOW) {
    j2_angle -= 25;
  }
  }
    Serial.println("J2_" + String(j2_angle, 3));
    Serial.flush();  // wait for messages to be sent
    delay(120);     // wait for 5 seconds

//////////////////////////////////////

  if (digitalRead(button5) == LOW) {  //buttons R(button5) + F(button6) to ROTATE section 4 of arm
    j3_angle += 25;
  } else {
  if (digitalRead(button6) == LOW) {
    j3_angle -= 25;
  }
  }
    Serial.println("J3_" + String(j3_angle, 3));
    Serial.flush();  // wait for messages to be sent
    delay(120);     // wait for 5 seconds

//////////////////////////////////////

  if (digitalRead(button7) == LOW) {  //buttons T(button7) + G(button8) to control UP + DOWN for section 5 of arm
    j4_angle += 25; 
  } else {
  if (digitalRead(button8) == LOW) {
    j4_angle -= 25;
  }
  }
    Serial.println("J4_" + String(j4_angle, 3));
    Serial.flush();  // wait for messages to be sent
    delay(120);     // wait for 5 seconds
}