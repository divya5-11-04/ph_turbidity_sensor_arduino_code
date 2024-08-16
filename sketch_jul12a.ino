// Define the analog pins for the sensors
const int pHPin = 32;       // GPIO32 for pH sensor
const int turbidityPin = 34; // GPIO33 for turbidity sensor

void setup() {
  // Initialize serial communication at 115200 baud
  Serial.begin(115200);
}

void loop() {
  // Read analog value from the pH sensor
  int pHAnalogValue = analogRead(pHPin);
  // Convert the analog value to voltage (assuming a 5V reference voltage)
  float pHVoltage = pHAnalogValue * (5.0 / 4095.0);
  // Convert the voltage to pH value
  float pHValue = 7.0 + ((2.5 - pHVoltage) / 0.18);

  // Read analog value from the turbidity sensor
  int turbidityAnalogValue = analogRead(turbidityPin);
  // Convert the analog value to voltage (assuming a 5V reference voltage)
  float turbidityVoltage = turbidityAnalogValue * (5.0 / 4095.0);
  // Convert the voltage to NTU (Nephelometric Turbidity Units)
  // This conversion depends on your specific turbidity sensor and its datasheet
  float turbidityValue = turbidityVoltage * 3000 / 4.5; // Example conversion

  // Print the pH value to the Serial Monitor
  Serial.print("pH Value: ");
  Serial.print(pHValue, 2);
  Serial.print(" | Voltage: ");
  Serial.print(pHVoltage, 2);
  Serial.print("V | pH Analog Value: ");
  Serial.println(pHAnalogValue);

  // Print the turbidity value to the Serial Monitor
  Serial.print("Turbidity Value: ");
  Serial.print(turbidityValue, 2);
  Serial.print(" NTU | Voltage: ");
  Serial.print(turbidityVoltage, 2);
  Serial.print("V | Turbidity Analog Value: ");
  Serial.println(turbidityAnalogValue);

  // Wait for a second
  delay(1000);
}
