int trigPin = 15;    // Trigger
int echoPin = 14;    // Echo
long duration, cm, inches;

int trigPin2 = 17;    // Trigger
int echoPin2 = 16;    // Echo
long duration2, cm2, inches2;

void setup() {
  //Serial Port begin
  Serial.begin (115200);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
}
 
void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  // cm = (duration/2) / 29.1;     
  inches = (duration/2) / 74;  
  






  digitalWrite(trigPin2, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
 

  pinMode(echoPin2, INPUT);
  duration2 = pulseIn(echoPin2, HIGH);

  // cm2 = (duration2/2) / 29.1;     
  inches2 = (duration2/2) / 74;  






  Serial.print(inches);
  // Serial.print("in, ");
  // Serial.print(cm);
  // Serial.print("cm | ");

  Serial.print(" ");

  Serial.print(inches2);
  // Serial.print("in, ");
  // Serial.print(cm2);
  // Serial.print("cm");
  
  Serial.println();
  
  delay(5);
}