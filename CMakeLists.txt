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
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(led-animations C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(led-animations led-animations.c src/animacoes.c src/buzzer.c src/keypad.c src/led_matrix.c beeps/marcha_imperial.c)

pico_set_program_name(led-animations "led-animations")
pico_set_program_version(led-animations "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(led-animations 1)
pico_enable_stdio_usb(led-animations 1)

pico_generate_pio_header(led-animations ${CMAKE_CURRENT_LIST_DIR}/pio_matrix.pio)
# Add the standard library to the build
target_link_libraries(led-animations
        hardware_pio
	    hardware_adc
        hardware_pwm
        pico_stdio_usb
        pico_bootrom
        pico_stdlib)

# Add the standard include files to the build
target_include_directories(led-animations PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
)

# Add any user requested libraries
target_link_libraries(led-animations 
        
        )

pico_add_extra_outputs(led-animations)

