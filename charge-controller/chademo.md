# Chademo

## Chademo pinout

 1. Ground
 2. CP : evse => car, IN1, contactor +ve signal, goes high when active, sensed by 'f'
 3. nc
 4. CP3 : car => evse, OUT1, charge enable, sensed by 'k'
 5. HV-
 6. HV+
 7. CS : connection check, goes low when plug inserted, sensed by 'h'
 8. CAN H
 9. CAN L
10. CP2 : evse => car, IN2, contactor -ve signal, goes low when active, sensed by 'g'

OUT2, contactor override, pull low to allow CP2 signal through

## Charging sequence

- station pulls CS high?low? to indicate plug insertion
- station pulls CP high (IN1), d1 closes, +ve contactor closes
- Start CAN
- Station/car send params, compatability check
- car pulls CP3 low to indicate start permission
- connector lock
- station runs insulation test
- station pulls CP2 low (IN2), d2 closes
- << charging >>
- car sends current request constantly
- battery fills up, car sends zero current request
- car deactivates CP3, stop permission
- station deactivates CP and CP2
- weld detection?
- unlock




