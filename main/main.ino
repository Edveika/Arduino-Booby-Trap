class Sensor 
{
private:
  const int trig_pin;
  const int echo_pin;

public:
  Sensor() {}
  Sensor(const int trig_pin, const int echo_pin) 
  {
    this->trig_pin = trig_pin;
    this->echo_pin = echo_pin;
    pinMode(trigPin, OUTPUT);  
    pinMode(echoPin, INPUT);  
  }
};

const int trigPin = 10;  
const int echoPin = 9; 
const float lethalDistance = 500.0;

float duration, distance;  
bool bExploded = false;

void playUltraSound();
void calcDistance();

void setup() {  
  pinMode(ledPin, OUTPUT);  
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
