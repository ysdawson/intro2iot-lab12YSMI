// === Automatic Room Light with Manual Override ===

const int lightSensorPin = A0;   // Photoresistor connected to A0
const int buttonPin = 2;         // Button connected to D2
const int ledPin = 9;            // LED (room light) connected to D9

const int darkThreshold = 500;   // Adjust based on ambient light conditions

bool isDark = false;
bool isButtonOn = false;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);  // Use internal pull-up resistor
  pinMode(ledPin, OUTPUT);
  pinMode(lightSensorPin, INPUT);
}

void loop() {
  isDark = isRoomDark();             // Light detection logic
  isButtonOn = isButtonActivated();  // Button-based manual override

  // Control the LED
  if (isDark || isButtonOn) {
    digitalWrite(ledPin, HIGH);
    Serial.println("LED: ON");
  } else {
    digitalWrite(ledPin, LOW);
    Serial.println("LED: OFF");
  }

  delay(200); // basic debounce + sampling interval
}

// ===============================
// Light Detection – Student 1
bool isRoomDark() {
  int lightLevel = analogRead(lightSensorPin);

  Serial.print("Light Level: ");
  Serial.println(lightLevel);

  // Return true if it's dark
  return (lightLevel < darkThreshold);
}
// ===============================
// Manual Switch Control – Student 2
bool isButtonActivated() {
  bool state = digitalRead(buttonPin);

  if (state == HIGH) {
    Serial.println("Button: OFF");
    return false;  // Not pressed
  } else {
    Serial.println("Button: ON");
    return true;   // Pressed
  }
}
