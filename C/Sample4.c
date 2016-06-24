// Distributed with a free-will license.
// Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
// MCP23017_I2CR16G5LE
// This code is designed to work with the MCP23017_I2CR16G5LE_10A I2C Mini Module available from ControlEverything.com.
// https://www.controleverything.com/content/Relay-Controller?sku=MCP23017_I2CR16G5LE_10A#tabs-0-product_tabset-2

#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>

void main()
{
	// Create I2C bus
	int file;
	char *bus = "/dev/i2c-1";
	if ((file = open(bus, O_RDWR)) < 0) 
	{
		printf("Failed to open the bus. \n");
		exit(1);
	}
	// Get I2C device, MCP23017 I2C address is 0x20(32)
	ioctl(file, I2C_SLAVE, 0x20);

	// // Configure all pins of port-A as input(0xFF)
	char config[2] = {0};
	config[0] = 0x00;
	config[1] = 0xFF;
	write(file, config, 2);
	// Configure all pins of port-B as input(0xFF)
	config[0] = 0x01;
	config[1] = 0xFF;
	write(file, config, 2);
	sleep(1);

	// Enable pull-up on all pins, one bye one
	// Enable pull-up on all pins of port-A
	char data = 0x01;
	int i;
	for(i = 0; i < 8; i++)
	{
		config[0] = 0x12;
		config[1] = data;
		write(file, config, 2);
		printf("Enabling Pull-up on GPIO pin %d of Port-A \n", i);
		data = (data << 1);
		data += 1;
		sleep(1);
	}

	// Enable pull-up on all pins of port-B
	data = 0x01;
	for(i = 0; i < 8; i++)
	{
		config[0] = 0x13;
		config[1] = data;
		write(file, config, 2);
		printf("Enabling Pull-up on GPIO pin %d of Port-B \n", i);
		data = (data << 1);
		data += 1;
		sleep(1);
	}

	// Disable pull-up on all pins, one bye one
	// Disable pull-up on all pins of port-A
	data = 0xFE;
	for(i = 0; i < 8; i++)
	{
		config[0] = 0x12;
		config[1] = data;
		write(file, config, 2);
		printf("Disabling Pull-up on GPIO pin %d of Port-A \n" ,i);
		data = (data << 1);
		sleep(1);
	}

	// Disable pull-up on all pins of port-B
	data = 0xFE;
	for(i = 0; i < 8; i++)
	{
		config[0] = 0x13;
		config[1] = data;
		write(file, config, 2);
		printf("Disabling Pull-up on GPIO pin %d of Port-B \n" ,i);
		data = (data << 1);
		sleep(1);
	}
}
