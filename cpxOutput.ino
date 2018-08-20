#include <Adafruit_CircuitPlayground.h>

const int THRESHOLD = 110;
int brightness;
int cpxPin = A3;

void setup() {
  // put your setup code here, to run once:
  CircuitPlayground.begin();
  
  Serial.begin(9600);
  delay(2000);
  Serial.println("Starting the light sensor demo...");
  
  pinMode(cpxPin, OUTPUT); //sets the digital pin 3 as output
}

void loop() {
  // put your main code here, to run repeatedly:
  brightness = CircuitPlayground.lightSensor();

  //to detect light at a distance of 2 ft
  if(brightness >= THRESHOLD){
    digitalWrite(cpxPin, HIGH);
  }
  else{
    digitalWrite(cpxPin, LOW);
  }
  Serial.print("Brightness is : ");
  Serial.println(brightness);
}
