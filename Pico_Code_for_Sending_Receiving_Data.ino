/******************************************************************************
 * HC-05 Bluetooth Serial Bridge
 * 
 * Filename: HC05_Serial_Bridge.ino
 * Author: Prof. Dr. Priyank Kalgaonkar
 * Date: 12/02/2025
 * Version: 1.0
 * 
 * Description:
 * This Arduino sketch creates a bidirectional serial bridge between:
 * 1. A computer (via USB/Serial), Pico and
 * 2. An HC-05 Bluetooth module
 * 
 * The bridge allows transparent communication between a serial terminal
 * on a computer and any Bluetooth device connected to the HC-05 module.
 * Data received from the computer is forwarded to the HC-05, and data
 * received from the HC-05 is forwarded to the computer.
 * 
 * Baud Rates:
 * - Computer to Arduino (USB): 115200 bps
 * - Arduino to HC-05 (UART): 9600 bps
 *   (Must match HC-05 configuration from factory reset script)
 * 
 * Typical Use Cases:
 * 1. Bluetooth debugging and monitoring
 * 2. Wireless serial communication between PC and microcontrollers
 * 3. Remote control applications
 * 4. Data logging from Bluetooth-enabled sensors
 * 
 * Usage Instructions:
 * 1. Read the PDF tutorial and follow it carefully!
 ******************************************************************************/

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
