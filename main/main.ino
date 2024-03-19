const int trigPin = 10;  
const int echoPin = 9; 
const int btnPin = 2;
const int ledPin = 8;
const float lethalDistance = 500.0;

float duration, distance;  
bool bExploded = false;

void playUltraSound();
void calcDistance();

void setup() {  
  pinMode(ledPin, OUTPUT);  
  pinMode(trigPin, OUTPUT);  
  pinMode(echoPin, INPUT);  
  pinMode(btnPin, INPUT);
  
  digitalWrite(ledPin, LOW);
}  

void loop() { 
  playUltraSound();
  calcDistance();
 
  if (distance <= lethalDistance && distance > 0 && !bExploded)
  {
    bExploded = true;
    digitalWrite(ledPin, HIGH);
  }
}

void playUltraSound() {
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2);  
  digitalWrite(trigPin, HIGH);  
  delayMicroseconds(10);  
  digitalWrite(trigPin, LOW); 
}
void calcDistance() {
  duration = pulseIn(echoPin, HIGH);  
  distance = (duration*.0343)/2;  
}
