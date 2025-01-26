#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "./includes/keypad.h"
#include "./includes/buzzer.h"
#include "./includes/led_matrix.h"
#include "./includes/animacoes.h"
#include "hardware/clocks.h"

// Arquivo .pio
#include "pio_matrix.pio.h"

// Função principal
int main() {
    PIO pio = pio0;
    uint sm = 0;
    uint offset = pio_add_program(pio, &pio_matrix_program);
    pio_matrix_program_init(pio, sm, offset, OUT_PIN);

    stdio_init_all();  // Inicializa a comunicação serial (para debug)
    iniciar_keypad();     // Inicializa o teclado matricial

    while (true) {
        char key = ler_keypad();  // Lê o teclado matricial
        if (key) {
            switch (key) {
                case '1': animacao_espiral(pio, sm); limpar_todos_leds(pio, sm); break;  // Animação 1
                case '2': animacao_coracao(pio, sm); limpar_todos_leds(pio, sm); break;
                case '3': animacao_cruz(pio, sm); limpar_todos_leds(pio, sm); break; //Animação 3
                case '4': animacao_balada(pio, sm); limpar_todos_leds(pio, sm); break; //Animação 4
                case '5': animacao_emoji(pio,sm); limpar_todos_leds(pio, sm); break; //Animação 5
                case '6': animacao_seta(pio,sm); limpar_todos_leds(pio, sm); break; //Animação 6
                case 'A': limpar_todos_leds(pio, sm); break;        // Desliga todos os LEDs
                case 'B': acender_leds(pio, sm, 0.0, 0.0, 1.0); break;  // Azul (100%)
            }
            sleep_ms(200);  // Debounce
        }
    }
}