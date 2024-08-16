# System Monitor for Arduino

This project provides a simple system monitoring tool that collects CPU, RAM, and disk usage statistics from a computer and sends this data to an Arduino via a serial connection. It uses the psutil library to gather system metrics and interacts with the Arduino to display or process this information.

## Features

- Real-time CPU usage monitoring
- RAM usage monitoring
- Disk space usage monitoring
- Serial communication with Arduino to display data

## Requirements

- Python 3.x
- psutil library
- Arduino board (e.g., Arduino Uno, Nano, etc.)
- Installed appropriate serial port driver on your computer
- Arduino IDE

## Installation

1. Clone the repository:
   
   git clone https://github.com/yourusername/system-monitor-for-arduino.git
   cd system-monitor-for-arduino
   

2. Install the required Python library:
   
   pip install psutil
   

3. Open the Arduino IDE, copy the provided Arduino code, and paste it into a new sketch.

4. Select your Arduino board and the correct port from the Tools menu.

5. Upload the sketch to your Arduino board by clicking on the upload button (right arrow icon).

6. Connect your Arduino to the computer and update the serial port in the Python script if necessary.

## Arduino Code

Here’s an example code that you can upload to your Arduino board:
```cpp
void setup() {
  Serial.begin(9600); // Initialize serial connection
}

void loop() {
  if (Serial.available()) {
    String data = Serial.readStringUntil('\n'); // Read data until newline
    Serial.println("Received: " + data); // Print received data to serial monitor
  }
}
```

This code initializes the serial connection and waits for incoming data. The received data is printed to the serial monitor.

## Connection

1. Connect the Arduino board to your computer via a USB cable.
2. Ensure that you have the correct driver installed for the serial port.
3. In the Python script, specify the correct serial port (e.g., COM3 for Windows or /dev/ttyUSB0 for Linux).

## Usage

Run the Python script to start collecting and sending system metrics to Arduino:
python monitor.py


The Arduino will receive and process the data, allowing you to visualize system performance in real time.

## Contribution

Contributions are welcome! Please feel free to submit a pull request or open an issue for any improvements or bug fixes.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

Feel free to modify it further if needed!
