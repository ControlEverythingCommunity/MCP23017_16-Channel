// Distributed with a free-will license.
// Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
// MCP23017_I2CR16G5LE
// This code is designed to work with the MCP23017_I2CR16G5LE_10A I2C Mini Module available from ControlEverything.com.
// https://www.controleverything.com/content/Relay-Controller?sku=MCP23017_I2CR16G5LE_10A#tabs-0-product_tabset-2

import com.pi4j.io.i2c.I2CBus;
import com.pi4j.io.i2c.I2CDevice;
import com.pi4j.io.i2c.I2CFactory;
import java.io.IOException;

public class SAMPLE3
{
	public static void main(String args[]) throws Exception
	{
		// Create I2C bus
		I2CBus bus = I2CFactory.getInstance(I2CBus.BUS_1);
		// Get I2C device, MCP23017 I2C address is 0x20(32)
		I2CDevice device = bus.getDevice(0x20);
		
		// Configure all pins of port-A as input
		device.write(0x00, (byte)0xFF);
		// Configure all pins of port-B as input
		device.write(0x01, (byte)0xFF);
		Thread.sleep(500);
		
		// Enable pull-up on all pins of port-A
		device.write(0x0C, (byte)0xFF);
		System.out.printf("Pull-up enabled on all GPIO pins of Port-A %n");
		// Enable pull-up on all pins of port-B
		device.write(0x0D, (byte)0xFF);
		System.out.printf("Pull-up enabled on all GPIO pins of Port-B %n");
	}
}
