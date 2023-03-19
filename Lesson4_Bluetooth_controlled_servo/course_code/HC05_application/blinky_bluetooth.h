#ifndef BLINKY_BLUETOOTH_H
#define BLINKY_BLUETOOTH_H

#include "pinmap.h"

class BLINKY
{
	private:
		GPIO_TypeDef* port;
		uint16_t pin_led;
	public:
		BLINKY(pinStruct_t& ledPin);
		
		void Blink(uint32_t delay);

};

#endif //BLINKY_BLUETOOTH_H
