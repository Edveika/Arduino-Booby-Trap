const int trigPin = 10;  
const int echoPin = 9; 
const int btnPin = 2;
const float lethalDistance = 200.0;

float duration, distance;  
bool bExploded = false;

void playUltraSound();
void calcDistance();

void setup() {  
  pinMode(trigPin, OUTPUT);  
  pinMode(echoPin, INPUT);  
  pinMode(btnPin, INPUT);
}  

void loop() {   
  playUltraSound();
  calcDistance();

  if (distance <= lethalDistance && !bExploded)
  {
    bExploded = true;
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
