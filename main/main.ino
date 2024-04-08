class Sensor 
{
private:
  const int trig_pin;
  const int echo_pin;
  float duration;
  float distance;

public:
  Sensor() {}
  Sensor(const int trig_pin, const int echo_pin) 
  {
    this->trig_pin = trig_pin;
    this->echo_pin = echo_pin;
    pinMode(trigPin, OUTPUT);  
    pinMode(echoPin, INPUT);  
  }
  
  float get_distance()
  {
    return distance;
  }
  void play_sound()
  {
    digitalWrite(trigPin, LOW);  
    delayMicroseconds(2);  
    digitalWrite(trigPin, HIGH);  
    delayMicroseconds(10);  
    digitalWrite(trigPin, LOW); 
  }
  void calc_distance() 
  {
    duration = pulseIn(echoPin, HIGH);  
    distance = (duration*.0343)/2;  
  }
  void run()
  {
    play_sound();
    calc_distance();
  }
};

const int trigPin = 10;  
const int echoPin = 9; 
const float lethalDistance = 500.0;

bool bExploded = false;

void setup()
{  
  
}  

void loop()
{ 
  if (distance <= lethalDistance && distance > 0 && !bExploded)
  {
    bExploded = true;
    digitalWrite(ledPin, HIGH);
  }
}
