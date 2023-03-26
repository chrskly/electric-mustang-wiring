cmake_minimum_required(VERSION 3.12)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

include(pico_sdk_import.cmake)

project(charger)

set(PICO_CXX_ENABLE_EXCEPTIONS 1)

pico_sdk_init()

add_executable(charger
        settings.h
        mcp2515/mcp2515.cpp
        ccs.h
        ccs.cpp
        ccsstatemachine.h
        ccsstatemachine.cpp
        chademo.h
        chademo.cpp
        chademocomms.h
        chademocomms.cpp
        chademostatemachine.h
        chademostatemachine.cpp
        chademostation.h
        chademostation.cpp
        charger.h
        charger.cpp
        ccscomms.h
        ccscomms.cpp
        comms.h
        comms.cpp
        led.h
        led.cpp
        inputs.h
        inputs.cpp
        car.h
        car.cpp
        )

pico_add_extra_outputs(charger)

target_link_libraries(charger pico_stdlib hardware_spi)
