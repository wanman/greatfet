/*
 * This file is part of GreatFET
 */

#ifndef __GREATFET_CORE_H
#define __GREATFET_CORE_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include <stdbool.h>

#include "spi_ssp.h"
#include "spiflash.h"

#include "i2c_bus.h"
#include "i2c_lpc.h"

/* convenience macros */
#define COUNT_OF(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))

/* hardware identification number */
#define BOARD_ID_ONE 0
#define BOARD_ID_XPLORER  1
#define BOARD_ID_RAD1O  2

#ifdef GREATFET_ONE
#define BOARD_ID BOARD_ID_ONE
#endif

#ifdef NXP_XPLORER
#define BOARD_ID BOARD_ID_XPLORER
#endif

#ifdef RAD1O_BADGE
#define BOARD_ID BOARD_ID_RAD1O
#endif


void delay(uint32_t duration);

/* TODO: Hide these configurations */
extern const ssp_config_t ssp_config_spi;
extern spi_bus_t spi_bus_ssp0;
extern const ssp_config_t ssp1_config_spi;
extern spi_bus_t spi_bus_ssp1;

extern i2c_bus_t i2c0;
extern i2c_bus_t i2c1;
extern const i2c_lpc_config_t i2c_config_slow_clock;
extern const i2c_lpc_config_t i2c_config_fast_clock;

void cpu_clock_init(void);
void cpu_clock_pll1_low_speed(void);
void cpu_clock_pll1_max_speed(void);

void rtc_init(void);

void pin_setup(void);

typedef enum {
	LED1 = 0,
	LED2 = 1,
	LED3 = 2,
	LED4 = 3,
} led_t;

void led_on(const led_t led);
void led_off(const led_t led);
void led_toggle(const led_t led);

void debug_led(uint8_t val);

#ifdef __cplusplus
}
#endif

#endif /* __GREATFET_CORE_H */
