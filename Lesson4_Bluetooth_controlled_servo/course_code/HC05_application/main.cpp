#include "hc05.h"
#include "servo.h"
#include "blinky_bluetooth.h"


char bluetoothData[1];

int main(void)
{
	HAL_Init();  // Initialize the HAL API 
	__HAL_RCC_GPIOA_CLK_ENABLE();  // Enable the HAL_GPIO clock (This is are macros)
	__HAL_RCC_USART1_CLK_ENABLE();  // Enable the HAL_TIMER clock
	__HAL_RCC_GPIOB_CLK_ENABLE();  // Enable the HAL_GPIO clock (This is are macros)
	__HAL_RCC_TIM4_CLK_ENABLE();   // Enable the HAL_TIMER clock
	
	//pinStruct_t uartRxPin;
	//uartRxPin.port = GPIOA;
	//uartRxPin.selectedPin = GPIO_PIN_10;
	pinStruct_t uartRxPin = {GPIOA,GPIO_PIN_10};
	pinStruct_t servoPin = {GPIOB,GPIO_PIN_8};
	pinStruct_t ledPin = {GPIOA,GPIO_PIN_5};
	pinStruct_t ledPin2 = {GPIOA,GPIO_PIN_6};
		
	static Servo servo (servoPin, TIM4, GPIO_AF2_TIM4, TIM_CHANNEL_3);     // this is a servo object
	static HC05 hc05(uartRxPin,USART1,9600,GPIO_AF7_USART1,UART_MODE_RX);     // this is a servo object  
	static BLINKY blinky_bluetooth(ledPin);
	static BLINKY blinky_bluetooth2(ledPin2);
	while(1)
	{
		bluetoothData[0] = hc05.GetChar();
		
		switch (bluetoothData[0]){
			case 'l':
			case 'L':
				//servo.TurnShaft(SERVO_LEFTPOSITION);
			
			blinky_bluetooth.Blink(100);
			break;
			case 'm':
			case 'M':
				//servo.TurnShaft(SERVO_MIDPOSITION);
			blinky_bluetooth.Blink(500);
			break;
			case 'r':
			case 'R':
			blinky_bluetooth2.Blink(100);
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