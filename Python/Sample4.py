# Distributed with a free-will license.
# Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
# MCP23017_I2CR16G5LE
# This code is designed to work with the MCP23017_I2CR16G5LE_10A I2C Mini Module available from ControlEverything.com.
# https://www.controleverything.com/content/Relay-Controller?sku=MCP23017_I2CR16G5LE_10A#tabs-0-product_tabset-2

import smbus
import time

# Get I2C bus
bus = smbus.SMBus(1)

# MCP23017 address, 0x20(32)
# Select IODIRA register, 0x00(00)
#		0xFF(255)	All pins are configured as input
bus.write_byte_data(0x20,0x00,0xFF)
# MCP23017 address, 0x20(32)
# Select IODIRB register, 0x01(01)
#		0xFF(255)	All pins are configured as input
bus.write_byte_data(0x20,0x01,0xFF)

# Enable pull-up on all pins, one bye one
# MCP23017 address, 0x20(32)
# Select GPPUA register, 0x0C(12), Enable pull-up on all pins of port-A
data = 0x01
for MyData in range(0,8):
	bus.write_byte_data(0x20,0x0C,data)
	print "Enabling Pull-up on GPIO pin %d of Port-A" %MyData
	data = data << 1
	data = data + 1
	time.sleep(0.5)

# MCP23017 address, 0x20(32)
# Select GPPUB register, 0x0D(13), Enable pull-up on all pins of port-B
data = 0x01
for MyData in range(0,8):
	bus.write_byte_data(0x20,0x0D,data)
	print "Enabling Pull-up on GPIO pin %d of Port-B" %MyData
	data = data << 1
	data = data + 1
	time.sleep(0.5)	

# MCP23017 address, 0x20(32)
# Select GPPUA register, 0x0C(12), Disable pull-up on all pins of port-A
data = 0xFE
for MyData in range(0,8):
	bus.write_byte_data(0x20,0x0C,data)
	print "Disabling Pull-up on GPIO pin %d of Port-A" %MyData
	data = data << 1
	time.sleep(0.5)

# MCP23017 address, 0x20(32)
# Select GPPUB register, 0x0D(13), Disable pull-up on all pins of port-B
data = 0xFE
for MyData in range(0,8):
	bus.write_byte_data(0x20,0x0D,data)
	print "Disabling Pull-up on GPIO pin %d of Port-B" %MyData
	data = data << 1
	time.sleep(0.5)
