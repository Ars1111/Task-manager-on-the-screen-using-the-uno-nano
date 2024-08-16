# System Monitor for Arduino

This project provides a simple system monitoring tool that collects CPU, RAM, and disk usage statistics from a computer and sends this data to an Arduino via a serial connection. It uses the psutil library to gather system metrics and interacts with the Arduino to display or process this information.
![photo_2024-08-17_02-48-21](https://github.com/user-attachments/assets/7905ac4b-08c6-4070-b46d-2d3e22b6e058)

## Features

- Real-time CPU usage monitoring
- RAM usage monitoring
- Disk space usage monitoring
- Serial communication with Arduino to display data
- Display metrics on an SSD1306 OLED screen

## Requirements

- Python 3.x
- psutil library
- Arduino board (e.g., Arduino Uno, Nano, etc.)
- Installed appropriate serial port driver on your computer
- Arduino IDE
- SSD1306 OLED display
- Libraries: Adafruit_SSD1306, Adafruit_GFX, Wire

## Installation

1. Clone the repository:
   
   git clone https://github.com/yourusername/system-monitor-for-arduino.git
   cd system-monitor-for-arduino
   

2. Install the required Python library:
   
   pip install psutil
   

3. Open the Arduino IDE, copy the provided Arduino code, and paste it into a new sketch.

4. Install the required libraries for the SSD1306 display:
   - Go to **Sketch > Include Library > Manage Libraries**.
   - Search for Adafruit SSD1306 and install it.
   - Search for Adafruit GFX and install it.
   - The Wire library is usually included with the Arduino IDE by default.

5. Select your Arduino board and the correct port from the Tools menu.

6. Upload the sketch to your Arduino board by clicking on the upload button (right arrow icon).

7. Connect your Arduino to the computer and update the serial port in the Python script if necessary.

## Arduino Code

Here’s an example code that you can upload to your Arduino board, including support for the SSD1306 display:
```cpp
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(9600); // Initialize serial connection
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); /![photo_2024-08-17_02-47-32](https://github.com/user-attachments/assets/583044f4-31a0-43e1-a691-05765af8d754)
/ Initialize display
  display.clearDisplay(); // Clear the display
}

void loop() {
  if (Serial.available()) {
    String data = Serial.readStringUntil('\n'); // Read data until newline
    Serial.println("Received: " + data); // Print received data to serial monitor
    
    // Display received data on SSD1306 screen
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("System Metrics:");
    display.println(data); // Display the received data
    display.display(); // Show on screen
  }
}
```

This code initializes the serial connection and the SSD1306 display. It waits for incoming data and displays it on the OLED screen.

## Connection

1. Connect the Arduino board to your computer via a USB cable.
2. Ensure that you have the correct driver installed for the serial port.
3. In the Python script, specify the correct serial port (e.g., COM3 for Windows or /dev/ttyUSB0 for Linux).
4. Connect the SSD1306 display to your Arduino:
   - VCC to 5V or 3.3V (depending on your display)
   - GND to Ground
   - SDA to A4 (for Uno) or corresponding SDA pin on other boards
   - SCL to A5 (for Uno) or corresponding SCL pin on other boards

## Usage

Run the Python script to start collecting and sending system metrics to Arduino:
python monitor.py
![photo_2024-08-17_02-47-32](https://github.com/user-attachments/assets/b121e719-e616-462e-a49c-17440a155495)


The Arduino will receive and process the data, allowing you to visualize system performance in real time on both the serial monitor and the SSD1306 display.

## Contribution

Contributions are welcome! Please feel free to submit a pull request or open an issue for any improvements or bug fixes.

Feel free to modify it further if needed!
