#include "lcd.h"
#include "blinky_bluetooth.h"
#include "hc05.h"

char bluetoothData[1];

int main(void)
{
	HAL_Init();
	__HAL_RCC_GPIOA_CLK_ENABLE();  // Enable the HAL_GPIO clock (This is are macros)
	__HAL_RCC_USART1_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_I2C1_CLK_ENABLE();
	
	pinStruct_t SCLpin = {GPIOB,GPIO_PIN_8};
	pinStruct_t SDApin = {GPIOB,GPIO_PIN_7};
	pinStruct_t uartRxPin = {GPIOA,GPIO_PIN_10};
	pinStruct_t ledPin = {GPIOA,GPIO_PIN_6};
	
	static LCD i2c(SCLpin, SDApin, GPIO_AF4_I2C1, I2C1);     // this is a servo object
	static HC05 hc05(uartRxPin,USART1,9600,GPIO_AF7_USART1,UART_MODE_RX);     // this is a servo object  
	static BLINKY blinky_bluetooth(ledPin);
	
  i2c.lcd_init();

	char welcomeString1[] = "Hello, World";
	char welcomeString2[] = "LCD 20x4 DEMO";
	char welcomeString3[] = "BY";
	char welcomeString4[] = "GBTech world";
	   
  i2c.lcd_send_cmd (0x80|0x04);   // Set cursor using DDRAM Address
	i2c.lcd_send_string(welcomeString1);

  i2c.lcd_send_cmd (0x80|0x43);   // Set cursor using DDRAM Address
  i2c.lcd_send_string(welcomeString2);

  i2c.lcd_send_cmd (0x80|0x1C);   // Set cursor using DDRAM Address
  i2c.lcd_send_string(welcomeString3);

  i2c.lcd_send_cmd (0x80|0x58);   // Set cursor using DDRAM Address
  i2c.lcd_send_string(welcomeString4);
	HAL_Delay(5000);
	i2c.lcd_clear();
	
	while(1)
	{
		char caseString1[] = "Command S/s received";
		char caseString2[] = "Command M/m received";
		char caseString3[] = "Command L/l received";
		char caseString01[] = "DEMO Designed";
		char caseString02[] = "BY";
		char caseString03[] = "GBTech World";
		char myString[] = "Waiting for Command!";
		
		i2c.lcd_send_cmd (0x80|0x00);
	  i2c.lcd_send_string(myString);
		
		i2c.lcd_send_cmd (0x80|0x43);
		i2c.lcd_send_string(caseString01);

		i2c.lcd_send_cmd (0x80|0x1C);
		i2c.lcd_send_string(caseString02);
		
		i2c.lcd_send_cmd (0x80|0x58);
		i2c.lcd_send_string(caseString03);
		HAL_Delay(350);
		
		bluetoothData[0] = hc05.GetChar();
		
		/*
		 for (int i=0; i<5; i++)
	  {
		  i2c.lcd_send_cmd (0x1C);  // display shift right
		  HAL_Delay(350);
	  }

	  for (int i=0; i<5; i++)
	  {
		  i2c.lcd_send_cmd (0x18);  // display shift left
		  HAL_Delay(350);
	  }
		*/
		switch (bluetoothData[0]){
			case 's':
			case 'S':
				//servo.TurnShaft(SERVO_LEFTPOSITION);
				i2c.lcd_clear();
		    i2c.lcd_send_cmd (0x80|0x00);
				i2c.lcd_send_string(caseString1);
				HAL_Delay(1000);
				blinky_bluetooth.Blink(200);
				i2c.lcd_clear();
				break;
			case 'm':
			case 'M':
					//servo.TurnShaft(SERVO_MIDPOSITION);
				i2c.lcd_clear();
				i2c.lcd_send_cmd (0x80|0x00);
				i2c.lcd_send_string(caseString2);
				HAL_Delay(1000);
				blinky_bluetooth.Blink(600);
				i2c.lcd_clear();
				break;
			case 'l':
			case 'L':
				i2c.lcd_clear();
				i2c.lcd_send_cmd (0x80|0x00);
				i2c.lcd_send_string(caseString3);
				HAL_Delay(2000);
				blinky_bluetooth.Blink(1000);
				i2c.lcd_clear();
				break;
				//servo.TurnShaft(SERVO_LEFTPOSITION);
			break;
		
	  }
	}
}

//The Method for HAL dlay function this can be find in the startup file.s
extern "C" void SysTick_Handler(void)
{
	HAL_IncTick();

}