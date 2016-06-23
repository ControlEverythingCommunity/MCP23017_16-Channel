// Distributed with a free-will license.
// Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
// MCP23017_I2CR16G5LE
// This code is designed to work with the MCP23017_I2CR16G5LE_10A I2C Mini Module available from ControlEverything.com.
// https://www.controleverything.com/content/Relay-Controller?sku=MCP23017_I2CR16G5LE_10A#tabs-0-product_tabset-2

#include <Wire.h>

// MCP23017_I2CR16G5LE I2C address is 0x20(32)
#define Addr 0x20

int data;
void setup()
{
  // Initialise I2C communication as MASTER
  Wire.begin();
  // Initialise serial communication, set baud rate = 9600
  Serial.begin(9600);

  // Start I2C Transmission
  Wire.beginTransmission(Addr);
  // Select IODIRA register
  Wire.write(0x00);
  // All pins are configured as input
  Wire.write(0xFF);
  // Stop I2C transmission
  Wire.endTransmission();

  // Start I2C Transmission
  Wire.beginTransmission(Addr);
  // Select IODIRB register
  Wire.write(0x01);
  // All pins are configured as input
  Wire.write(0xFF);
  // Stop I2C transmission
  Wire.endTransmission();
  delay(500);
}

void loop()
{
  // Enable pull-up on all pins, one bye one
  data = 0x01;
  for (int i = 0; i < 8; i++)
  {
    // Start I2C Transmission
    Wire.beginTransmission(Addr);
    // Select GPPUA register
    Wire.write(0x0C);
    // Enable pull-up on all pins of port-A
    Wire.write(data);
    // Stop I2C transmission
    Wire.endTransmission();

    // Output data to serial monitor
    Serial.print("Enabling Pull-up on GPIO pin ");
    Serial.print(i);
    Serial.println(" of Port-A");
    data = data << 1;
    data = data + 1;
    delay(500);
  }

  data = 0x01;
  for (int i = 0; i < 8; i++)
  {
    // Start I2C Transmission
    Wire.beginTransmission(Addr);
    // Select GPPUB register
    Wire.write(0x0D);
    // Enable pull-up on all pins of port-B
    Wire.write(data);
    // Stop I2C transmission
    Wire.endTransmission();

    // Output data to serial monitor
    Serial.print("Enabling Pull-up on GPIO pin ");
    Serial.print(i);
    Serial.println(" of Port-B");
    data = data << 1;
    data = data + 1;
    delay(500);
  }

  // Disable pull-up on all pins, one bye one
  data = 0xFE;
  for (int i = 0; i < 8; i++)
  {
    // Start I2C Transmission
    Wire.beginTransmission(Addr);
    // Select GPPUA register
    Wire.write(0x0C);
    // Disable pull-up on all pins of port-A
    Wire.write(data);
    // Stop I2C transmission
    Wire.endTransmission();

    // Output data to serial monitor
    Serial.print("Disabling Pull-up on GPIO pin ");
    Serial.print(i);
    Serial.println(" of Port-A");
    data = data << 1;
    delay(500);
  }

  data = 0xFE;
  for (int i = 0; i < 8; i++)
  {
    // Start I2C Transmission
    Wire.beginTransmission(Addr);
    // Select GPPUB register
    Wire.write(0x0D);
    // Disable pull-up on all pins of port-B
    Wire.write(data);
    // Stop I2C transmission
    Wire.endTransmission();

    // Output data to serial monitor
    Serial.print("Disabling Pull-up on GPIO pin ");
    Serial.print(i);
    Serial.println(" of Port-B");
    data = data << 1;
    delay(500);
  }
}
