#ifndef BUZZER_H
#define BUZZER_H
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"

#define BUZZER 15

void pwm_init_buzzer(uint pin);
void beep(uint note, uint duration);
void beep_marcha(PIO pio, uint sm, uint note, uint duration);

#endif // BUZZER_H