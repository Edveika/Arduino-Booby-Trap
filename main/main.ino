class LED {
private:
  int led_pin;

public:
  LED(const int pin) 
  {
    led_pin = pin;
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  }

  void turn_on() { digitalWrite(led_pin, HIGH); }
  void turn_off() { digitalWrite(led_pin, LOW); }
};

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
  float cm_cur_distance;
  float cm_lethal_distance;
  LED* led;
  
public:
  BoobyTrap() {}
  BoobyTrap(Sensor* sensor, const int led_pin, float cm_lethal_distance) 
  {
    this->sensor = sensor;
    this->exploded = false;
    this->cm_lethal_distance = cm_lethal_distance;
    this->led = new LED(led_pin);
    this->cm_cur_distance = get_cur_distance();
    pinMode(6, OUTPUT);
  }
  ~BoobyTrap() { delete sensor; }

  float get_cur_distance()
  {
    float cur_distance = 0.0f;

    for (int i = 0; i < 10; ++i)
    {
      sensor->run();
      cur_distance += sensor->get_distance();
    }

    return cur_distance / 10.0f;
  }
  void run()
  {
    if (!sensor)
      return;

    if (exploded)
      return;
    
    sensor->run();
    if (abs(cm_cur_distance - sensor->get_distance()) >= cm_lethal_distance && sensor->get_distance() > 0)
    {
      led->turn_on();
      digitalWrite(6, LOW);
      exploded = true;
    }
  }
};

Sensor* sensor;
BoobyTrap* trap;

void setup()
{  
  sensor = new Sensor(3, 2);
  trap = new BoobyTrap(sensor, 4, 10.0f);
}  

void loop()
{ 
  if (trap)
    trap->run();
}
