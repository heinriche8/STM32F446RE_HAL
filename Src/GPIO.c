#include <stdint.h>
#include "GPIO.h"

void GPIO_PIN_MODE(GPIO_PORT port, uint8_t pin, GPIO_MODE mode) {
	GPIO_Struct* target = (GPIO_Struct*) port;

	// Only 16 pins per GPIO port
	if(pin >= 0 && pin <= 15) {
		target->MODE |= (mode << (pin << 1));
	}

}

void GPIO_PIN_SET(GPIO_PORT port, uint8_t pin) {
	GPIO_Struct* target = (GPIO_Struct*) port;

	if(pin >= 0 && pin <= 15) {
		target->BSRR = (1 << pin);
	}
}

void GPIO_PIN_CLR(GPIO_PORT port, uint8_t pin) {
	GPIO_Struct* target = (GPIO_Struct*) port;

	if(pin >= 0 && pin <= 15) {
		target->BSRR = (1 << (pin+16));
	}
}

void GPIO_PIN_ALTFUN(GPIO_PORT port, uint8_t pin, GPIO_ALTFUN funct) {
	GPIO_Struct* target = (GPIO_Struct*) port;

	// Valid pin
	if(pin >= 0 && pin <= 15) {

		// Valid alternate funct
		if(funct >= 0 && funct <= 15) {
			uint8_t shift = (pin << 2);

			// Each alternate funct register only controls half of the pins,
			// so this does some logic to determine if the alternate funct will
			// go into the high or low register for the specified port
			if(shift > 7) {
				shift -= 7;
				target->AFR_H |= (funct << shift);
			} else {
				target->AFR_L |= (funct << shift);
			}

		}
	}
}
