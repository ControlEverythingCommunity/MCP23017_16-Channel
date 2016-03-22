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
#		0x00(00)	All pins of port-A are configured as output
bus.write_byte_data(0x20, 0x00, 0x00)
# MCP23017 address, 0x20(32)
# Select IODIRB register, 0x01(01)
#		0x00(00)	All pins of port-B are configured as output
bus.write_byte_data(0x20, 0x01, 0x00)

time.sleep(0.5)

# MCP23017 address, 0x20(32)
# Select GPIOA register, 0x12(18)
#		0xFF(255)   All pins of port-A are set to logic HIGH
bus.write_byte_data(0x20, 0x12, 0xFF)
print "Turning all Relays of Port-A ON"

# MCP23017 address, 0x20(32)
# Select GPIOB register, 0x13(19)
#		0xFF(255)	All pins of port-B are set to logic HIGH
bus.write_byte_data(0x20, 0x13, 0xFF)
print "Turning all Relays of Port-B ON"
