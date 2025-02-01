#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2812.pio.h"


// Definição do número de LEDs e pino.
#define LED_COUNT 25   
#define LED_PIN 7

//Definição dos Botões e RGB
#define BUTTON_A 5  // Pino do botão A
#define BUTTON_B 6  // Pino do botão B
#define LED_VERDE 11    // Pino do LED Verde
#define LED_AZUL 12    // Pino do LED Azul
#define LED_VERMELHO 13    // Pino do LED Vermelho



int main()
{
    stdio_init_all();

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}
