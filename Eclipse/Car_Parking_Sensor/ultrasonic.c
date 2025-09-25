/******************************************************************************
 *
 * Module: Ultrasonic Sensor
 *
 * File Name: ultrasonic.c
 *
 * Description: Source file for distance measurement using ICU and ultrasonic sensor.
 *
 * Author: Youssef Alaa
 *
 *******************************************************************************/

#include "ultrasonic.h"
#include "gpio.h"
#include "icu.h"
#include <util/delay.h>

/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/

static uint8 g_edgeCount = 0;
static uint16 g_risingEdgeTime = 0;
static uint16 g_fallingEdgeTime = 0;

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void Ultrasonic_init(void)
{
	ICU_ConfigType config = {F_CPU_8, RAISING};
	ICU_init(&config);

	ICU_setCallBack(Ultrasonic_edgeProcessing);

	GPIO_setupPinDirection(ULTRASONIC_TRIGGER_PORT_ID, ULTRASONIC_TRIGGER_PIN_ID, PIN_OUTPUT);
	GPIO_writePin(ULTRASONIC_TRIGGER_PORT_ID, ULTRASONIC_TRIGGER_PIN_ID, LOGIC_LOW); // ensure trigger low at start
}

void Ultrasonic_trigger(void)
{
	GPIO_writePin(ULTRASONIC_TRIGGER_PORT_ID, ULTRASONIC_TRIGGER_PIN_ID, LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(ULTRASONIC_TRIGGER_PORT_ID, ULTRASONIC_TRIGGER_PIN_ID, LOGIC_LOW);
}

uint16 Ultrasonic_readDistance(void)
{
	Ultrasonic_trigger();

	while (g_edgeCount < 2); // wait for both edges to be captured

	g_edgeCount = 0;

	uint16 timeDifference = g_fallingEdgeTime - g_risingEdgeTime;
	uint16 distance = timeDifference / 58;  // Convert to cm (for 8MHz, prescaler 8)

	return distance;
}

void Ultrasonic_edgeProcessing(void)
{
	if (g_edgeCount == 0)
	{
		g_risingEdgeTime = ICU_getInputCaptureValue();
		ICU_setEdgeDetectionType(FALLING);
		g_edgeCount = 1;
	}
	else if (g_edgeCount == 1)
	{
		g_fallingEdgeTime = ICU_getInputCaptureValue();
		ICU_clearTimerValue();
		ICU_setEdgeDetectionType(RAISING);
		g_edgeCount = 2;
	}
}
