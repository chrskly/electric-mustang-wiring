# Functional Spec for BMS

Battery pack will be made up of two BMW PHEV battery packs.

BMS will always be on.

BMS will be able to enable/disable HV for each pack separately via contactors.

BMS will have states of rest, drive, and charge.

## Functionality

1. Deny concator close when pack 1 and pack 2 voltages differ by more than a
   certain number of mV.

2. Warn when cell(s) near overvolt.

3. Deny charging when cell(s) overvolt.

4. Warn when cell(s) near undervolt.

5. Deny drive when cell(s) undervolt.

6. Deny charge when temperature below 0 degrees c.

7. Deny drive when temperature over XX degress c.

8. Report range estimate.

## CAN messages consumed by BMS

1. SoC data from ISA shunt.

## CAN messages produced by BMS

1. Computed value of max charge or discharge current (or power) available from
   pack.

2. Overcurrent warning message.

3. Over/under voltage warning.

4. Over/under temp warning.