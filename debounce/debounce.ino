const int buttonPin = 2;
unsigned long count = 0;
int buttonState=HIGH;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

void buttonPressed() {
int reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    Serial.println("inside");
    // if the button state has changed:
    if (reading != buttonState) {
      count++;
      Serial.println("hi");
      Serial.println(count);
      }
    }
  

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;
}

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonPressed, FALLING);
  Serial.begin(9600);
}

void loop() {
  
}
