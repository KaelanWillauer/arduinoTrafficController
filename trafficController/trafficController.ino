// Gate
const int OPENING_TIME = 30;
const int CLOSING_TIME = 35;

// Walk signal
const int CLOCK_TIME = 14;

// Pin numbers (walk signal)
const int WALK = 13;
const int HAND = 12;

// Pin numbers (traffic light)
const int GREEN = 32;
const int YELLOW = 33;
const int RED = 25;

// Pin numbers (test button)
const int BUTTON_POW = 27;
const int BUTTON_IN = 26;

void setup() {
  Serial.begin(9600);
  delay(1000);
  
  // Setting pins
  pinMode(WALK, OUTPUT);
  pinMode(HAND, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(BUTTON_POW, OUTPUT);
  pinMode(BUTTON_IN, INPUT);

  // Setting states
  state(BUTTON_POW);
  state(HAND);
  state(RED);

  // Programming walk signal...
  delay(5000);
  cycle();
  delay(5000);
  cycle();
}

void loop() {
  // Input starts cycle
  if (digitalRead(BUTTON_IN) == HIGH) {
    cycle();
    delay(CLOSING_TIME);
  }

}

void cycle() {

  // Gate opening
  state(WALK);
  state(HAND);
  state(RED);
  state(GREEN);
  delay(OPENING_TIME * 1000);

  // Gate open
  state(WALK);
  state(HAND);

  // Toggle traffic light
  state(GREEN);
  state(YELLOW);

  // Flash hand and countdown timmer
  for (int i = 0; i < OPENING_TIME; i++) {
    delay(500);
    state(HAND);
    delay(500);
    state(HAND);
  }

  // Gate closed
  state(YELLOW);
  state(RED);

}

// Toggle state of pin
void state(int pin) {
  digitalWrite(pin, !digitalRead(pin));
}
