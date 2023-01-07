cmake_minimum_required(VERSION 3.12)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

include(pico_sdk_import.cmake)

project(voicebox)

set(PICO_CXX_ENABLE_EXCEPTIONS 1)

pico_sdk_init()

add_executable(voicebox
        voicebox.c
        )

pico_add_extra_outputs(voicebox)

target_link_libraries(voicebox pico_stdlib hardware_spi hardware_dma hardware_pwm hardware_adc)
