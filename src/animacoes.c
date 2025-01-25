#include "animacoes.h"
#include "led_matrix.h"
#include "pico/stdlib.h"

void animacao_espiral(PIO pio, uint sm) {
    double frames[5][25] = {
        // Adicione os frames da animação aqui
    };

    for (int repeat = 0; repeat < 3; repeat++) {
        for (int frame = 0; frame < 5; frame++) {
            for (int i = 0; i < NUM_PIXELS; i++) {
                pio_sm_put_blocking(pio, sm, matrix_rgb(0.0, 0.0, frames[frame][i]));
            }
            sleep_ms(200);
        }
    }
}
