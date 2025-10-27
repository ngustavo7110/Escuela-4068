#include <Servo.h>

#define trigPin 12
#define echoPin 13
#define enA 5
#define in1 8
#define in2 9
#define enB 6
#define in3 10
#define in4 11
#define servoPin 3

Servo servoMotor;

long distancia;
int posServo = 90; // posición central

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  servoMotor.attach(servoPin);
  servoMotor.write(posServo);
  delay(1000);
}

void loop() {
  distancia = medirDistancia();

  if (distancia > 20) {
    avanzar();
  } else {
    detener();
    retroceder();
    detener();
    int distanciaIzq = mirarIzquierda();
    int distanciaDer = mirarDerecha();

    if (distanciaDer > distanciaIzq) {
      girarDerecha();
    } else {
      girarIzquierda();
    }
  }
}

long medirDistancia() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duracion = pulseIn(echoPin, HIGH);
  long distancia = duracion * 0.034 / 2;
  return distancia;
}

void avanzar() {
  analogWrite(enA, 150);
  analogWrite(enB, 150);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void retroceder() {
  analogWrite(enA, 150);
  analogWrite(enB, 150);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(500);
}

void detener() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(200);
}

void girarIzquierda() {
  analogWrite(enA, 150);
  analogWrite(enB, 150);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(600);
}

void girarDerecha() {
  analogWrite(enA, 150);
  analogWrite(enB, 150);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(600);
}

int mirarIzquierda() {
  servoMotor.write(150);
  delay(500);
  int distancia = medirDistancia();
  servoMotor.write(90);
  delay(500);
  return distancia;
}

int mirarDerecha() {
  servoMotor.write(30);
  delay(500);
  int distancia = medirDistancia();
  servoMotor.write(90);
  delay(500);
  return distancia;
}
