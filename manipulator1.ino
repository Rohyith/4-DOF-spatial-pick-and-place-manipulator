#include "thingProperties.h"
//#include <ESP8266WiFi.h>
//#include <ESP8266WebServer.h>
//#include <ArduinoOTA.h>
#include <Servo.h>
#define IN_1  16
#define IN_2  5
#define IN_3  4
#define IN_4  0
#define IN_5  3
Servo servo1; // Create a Servo object for servo 1
Servo servo2; 
Servo servo3;
Servo servo4;
Servo servo5;

void setup() {
  Serial.begin(9600);
  delay(1500);
  servo1.attach(IN_1); // Attach servo 1 to pin D2
  servo2.attach(IN_2); // Attach servo 2 to pin D3
  servo3.attach(IN_3);
  servo4.attach(IN_4);
  servo5.attach(IN_5);

  // Defined in thingProperties.h
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);


  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  
}
void onJoint1Change()  {
  Serial.println(joint1);
  servo1.write(joint1);
}


void onJoint2Change()  {
  Serial.println(joint2);
  servo2.write(joint2);
}

void onJoint3Change()  {

  Serial.println(joint3);
  servo3.write(joint3);
}
void onJoint4Change()  {
  Serial.println(joint4);
  servo4.write(joint4);
}
void onJoint5Change()  {
  Serial.println(joint5);
  servo5.write(joint5);
}
