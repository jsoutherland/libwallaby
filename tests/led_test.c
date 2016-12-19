/*
 * led_test.c
 *
 *  Created on: Nov 2, 2015
 *      Author: Joshua Southerland
 */

#include <stdio.h>

#include "wallaby/wallaby.h"

int main(int argc, char ** argv)
{
	printf("set_digital_output(12,1);\n");
	set_digital_output(12, 1);
	msleep(250);

	//while(1)
	//{

		msleep(250);
		printf("set_digital_value(12,1);\n");
		set_digital_value(12,1);

		msleep(250);
		printf("set_digital_value(12,0);\n");
		set_digital_value(12,0);
	//}

	return 0;
}
