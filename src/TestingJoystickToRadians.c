#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "HolonomicPolarJoystick.h";

task main()
{
	/*
	float rads = 0;
	float magnitude;
	float joy_x;
	float joy_y;
	float sum_joy;
	while(true)
	{
	clearLCDLine(0);
	clearLCDLine(1);
	joy_x = vexRT[Ch1];
	joy_y = vexRT[Ch2];
	if(abs(joy_x) < 20 && abs(joy_y) < 20) {
	rads = 0;
	magnitude = 0;
	}
	else {
	rads = atan2(joy_y,joy_x);
	sum_joy = (abs(joy_y) * abs(joy_y)) + (abs(joy_x) * abs(joy_x));
	magnitude = sqrt(sum_joy);
	magnitude = magnitude/127;
	if(magnitude > 1) magnitude = 1;
	}
	writeDebugStreamLine("gees: %f",radiansToDegrees(rads));
	writeDebugStream(" magn: %f", magnitude);
	displayLCDNumber(0,0,vexRT[Ch2]);
	displayLCDNumber(1,0,vexRT[Ch1]);
	wait1Msec(100);
	}
	*/
	PolarJoystick joy;
	while(true)
	{
		byte x_val = vexRT[Ch1];
		byte y_val = vexRT[Ch2];
		if((abs(x_val) < 20) && (abs(y_val) < 20)) {
			joy.radians = 0;
			joy.speed = 0;
		}
		else {
			joy.radians = atan2(y_val,x_val);
			float speed = sqrt((abs(y_val) * abs(y_val)) + (abs(x_val) * abs(x_val)));
			speed = speed/127;
			if(speed > 1) speed = 1;
			joy.speed = speed;
		}
		writeDebugStreamLine("gees: %f", radiansToDegrees(joy.radians));
		writeDebugStream(" speed: %f", joy.speed);
		wait1Msec(100);
	}
}