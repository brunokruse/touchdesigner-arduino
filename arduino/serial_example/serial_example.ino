unsigned long previousMillis = 0;  // Stores the last time the counter was updated
const long interval = 25;        // Interval for one second (1000 ms)
int counter = 0;                   // Counter variable

const int ledPin = 13;  // LED pin

void setup() {
  Serial.begin(9600);              // Start serial communication at 9600 baud
  pinMode(ledPin, OUTPUT);   // Set pin 13 as an output
}

void loop() {

  sendSerialData();
  receiveSerialData();       // Check for incoming serial data
}

void sendSerialData() {
    unsigned long currentMillis = millis();  // Get the current time

  // Check if it's time to update the counter
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;  // Save the last time the counter was updated
    Serial.println(counter);         // Print the counter value to the Serial Monitor
    counter += 1;                       // Increment the counter

    if (counter >= 255) {
      counter = 0;
    }
  }
}

// Function to receive serial data and control LED
void receiveSerialData() {
  if (Serial.available() > 0) {     // Check if data is available to read
    int receivedValue = Serial.parseInt();  // Parse incoming integer value
    
    // Control LED based on received value
    if (receivedValue == 1) {
      digitalWrite(ledPin, HIGH);   // Turn LED on
      Serial.println("LED ON");     // Feedback to TouchDesigner
    } else if (receivedValue == 0) {
      digitalWrite(ledPin, LOW);    // Turn LED off
      Serial.println("LED OFF");    // Feedback to TouchDesigner
    }
  }
}