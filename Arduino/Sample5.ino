// Distributed with a free-will license.
// Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
// MCP23017_I2CR16G5LE
// This code is designed to work with the MCP23017_I2CR16G5LE_10A I2C Mini Module available from ControlEverything.com.
// https://www.controleverything.com/content/Relay-Controller?sku=MCP23017_I2CR16G5LE_10A#tabs-0-product_tabset-2

#include <Wire.h>

// MCP23017_I2CR16G5LE I2C address is 0x20(32)
#define Addr 0x20

int value, status, state;
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
  unsigned int data[0];

  // Start I2C Transmission
  Wire.beginTransmission(Addr);
  // Select GPPUA register
  Wire.write(0x0C);
  // Enable pull-up on all pins of port-A
  Wire.write(0xFF);
  // Stop I2C transmission
  Wire.endTransmission();
  Serial.println("Pull-up enabled on all GPIO pins of Port-A");

  // Checking status of all GPIO pins of port-A
  // Start I2C Transmission
  Wire.beginTransmission(Addr);
  // Select GPIOA register
  Wire.write(0x12);
  // Stop I2C transmission
  Wire.endTransmission();

  // Request 1 byte of data
  Wire.requestFrom(Addr, 1);

  // Read 1 byte of data
  if (Wire.available() == 1)
  {
    data[0] = Wire.read();
  }
  status = data[0];
  
  value = 0x01;
  for (int i = 0; i < 8; i++)
  {
    state = (status & value);
    if (state == value)
    {
      Serial.print("GPIO Pin ");
      Serial.print(i);
      Serial.println(" of Port-A is High");
    }
    else
    {
      Serial.print("GPIO Pin ");
      Serial.print(i);
      Serial.println(" of Port-A is Low");
    }
    value = value << 1;
    delay(500);
  }

  // Start I2C Transmission
  Wire.beginTransmission(Addr);
  // Select GPPUB register
  Wire.write(0x0D);
  // Enable pull-up on all pins of port-B
  Wire.write(0xFF);
  // Stop I2C transmission
  Wire.endTransmission();
  Serial.println("Pull-up enabled on all GPIO pins of Port-B");

  // Checking status of all GPIO pins of port-B
  // Start I2C Transmission
  Wire.beginTransmission(Addr);
  // Select GPIOB register
  Wire.write(0x13);
  // Stop I2C transmission
  Wire.endTransmission();

  // Request 1 byte of data
  Wire.requestFrom(Addr, 1);

  // Read 1 byte of data
  if (Wire.available() == 1)
  {
    data[0] = Wire.read();
  }
  status = data[0];
  
  value = 0x01;
  for (int i = 0; i < 8; i++)
  {
    state = (status & value);
    if (state == value)
    {
      Serial.print("GPIO Pin ");
      Serial.print(i);
      Serial.println(" of Port-B is High");
    }
    else
    {
      Serial.print("GPIO Pin ");
      Serial.print(i);
      Serial.println(" of Port-B is Low");
    }
    value = value << 1;
    delay(500);
  }
}
