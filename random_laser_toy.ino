// this code was made by Mark Summers on 13/3/2020 at rubberDucky labs Australia.
//this code is provided as is and is free to modify. rubberDucky labs takes responsablity for miss use of this code. 
// include servo library
#include <Servo.h>

 // Define Variable for Servo position
int pos = 90; 
// Define Variable for delay to save time if you want to changing it
int Delay=400; 
// needed for the random number generator
long randNumber;
// name this what ever you want i just went with blue
boolean blue = true;
//initialize servo pins
const int SERVO_PIN1 = 9; //pan
const int SERVO_PIN2 = 10; //tilt

//create servo objects
Servo myservo1; 
Servo myservo2; 
void setup() {
  
     
  randomSeed(analogRead(0));//start random number generator
 
  //attach servo to initialize pins
  myservo1.attach(SERVO_PIN1); 
  
  myservo2.attach(SERVO_PIN2);

  Serial.begin(9600);

}
void loop() {


do{
randNumber = random(15, 61);
  Serial.println(randNumber);
  delay(Delay);
  Serial.read();
                   while (myservo2.read() <= randNumber) {
                           myservo2.write(pos++);
                           delay(Delay);}
                   while ( myservo2.read() >= randNumber) {
                            myservo2.write(pos--);
                            delay(Delay);  }     
  randNumber = random(15, 61);
  Serial.println(randNumber);
  delay(25);
  Serial.read();
                   while (myservo1.read() <= randNumber) {
                           myservo1.write(pos++);
                           delay(Delay);}
                   while ( myservo1.read() >= randNumber) {
                            myservo1.write(pos--);
                            delay(Delay); } 
         
}while ( blue == true)  ;
}
