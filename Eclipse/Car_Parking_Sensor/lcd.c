#include "lcd.h"
#include "gpio.h"
#include "common_macros.h"
#include <util/delay.h>
#include <stdlib.h>

void LCD_initialize(void)
{
	GPIO_setupPinDirection(LCD_RS_PORT, LCD_RS_PIN, PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_E_PORT, LCD_E_PIN, PIN_OUTPUT);

#if (LCD_MODE_BITS == 4)
	GPIO_setupPinDirection(LCD_DATA_PORT, LCD_PIN_DB4, PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT, LCD_PIN_DB5, PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT, LCD_PIN_DB6, PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT, LCD_PIN_DB7, PIN_OUTPUT);

	_delay_ms(20);
	LCD_sendCommand(LCD_CMD_INIT_4BIT_1);
	LCD_sendCommand(LCD_CMD_INIT_4BIT_2);
	LCD_sendCommand(LCD_CMD_2LINE_4BIT_MODE);
#elif (LCD_MODE_BITS == 8)
	GPIO_setupPortDirection(LCD_DATA_PORT, PORT_OUTPUT);
	LCD_sendCommand(LCD_CMD_2LINE_8BIT_MODE);
#endif

	LCD_sendCommand(LCD_CMD_CURSOR_OFF);
	LCD_sendCommand(LCD_CMD_CLEAR_SCREEN);
}

void LCD_sendCommand(uint8 cmd)
{
	GPIO_writePin(LCD_RS_PORT, LCD_RS_PIN, LOGIC_LOW);
	_delay_ms(1);
	GPIO_writePin(LCD_E_PORT, LCD_E_PIN, LOGIC_HIGH);
	_delay_ms(1);

#if (LCD_MODE_BITS == 4)
	GPIO_writePin(LCD_DATA_PORT, LCD_PIN_DB4, GET_BIT(cmd, 4));
	GPIO_writePin(LCD_DATA_PORT, LCD_PIN_DB5, GET_BIT(cmd, 5));
	GPIO_writePin(LCD_DATA_PORT, LCD_PIN_DB6, GET_BIT(cmd, 6));
	GPIO_writePin(LCD_DATA_PORT, LCD_PIN_DB7, GET_BIT(cmd, 7));
	_delay_ms(1);
	GPIO_writePin(LCD_E_PORT, LCD_E_PIN, LOGIC_LOW);
	_delay_ms(1);
	GPIO_writePin(LCD_E_PORT, LCD_E_PIN, LOGIC_HIGH);
	_delay_ms(1);
	GPIO_writePin(LCD_DATA_PORT, LCD_PIN_DB4, GET_BIT(cmd, 0));
	GPIO_writePin(LCD_DATA_PORT, LCD_PIN_DB5, GET_BIT(cmd, 1));
	GPIO_writePin(LCD_DATA_PORT, LCD_PIN_DB6, GET_BIT(cmd, 2));
	GPIO_writePin(LCD_DATA_PORT, LCD_PIN_DB7, GET_BIT(cmd, 3));
	_delay_ms(1);
	GPIO_writePin(LCD_E_PORT, LCD_E_PIN, LOGIC_LOW);
	_delay_ms(1);
#elif (LCD_MODE_BITS == 8)
	GPIO_writePort(LCD_DATA_PORT, cmd);
	_delay_ms(1);
	GPIO_writePin(LCD_E_PORT, LCD_E_PIN, LOGIC_LOW);
	_delay_ms(1);
#endif
}

void LCD_writeChar(uint8 data)
{
	GPIO_writePin(LCD_RS_PORT, LCD_RS_PIN, LOGIC_HIGH);
	_delay_ms(1);
	GPIO_writePin(LCD_E_PORT, LCD_E_PIN, LOGIC_HIGH);
	_delay_ms(1);

#if (LCD_MODE_BITS == 4)
	GPIO_writePin(LCD_DATA_PORT, LCD_PIN_DB4, GET_BIT(data, 4));
	GPIO_writePin(LCD_DATA_PORT, LCD_PIN_DB5, GET_BIT(data, 5));
	GPIO_writePin(LCD_DATA_PORT, LCD_PIN_DB6, GET_BIT(data, 6));
	GPIO_writePin(LCD_DATA_PORT, LCD_PIN_DB7, GET_BIT(data, 7));
	_delay_ms(1);
	GPIO_writePin(LCD_E_PORT, LCD_E_PIN, LOGIC_LOW);
	_delay_ms(1);
	GPIO_writePin(LCD_E_PORT, LCD_E_PIN, LOGIC_HIGH);
	_delay_ms(1);
	GPIO_writePin(LCD_DATA_PORT, LCD_PIN_DB4, GET_BIT(data, 0));
	GPIO_writePin(LCD_DATA_PORT, LCD_PIN_DB5, GET_BIT(data, 1));
	GPIO_writePin(LCD_DATA_PORT, LCD_PIN_DB6, GET_BIT(data, 2));
	GPIO_writePin(LCD_DATA_PORT, LCD_PIN_DB7, GET_BIT(data, 3));
	_delay_ms(1);
	GPIO_writePin(LCD_E_PORT, LCD_E_PIN, LOGIC_LOW);
	_delay_ms(1);
#elif (LCD_MODE_BITS == 8)
	GPIO_writePort(LCD_DATA_PORT, data);
	_delay_ms(1);
	GPIO_writePin(LCD_E_PORT, LCD_E_PIN, LOGIC_LOW);
	_delay_ms(1);
#endif
}

void LCD_writeString(const char *str)
{
	while (*str != '\0')
	{
		LCD_writeChar(*str);
		str++;
	}
}

void LCD_setCursor(uint8 row, uint8 col)
{
	uint8 address;
	switch (row)
	{
	case 0: address = col; break;
	case 1: address = col + 0x40; break;
	case 2: address = col + 0x10; break;
	case 3: address = col + 0x50; break;
	default: address = 0; break;
	}
	LCD_sendCommand(address | LCD_CMD_SET_CURSOR);
}

void LCD_displayNumber(uint16 number)
{
	char buffer[7];
	itoa(number, buffer, 10);
	LCD_writeString(buffer);
}

void LCD_clear(void)
{
	LCD_sendCommand(LCD_CMD_CLEAR_SCREEN);
}
#include "lcd.h"

void LCD_writeStringAt(uint8 row, uint8 col, const char *str)
{
	LCD_setCursor(row, col);     // Go to (row, col)
	LCD_writeString(str);        // Print string from that position
}
