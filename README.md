# Medical-Assisting-Rover
This ESP32-based autonomous rover uses RFID for access, LoRa SX1278 for signal-based navigation, and LiDAR for obstacle avoidance. It checks patient vitals at the destination using sensors. In case of navigation failure, it can be manually controlled via the Dabble app. Designed for medical use in remote or constrained areas.
Start

The ESP32-powered rover is powered on and enters idle mode.

RFID Authentication

An RFID scanner reads an RFID tag.

If the tag matches a predefined ID, access is granted and the rover proceeds.

If authentication fails, access is denied and the system remains idle.

LoRa-Based Navigation Begins

A second ESP32 at the destination sends continuous LoRa signals.

The rover receives these signals and measures RSSI (Received Signal Strength Indicator) to determine direction.

Path Following

The rover moves forward when signal strength increases.

If RSSI decreases or becomes unstable, the rover adjusts its direction toward stronger signals.

Obstacle Detection via LiDAR

A LiDAR sensor mounted on a micro servo scans the path ahead.

If an obstacle is detected:

The servo rotates 90° right and then left.

The rover checks both sides for a clear path.

If the right is clear, the rover turns right; if not, it turns left.

If no obstacle is detected, the rover continues on the same path.

Arrival at Destination

The rover identifies destination proximity when RSSI reaches a preset threshold.

It stops and transitions into patient interaction mode.

Patient Vital Check

The rover activates sensors to measure vital signs (e.g., temperature, heart rate).

The results are displayed on a connected OLED display.

System Stop

After vitals are displayed, the rover stops all motors and enters standby or waits for further instruction.

Electronic Components:
ESP32 (×2)

One for LoRa transmission and RFID

One for motor control, LiDAR, and vital monitoring

LoRa SX1278 Modules (×2)

For long-range wireless navigation (transmitter & receiver)

RFID Module (RC522 or similar)

To scan RFID cards/tags for identity verification

RFID Tags/Cards

Used for authorized user identification

L298N Motor Driver

To control the speed and direction of Johnson motors

Johnson Motors (×4)

Drive the rover wheels; left and right side motors connected in parallel

LiDAR Sensor (e.g., TF Mini / VL53L0X)

For obstacle detection in front of the rover

Micro Servo Motor (e.g., SG90)

To rotate LiDAR sensor for left-right obstacle scanning

OLED Display (e.g., SSD1306)

To display patient vital readings and system messages

Vital Sign Sensors (optional, based on implementation)

Examples:

MLX90614 (non-contact temperature sensor)

MAX30100/MAX30102 (heart rate and SpO2)

Bluetooth Module (optional if ESP32 Bluetooth not used)

For manual override/control via Dabble app if needed

Power Supply/Battery Pack

7.4V Li-ion or LiPo battery pack to power the entire rover

🔌 Wires and Miscellaneous:
Jumper Wires (Male–Male, Male–Female)

Breadboard (for prototyping)

Switches (for manual reset/power)

Castor wheel (support wheel)

Chassis body (base frame for mounting components)

Antennas (for LoRa modules)
