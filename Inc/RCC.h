#include <stdint.h>

#define RCC_BASE_ADDR 0x40023800

// Struct used to interact with the RCC Registers
typedef struct {
	volatile uint32_t UNUSED_0[12];
	volatile uint32_t AHB1ENR;
	volatile uint32_t AHB2ENR;
	volatile uint32_t AHB3ENR;
	volatile uint32_t UNUSED_1;
	volatile uint32_t APB1ENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t UNUSED_2[20];
} RCC_Struct;

// Enumerated values for devices controlled by AHB1
typedef enum {
	GPIO_A = 0,
	GPIO_B = 1,
	GPIO_C = 2,
	GPIO_D = 3,
	GPIO_E = 4,
	GPIO_F = 5,
	GPIO_G = 6,
	GPIO_H = 7,
	CRC = 12,
	DMA1 = 21,
	DMA2 = 22
}  AHB1_Dev;

// Enumerated values for devices controlled by APB1
typedef enum {
	TIMER_2 = 0,
	TIMER_3 = 1,
	TIMER_4 = 2,
	TIMER_5 = 3,
	TIMER_6 = 4,
	TIMER_7 = 5,
	TIMER_12 = 6,
	TIMER_13 = 7,
	TIMER_14 = 8,
	SPI_2 = 14,
	SPI_3 = 15,
	USART_2 = 17,
	USART_3 = 18,
	UART_4 = 19,
	UART_5 = 20,
	I2C_1 = 21,
	I2C_2 = 22,
	I2C_3 = 23,
	DAC = 29
} APB1_Dev;

// Enumerated values for devices controlled by APB2
typedef enum {
	TIMER_1 = 0,
	TIMER_8 = 1,
	USART_1 = 4,
	USART_6 = 5,
	ADC_1 = 8,
	ADC_2 = 9,
	ADC_3 = 10,
	SPI_1 = 12,
	SPI_4 = 13,
	TIMER_9 = 16,
	TIMER_10 = 17,
	TIMER_11 = 18
} APB2_Dev;

#ifndef RCC_H_
#define RCC_H_ 1

// Functions used to enable said devices by enumerated type
void RCC_API_INIT();
void RCC_AHB1_ENABLE(AHB1_Dev device);
void RCC_APB1_ENABLE(APB1_Dev device);
void RCC_APB2_ENABLE(APB2_Dev device);

#endif /* RCC_H_ */
