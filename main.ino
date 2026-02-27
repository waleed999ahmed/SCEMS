// Define pins
int irOnPin = 11;      // IR sensor 1 (turns LED ON)
int irOffPin = 12;     // IR sensor 2 (turns LED OFF)
int ledPin1 = 2;      // LED pin 1
int ledPin2 = 3;      // LED pin 2
int ledPin3 = 4;      // LED pin 3
int ledPin4 = 5;      // LED pin 4
int ledPin5 = 6;      // LED pin 5
int fanPin = 13;      // Fan pin

int ledState = LOW;   // LED starts OFF

void setup() {
  pinMode(irOnPin, INPUT);
  pinMode(irOffPin, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(fanPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("System initialized. Waiting for IR detection...");
}

void loop() {
  int irOnState = digitalRead(irOnPin);
  int irOffState = digitalRead(irOffPin);

  // If IR1 detects an object (LOW signal) → turn ON LED
  if (irOnState == LOW) {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin5, HIGH);
    digitalWrite(fanPin, HIGH);
    if (ledState == LOW) {
      Serial.println("Object detected by IR1 → LED ON");
      ledState = HIGH;
      delay(500); // debounce delay
    }
  }

  // If IR2 detects an object (LOW signal) → turn OFF LED
  if (irOffState == LOW) {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin5, LOW);
    digitalWrite(fanPin, LOW);
    if (ledState == HIGH) {
      Serial.println("Object detected by IR2 → LED OFF");
      ledState = LOW;
      delay(500); // debounce delay
    }
  }
}
