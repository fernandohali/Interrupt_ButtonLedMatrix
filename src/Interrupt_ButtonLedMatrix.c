#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2812.pio.h"

// Chamando as funções organizadas em pastas
#include "led/led.h"
#include "buttons/buttons.h"
#include "matriz_Numeros/matriz_Numeros.h"

PIO pio = pio0; // Definição global para evitar reinicialização contínua
int sm = 0;
uint offset;

int main()
{
    stdio_init_all();

    // Inicializa os LEDs e os botões
    init_led();
    init_buttons();

    // Inicializa a comunicação WS2812 apenas uma vez
    uint offset = pio_add_program(pio, &ws2812_program);
    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW);

    while (true)
    {
        set_led_color();
        sleep_ms(100); // Pequeno delay para evitar consumo excessivo de CPU
    }
}
