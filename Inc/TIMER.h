#include <stdint.h>

typedef struct {
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t SMCR;
	volatile uint32_t DIER;
	volatile uint32_t SR;
	volatile uint32_t EGR;
	volatile uint32_t CCMR1;
	volatile uint32_t CCMR2;
	volatile uint32_t CCER;
	volatile uint32_t COUNT;
	volatile uint32_t PRESCALE;
	volatile uint32_t AUTORELOAD;
	volatile uint32_t RESERVED_0;
	volatile uint32_t CCR1;
	volatile uint32_t CCR2;
	volatile uint32_t CCR3;
	volatile uint32_t CCR4;
	volatile uint32_t RESERVED_1;
	volatile uint32_t DCR;
	volatile uint32_t DMAR;
	volatile uint32_t OR;
} GP_TIMER_Struct;

typedef enum {
	TIM_2 = 0x40000000,
	TIM_3 = 0x40000400,
	TIM_4 = 0x40000800,
	TIM_5 = 0x40000C00
} GP_TIMER;

/*
 * Note for self:
 * When a GP Timer is configured in PWM mode,
 * ARR = Freq.
 * Duty Cycle = CCR
 *
 * Set TIM3 OC2M = 0b110 or 0b111 (test to see which works in this case) in CCMR
 * Set TIM3 OC2PE in TIM3_CCMR1
 * Set TIM3 CR1 ARPE
 * Set TIM3 EGR UG
 */

#ifndef TIMER_H_
#define TIMER_H_ 1

void GP_TIMER_PWM_INIT(GP_TIMER target, uint8_t channel);
void GP_TIMER_ASYNC_START(GP_TIMER target);
void GP_TIMER_ASYNC_STOP(GP_TIMER target);
void GP_TIMER_DELAY_INIT(GP_TIMER target);
void GP_TIMER_DELAY_SET_SEC(GP_TIMER target, uint8_t seconds);
void GP_TIMER_DELAY_SET_MS(GP_TIMER target, uint16_t millis);
void GP_TIMER_DELAY_START(GP_TIMER target);
void GP_TIMER_PWM_DUTY(uint8_t channel, uint8_t dc);

#endif /* TIMER_H_ */
