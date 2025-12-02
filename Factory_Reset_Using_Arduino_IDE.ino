void setup() {
  Serial.begin(115200);    // USB to PC
  Serial1.begin(9600);     // HC-05 UART
}

void loop() {
  if (Serial1.available()) {
    Serial.write(Serial1.read());
  }
  if (Serial.available()) {
    Serial1.write(Serial.read());
  }
}