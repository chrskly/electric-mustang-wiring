# Functional Spec for BMS

Battery pack will be made up of two BMW PHEV battery packs.

BMS will always be on.

BMS will be able to enable/disable HV for each pack separately via contactors.

BMS will have states of : standby, drive, and charge.

## State machine

### States
* standby
* drive
* charging
* overTempFault
* overVoltageFault
* underVoltageFault
* unknownFault

### Events
* E_TEMPERATURE_UPDATE  - the readings from the battery temperature sensors have
                          updated values.
* E_CELL_VOLTAGE_UPDATE - the readins from the battery voltage sensors have
                          updated values.
* E_IGNITION_ON         - the ignition has been turned on.
* E_IGNITION_OFF        - the ignition has been turned off.
* E_CHARGING_INITIATED  - charging has been initiated.
* E_EMERGENCY_SHUTDOWN  - some bad has happened. Shut down as soon as possible.

## Functionality

1. Provide protection for issues relating to paralleling packs. Deny contactor
   close when pack voltages (not cell voltages) differ by more than a certain
   number of mV. Instead, when going into drive mode, only close the
   contactors for the pack with the highest voltage and, when going into charge
   mode, only close the contactors for the pack with the lowest voltage. Car
   will still be drivable and full battery capacity will still be usable (by
   turning ignition off and on again).
2. When driving on a subset of packs, allow contactors to close when the pack
   voltages get back into alignment.
3. When charging on a subset of packs, allow contactors to close when the pack
   voltages get back into alignment.
4. Send CAN message warn when cell(s) near overvolt.
5. Deny charging when cell(s) overvolt. Programmable buffer.
6. Warn when cell(s) near undervolt. Programmable buffer.
7. Deny drive when cell(s) undervolt.
8. When cells are below 0 degrees c, turn on heaters and deny charge until warm
   enough.
9. Deny drive when temperature over XX degress c.
10. Report range estimate.
11. Provide max charging rate value to charger.

## Connections

1. CAN port connected to main CAN bus.
2. CAN port connected to front battery CAN bus.
3. CAN port connected to rear battery CAN bus.
4. Low side switch for front battery contactors. Contactors are actually controlled by inverter, but BMS can override.
5. Low side switch for rear battery contactors. Contactors are actually controlled by inverter, but BMS can override.
6. Low side switch to turn on battery heater.
7. IGNITION_ON input signal
8. CHARGE_ENABLE input signal
9. CHARGE_INHIBIT output signal
10. DRIVE_INHIBIT output signal

## CAN messages consumed by BMS

1. kWh, Ah data from ISA shunt to calculate SoC.

## CAN messages produced by BMS

1. Computed value of max charge or discharge current (or power) available from
   pack.
2. Overcurrent warning message.
3. Over/under voltage warning.
4. Over/under temp warning.

## Configurables

1. minCellVoltage - disallow drive when cell voltage at or below this level.
2. maxCellVoltage - disallow charge when cell voltage at or above this level.
3. maxPackVoltageDelta - max allowed difference in voltage between packs. Above
   this, contactors will not be allowed to close.
4. minChargeTemp - disallow charging at or below this temperature.

## To Do

- [ ] Fetch SoC from shunt and store in memory
- [ ] Broadcast BMS mode
- [ ] CHARGE_ENABLE input
- [ ] IGNITION_ON input
- [ ] DRIVE_INHIBIT output
- [ ] Use other core for comms?
- [ ] Implement balancing

## Credits

This project uses the [adamczykpiotr/pico-mcp2515](https://github.com/adamczykpiotr/pico-mcp2515) 
library for CAN communication.

The [Tom-evnut/BMWPhevBMS](https://github.com/Tom-evnut/BMWPhevBMS) project was
used as a reference for how to communicate with this battery pack.
