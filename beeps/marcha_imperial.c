#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "../includes/buzzer.h"
#include "../includes/marcha_imperial.h"

// Definição das frequências
#define c 261
#define d 294
#define e 329
#define f 349
#define g 391
#define a 440
#define b 466
#define cH 523
#define dH 587
#define eH 659
#define fH 698
#define gH 784
#define aH 880

// Função que reproduz a Marcha Imperial
void tocar_marcha_imperial(PIO pio, uint sm) {
    printf("\nExecutando a marcha imperial\n");
    beep_marcha(pio, sm, a, 500);
    beep_marcha(pio, sm, a, 500);
    beep_marcha(pio, sm, f, 350);
    beep_marcha(pio, sm, cH, 150);

    beep_marcha(pio, sm, a, 500);
    beep_marcha(pio, sm, f, 350);
    beep_marcha(pio, sm, cH, 150);
    beep_marcha(pio, sm, a, 1000);
    beep_marcha(pio, sm, eH, 500);

    beep_marcha(pio, sm, eH, 500);
    beep_marcha(pio, sm, eH, 500);
    beep_marcha(pio, sm, fH, 350);
    beep_marcha(pio, sm, cH, 150);
    beep_marcha(pio, sm, g, 500);

    beep_marcha(pio, sm, f, 350);
    beep_marcha(pio, sm, cH, 150);
    beep_marcha(pio, sm, a, 1000);
    beep_marcha(pio, sm, aH, 500);
    beep_marcha(pio, sm, a, 350);

    beep_marcha(pio, sm, a, 150);
    beep_marcha(pio, sm, aH, 500);
    beep_marcha(pio, sm, gH, 250);
    beep_marcha(pio, sm, g, 250);
    beep_marcha(pio, sm, fH, 125);

    beep_marcha(pio, sm, f, 125);
    beep_marcha(pio, sm, fH, 250);

    sleep_ms(250);

    beep_marcha(pio, sm, b, 250);
    beep_marcha(pio, sm, dH, 500);
    beep_marcha(pio, sm, d, 250);
    beep_marcha(pio, sm, cH, 250);
    beep_marcha(pio, sm, b, 125);

    beep_marcha(pio, sm, a, 125);
    beep_marcha(pio, sm, b, 250);

    sleep_ms(250);

    beep_marcha(pio, sm, f, 125);
    beep_marcha(pio, sm, g, 500);
    beep_marcha(pio, sm, f, 375);
    beep_marcha(pio, sm, a, 125);
    beep_marcha(pio, sm, cH, 500);

    beep_marcha(pio, sm, a, 375);
    beep_marcha(pio, sm, cH, 125);
    beep_marcha(pio, sm, eH, 1000);
}