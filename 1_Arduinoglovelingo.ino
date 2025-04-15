#include <Wire.h>
#include <SoftwareSerial.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

// Define Bluetooth pins
#define TxD 2  // Bluetooth TX pin
#define RxD 3  // Bluetooth RX pin

SoftwareSerial BTSerial(RxD, TxD); // Bluetooth communication

Adafruit_MPU6050 mpu;

// Flex sensor pins
const int flexPin[] = {A0, A1, A2, A3, A4};  // Flex sensor analog pins
int flexValues[5];  // Array to hold flex sensor values

void setup() {
  // Initialize Serial Communication
  Serial.begin(9600);
  BTSerial.begin(9600);  // Bluetooth communication
#include <Wire.h>
#include <SoftwareSerial.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

// Define Bluetooth pins
#define TxD 2  // Bluetooth TX pin
#define RxD 3  // Bluetooth RX pin

SoftwareSerial BTSerial(RxD, TxD); // Bluetooth communication

Adafruit_MPU6050 mpu;

// Flex sensor pins
const int flexPin[] = {A0, A1, A2, A3, A4};  // Flex sensor analog pins
int flexValues[5];  // Array to hold flex sensor values

void setup() {
  // Initialize Serial Communication
  Serial.begin(9600);
  BTSerial.begin(9600);  // Bluetooth communication

 // Initialize MPU6050 sensor
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 sensor");
    while (1);
  }

  Serial.println("MPU6050 initialized!");
  
  // Initialize flex sensors (analog readings)
  for (int i = 0; i < 5; i++) {
    pinMode(flexPin[i], INPUT);
  }

  delay(500);
}

void loop() {
  // Variables to hold accelerometer data
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp); // Get accelerometer data

  // Read flex sensor values
  for (int i = 0; i < 5; i++) {
    flexValues[i] = analogRead(flexPin[i]);
  }

 // Combine flex and accelerometer data to detect gestures
  String gesture = detectGesture(a, flexValues);


