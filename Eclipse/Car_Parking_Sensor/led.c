/*
 * File: led.c
 * Author: Youssef Alaa
 */

#include "led.h"
#include "gpio.h"

void LED_initAll(void)
{
	GPIO_setupPinDirection(LED_PORT_RED, LED_PIN_RED, PIN_OUTPUT);
	GPIO_setupPinDirection(LED_PORT_GREEN, LED_PIN_GREEN, PIN_OUTPUT);
	GPIO_setupPinDirection(LED_PORT_BLUE, LED_PIN_BLUE, PIN_OUTPUT);

	GPIO_writePin(LED_PORT_RED, LED_PIN_RED, LED_STATE_OFF);
	GPIO_writePin(LED_PORT_GREEN, LED_PIN_GREEN, LED_STATE_OFF);
	GPIO_writePin(LED_PORT_BLUE, LED_PIN_BLUE, LED_STATE_OFF);
}

void LED_turnOn(LED_Color color)
{
	switch(color)
	{
	case LED_COLOR_RED:
		GPIO_writePin(LED_PORT_RED, LED_PIN_RED, LED_STATE_ON);
		break;
	case LED_COLOR_GREEN:
		GPIO_writePin(LED_PORT_GREEN, LED_PIN_GREEN, LED_STATE_ON);
		break;
	case LED_COLOR_BLUE:
		GPIO_writePin(LED_PORT_BLUE, LED_PIN_BLUE, LED_STATE_ON);
		break;
	}
}

void LED_turnOff(LED_Color color)
{
	switch(color)
	{
	case LED_COLOR_RED:
		GPIO_writePin(LED_PORT_RED, LED_PIN_RED, LED_STATE_OFF);
		break;
	case LED_COLOR_GREEN:
		GPIO_writePin(LED_PORT_GREEN, LED_PIN_GREEN, LED_STATE_OFF);
		break;
	case LED_COLOR_BLUE:
		GPIO_writePin(LED_PORT_BLUE, LED_PIN_BLUE, LED_STATE_OFF);
		break;
	}
}
