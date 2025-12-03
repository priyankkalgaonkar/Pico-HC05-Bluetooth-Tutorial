void setup() {
  Serial.begin(115200);
  Serial1.begin(38400);   // AT-mode baud
  delay(2000);
  
  Serial.println("Factory Resetting HC-05...");

  sendAT("AT");
  sendAT("AT+ORGL");          // Factory reset
  sendAT("AT+UART=9600,0,0"); // Set normal operation baud
  sendAT("AT+NAME=ECE414HC05");    // Device name
  sendAT("AT+PSWD=1234");     // Bluetooth PIN
  sendAT("AT+ROLE=0");        // Slave mode (default)
  sendAT("AT+CMODE=1");       // Allow any device to connect
  sendAT("AT+RESET");         // Reboot

  Serial.println("Factory reset complete!");
  Serial.println("Power cycle HC-05 WITHOUT pressing button.");
}

void sendAT(String cmd) {
  Serial1.println(cmd);
  delay(500);
  Serial.print(cmd);
  Serial.print(" : ");
  while (Serial1.available()) {
    Serial.write(Serial1.read());
  }
  Serial.println();
}

void loop() {}
