const int TIME = 15;
const int WALK = 13;
const int HAND = 12;
const int BUTTON_POW = 27;
const int BUTTON_IN = 26;

const int GREEN = 32;
const int YELLOW = 33;
const int RED = 25;

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
  }

}

void cycle() {

  // Walk signal on
  state(WALK);
  state(HAND);
  state(RED);
  state(GREEN);
  delay(TIME * 1000);

  state(WALK);
  state(HAND);

  // Toggle traffic light
  state(GREEN);
  state(YELLOW);

  // Flash hand and countdown timmer
  for (int i = 0; i < TIME; i++) {
    delay(500);
    state(HAND);
    delay(500);
    state(HAND);
  }

  // Toggle traffic light
  state(YELLOW);
  state(RED);

}

void state(int pin) {
  digitalWrite(pin, !digitalRead(pin));
}