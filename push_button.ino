#define Motor_PIN 8
#define BUTTON_PIN 7
byte lastButtonState = LOW;
byte MotorState = LOW;
unsigned long debounceDuration = 50; // millis
unsigned long lastTimeButtonStateChanged = 0;
void setup() {
  pinMode(Motor_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
}
void loop() {
  if (millis() - lastTimeButtonStateChanged > debounceDuration) {
    byte buttonState = digitalRead(BUTTON_PIN);
    if (buttonState != lastButtonState) {
      lastTimeButtonStateChanged = millis();
      lastButtonState = buttonState;
      if (buttonState == LOW) {
        MotorState = (MotorState == HIGH) ? LOW: HIGH;
        digitalWrite(Motor_PIN, MotorState);
      }
    }
  }
}
