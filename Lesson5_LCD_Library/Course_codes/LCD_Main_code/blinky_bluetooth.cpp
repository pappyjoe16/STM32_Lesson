#include "blinky_bluetooth.h"

BLINKY::BLINKY(pinStruct_t& ledPin)
{
	port = ledPin.port;
	pin_led = ledPin.selectedPin;
	// GPIO CONFIG
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = ledPin.selectedPin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(ledPin.port, &GPIO_InitStruct);
	
	
}

void BLINKY::Blink(uint32_t delay)
{
	for(int i = 0; i < 20; i++) {
    // code to be executed inside the loop
		HAL_GPIO_TogglePin(port, pin_led);
		HAL_Delay(delay);
	}

}
