#ifndef PINMAP_H
#define PINMAP_H

#include "stm32f4xx_hal.h"  // Keil :: Devie: STM32Cube HAL:Common

struct pinConfig {
  GPIO_TypeDef* port;    // GPIO_TypeDef is a structure whose member are GPIO registers, it is accessible by including CMSIS or HAL lib
	uint16_t selectedPin;
};

typedef struct pinConfig pinStruct_t; 

#endif //PINMAP_H
