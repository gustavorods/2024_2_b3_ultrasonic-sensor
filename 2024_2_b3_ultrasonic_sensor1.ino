// C++ code

// Led's array 
int leds[3] = {13,12,11};

// buzzer
const int buzzerPin = 8;

const int tom1 = 262; 
const int tom2 = 330; 
const int tom3 = 392; 
 
// ultrasonic sensor (us)
int echoPin = 5;
int trigPin = 6;

void setup()
{
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  for(int p : leds) {
  	pinMode(p, OUTPUT);
  }
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  int duration = pulseIn(echoPin, HIGH);
  
  int distance = (duration/2) / 29.1;
  
  Serial.println(distance);
  
  if(distance <= 50) {
    digitalWrite(leds[0], HIGH);
	digitalWrite(leds[1], LOW);
    digitalWrite(leds[2], LOW);
   	tone(buzzerPin, tom1);
  } 
  else if(distance > 50 and distance <= 150) {
  	digitalWrite(leds[0], LOW);
	digitalWrite(leds[1], HIGH);
    digitalWrite(leds[2], LOW);
   	tone(buzzerPin, tom2);
  }
  else {
  	digitalWrite(leds[0], LOW);
	digitalWrite(leds[1], LOW);
    digitalWrite(leds[2], HIGH);
   	tone(buzzerPin, tom3);
  }
}