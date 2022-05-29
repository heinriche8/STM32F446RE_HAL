// GPIO port enumerated type
// Capital letters A to H, inclusive
typedef enum {
	A = 0x40020000,
	B = 0x40020400,
	C = 0x40020800,
	D = 0x40020C00,
	E = 0x40021000,
	F = 0x40021400,
	G = 0x40021800,
	H = 0x40021C00
} GPIO_PORT;

// GPIO mode enumerated type
// INPUT, OUTPUT, ALT, ANALOG
typedef enum {
	INPUT = 0b00,
	OUTPUT = 0b01,
	ALT = 0b10,
	ANALOG = 0b11
} GPIO_MODE;

// Alternate function enumerated type
// Alternate function chart can be found within the Datasheet PDF as Table 11
typedef enum {
	ALT_0 = 0,
	ALT_1 = 1,
	ALT_2 = 2,
	ALT_3 = 3,
	ALT_4 = 4,
	ALT_5 = 5,
	ALT_6 = 6,
	ALT_7 = 7,
	ALT_8 = 8,
	ALT_9 = 9,
	ALT_10 = 10,
	ALT_11 = 11,
	ALT_12 = 12,
	ALT_13 = 13,
	ALT_14 = 14,
	ALT_15 = 15
} GPIO_ALTFUN;

// Structure used to interact with the GPIO ports
typedef struct {
	volatile uint32_t MODE;
	volatile uint32_t OUT_TYPE;
	volatile uint32_t OUT_SPEED;
	volatile uint32_t PU_PD;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LOCK;
	volatile uint32_t AFR_L;
	volatile uint32_t AFR_H;

} GPIO_Struct;

#ifndef GPIO_H_
#define GPIO_H_ 1

void GPIO_PIN_MODE(GPIO_PORT port, uint8_t pin, GPIO_MODE mode);
void GPIO_PIN_SET(GPIO_PORT port, uint8_t pin);
void GPIO_PIN_CLR(GPIO_PORT port, uint8_t pin);
void GPIO_PIN_ALTFUN(GPIO_PORT port, uint8_t pin, GPIO_ALTFUN funct);

#endif /* GPIO_H_ */
