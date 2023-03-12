#include "hc05.h"

char bluetoothData = '\0';

int main(void)
{
	HAL_Init();  // Initialize the HAL API 
	__HAL_RCC_GPIOA_CLK_ENABLE();  // Enable the HAL_GPIO clock (This is are macros)
	__HAL_RCC_USART1_CLK_ENABLE();  // Enable the HAL_TIMER clock
	
	pinStruct_t uartRxPin;
	uartRxPin.port = GPIOA;
	uartRxPin.selectedPin = GPIO_PIN_10;
	
	static HC05 hc05 (uartRxPin, USART1, 9600, GPIO_AF7_USART1, UART_MODE_RX);     // this is a servo object  
	while(1)
	{
		bluetoothData = hc05.GetChar();
		
	}
}

//The Method for HAL delay function this can be find in the startup file.s
extern "C" void SysTick_Handler(void)
{
	HAL_IncTick();

}