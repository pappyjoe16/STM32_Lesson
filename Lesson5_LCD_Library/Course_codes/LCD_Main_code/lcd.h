#ifndef LCD_H
#define LCD_H

#include "pinmap.h"

enum
{
	SLAVE_ADDRESS_LCD = 0x4E
	
};

class LCD
{
	private:
		I2C_HandleTypeDef hi2c;
			
	public:
		LCD(pinStruct_t& SCLpin, 
				pinStruct_t& SDApin, 
				uint32_t gpioAFSelI2Cx,
				I2C_TypeDef* I2Cx);

		void lcd_init (void);   // initialize lcd
		void lcd_send_cmd (char cmd);  // send command to the lcd
		void lcd_send_data (char data);  // send data to the lcd
		void lcd_send_string (char *str);  // send string to the lcd
		void lcd_clear (void); 
				
};

#endif //LCD_H
