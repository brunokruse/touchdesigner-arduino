unsigned long previousMillis = 0;   // Stores the last time the counter was updated
const long interval = 1000;         // Interval for one second (1000 ms)
const int ledPin = 13;              // LED pin
int ledState = 0;                   // LED state (0 = off, 1 = on)

// RGB values
int redValue = 0;
int greenValue = 0;
int blueValue = 0;

void setup() {
  Serial.begin(9600);               // Start serial communication at 9600 baud
  pinMode(ledPin, OUTPUT);          // Set pin 13 as an output
}

void loop() {
  sendSerialData();                 // Send counter data every second
  receiveSerialData();              // Check for incoming serial data
}

// Function to send three parameters to the serial port as comma-separated values
void sendMultipleData(int param1, int param2, unsigned long param3) {
  Serial.print(param1);
  Serial.print(",");
  Serial.print(param2);
  Serial.print(",");
  Serial.println(param3);            // Newline after the third parameter
}

// Function to send counter data at a specified interval
void sendSerialData() {
  unsigned long currentMillis = millis();  // Get the current time

  // Check if it's time to update the counter
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;        // Save the last time the counter was updated

    // Generate random RGB values (0-255)
    redValue = random(0, 256);
    greenValue = random(0, 256);
    blueValue = random(0, 256);

    // Send RGB values to TouchDesigner
    sendMultipleData(redValue, greenValue, blueValue);
  }
}

// Function to receive serial data and control LED
void receiveSerialData() {
  if (Serial.available() > 0) {              // Check if data is available to read
    int receivedValue = Serial.parseInt();   // Parse incoming integer value
    
    // Control LED based on received value
    if (receivedValue == 1) {
      digitalWrite(ledPin, HIGH);            // Turn LED on
      ledState = 1;                          // Update LED state
      Serial.println("LED ON");              // Feedback to TouchDesigner
    } else if (receivedValue == 0) {
      digitalWrite(ledPin, LOW);             // Turn LED off
      ledState = 0;                          // Update LED state
      Serial.println("LED OFF");             // Feedback to TouchDesigner
    }
  }
}
