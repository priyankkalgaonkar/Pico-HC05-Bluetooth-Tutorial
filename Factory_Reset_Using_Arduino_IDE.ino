/******************************************************************************
 * HC-05 Bluetooth Module Factory Reset Configuration
 * 
 * Filename: HC05_Factory_Reset.ino
 * Author: Prof. Dr. Priyank Kalgaonkar.
 * Date: 12/02/2025
 * Version: 1.0
 * 
 * Description:
 * This Arduino sketch performs a factory reset and configuration of an HC-05
 * Bluetooth module. It resets the module to default settings, configures it
 * with specific parameters, and prepares it for use as a Bluetooth slave
 * device.
 * 
 * HC-05 Configuration:
 * - Baud Rate (AT-mode): 38400 bps
 * - Baud Rate (Normal): 9600 bps
 * - Device Name: ECE414HC05
 * - PIN Code: 1234
 * - Role: Slave (0)
 * - Connection Mode: Allow any device to connect (1)
 * 
 * Hardware Connections:
 * - Arduino TX1 (Pin 18) -> HC-05 RX
 * - Arduino RX1 (Pin 19) -> HC-05 TX
 * - HC-05 KEY pin must be HIGH/connected to 3.3V before powering on
 * 
 * Usage:
 * 1. Follow the PDF tutorial instructions carefully!
 * 
 * Notes:
 * - HC-05 LED should blink slowly (2 seconds on/2 seconds off) in AT mode
 * - After configuration, LED will blink rapidly when searching for connection
 * - Ensure proper voltage levels as outlined in my PDF Tutorial.
 * 
 * AT Commands Used:
 * AT        - Test command (should return OK)
 * AT+ORGL   - Factory reset
 * AT+UART   - Set baud rate for normal operation
 * AT+NAME   - Set device name
 * AT+PSWD   - Set PIN code
 * AT+ROLE   - Set role (0=slave, 1=master)
 * AT+CMODE  - Set connection mode
 * AT+RESET  - Reboot module
 * 
 ******************************************************************************/

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
