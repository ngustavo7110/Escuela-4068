// Proyecto: Detector de presencia con IR-08H y LED
// Autor: [Tu nombre o el del grupo]
// Nivel: Secundario (3° o 4° año)

const int pinSensor = 2;  // Pin OUT del sensor IR
const int pinLed = 13;    // Pin del LED indicador

void setup() {
  pinMode(pinSensor, INPUT);
  pinMode(pinLed, OUTPUT);
  Serial.begin(9600);
  Serial.println("Sistema de deteccion IR listo");
}

void loop() {
  int lectura = digitalRead(pinSensor);  // Leer estado del sensor

  if (lectura == HIGH) {   // Detecta objeto (según modelo puede ser LOW)
    digitalWrite(pinLed, HIGH);
    Serial.println("Objeto detectado");
  } else {
    digitalWrite(pinLed, LOW);
    Serial.println("Sin objeto");
  }

  delay(200); // pequeña pausa
}
