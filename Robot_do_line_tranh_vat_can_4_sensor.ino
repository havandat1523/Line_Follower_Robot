
int ENA = 11;
int IN1 = 10;
int IN2 = 9;

int ENB = 6;
int IN3 = 7;
int IN4 = 8;

//Set tốc độ của robot
#define ENASpeed 180
#define ENBSpeed 180

int Sensor1 = 0;
int Sensor2 = 0;
int Sensor3 = 0;
int Sensor4 = 0;



void setup() {

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(Sensor1, INPUT);
  pinMode(Sensor2, INPUT);
  pinMode(Sensor3, INPUT);
  pinMode(Sensor4, INPUT);

  analogWrite(ENA, ENASpeed);
  analogWrite(ENB, ENBSpeed);
  delay(2000);
}

void loop() {


  Sensor1 = digitalRead(5);
  Sensor2 = digitalRead(4);
  Sensor3 = digitalRead(3);
  Sensor4 = digitalRead(2);


  if (Sensor4 == HIGH && Sensor3 == HIGH && Sensor2 == LOW && Sensor1 == LOW) {
    Turn_left();
  }

  if (Sensor4 == HIGH && Sensor3 == HIGH && Sensor2 == HIGH && Sensor1 == LOW) {
    Turn_left();
  }

  if (Sensor4 == HIGH && Sensor3 == LOW && Sensor2 == LOW && Sensor1 == LOW) {
    Turn_left();
  }

  if (Sensor4 == LOW && Sensor3 == LOW && Sensor2 == HIGH && Sensor1 == HIGH) {
    Turn_right();
  }

  if (Sensor4 == LOW && Sensor3 == LOW && Sensor2 == LOW && Sensor1 == HIGH) {
    Turn_right();
  }

  if (Sensor4 == LOW && Sensor3 == HIGH && Sensor2 == HIGH && Sensor1 == HIGH) {
    Turn_right();
  }

  if (Sensor4 == HIGH && Sensor3 == HIGH && Sensor2 == HIGH && Sensor1 == HIGH) {
    Robot_stop();
  }

  if (Sensor4 == LOW && Sensor3 == HIGH && Sensor2 == HIGH && Sensor1 == LOW) {
    forward();
  }
}
void forward() {
  //motor A tiến
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  //motor B tiến
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void Backward() {
  //motor A lùi
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  //motor B lùi
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void Turn_right() {
  //motor A lùi
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  //motor B tiến
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void Turn_left() {
  //motor A tiến
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  //motor B lùi
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
void Robot_stop() {
  //motor A tiến
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  //motor B lùi
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
