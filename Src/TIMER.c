#include "TIMER.h"

void GP_TIMER_PWM_INIT(GP_TIMER target, uint8_t channel) {
	GP_TIMER_Struct* timer = (GP_TIMER_Struct*) target;

	switch(channel) {

	case 1:
		// Set OC1M for PWM
		timer->CCMR1 |= (0b110 << 4);

		// Set OC1PE for PWM
		timer->CCMR1 |= (1 << 3);

		// Set ARPE in CR
		timer->CR1 |= (1 << 7);

		// Set UG flag in EGR
		// This register is write only
		timer->EGR = 0b1;

		break;

	case 2:
		// Set OC2M for PWM
		timer->CCMR1 |= (0b110 << 12);

		// Set OC2PE for PWM
		timer->CCMR1 |= (1 << 11);

		// Set ARPE in CR
		timer->CR1 |= (1 << 7);

		// Set UG flag in EGR
		// This register is write only
		timer->EGR = 0b1;

		break;

	case 3:
		// Set OC3M for PWM
		timer->CCMR2 |= (0b110 << 4);

		// Set OC3PE for PWM
		timer->CCMR2 |= (1 << 3);

		// Set ARPE in CR
		timer->CR1 |= (1 << 7);

		// Set UG flag in EGR
		// This register is write only
		timer->EGR = 0b1;

		break;

	case 4:
		// Set OC4M for PWM
		timer->CCMR2 |= (0b110 << 12);

		// Set OC4PE for PWM
		timer->CCMR2 |= (1 << 11);

		// Set ARPE in CR
		timer->CR1 |= (1 << 7);

		// Set UG flag in EGR
		// This register is write only
		timer->EGR = 0b1;
		break;

	default:
		break;
	}
}

void GP_TIMER_ASYNC_START(GP_TIMER target) {
	GP_TIMER_Struct* timer = (GP_TIMER_Struct*) target;

	timer->CR1 |= 0b1;
}

void GP_TIMER_ASYNC_STOP(GP_TIMER target) {
	GP_TIMER_Struct* timer = (GP_TIMER_Struct*) target;

	timer->CR1 &= ~(0b1);
}

void GP_TIMER_DELAY_INIT(GP_TIMER target) {
	GP_TIMER_Struct* timer = (GP_TIMER_Struct*) target;

	// One-pulse-mode
	timer->CR1 |= 0b1;

	// Set direction to count-down
	timer->CR1 |= (1<<4);

	// Prescaler to 16k, resulting clock rate of 1kHz
	timer->PRESCALE = 16000;
}

/*
 * NOTE:
 * 	If using a 16-bit General Purpose timer, the maximum time achievable is only around 16 seconds
 */
void GP_TIMER_DELAY_SET_SEC(GP_TIMER target, uint8_t seconds) {
	GP_TIMER_Struct* timer = (GP_TIMER_Struct*) target;

	if(seconds <= 16) {
		// Convert to milliseconds, since one clock period is 1ms
		uint16_t counts = seconds * 1000;

		timer->COUNT = counts;
	}
}

/*
 * NOTE:
 * 	If using a 16-bit General Purpose timer, the maximum time achievable is only around 16 seconds
 */
void GP_TIMER_DELAY_SET_MS(GP_TIMER target, uint16_t millis) {
	GP_TIMER_Struct* timer = (GP_TIMER_Struct*) target;
	timer->COUNT = millis;
}

void GP_TIMER_DELAY_START(GP_TIMER target) {
	GP_TIMER_Struct* timer = (GP_TIMER_Struct*) target;

	// Start timer
	timer->CR1 |= 0b1;

	uint8_t busy = (timer->CR1 & 0b1);
	while(busy) {
		busy = (timer->CR1 & 0b1);
	}
}

void GP_TIMER_PWM_DUTY(uint8_t channel, uint8_t dc) {
	GP_TIMER_Struct* timer = (GP_TIMER_Struct*) target;
}
