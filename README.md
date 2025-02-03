# Projeto de Interrupções com RP2040 e BitDogLab

Este projeto tem como objetivo consolidar o entendimento sobre o uso de interrupções no microcontrolador RP2040, utilizando a placa de desenvolvimento BitDogLab. O projeto envolve o controle de LEDs e botões, com foco na implementação de interrupções, debouncing via software e manipulação de LEDs endereçáveis WS2812.

## Objetivos

- Compreender o funcionamento e a aplicação de interrupções em microcontroladores.
- Identificar e corrigir o fenômeno de bouncing em botões por meio de debouncing via software.
- Manipular e controlar LEDs comuns e LEDs endereçáveis WS2812.
- Fixar o estudo do uso de resistores de pull-up internos em botões de acionamento.
- Desenvolver um projeto funcional que combine hardware e software.

## Vídeo

- https://www.dropbox.com/scl/fi/h7fuktkaf1lidz8pf6t78/Unidade-4-Capitulo-4.mp4?rlkey=vbqjtnswtbmz9ilqrbsmal8im&st=7wrs3f8p&dl=0

## Componentes Utilizados

- **Matriz 5x5 de LEDs WS2812** conectada à GPIO 7.
- **LED RGB** com os pinos conectados às GPIOs 11, 12 e 13.
- **Botão A** conectado à GPIO 5.
- **Botão B** conectado à GPIO 6.

## Funcionalidades do Projeto

1. **LED RGB**: O LED vermelho do LED RGB deve piscar continuamente 5 vezes por segundo.
2. **Botão A**: Cada vez que o botão A for pressionado, ele deve incrementar o número exibido na matriz de LEDs.
3. **Botão B**: Cada vez que o botão B for pressionado, ele deve decrementar o número exibido na matriz de LEDs.
4. **Matriz de LEDs WS2812**: Os LEDs WS2812 devem ser usados para criar efeitos visuais representando números de 0 a 9. A formatação pode ser fixa (como caracteres em estilo digital) ou criativa, desde que o número seja claramente identificável.

## Estrutura do Projeto

O projeto deve ser organizado da seguinte forma:<br>
/projeto<br>
│<br>
├── /src<br>
│     ├── Interrupt_ButtonLedMatrix.c # Código principal do projeto<br>
│     ├── interrupts.c # Rotinas de interrupção<br>
│     ├── debouncing.c # Implementação do debouncing<br>
│     └── ws2812.pio # Controle dos LEDs WS2812<br>
...


## Desenvolvedor
- *Fernando Hali Santos Andrade*  


## Conclusão

Este projeto visa integrar conceitos de hardware e software, com foco no uso de interrupções e controle de LEDs. A implementação correta do debouncing e a organização do código são aspectos fundamentais para o sucesso do projeto.
