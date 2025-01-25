#include "keypad.h"

const uint row_pins[] = {21, 20, 19, 18};
const uint col_pins[] = {17, 16, 22, 26};

const char keys[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

void iniciar_keypad() {
    for (int i = 0; i < 4; i++) {
        gpio_init(row_pins[i]);
        gpio_set_dir(row_pins[i], GPIO_OUT);
        gpio_put(row_pins[i], 0);
    }
    for (int i = 0; i < 4; i++) {
        gpio_init(col_pins[i]);
        gpio_set_dir(col_pins[i], GPIO_IN);
        gpio_pull_down(col_pins[i]);
    }
}

char ler_keypad() {
    for (int row = 0; row < 4; row++) {
        gpio_put(row_pins[row], 1);
        for (int col = 0; col < 4; col++) {
            if (gpio_get(col_pins[col])) {
                gpio_put(row_pins[row], 0);
                return keys[row][col];
            }
        }
        gpio_put(row_pins[row], 0);
    }
    return '\0';
}
