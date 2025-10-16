// Pines sensor ultrasónico
#define TRIG 3
#define ECHO 2

// Pines motor izquierdo
#define ENA 5   // Velocidad (PWM)
#define IN1 6
#define IN2 7

// Pines motor derecho
#define ENB 10  // Velocidad (PWM)
#define IN3 8
#define IN4 9

int velocidad = 200; // Velocidad fija (0-255)

void setup() {
  // Configuración sensor ultrasónico
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  // Configuración motores
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  long distancia = medirDistancia();
  Serial.print("Distancia: ");
  Serial.println(distancia);

  if (distancia > 10) {
    avanzar();
  } else {
    retroceder();
    delay(500); // retrocede medio segundo antes de volver a medir
  }
}

// Función para medir distancia
long medirDistancia() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duracion = pulseIn(ECHO, HIGH);
  long distancia = duracion * 0.034 / 2; // cm
  return distancia;
}

// Movimiento: Avanzar
void avanzar() {
  analogWrite(ENA, velocidad);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  analogWrite(ENB, velocidad);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// Movimiento: Retroceder
void retroceder() {
  analogWrite(ENA, velocidad);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  analogWrite(ENB, velocidad);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
