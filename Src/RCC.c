#include <stdint.h>
#include "RCC.h"

static RCC_Struct* RCC;

// "Instantiates" the RCC structure
void RCC_API_INIT() {
	RCC = (RCC_Struct*) RCC_BASE_ADDR;
}

// Uses the integer value of the device enumeration to enable the specified device
void RCC_AHB1_ENABLE(AHB1_Dev device) {
	RCC->AHB1ENR |= (1 << device);
}

// Uses the integer value of the device enumeration to enable the specified device
void RCC_APB1_ENABLE(APB1_Dev device) {
	RCC->APB1ENR |= (1 << device);
}

// Uses the integer value of the device enumeration to enable the specified device
void RCC_APB2_ENABLE(APB2_Dev device) {
	RCC->APB2ENR |= (1 << device);
}
