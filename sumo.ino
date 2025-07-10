int trigPin=10;   //create variable of type int called trigPin 
int echoPin=9;   //create variable of type int called echoPin
int distance ;
long duration;   // create variable of type long called duration

const int IN1=4;
const int IN2=5;
const int IN3=6;
const int IN4=7;
const int ENA=3;
const int ENB=11;


#define IR_sensor_front A0 // front sensor
#define IR_sensor_back A1 // rear senson
int IR_front;
int IR_back;


void setup() 
{
  pinMode (trigPin, OUTPUT);  // trigPin its mode is output to send waves 
  pinMode (echoPin, INPUT);   // echoPin its mode is input to receive waves 
  Serial.begin(9600);
  delay (5000); // as per sumo compat roles
  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);
}
void loop()
{
   analogWrite(ENA, 255);
  analogWrite(ENB, 255); 
 
 
 IR_front = analogRead(IR_sensor_front);

 //Serial.println(IR_front);
 //Serial.println("first");
 
 
  IR_back = analogRead(IR_sensor_back);
//Serial.println(IR_back);
  
  
  digitalWrite (trigPin,LOW);  //no volt is connected to the trigPin 
  delayMicroseconds (2);  //wait 2 microseconds
  digitalWrite (trigPin, HIGH); //trigPin starting to send waves
  delayMicroseconds (10);   //wait 10 microseconds
  digitalWrite (trigPin, LOW);  //no volt is connected to the trigPin 
  duration = pulseIn (echoPin, HIGH);  //get the duraction took by the wave to reach the echo pin
  distance = duration/58   ;
 //Serial.println(distance);
 
 
 
 ROTATE(150); // start rotete 0 255
 
 if (distance < 6){
    Stop(0);
    
    while (distance < 6 ) {
        if (IR_front > 650 )  // > 650 means black line
   {
    //Serial.println(IR_front);
 //Serial.println("inloop1");
   Stop(0);
   delay (50);
   BACKWARD(150);

 
   delay (500);
   break;
   } 
   
         if (IR_back > 650 )  // < 650 means white line
   {
   Stop(0);
   delay (50);
   FORWARD(255);
   delay (150);
   break;
   } 
  
   FORWARD(255); 
    digitalWrite (trigPin,LOW);  //no volt is connected to the trigPin 
  delayMicroseconds (2);  //wait 2 microseconds
  digitalWrite (trigPin, HIGH); //trigPin starting to send waves
  delayMicroseconds (10);   //wait 10 microseconds
  digitalWrite (trigPin, LOW);  //no volt is connected to the trigPin 
  duration = pulseIn (echoPin, HIGH);  //get the duraction took by the wave to reach the echo pin
  distance = duration/58   ;
    IR_front = analogRead(IR_sensor_front);
    IR_back = analogRead(IR_sensor_back);
  // Serial.println(IR_front);
 //Serial.println("inloop");
    delay(10); 
  }//end of while loop
 }
  
 if (IR_front > 650 )  // < 650 means black line
   {
   Stop(0);
   delay (50);
  //Serial.println(IR_front);
 //Serial.println("last");
   BACKWARD(150);
   delay (500);
   } 
   
if (IR_back > 650 )  //
   {
   Stop(0);
   delay (50);
   FORWARD(255);
   delay (500);
   }
   


 
}//--------------------------------------------
void FORWARD (int speed){
  //When we want to let Motor To move forward,
  // just void this part on the loop section .
  analogWrite(IN1,speed);
  analogWrite(IN2,0);
  analogWrite(IN3,speed);
  analogWrite(IN4,0);
}//--------------------------------------------
void BACKWARD (int speed){
  //When we want to let Motor To move forward,
  // just void this part on the loop section .
  analogWrite(IN1,0);
  analogWrite(IN2,speed);
  analogWrite(IN3,0);
  analogWrite(IN4,speed);
}//--------------------------------------------
void ROTATE (int speed)
{
  //When we want to let Motor To Rotate ,
  // just void this part on the loop section .
  analogWrite(IN1,speed);
  analogWrite(IN2,0);
  analogWrite(IN3,0);
  analogWrite(IN4,speed);
}//--------------------------------------------
void Stop(int speed){
  //When we want to  Motor To stop ,
  // just void this part on the loop section .
  analogWrite(IN1,0);
  analogWrite(IN2,0);
  analogWrite(IN3,0);
  analogWrite(IN4,0);
}
