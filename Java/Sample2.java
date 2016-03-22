// Distributed with a free-will license.
// Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
// MCP23017_I2CR16G5LE
// This code is designed to work with the MCP23017_I2CR16G5LE_10A I2C Mini Module available from ControlEverything.com.
// https://www.controleverything.com/content/Relay-Controller?sku=MCP23017_I2CR16G5LE_10A#tabs-0-product_tabset-2

import com.pi4j.io.i2c.I2CBus;
import com.pi4j.io.i2c.I2CDevice;
import com.pi4j.io.i2c.I2CFactory;
import java.io.IOException;

public class SAMPLE2
{
	public static void main(String args[]) throws Exception
	{
		// Create I2C bus
		I2CBus bus = I2CFactory.getInstance(I2CBus.BUS_1);
		// Get I2C device, MCP23017 I2C address is 0x20(32)
		I2CDevice device = bus.getDevice(0x20);
		
		// Configure all pins of port-A as output
		device.write(0x00, (byte)0x00);
		// Configure all pins of port-B as output
		device.write(0x01, (byte)0x00);
		
		// Turn all relays ON, one by one
		// Set all pins of port-A to logic HIGH
		data = (byte)0x01;
		for (int i = 0; i < 8; i++)
		{
			device.write(0x12, (byte)data);
			System.out.prinf("Turning Relay %d of Port-A ON%n" ,i);
			data = (byte)(data << 1);
			data += 1;
			Thread.sleep(1000);
		}
		
		// Set all pins of port-B to logic HIGH
		data = (byte)0x01;
		for (int i = 0; i < 8; i++)
		{
			device.write(0x13, (byte)data);
			System.out.prinf("Turning Relay %d of Port-B ON%n" ,i);
			data = (byte)(data << 1);
			data += 1;
			Thread.sleep(1000);
		}
		
		// Turn all relays OFF, one by one
		// Set all pins of port-A to logic LOW
		data = (byte)0xFE;
		for (int i = 0; i < 8; i++)
		{
			device.write(0x12, (byte)data);
			System.out.prinf("Turning Relay %d of Port-A OFF%n" ,i);
			data = (byte)(data << 1);
			Thread.sleep(1000);
		}
		
		// Set all pins of port-A to logic LOW
		data = (byte)0xFE;
		for (int i = 0; i < 8; i++)
		{
			device.write(0x13, (byte)data);
			System.out.prinf("Turning Relay %d of Port-B OFF%n" ,i);
			data = (byte)(data << 1);
			Thread.sleep(1000);
		}
	}
}
