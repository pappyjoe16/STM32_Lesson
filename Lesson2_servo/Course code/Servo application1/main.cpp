#include "servo.h"

int main(void)
{
	HAL_Init();  // Initialize the HAL API 
	__HAL_RCC_GPIOB_CLK_ENABLE();  // Enable the HAL_GPIO clock (This is are macros)
	__HAL_RCC_TIM4_CLK_ENABLE();   // Enable the HAL_TIMER clock

	// This create pinStruct type for servoPin
	//pinStruct_t servoPin;
	//servoPin.port = GPIOB;
	//servoPin.selectedPin = GPIO_PIN_8;
	pinStruct_t servoPin = {GPIOB,GPIO_PIN_8};
	
	static Servo servo (servoPin, TIM4, GPIO_AF2_TIM4, TIM_CHANNEL_3);     // this is a servo object
		
	while(1)
	{
		servo.TurnShaft(SERVO_MIDPOSITION);
		HAL_Delay(1000);
		servo.TurnShaft(SERVO_LEFTPOSITION);
		HAL_Delay(1000);
		servo.TurnShaft(SERVO_MIDPOSITION);
		HAL_Delay(1000);
		servo.TurnShaft(SERVO_RIGHTPOSITION);
		HAL_Delay(1000);
				
	}
	
	
	
}

//The Method for HAL delay function this can be find in the startup file.s
extern "C" void SysTick_Handler(void)
{
	HAL_IncTick();

}