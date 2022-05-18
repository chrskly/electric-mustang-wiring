# Functional spec for charge controller

Charge controller will manage LIM unit for DC charging and Tesla v2 unit for
AC charging.

## Functionality

1. Measure temp of charge port.

2. Limit charging rate based on battery temp.

## Connections

1. CAN port connected to main CAN bus.

2. CAN port connected to Tesla gen 2 OBC.

3. CAN port connected to LIM.

4. 2x thermistor inputs.

5. Stop charge input.

## CAN messages consumed by charge controller

1. BMS temperature readings.

## CAN messages produced by charge controller

1. Control messages for LIM

2. Control messages for Tesla charger

## External resources

### Damien's LIM control implementation for Zombieverter

https://github.com/damienmaguire/Stm32-vcu/blob/master/src/i3LIM.cpp

### OpenInverter forum LIM docs

https://openinverter.org/wiki/BMW_I3_Fast_Charging_LIM_Module