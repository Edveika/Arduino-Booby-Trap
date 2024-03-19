const int trigPin = 10;  
const int echoPin = 9; 
const int btnPin = 2;
const float lethalDistance = 500.0;

float duration, distance;  
bool bExploded = false;

void playUltraSound();
void calcDistance();

void setup() {  
  pinMode(8, OUTPUT);  
  pinMode(trigPin, OUTPUT);  
  pinMode(echoPin, INPUT);  
  pinMode(btnPin, INPUT);
  digitalWrite(8, LOW);
  Serial.begin(9600);
}  

void loop() { 
  playUltraSound();
  calcDistance();
 
  if (distance <= lethalDistance && distance > 0 && !bExploded)
  {
    bExploded = true;
    Serial.print("Good luck in the after-life, BITCH");
    digitalWrite(8, HIGH);
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
