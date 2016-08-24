# Distributed with a free-will license.
# Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
# MCP23017_I2CR16G5LE
# This code is designed to work with the MCP23017_I2CR16G5LE_10A I2C Mini Module available from ControlEverything.com.
# https://www.controleverything.com/content/Relay-Controller?sku=MCP23017_I2CR16G5LE_10A#tabs-0-product_tabset-2

from OmegaExpansion import onionI2C
import time

# Get I2C bus
i2c = onionI2C.OnionI2C()

# MCP23017 address, 0x20(32)
# Select IODIRA register, 0x00(00)
#		0xFF(255)	All pins are configured as input
i2c.writeByte(0x20,0x00,0xFF)
# MCP23017 address, 0x20(32)
# Select IODIRB register, 0x01(01)
#		0xFF(255)	All pins are configured as input
i2c.writeByte(0x20,0x01,0xFF)

# MCP23017 address, 0x20(32)
# Select GPPUA register, 0x0C(12)
#		0xFF(255)	Pull-up enabled on all pins of Port-A
i2c.writeByte(0x20, 0x0C, 0xFF)
print "Pull-up enabled on all GPIO pins of Port-A"

# Checking status of all GPIO pins of port-A
status = i2c.readBytes(0x20, 0x12, 1)
data = 0x01
for MyData in range(0, 8):
	state = status[0] & data
	if state == data:
		print "GPIO Pin %d of Port-A is High" %MyData
	else:
		print "GPIO Pin %d of Port-A is Low" %MyData
	data = data << 1
	time.sleep(0.5)

# MCP23017 address, 0x20(32)
# Select GPPUB register, 0x0D(13)
#		0xFF(255)	Pull-up enabled on all pins of Port-B
i2c.writeByte(0x20, 0x0D, 0xFF)
print "Pull-up enabled on all pins of Port-B"

# Checking status of all GPIO pins of port-B
status = bus.readBytes(0x20, 0x13, 1)
data = 0x01
for MyData in range(0,8):
	state = status[0] & data
	if state == data:
		print "GPIO Pin %d of Port-B is High" %MyData
	else:
		print "GPIO Pin %d of Port-B is Low" %MyData
	data = data << 1
	time.sleep(0.5)
