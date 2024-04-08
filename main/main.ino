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
  // Returns the distance from sensor to object in cm
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
  bool exploded;
  float cm_lethal_distance;
  
public:
  BoobyTrap() {}
  BoobyTrap(Sensor* sensor, float cm_lethal_distance) 
  {
    this->sensor = sensor;
    this->exploded = false;
    this->cm_lethal_distance = cm_lethal_distance;
  }
  ~BoobyTrap() { delete sensor; }

  void run()
  {
    sensor->run();
    
    if (sensor->get_distance() <= cm_lethal_distance && sensor->get_distance() > 0 && !exploded)
    {
      exploded = true;
    }
  }
};

Sensor* sensor;
BoobyTrap* trap;

void setup()
{  
  sensor = new Sensor(10, 9);
  trap = new BoobyTrap(sensor, 100.0f);
}  

void loop()
{ 

}
