/*
 * File: led.h
 * Author: Youssef Alaa
 */

#ifndef LED_H_
#define LED_H_

#include "std_types.h"

#define LED_PORT_RED    PORTC_ID
#define LED_PIN_RED     PIN0_ID

#define LED_PORT_GREEN  PORTC_ID
#define LED_PIN_GREEN   PIN1_ID

#define LED_PORT_BLUE   PORTC_ID
#define LED_PIN_BLUE    PIN2_ID

#define LED_STATE_ON    LOGIC_HIGH
#define LED_STATE_OFF   LOGIC_LOW

typedef enum
{
	LED_COLOR_RED,
	LED_COLOR_GREEN,
	LED_COLOR_BLUE
} LED_Color;

void LED_initAll(void);
void LED_turnOn(LED_Color color);
void LED_turnOff(LED_Color color);

#endif /* LED_H_ */
