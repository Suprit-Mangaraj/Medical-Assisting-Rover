#include <DabbleESP32.h> 
#include <driver/ledc.h> // Include the ESP32 LEDC driver for PWM

// Motor control pins
#define r_pwm 12
#define l_pwm 33
#define RF 14
#define LF 27
#define RB 26
#define LB 25

// Variables for motor speed
int speed = 150;

// Movement functions
void moveForward() {
  digitalWrite(RF, HIGH);
  digitalWrite(LB, LOW);
  digitalWrite(LF, HIGH);
  digitalWrite(RB, LOW);
  ledcWrite(0, speed);
  ledcWrite(1, speed);
}

void moveBackward() {
  digitalWrite(RF, LOW);
  digitalWrite(LB, HIGH);
  digitalWrite(LF, LOW);
  digitalWrite(RB, HIGH);
  ledcWrite(0, speed);
  ledcWrite(1, speed);
}

void turnLeft() {
  digitalWrite(RF, LOW);
  digitalWrite(LB, LOW);
  digitalWrite(LF, HIGH);
  digitalWrite(RB, LOW);
  ledcWrite(0, speed / 2);
  ledcWrite(1, speed);
}

void turnRight() {
  digitalWrite(RF, HIGH);
  digitalWrite(LB, LOW);
  digitalWrite(LF, LOW);
  digitalWrite(RB, LOW);
  ledcWrite(0, speed);
  ledcWrite(1, speed / 2);
}

// Gradual stop function
void gradualStop() {
  for (int i = speed; i >= 0; i -= 5) {
    ledcWrite(0, i);
    ledcWrite(1, i);
    delay(50);  // Gradual slowdown
  }
  digitalWrite(RF, LOW);
  digitalWrite(LB, LOW);
  digitalWrite(LF, LOW);
  digitalWrite(RB, LOW);
}

// Function to stop the car immediately
void stopCar() {
  digitalWrite(RF, LOW);
  digitalWrite(LB, LOW);
  digitalWrite(LF, LOW);
  digitalWrite(RB, LOW);
  ledcWrite(0, 0);
  ledcWrite(1, 0);
}

// Setup function
void setup() {
  Serial.begin(115200);
  Dabble.begin("ESP32_RC_Car");  // Initialize Dabble with a Bluetooth name

  // Motor control pin setup
  pinMode(RF, OUTPUT);
  pinMode(LF, OUTPUT);
  pinMode(LB, OUTPUT);
  pinMode(RB, OUTPUT);
  digitalWrite(RF, LOW);
  digitalWrite(LB, LOW);
  digitalWrite(LF, LOW);
  digitalWrite(RB, LOW);

  // Set PWM pins for motor speed control
  ledcSetup(0, 5000, 8);  // Set PWM channel 0, 5kHz frequency, 8-bit resolution
  ledcSetup(1, 5000, 8);  // Set PWM channel 1, 5kHz frequency, 8-bit resolution
  ledcAttachPin(r_pwm, 0);  // Attach the r_pwm pin to PWM channel 0
  ledcAttachPin(l_pwm, 1);  // Attach the l_pwm pin to PWM channel 1
}

// Main loop
void loop() {
  Dabble.processInput();  // Process input from the Dabble app

  // Check for control inputs
  if (GamePad.isUpPressed()) {
    moveForward();
  }
  else if (GamePad.isDownPressed()) {
    moveBackward();
  }
  else if (GamePad.isLeftPressed()) {
    turnLeft();
  }
  else if (GamePad.isRightPressed()) {
    turnRight();
  }
  else if (GamePad.isSquarePressed()) {
    // Use either gradual or immediate stop
    // gradualStop();
    stopCar();
  }
  else if (!GamePad.isUpPressed() && !GamePad.isDownPressed() && 
          !GamePad.isLeftPressed() && !GamePad.isRightPressed()) {
    // Auto-stop when no direction buttons are pressed
    stopCar();
  }

  // Speed control
  if (GamePad.isTrianglePressed()) {
    speed = min(speed + 10, 255);  // Increase speed
    Serial.print("Speed increased to: ");
    Serial.println(speed);
  } 
  else if (GamePad.isCirclePressed()) {
    speed = max(speed - 10, 0);  // Decrease speed
    Serial.print("Speed decreased to: ");
    Serial.println(speed);
  }
}