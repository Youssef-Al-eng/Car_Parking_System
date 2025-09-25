#ifndef LCD_H_
#define LCD_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define LCD_MODE_BITS 4

#if ((LCD_MODE_BITS != 4) && (LCD_MODE_BITS != 8))
#error "LCD mode must be 4 or 8 bits"
#endif

#define LCD_RS_PORT          PORTA_ID
#define LCD_RS_PIN           PIN1_ID

#define LCD_E_PORT           PORTA_ID
#define LCD_E_PIN            PIN2_ID

#define LCD_DATA_PORT        PORTA_ID

#if (LCD_MODE_BITS == 4)
#define LCD_PIN_DB4          PIN3_ID
#define LCD_PIN_DB5          PIN4_ID
#define LCD_PIN_DB6          PIN5_ID
#define LCD_PIN_DB7          PIN6_ID
#endif

#define LCD_CMD_CLEAR_SCREEN           0x01
#define LCD_CMD_RETURN_HOME            0x02
#define LCD_CMD_2LINE_8BIT_MODE        0x38
#define LCD_CMD_2LINE_4BIT_MODE        0x28
#define LCD_CMD_INIT_4BIT_1            0x33
#define LCD_CMD_INIT_4BIT_2            0x32
#define LCD_CMD_CURSOR_OFF             0x0C
#define LCD_CMD_CURSOR_ON              0x0E
#define LCD_CMD_SET_CURSOR             0x80

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void LCD_writeStringAt(uint8 row, uint8 col, const char *str);

void LCD_initialize(void);
void LCD_sendCommand(uint8 cmd);
void LCD_writeChar(uint8 data);
void LCD_writeString(const char *str);
void LCD_setCursor(uint8 row, uint8 col);
void LCD_displayNumber(uint16 number);
void LCD_clear(void);
void LCD_writeStringAt(uint8 row, uint8 col, const char *str);
void LCD_displayNumber(uint16 num);

#endif /* LCD_H_ */
