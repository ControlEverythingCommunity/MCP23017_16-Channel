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
#		0xFF(255)	All pins of port-A are configured as input
bus.write_byte_data(0x20, 0x00, 0xFF)
# MCP23017 address, 0x20(32)
# Select IODIRB register, 0x01(01)
#		0xFF(255)	All pins of port-B are configured as input
bus.write_byte_data(0x20, 0x01, 0x255)

time.sleep(0.5)

# MCP23017 address, 0x20(32)
# Select GPPUA register, 0x0C(12)
#		0xFF(255)	Pull-up enabled on all pins of port-A
bus.write_byte_data(0x20, 0x0C, 0xFF)
print "Pull-up enabled on all GPIO pins of Port-A"

# MCP23017 address, 0x20(32)
# Select GPPUB register, 0x0D(13)
#		0xFF(255)	Pull-up enabled on all pins of port-B
bus.write_byte_data(0x20, 0x0D, 0xFF)
print "Pull-up enabled on all GPIO pins of Port-B"
