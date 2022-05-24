cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)

project(bms)

pico_sdk_init()

add_executable(bms
        mcp2515/mcp2515.cpp
        module.h
        module.cpp
        pack.h
        pack.cpp
        battery.h
        battery.cpp
        bms.cpp
        update.cpp
        comms.cpp
        statemachine.cpp
        statemachine.h
        )

pico_add_extra_outputs(bms)

target_link_libraries(bms pico_stdlib hardware_spi)
