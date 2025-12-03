# HC-05 Bluetooth Module with Raspberry Pi Pico  
A complete step-by-step tutorial for wiring, factory resetting, configuring, and communicating with the **HC-05 Bluetooth module** using a **Raspberry Pi Pico** and the **Arduino IDE**.  
Tested personally with two Windows 11 PCs for reliable wireless serial communication.

---

## 📁 Repository Contents

| File | Description |
|------|-------------|
| `Pico_HC05_FactoryReset.ino` | Arduino code to put HC-05 into AT mode and perform a full factory reset (ORGL, name, PIN, baud, role). |
| `Pico_HC05_Passthrough.ino` | UART passthrough sketch for Bluetooth serial communication between Pico ⇄ Windows PC. |
| `Pico with HC-05 Bluetooth Setup Tutorial.pdf` | **Full PDF tutorial** with wiring diagrams, voltage divider, photos, and Windows 11 pairing instructions. |
| `IMG_9117.JPG` | Photos and wiring diagram used in the tutorial. |

---

## 🔧 Hardware Required

- Raspberry Pi Pico or Pico W  
- HC-05 Bluetooth Module (DSD TECH recommended)  
- Breadboard + jumper wires  
- **1.8 kΩ resistor + 3.3 kΩ resistor** (for safe voltage divider on HC-05 RX pin)  
- Windows 10/11 PC with Bluetooth  
- Arduino IDE installed

---

## 🧩 Wiring Diagram (HC-05 → Pico)

| HC-05 Pin | Pico Pin | Notes |
|-----------|----------|-------|
| **VCC** | **VBUS (5V)** | Must use 5V |
| **GND** | **GND** | Shared ground |
| **TXD** | **GP1 (UART0 RX)** | Direct connection |
| **RXD** | **GP0 (UART0 TX)** | Through voltage divider |
| **KEY (optional)** | **3.3V** | Required only for AT mode |

### **Voltage Divider for HC-05 RXD**

![Alt See the wiring diagram: ](https://github.com/priyankkalgaonkar/Pico-HC05-Bluetooth-Tutorial/blob/main/Pico%20with%20HC-05_bb.png)

This ensures HC-05 RX pin receives ~2.1V (safe).

---

## 🛠️ Part 1 — Factory Reset the HC-05 (AT Mode)

1. Put the HC-05 into **AT Mode**  
   - Hold the HC-05 button  
   - Power the Pico  
   - LED blinks **slow** (once every 2s)  
2. Flash `Pico_HC05_FactoryReset.ino`  
3. The code automatically sends:  
   - `AT+ORGL`  
   - `AT+UART=9600,0,0`  
   - `AT+NAME=HC05`  
   - `AT+PSWD=1234`  
   - `AT+ROLE=0`  
   - `AT+CMODE=1`  
   - `AT+RESET`

After reset, the HC-05 enters normal mode (fast blinking).

---

## 💻 Part 2 — Pair with Windows 10/11

1. Open  
   **Settings → Bluetooth & Devices → Add Device → Bluetooth**
2. Select **HC-05**  
3. Enter PIN:  
   ```
   1234
   ```
4. Windows will show:  
   - **Connected** → then **Disconnected**  
   (This is normal. HC-05 stays connected only when a COM port is opened.)

---

## 📡 Part 3 — Find the Bluetooth COM Port

1. Press:  
   **Win + X → Device Manager**
2. Expand:  
   **Ports (COM & LPT)**
3. Identify:
   - **Outgoing COM Port** → used for Bluetooth communication  
   - Incoming COM port → not used

Example:
```
Standard Serial over Bluetooth link (COM7)
Standard Serial over Bluetooth link (COM8)
```

Outgoing port is typically the higher-numbered one.

---

## 🔁 Part 4 — Communication Test (Pico ⇄ Windows PC)

Flash `Pico_HC05_Passthrough.ino` to the Pico.

This sketch acts as a simple UART bridge:
- USB Serial ⇄ HC-05 Bluetooth Serial

### Steps:
1. Open Arduino Serial Monitor  
2. Select **HC-05 OUTGOING COM port**  
3. Set baud: **9600**  
4. Set “Both NL & CR”

### Test:
- Type `Hello Pico!` in Bluetooth COM → appears on USB COM  
- Type `Hello Windows!` in USB COM → appears on Bluetooth COM

✔ Two-way communication confirmed  
✔ HC-05 and Pico working perfectly

---

## 📚 Documentation & Resources

-   **[Full Tutorial PDF](./Pico%20with%20HC05%20Bluetooth%20Setup%20Tutorial.pdf)**: The complete guide, including detailed wiring, code walkthroughs, and porting instructions.
-   **Setup Photo**: [View on GitHub](./IMG_9117.JPG)
-   **Video Demonstration**: [Watch on Google Drive](https://drive.google.com/file/d/1GIWd8nUkWbApizmgz8QzmVkbEznXsuho/view?usp=sharing)

---

## ⚠️ Important Notes

- **iPhones cannot pair with HC-05** (Classic Bluetooth SPP only).  
- Only **Android** and **Windows/Linux** support HC-05 serial connections.  
- LED patterns:
  - Fast blink = waiting for connection  
  - Slow blink = AT mode  
  - Double-blink = connected

---

## 🤝 Contributing

Pull requests for improvements or extensions (e.g., mobile apps, BLE version, Python GUI) are welcome.

---

## 📄 License

This project is provided for educational purposes.  
MIT License recommended for sharing code publicly.

