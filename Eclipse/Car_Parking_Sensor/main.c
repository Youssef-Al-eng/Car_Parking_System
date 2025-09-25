/******************************************************************************
 *
 * Module: Main Application
 *
 * File Name: main.c
 *
 * Description: Main file for Car Parking System Application
 *
 * Author: Youssef Alaa
 *
 ******************************************************************************/

#include "lcd.h"
#include "ultrasonic.h"
#include "led.h"
#include "buzzer.h"
#include <util/delay.h>
#include <avr/io.h>
#include "interrupt.h"

int main(void)
{
	uint16 distance = 0;
	uint16 lastDistance = 0xFFFF; // Large initial value to ensure LCD updates first time

	LCD_initialize();
	LED_initAll();
	Buzzer_init();
	Ultrasonic_init();  // ✅ Corrected name to match ultrasonic.c

	LCD_writeStringAt(0, 0, "Distance =     cm");

	Enable_Global_Interrupt();

	while (1)
	{
		distance = Ultrasonic_readDistance();  // ✅ Matches the ultrasonic driver name

		/* Only update LCD if the distance changed significantly */
		if ((lastDistance == 0xFFFF) || ((distance > lastDistance) ? (distance - lastDistance) : (lastDistance - distance)) >= 2)
		{
			LCD_setCursor(0, 10);
			LCD_writeString("    ");  // Clear old value
			LCD_setCursor(0, 10);
			LCD_displayNumber(distance);
			lastDistance = distance;
		}

		/* Visual + Audio alerts based on distance */
		if (distance <= 5)
		{
			Buzzer_on();
			LCD_writeStringAt(1, 6, "STOP");
			LED_turnOn(LED_COLOR_RED);
			LED_turnOn(LED_COLOR_GREEN);
			LED_turnOn(LED_COLOR_BLUE);
			_delay_ms(300);
			LED_turnOff(LED_COLOR_RED);
			LED_turnOff(LED_COLOR_GREEN);
			LED_turnOff(LED_COLOR_BLUE);
		}
		else if (distance <= 10)
		{
			Buzzer_off();
			LCD_writeStringAt(1, 6, "    "); // Clear previous message
			LED_turnOn(LED_COLOR_RED);
			LED_turnOn(LED_COLOR_GREEN);
			LED_turnOn(LED_COLOR_BLUE);
		}
		else if (distance <= 15)
		{
			Buzzer_off();
			LCD_writeStringAt(1, 6, "    ");
			LED_turnOn(LED_COLOR_RED);
			LED_turnOn(LED_COLOR_GREEN);
			LED_turnOff(LED_COLOR_BLUE);
		}
		else if (distance <= 20)
		{
			Buzzer_off();
			LCD_writeStringAt(1, 6, "    ");
			LED_turnOn(LED_COLOR_RED);
			LED_turnOff(LED_COLOR_GREEN);
			LED_turnOff(LED_COLOR_BLUE);
		}
		else
		{
			Buzzer_off();
			LCD_writeStringAt(1, 6, "    ");
			LED_turnOff(LED_COLOR_RED);
			LED_turnOff(LED_COLOR_GREEN);
			LED_turnOff(LED_COLOR_BLUE);
		}

		_delay_ms(100);
	}
}
