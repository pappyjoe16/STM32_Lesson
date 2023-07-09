#include "hc05.h"

HC05::HC05(pinStruct_t& uartPin, 
						USART_TypeDef* USARTx, 
						uint32_t baudRate,
						uint32_t gpioAFSelUSARTx, 
						uint32_t mode)
{
	// GPIO CONFIG
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = uartPin.selectedPin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = gpioAFSelUSARTx;
  HAL_GPIO_Init(uartPin.port, &GPIO_InitStruct);
	
	
	// UART CONFIG
	huart.Instance = USARTx;
  huart.Init.BaudRate = baudRate;
  huart.Init.WordLength = UART_WORDLENGTH_8B;
  huart.Init.StopBits = UART_STOPBITS_1;
  huart.Init.Parity = UART_PARITY_NONE;
  huart.Init.Mode = mode;
  huart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart.Init.OverSampling = UART_OVERSAMPLING_16;
	HAL_UART_Init(&huart);
}

char HC05::GetChar(void)
{
	//wait for rx buffer to be full then read the data (check the status register (SR))
	while((huart.Instance->SR & USART_SR_RXNE) != USART_SR_RXNE){}
	return huart.Instance->DR;
	//uint8_t data[2];
	//HAL_UART_Receive(&huart, data, sizeof(data), HAL_MAX_DELAY);
	//return data[1];
}

