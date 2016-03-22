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
#		0x00(00)	All pins of Port-A are configured as output
bus.write_byte_data(0x20, 0x00, 0x00)
# MCP23017 address, 0x20(32)
# Select IODIRB register, 0x01(01)
#		0x00(00)	All pins of Port-B are configured as output
bus.write_byte_data(0x20, 0x01, 0x00)

# Turning all relays ON, one by one
# MCP23017 address, 0x20(32)
# Select GPIOA register, 0x12(18), All pins logic HIGH
data = 0x01
for MyData in range(0,8):
	bus.write_byte_data(0x20,0x12,data)
	print "Turning Relay %d of Port-A ON" %MyData
	data = data << 1
	data = data + 1
	time.sleep(0.5)

# MCP23017 address, 0x20(32)
# Select GPIOB register, 0x13(19), All pins logic HIGH
data = 0x01
for MyData in range(0,8):
	bus.write_byte_data(0x20,0x13,data)
	print "Turning Relay %d of Port-B ON" %MyData
	data = data << 1
	data = data + 1
	time.sleep(0.5)

# Turning all relays OFF, one by one
# MCP23017 address, 0x20(32)
# Select GPIOA register, 0x12(12), All pins logic LOW
data = 0xFE
for MyData in range(0,8):
	bus.write_byte_data(0x20,0x12,data)
	print "Turning Relay %d of Port-A OFF" %MyData
	data = data << 1
	time.sleep(0.5)

# MCP23017 address, 0x20(32)
# Select GPIOB register, 0x13(13), All pins logic LOW
data = 0xFE
for MyData in range(0,8):
	bus.write_byte_data(0x20,0x13,data)
	print "Turning Relay %d of Port-A OFF" %MyData
	data = data << 1
	time.sleep(0.5)
