#include "buttons.h"
#include "pico/stdlib.h"
#include <stdio.h>
#include "../matriz_Numeros/matriz_Numeros.h"

// Definição de variáveis globais
static volatile uint32_t last_time = 0;
static volatile int indice = 0; // Inicializa com 0

// Função de interrupção com debounce
void gpio_irq_handler(uint gpio, uint32_t events)
{
    uint32_t current_time = to_us_since_boot(get_absolute_time());

    // Debounce - Evita múltiplos acionamentos em curto período de tempo
    if (current_time - last_time > 200000) // 200 ms
    {
        last_time = current_time;

        if (gpio == BUTTON_A)
        {
            if (indice < 9) // Evita ultrapassar 9
            {
                printf("Mudanca de Estado do Led. A = %d\n", indice);
                indice++;
            }
        }
        else if (gpio == BUTTON_B)
        {
            if (indice > 0) // Evita valores negativos
            {
                printf("Mudanca de Estado do Led. A = %d\n", indice);
                indice--;
            }
        }

        /*   // Atualiza o número exibido na matriz de LEDs
          npSetPattern(indice); */
    }
}

// Inicializa os botões com interrupções
void init_buttons()
{
    gpio_init(BUTTON_A);
    gpio_init(BUTTON_B);

    gpio_set_dir(BUTTON_A, GPIO_IN);
    gpio_set_dir(BUTTON_B, GPIO_IN);

    gpio_pull_up(BUTTON_A);
    gpio_pull_up(BUTTON_B);

    gpio_set_irq_enabled_with_callback(BUTTON_A, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    gpio_set_irq_enabled_with_callback(BUTTON_B, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
}
