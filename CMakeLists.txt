# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if(EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(Interrupt_ButtonLedMatrix C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(Interrupt_ButtonLedMatrix
    src/Interrupt_ButtonLedMatrix.c
    src/led/led.c
    src/buttons/buttons.c
    src/matriz_Numeros/matriz_Numeros.c
)

pico_set_program_name(Interrupt_ButtonLedMatrix "Interrupt_ButtonLedMatrix")
pico_set_program_version(Interrupt_ButtonLedMatrix "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(Interrupt_ButtonLedMatrix 1)
pico_enable_stdio_usb(Interrupt_ButtonLedMatrix 0)

pico_generate_pio_header(Interrupt_ButtonLedMatrix ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio)

# Add the standard library to the build
target_link_libraries(Interrupt_ButtonLedMatrix
    pico_stdlib
    hardware_pwm
    hardware_pio
)

# Add the standard include files to the build
target_include_directories(Interrupt_ButtonLedMatrix PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

# Add any user requested libraries
target_link_libraries(Interrupt_ButtonLedMatrix

)

pico_add_extra_outputs(Interrupt_ButtonLedMatrix)

