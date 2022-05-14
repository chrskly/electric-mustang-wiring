# Functional spec for charge controller

Charge controller will manage LIM unit for DC charging and Tesla v2 unit for
AC charging.

## Functionality

1. Measure temp of charge port.

## Connections

1. CAN port connected to main CAN bus.

2. CAN port connected to Tesla gen 2 OBC.

3. CAN port connected to LIM.

## CAN messages consumed by charge controller

## CAN messages produced by charge controller

1. Control messages for LIM

2. Control messages for Tesla charger