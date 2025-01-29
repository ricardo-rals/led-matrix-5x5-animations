# Projeto: LED Matriz 5x5 Animations

## Descrição
Este projeto implementa um sistema que gerar informações visuais em uma matriz de LEDs Coloridos (5x5 WS2812).

## Funcionalidades
- **Teclas de 1 a 7**: Executam 7 animações diferentes, com no mínimo 5 frames cada
- **Tecla A**: Desliga todos os LEDs.
- **Tecla B:**: Liga todos os LEDs na cor azul com 100% de intensidade.
- **Tecla C**: Liga todos os LEDs na cor vermelha com 80% de intensidade.
- **Tecla D**: Liga todos os LEDs na cor verde com 50% de intensidade.
- **Tecla #**: Liga todos os LEDs na cor branca com 20% de intensidade.
- **Tecla (*)**: Reinicia o sistema (habilita o modo de gravação).

## Estrutura do Código
O código está organizado em funções principais para inicialização e controle dos periféricos:
- `pwm_init_buzzer(uint pin)`: Inicializa o PWM para controle do buzzer.
- `beep(uint note, uint duration)`: Gera um som no buzzer em uma frequência e duração específicas.
- `matrix_rgb`: Inicializa a matriz de LEDs RGB.
- `iniciar_keypad`: Inicializa o teclado matricial 4x4.
- `tocar_marcha_imperial`: Tocar a musica marcha imperial de star wars.

## Estrutura dos arquivos
```
project/
│
├── beeps/
│   ├── marcha_imperial.c
│
├── includes/
│   ├── animacoes.h
│   ├── buzzer.h
│   ├── keypad.h
│   ├── led_matrix.h
│   └── marcha_imperial.h
│
├── src/
│   ├── animacoes.c
│   ├── buzzer.c
│   ├── keypad.c
│   └── led_matrix.c
├── led-animations.c
├── CMakeLists.txt
└── README.md
```

## Requisitos de Hardware
- Raspberry Pi Pico W.
- Matriz de LEDs Coloridos (5x5 WS2812).
- Teclado Matricial 4x4
- Buzzer conectado ao pino GPIO 15.

## **Equipe**

| **Grupo 8 - Subgrupo 5**
|--------------------------------|
|Ricardo Augusto Lima da Silva   |
|Dorivaldo Jesus da Silva Júnior | 
|Guilherme Miller Gama Cardoso   | 
|Adson Oliveira Albano           |
|Isabella Carvalho Andrade       |
|Arthur Silva Santos Argollo     | 
|Jabson Gama Santana Junior      |

## **Link com a produção do vídeo:**
https://youtube.com/shorts/0cR-x1ztTEw

![Matriz 5x5](https://github.com/user-attachments/assets/2a0f739d-9bf2-4a4f-a034-cb2d0799a942)
