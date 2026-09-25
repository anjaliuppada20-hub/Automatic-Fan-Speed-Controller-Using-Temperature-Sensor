// Automatic Fan Speed Controller
// Temperature Sensor: LM35
// Fan controlled using PWM

int tempPin = A0;
int fanPin = 9;

void setup() {
  Serial.begin(9600);
  pinMode(fanPin, OUTPUT);
}

void loop() {

  // Read LM35 sensor
  int sensorValue = analogRead(tempPin);

  // Convert ADC value to temperature
  float voltage = sensorValue * (5.0 / 1023.0);
  float temperature = voltage * 100.0;

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  // Control fan speed
  if (temperature < 25) {
    analogWrite(fanPin, 0);       // Fan OFF
  }
  else if (temperature < 30) {
    analogWrite(fanPin, 100);     // Low speed
  }
  else if (temperature < 35) {
    analogWrite(fanPin, 180);     // Medium speed
  }
  else {
    analogWrite(fanPin, 255);     // Full speed
  }

  delay(1000);
}
