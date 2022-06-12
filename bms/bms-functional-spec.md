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

1. Deny contactor close when pack 1 and pack 2 voltages differ by more than a
   certain number of mV. Instead, only close the contactors for the pack with
   the highest voltage. Car will still be drivable and full battery capacity
   will still be usable (by turning ignition off and on again).
2. Send CAN message warn when cell(s) near overvolt.
3. Deny charging when cell(s) overvolt. Programmable buffer.
4. Warn when cell(s) near undervolt. Programmable buffer.
5. Deny drive when cell(s) undervolt.
6. Deny charge when temperature below 0 degrees c.
7. Deny drive when temperature over XX degress c.
8. Report range estimate.
9. Provide max charging rate value to charger.

## Connections

1. CAN port connected to main CAN bus.
2. CAN port connected to front battery CAN bus.
3. CAN port connected to rear battery CAN bus.
4. Low side switch for rear battery contactors.
5. Low side switch for front battery contactors.
6. Drive-enable input signal
7. Charge-enable input signal

## CAN messages consumed by BMS

1. SoC data from ISA shunt.

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
