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

	// Enable pull-up on all pins of port-A
	config[0] = 0x0C;
	config[1] = 0xFF;
	write(file, config, 2);
	printf("Pull-up enabled on all GPIO pins of Port-A \n");

	// Checking status of all GPIO pins of port-A
	char reg[1] = {0x12};
	write(file, reg, 1);
	char data[1] = {0};
	read(file, data, 1);
	char status = data[0];
	char data1 = 0x01;
	int i;
	for(i = 0; i < 8; i++)
	{
		char state = (status & data1);
		if(state == data1)
		{
			printf("GPIO pin %d of PORT A is HIGH \n", i);
		}
		else
		{
			printf("GPIO pin %d of PORT A is LOW \n", i);
		}
		data1 = (data1 << 1);
		sleep(1);
	}

	// Enable pull-up on all pins of port-B
	config[0] = 0x0D;
	config[1] = 0xFF;
	write(file, config, 2);
	printf("Pull-up enabled on all GPIO pins of Port-B \n");

	// Checking status of all GPIO pins of port-B
	reg[0] = 0x13;
	write(file, reg, 1);
	read(file, data, 1);
	status = data[0];
	char data2 = 0x01;
	for(i = 0; i < 8; i++)
	{
		char state = (status & data2);
		if(state == data2)
		{
			printf("GPIO pin %d of PORT B is HIGH \n", i);
		}
		else
		{
			printf("GPIO pin %d of PORT B is LOW \n", i);
		}
		data2 = (data2 << 1);
		sleep(1);
	}
}
