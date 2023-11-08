const int sensorPin = A0;    // Pin analógico donde está conectada la KY-018.
const int ledPin = 5;        // Pin digital donde está conectado el LED de la KY-018.
const int mercuryPin = 4;    // Pin digital donde está conectado el KY-027.
const int ledMercuryPin = 0; // Pin digital donde está conectado el LED del KY-027.
int inclinacion = 0;         // Variable para el estado de inclinación del KY-027.

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ledMercuryPin, OUTPUT);
  pinMode(mercuryPin, INPUT);
  Serial.begin(115200);
}

void loop() {
  int valorSensor = analogRead(sensorPin);

  // Convierte el valor del sensor en una escala no basada en voltaje.
  int nivelLuz = map(valorSensor, 0, 1023, 0, 100);  // Mapea de 0 a 100.

  Serial.print("Valor del sensor: ");
  Serial.print(valorSensor);
  Serial.print("\tNivel de luz (%): ");
  Serial.println(100 - nivelLuz);  // Invierte el nivel de luz.

  // Lectura del sensor de inclinación KY-027.
  inclinacion = digitalRead(mercuryPin);


/*
 * Entre menos luminocidad el led enciende con mayor intencidad 
  valorSensor = (valorSensor*255 ) / 1023;
  analogWrite(ledPin, valorSensor);
  */

    if (inclinacion == 1) {  // Cuando el KY-027 se inclina (circuit abierto), enciende el LED KY-027.
    digitalWrite(ledMercuryPin, HIGH);
  } else {
    digitalWrite(ledMercuryPin, LOW);  // De lo contrario, apaga el LED KY-027.
  }

  
  
  if (nivelLuz < 50) {  // Si el nivel de luz es menor al 50%, consideramos que está oscuro.
    digitalWrite(ledPin, LOW);  // Enciende el LED KY-018.
    
  } else {
    digitalWrite(ledPin, HIGH);  // Apaga el LED KY-018.
  }


  
  delay(1000);  // Espera 1 segundo antes de volver a leer los sensores.
}
