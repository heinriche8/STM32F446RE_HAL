#define F_CPU 16000000UL

#include <stdint.h>
#include <stdio.h>
#include "uart_driver.h"
#include "RCC.h"
#include "GPIO.h"
#include "TIMER.h"


/*
 * Used for peripheral initialization
 */
void init() {
	// Initialization for serial console
	init_usart2(115200, F_CPU);

	// RCC Initialization, we need TIM3 and GPIOB
	RCC_API_INIT();
	RCC_AHB1_ENABLE(GPIO_B);
	RCC_APB1_ENABLE(TIMER_3);

	// GPIO Initialization, set PB5 to Alternate function
	GPIO_PIN_MODE(B, 5, ALT);

	// PB5 Alt funct 2 = TIM3_CH2
	GPIO_PIN_ALTFUN(B, 5, ALT_2);

	GP_TIMER_PWM_INIT(TIM_3, 2);
}


int main(void)
{

    while(1) {}

    return 0;
}
