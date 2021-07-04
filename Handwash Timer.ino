
#define buzzer 10


int echoPin = 11;
int trigPin = 12;
long duration;
int distance;


void setup() {
  for (int i = 2; i <= 7; i++) {
    pinMode (i, OUTPUT);
  }
  pinMode (trigPin, OUTPUT);
  pinMode (echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
}
void loop() {
  // measure distance and reads the measured data
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration * .0343) / 2;

  // Check if there is any object within 30cm
  if (distance > 0 && distance <= 30) {
    timer();
  }
}

void timer() {
  digitalWrite (7, HIGH);
  delay(4000);
  for (int i = 6; i >= 2; i--) {
    digitalWrite (i, HIGH);
    if (i == 2) {
      digitalWrite (7, LOW);
      for (int i = 0; i <= 2; i++ ){
            digitalWrite(buzzer, HIGH);
            delay(100);
            digitalWrite(buzzer, LOW);
            delay(250);
            digitalWrite(buzzer, HIGH);
            delay(100);
            digitalWrite(buzzer, LOW);
      
            delay(500);
            digitalWrite(buzzer, HIGH);
            delay(100);
            digitalWrite(buzzer, LOW);
            delay(125);
      
            digitalWrite(buzzer, HIGH);
            delay(100);
            digitalWrite(buzzer, LOW);
            delay(125);
      
            digitalWrite(buzzer, HIGH);
            delay(100);
            digitalWrite(buzzer, LOW);
            delay(750);
            for (int i = 7; i >= 2; i--) {
            digitalWrite (i, LOW);

             }
        }
      
    }
    delay(4000);
  }

}
