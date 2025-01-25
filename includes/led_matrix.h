#ifndef LED_MATRIX_H
#define LED_MATRIX_H

#include "hardware/pio.h"

#define NUM_PIXELS 25
#define OUT_PIN 7

uint32_t matrix_rgb(double b, double r, double g);
void limpar_todos_leds(PIO pio, uint sm);
void acender_todos_leds(PIO pio, uint sm, double r, double g, double b);

#endif // LED_MATRIX_H
