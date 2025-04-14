// Pin definitions
const int lightSensorPin = A0;
const int buttonPin = 2;
const int ledPin = 9;

// Threshold (tweak as needed)
const int darkThreshold = 500;

// Shared state
bool isDark = false;
bool overrideActive = false;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP); // or INPUT with external pull-down
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Get current light status
  isDark = isRoomDark(); // Student 1's function

  // Check override status
  overrideActive = checkOverride(); // Student 2's function

  // Apply logic
  if (isDark && !overrideActive) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(200);
}

// ===> STUDENT 1 <===
bool isRoomDark() {
  int lightLevel = analogRead(lightSensorPin);
  Serial.print("Light level: ");
  Serial.println(lightLevel);
  
  // Bug: Comparison logic is inverted or wrong threshold (fix it!)
  return lightLevel < darkThreshold; // should return true when dark
}

// ===> STUDENT 2 <===
bool checkOverride() {
  static bool lastButtonState = HIGH;
  static bool override = false;

  bool currentButtonState = digitalRead(buttonPin);

  // Bug: Debounce missing, toggle logic broken (fix it!)
  if (lastButtonState == HIGH && currentButtonState == LOW) {
    override = !override;
    Serial.print("Override toggled: ");
    Serial.println(override ? "ON" : "OFF");
    delay(250); // crude debounce
  }

  lastButtonState = currentButtonState;
  return override;
}