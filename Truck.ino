int triggerPin[] = {2, 5};
int echoPin[] = {3, 7};

int right = 0, left = 0;
int diff = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(triggerPin[0], OUTPUT);
  pinMode(triggerPin[1], OUTPUT);
  
  pinMode(echoPin[0], INPUT);
  pinMode(echoPin[1], INPUT);
}

int getDistance(int trigger, int echo) {
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  long time = pulseIn(echo, HIGH);
  int distance = time * 0.034/2;

  return distance;
}

void halt() {
  Serial.println("Halt");
  
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
}

void moveRight() {
  Serial.println("Right");
  
  digitalWrite( , HIGH);
  digitalWrite( , HIGH);

  digitalWrite( , LOW);
  digitalWrite( , LOW);
}

void moveLeft() {
  Serial.println("Left");

  digitalWrite( , HIGH);
  digitalWrite( , HIGH);

  digitalWrite( , LOW);
  digitalWrite( , LOW);
}

void moveAhead() {
  Serial.println("Straight");

  digitalWrite( , HIGH);
  digitalWrite( , HIGH);

  digitalWrite( , HIGH);
  digitalWrite( , HIGH);
}

bool inRange(int distance) {
  if (distance >= 0 && distance <= 35)
    return true;
  return false;
}

void loop() {
  right = getDistance(triggerPin[0], echoPin[0]);
  left = getDistance(triggerPin[1], echoPin[1]);

  diff = right - left;

  if ( !(inRange(right) && inRange(left) ) ) {
    halt();
  } else if ( abs(diff) <= 1 ) {
    moveAhead();
  } else if ( left > right ) {
    moveRight();
  } else if ( right > left ) {
    moveLeft();
  }

  /*Serial.println(left);
  Serial.println(right);
  Serial.println();*/

  delay(500);

}
