const int trigPin = 9;  
const int echoPin = 10; 
const int GREEN = 6;    
const int YELLOW = 5;   
const int RED = 3;      

const int trigPin1 = 7;   
const int echoPin1 = 8;   
const int GREEN1 = 11;    
const int RED1 = 13;      

void setup() {
  Serial.begin(9600);   
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);  
  pinMode(GREEN, OUTPUT);  
  pinMode(YELLOW, OUTPUT); 
  pinMode(RED, OUTPUT);    

  pinMode(trigPin1, OUTPUT);T
  pinMode(echoPin1, INPUT);  
  pinMode(GREEN1, OUTPUT);   
  pinMode(YELLOW1, OUTPUT);  
  pinMode(RED1, OUTPUT);   
}

void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2; 

  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  
  if (distance < 15 && distance > 5) {
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(RED, HIGH);
  } else if (distance >= 15 && distance < 30) {
    digitalWrite(GREEN, LOW);
    digitalWrite(YELLOW, HIGH);
    digitalWrite(RED, LOW);
  } else if (distance <= 5) {
    digitalWrite(RED, HIGH);
    delay(100);
    digitalWrite(RED, LOW);
    delay(100);
    digitalWrite(GREEN, LOW);
  } else {
    digitalWrite(GREEN, HIGH);
    digitalWrite(YELLOW, LOW);
    digitalWrite(RED, LOW);
  }

 
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

  
  duration = pulseIn(echoPin1, HIGH);
  distance = duration * 0.034 / 2; 

  
  Serial.print("Distance Sensor 2: ");
  Serial.print(distance);
  Serial.println(" cm");


  if (distance < 15 && distance > 5) {
    digitalWrite(YELLOW1, LOW);
    digitalWrite(GREEN1, LOW);
    digitalWrite(RED1, HIGH);
  } else if (distance >= 15 && distance < 30) {
    digitalWrite(GREEN1, LOW);
    digitalWrite(YELLOW1, HIGH);
    digitalWrite(RED1, LOW);
  } else if (distance <= 5) {
    digitalWrite(RED1, HIGH);
    delay(100);
    digitalWrite(RED1, LOW);
    delay(100);
    digitalWrite(GREEN1, LOW);
  } else {
    digitalWrite(GREEN1, HIGH);
    digitalWrite(YELLOW1, LOW);
    digitalWrite(RED1, LOW);
  }

  delay(500); 
}