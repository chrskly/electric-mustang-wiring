cmake_minimum_required(VERSION 3.12)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

include(pico_sdk_import.cmake)

project(bms)

#set(PICO_ENABLE_CXX_EXCEPTIONS 1)
set(PICO_CXX_ENABLE_EXCEPTIONS 1)

pico_sdk_init()

add_executable(bms
        settings.h
        mcp2515/mcp2515.cpp
        module.h
        module.cpp
        pack.h
        pack.cpp
        battery.h
        battery.cpp
        bms.h
        bms.cpp
        comms.h
        comms.cpp
        statemachine.h
        statemachine.cpp
        led.h
        led.cpp
        CRC8.h
        CRC8.cpp
        inputs.cpp
        )

#add_executable(module-test
#        mcp2515/mcp2515.cpp
#	module.h
#	module.cpp
#	structs.h
#	test/module/test.cpp
#)

pico_add_extra_outputs(bms)
#pico_add_extra_outputs(module-test)

target_link_libraries(bms pico_stdlib hardware_spi)
#target_link_libraries(module-test pico_stdlib hardware_spi)
