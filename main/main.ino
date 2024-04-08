class Sensor 
{
private:
  int trig_pin;
  int echo_pin;
  float duration;
  float distance;

public:
  Sensor() {}
  Sensor(const int trig_pin, const int echo_pin) 
  {
    this->trig_pin = trig_pin;
    this->echo_pin = echo_pin;
    pinMode(trig_pin, OUTPUT);  
    pinMode(echo_pin, INPUT);  
  }
  
  float get_distance()
  {
    return distance;
  }
  void play_sound()
  {
    digitalWrite(trig_pin, LOW);  
    delayMicroseconds(2);  
    digitalWrite(trig_pin, HIGH);  
    delayMicroseconds(10);  
    digitalWrite(trig_pin, LOW); 
  }
  void calc_distance() 
  {
    duration = pulseIn(echo_pin, HIGH);  
    distance = (duration*.0343)/2;  
  }
  void run()
  {
    play_sound();
    calc_distance();
  }
};

class BoobyTrap
{
private:
  Sensor* sensor;

public:
  BoobyTrap() {}
  BoobyTrap(Sensor* sensor) 
  {
    this->sensor = sensor;
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
  /*if (distance <= lethalDistance && distance > 0 && !bExploded)
  {
    bExploded = true;
    digitalWrite(ledPin, HIGH);
  }*/
}
