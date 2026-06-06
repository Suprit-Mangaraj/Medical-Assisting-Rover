# Medical Assisting Rover

Developed an autonomous medical assistance rover using ESP32, LoRa communication, RFID authentication, and sensor-based navigation. The rover utilized four 1000 RPM DC motors driven through an L298N motor driver for mobility and employed LoRa SX1278 modules for signal-strength-based navigation toward a predefined destination. A transmitter node continuously broadcasted LoRa signals, while the rover analyzed RSSI values to determine and adjust its movement direction.

For obstacle avoidance, an Arduino Uno-controlled ultrasonic sensor mounted on a servo motor scanned the surroundings and communicated obstacle data to the ESP32 main controller, enabling dynamic path correction. The system also integrated an RFID module for access control, allowing only authorized users to activate the rover. Upon reaching the destination, a YX100 pulse sensor measured the patient's pulse rate and displayed the readings on an OLED display.

**Key Features:**

* LoRa RSSI-based autonomous navigation and destination tracking.
* RFID-based secure access control.
* Ultrasonic sensor and servo-based obstacle detection and avoidance.
* Real-time pulse monitoring using YX100 sensor.
* OLED-based patient vital display.
* ESP32-Arduino distributed control architecture.

**Tech Stack:** ESP32, Arduino Uno, LoRa SX1278, RFID RC522, Ultrasonic Sensor, Servo Motor, L298N Motor Driver, OLED Display, YX100 Pulse Sensor, Embedded Systems, Wireless Communication, Autonomous Robotics.
