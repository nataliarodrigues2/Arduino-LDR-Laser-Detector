
const int LDR = A0;
const int BUZZER = 8;
const int LED = 7;

int limiteLuz = 500;

void setup() {
  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int luz = analogRead(LDR);

  Serial.print("Nivel de luz: ");
  Serial.println(luz);

  // Quando a luz diminuir, ativa o alarme
  if (luz < limiteLuz) {
    tone(BUZZER, 1000);
    digitalWrite(LED, HIGH);
  } else {
    noTone(BUZZER);
    digitalWrite(LED, LOW);
  }

  delay(100);
}
