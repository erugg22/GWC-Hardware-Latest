//additional edits by elizabeth
#include <Servo.h>

//------------------------Declared Variables-------------------
Servo servo0;
Servo servo1;
Servo servo2;
Servo servo3;

const int delayTime = 500;
int pos = 0;

int sensor0Pin = 3;
int sensor1Pin = 4;
int sensor2Pin = 5;
int sensor3Pin = 6;

int degree0 = 0;
int degree1 = 270;
int degree2 = 180;
int degree3 = 90;

int sensor0firefound;
int sensor1firefound;
int sensor2firefound;
int sensor3firefound;

int numDetection = 0;

int thetaFinal;
int x1final;
int y1final;
int phiFinal;
int x2final;
int y2final;
int xAnsFinal;
int yAnsFinal;


void rotatingLimit(){
   if (degree0 == 90){
    Serial.print("done");
    while (1 == 1){
      
    }
  }
}
//------------------------Sol's ACTUAL Code---------------------


void getCoord(int x1, int y1, int x2, int y2, float theta, float phi, float xAns, float yAns) {
  theta = theta * 3.14159 / 180;
  phi = phi * 3.14159 / 180;
  float slope1 = tan(theta);
  float slope2 = tan(phi);
  
  int C = (y1 - y2);
  int B = (slope2 * x2) - (slope1 * x1);
  xAns = (C + B) / (slope2 - slope1); 
  yAns = slope1 * (xAns - x1) + y1;
}

 
//----------------------Sol's Variables & Parameters-------------

void mathInput(int degree, int xcoor, int ycoor){
  if (numDetection == 1){
    degree = thetaFinal;
    xcoor = x1final;
    ycoor = y1final;
  }
  if (numDetection == 2){
    degree = phiFinal;
    xcoor = x2final;
    ycoor = y2final;
  }
}

//------------------------Ami's STUB Function-------------------
void setservo0(int degree) {
  servo0.write(degree);
}

int setservo1(int degree) {
  int theDegrees = degree - 270;
  servo1.write(theDegrees);
}

int setservo2(int degree) {
  int theDegrees = degree -180;
  servo2.write(theDegrees);
}

int setservo3(int degree) {
  int theDegrees = degree - 90;
  servo3.write(theDegrees);
}

//--------------------------------------------------------------


void setup() {
  Serial.begin(9600);
  pinMode(sensor0Pin, INPUT);
  pinMode(sensor1Pin, INPUT);
  pinMode(sensor2Pin, INPUT);
  pinMode(sensor3Pin, INPUT);
  servo0.attach(8);
  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(11);
}

//--------------------Elizabeth's STUB Function-------------------
int getsensordata0(int pin) {
  digitalRead(pin);
  if(digitalRead(pin) == HIGH){
    return(1);
  }
  else if(digitalRead(pin) == LOW){
    return(0);
  }
}

int getsensordata1(int pin) {
  digitalRead(pin);
  if(digitalRead(pin) == HIGH){
    return(1);
  }
  else if(digitalRead(pin) == LOW){
    return(0);
  }
}

int getsensordata2(int pin) {
  digitalRead(pin);
  if(digitalRead(pin) == HIGH){
    return(1);
  }
  else if(digitalRead(pin) == LOW){
    return(0);
  }
}

int getsensordata3(int pin) {
  digitalRead(pin);
  if(digitalRead(pin) == HIGH){
    return(1);
  }
  else if(digitalRead(pin) == LOW){
    return(0);
  }
}

//-----------------------------------------------------------------

void detectionLimit(){
    if (numDetection > 2){
    numDetection = 2;
  }
}

//------------------------Aida's Main Loop Function----------------
void loop() {

  rotatingLimit();
  
  setservo0(degree0);
  sensor0firefound = getsensordata0(sensor0Pin);
  Serial.print("servo 0  ");
  Serial.print(degree0  );
  Serial.print("  ");
  Serial.println(sensor0firefound  );
  if (sensor0firefound == 1){
    numDetection++;
    servo0.detach();
  }
  detectionLimit();
  mathInput(degree0, 0, 0);
  

  setservo1(degree1);
  sensor1firefound = getsensordata1(sensor1Pin);
  Serial.print("servo 1  ");
  Serial.print(degree1  );
  Serial.print("  ");
  Serial.println(sensor1firefound  );
  if (sensor1firefound == 1){
    numDetection++;
    servo1.detach();
  }
  detectionLimit();
  mathInput(degree1, 0, 20);
  

  setservo2(degree2);
  sensor2firefound = getsensordata2(sensor2Pin);
  Serial.print("servo 2  ");
  Serial.print(degree2  );
  Serial.print("  ");
  Serial.println(sensor2firefound  );
  if (sensor2firefound == 1){
    numDetection++;
    servo2.detach();
  }
  detectionLimit();
  mathInput(degree2, 40, 20);


  setservo3(degree3);
  sensor3firefound = getsensordata3(sensor3Pin);
  Serial.print("servo 3  ");
  Serial.print(degree3  );
  Serial.print("  ");
  Serial.println(sensor3firefound);
  if (sensor3firefound == 1){
    numDetection++;
    servo3.detach();
  }
  detectionLimit();
  mathInput(degree3, 40, 0);

  
  Serial.println("=====");

  degree0 = degree0 + 1;
  degree1 = degree1 + 1;
  degree2 = degree2 + 1;
  degree3 = degree3 + 1;
  

  if (numDetection == 2){
    getCoord(x1final, y1final, x2final, y2final, thetaFinal, phiFinal, xAnsFinal, yAnsFinal);
    Serial.print(xAnsFinal);
    Serial.print(", ");
    Serial.print(yAnsFinal);
  }

    delay(delayTime);

}


