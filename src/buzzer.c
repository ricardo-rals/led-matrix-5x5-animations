#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"
#include "../includes/buzzer.h"
#include "../includes/led_matrix.h"
#include "../includes/animacoes.h"

// Pino do buzzer
#define BUZZER 15

// Inicialização do PWM no pino do buzzer
void pwm_init_buzzer(uint pin) {
    gpio_set_function(pin, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(pin);
    pwm_config config = pwm_get_default_config();
    pwm_init(slice_num, &config, true);
    pwm_set_gpio_level(pin, 0);  // Desativa o buzzer
}

// Função para gerar uma frequência no buzzer
void beep(uint note, uint duration) {
    uint slice_num = pwm_gpio_to_slice_num(BUZZER);
    uint32_t clock = clock_get_hz(clk_sys);
    
    // Calcula divisor de clock para a frequência desejada
    uint32_t divisor = clock / (note * 4096);
    pwm_set_clkdiv(slice_num, divisor);

    // Define duty cycle para 50%
    pwm_set_gpio_level(BUZZER, 2048);

    sleep_ms(duration); // Dura o tempo necessário

    // Desativa o buzzer
    pwm_set_gpio_level(BUZZER, 0);
    sleep_ms(20); // Pequena pausa entre notas
}


void beep_marcha(PIO pio, uint sm, uint note, uint duration) {
    uint slice_num = pwm_gpio_to_slice_num(BUZZER);
    uint32_t clock = clock_get_hz(clk_sys);
    
    // Calcula divisor de clock para a frequência desejada
    uint32_t divisor = clock / (note * 4096 * 3);
    pwm_set_clkdiv(slice_num, divisor);

    // Exibe o rosto do Darth Vader
    animacao_darth_vader(pio, sm);

    // Define duty cycle para 50%
    pwm_set_gpio_level(BUZZER, 2048);
    sleep_ms(duration); // Dura o tempo necessário

    // Desativa o buzzer e apaga a matriz de LEDs
    pwm_set_gpio_level(BUZZER, 0);
    limpar_todos_leds(pio, sm);

    sleep_ms(20); // Pequena pausa entre notas
}