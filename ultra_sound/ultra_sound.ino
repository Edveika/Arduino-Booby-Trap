const int trigPin = 10;  
const int echoPin = 9; 
const int btnPin = 2;

float duration, distance;  

void setup() {  
  pinMode(trigPin, OUTPUT);  
  pinMode(echoPin, INPUT);  
  pinMode(btnPin, INPUT);
  Serial.begin(9600);  
}  

void loop() {  
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2);  
  digitalWrite(trigPin, HIGH);  
  delayMicroseconds(10);  
  digitalWrite(trigPin, LOW);  
  duration = pulseIn(echoPin, HIGH);  
  distance = (duration*.0343)/2;  
  Serial.print("Distance: ");  
  Serial.println(distance);  

   int buttonState = LOW;
   buttonState = digitalRead(btnPin);
    if (buttonState == HIGH)
    {
        Serial.print("fu2 "); 
    }
  delay(100);  

}
