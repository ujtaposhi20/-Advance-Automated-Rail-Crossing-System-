#include <Servo.h>

Servo myservo;

int trigPin1 = 10;  // Ultrasonic sensor trigger pin

int echoPin1 = 12;  // Ultrasonic sensor echo pin
// int trigPin2 = 2;  // Ultrasonic sensor trigger pin

// int echoPin2 = 3;

int IRSensor = 8; // warning

int IRSensor1 = 9; // gate

int LED_R = 2; // warning

int LED_G = 5; // green

int buz=6 ;// warning

int servoPin=7; // servo pin 

void setup(){

  Serial.begin(115200); // Init Serial at 115200 Baud Rate.

  Serial.println("Serial Working"); // Test to check if serial is working or not

  pinMode(trigPin1, OUTPUT);

  pinMode(echoPin1, INPUT);
  // pinMode(trigPin2, OUTPUT);

  // pinMode(echoPin2, INPUT);

  pinMode(IRSensor, INPUT);

  pinMode(IRSensor1, INPUT); 

  pinMode(LED_R, OUTPUT);

  pinMode(LED_G, OUTPUT);

  pinMode(buz,OUTPUT);

  myservo.attach(servoPin);

}


void loop(){

//IR1 warning
  digitalWrite(LED_G, HIGH);
  int sense=digitalRead(IRSensor);

  if (sense == 1) {

    digitalWrite(buz,LOW);
    digitalWrite(LED_R, LOW);



  }

  else{

     // Turn on the LED

     digitalWrite(LED_R, HIGH);

     digitalWrite(LED_G, LOW);


     // Clear the trigger pin

     digitalWrite(trigPin1, LOW);

     delayMicroseconds(2);


  // Send a 10us pulse to the trigger pin

    digitalWrite(trigPin1, HIGH);

    delayMicroseconds(10);

    digitalWrite(trigPin1, LOW);


  // Measure the duration of the pulse on the echo pin

    unsigned long duration1 = pulseIn(echoPin1, HIGH);


  // Calculate the distance in centimeters

     float distance1 = (duration1 * 0.0343) / 2;


     Serial.print("Distance: ");

     Serial.print(distance1);

     Serial.println(" cm");


  // Set a distance threshold for object detection

  float threshold = 20; // Adjust this value as needed


  // Check if an object is within the threshold distance

  if (distance1 <= threshold) {

    digitalWrite(buz,HIGH);

    tone(buz, 1000, 1000);

  } else {

     digitalWrite(buz,LOW);

  }


  delay(100); // Delay for stability


   }


//lathi uthabe namabe

  int sensorStatus = digitalRead(IRSensor1); // Set the GPIO as Input

  if (sensorStatus == 1) {
    

    myservo.write(180);

    Serial.println(" No Motion Detected!");

    delay(15);// print Motion Detected!

 

  }

  else  {

   

    digitalWrite(LED_R, HIGH);
    digitalWrite(LED_G, LOW);
    myservo.write(90);
   delay(5000);
    Serial.println("left ir Motion Detected!");



  
    }


  delay(200);

}