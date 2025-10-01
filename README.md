# Arduino I2C Scanner with OLED Display

A simple and effective Arduino sketch to scan the I2C bus for connected devices. It displays the addresses of any found devices on a 128x64 I2C OLED display (compatible with both SSD1306 and SSH1106 drivers).

![demo](https://i.imgur.com/u5gqJzL.gif)  ## Features

- Scans all possible I2C addresses (1 to 127).
- Displays the address of any found device in hexadecimal format on an OLED screen.
- Provides clear status messages like "Scanning..." and "No I2C devices found".
- Easily configurable for different OLED display types (SSD1306/SSH1106, 128x32/128x64) by uncommenting a single line.
- Includes an optional debug output to the Serial Monitor.

## Hardware Requirements

- An Arduino-compatible microcontroller (e.g., Arduino Uno/Nano, ESP32, ESP8266).
- A 128x64 I2C OLED Display based on the SSD1306 or SSH1106 driver.
- Jumper wires to connect the components.
- Any I2C device to test with (e.g., a BME280 sensor, a DS3231 RTC, etc.).

## Software Requirements

1.  **Arduino IDE**: Download from the [official Arduino website](https://www.arduino.cc/en/software).
2.  **GyverOLED Library**: This powerful library is required to control the display. You can install it from the Arduino IDE's Library Manager:
    - Go to `Tools` > `Manage Libraries...`
    - Search for `GyverOLED`.
    - Click `Install`.

## Schematics / Wiring

Connect your OLED display to your microcontroller using the I2C pins. The specific pins can vary depending on your board.

| OLED Pin | Arduino Uno / Nano | ESP32           |
| :------- | :----------------- | :-------------- |
| `VCC`    | `5V`               | `3.3V` or `5V`  |
| `GND`    | `GND`              | `GND`           |
| `SCL`    | `A5`               | `GPIO 22`       |
| `SDA`    | `A4`               | `GPIO 21`       |

**Note:** Always check the pinout diagram for your specific board.

## How to Use

1.  **Connect Hardware**: Wire the OLED display to your microcontroller as shown in the schematics section.
2.  **Install Library**: Ensure the `GyverOLED` library is installed in your Arduino IDE.
3.  **Open the Sketch**: Open the `I2C_OLED_Scanner.ino` file in the Arduino IDE.
4.  **Configure Display**: At the top of the sketch, uncomment the line that corresponds to your specific OLED display. The default is set for a 128x64 SSH1106 display.
    ```cpp
    // For a 128x64 SSD1306 display, use this line:
    // GyverOLED<SSD1306_128x64, OLED_BUFFER> oled;

    // For a 128x64 SSH1106 display, use this line:
    GyverOLED<SSH1106_128x64> oled;
    ```
5.  **Select Board & Port**: In the Arduino IDE, go to `Tools` > `Board` and select your microcontroller. Then, go to `Tools` > `Port` and select the correct COM port.
6.  **Upload**: Click the upload button.
7.  **View Output**: The OLED display will first show "Scanning...". If it finds a device, it will display its hexadecimal address. If no devices are found, it will report that.

## Troubleshooting

-   **"No I2C devices found" is displayed:**
    -   Double-check your `SDA` and `SCL` wiring. They are often swapped by mistake.
    -   Ensure the OLED display and any other I2C devices are powered correctly (`VCC` and `GND`).
    -   The I2C address of your OLED display is `0x3C`. The code intentionally skips this address to find *other* devices on the bus. If your OLED is the only device connected, the scanner will correctly report "No I2C devices found". Connect another I2C sensor to see its address appear.

## License

This project is released under the MIT License. See the `LICENSE` file for details.
