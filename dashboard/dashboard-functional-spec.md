# Functional spec for dashboard

I want the interior of the car to remain original, or, at least, feel original.
No screens. The existing gauges and dash lights are more than enough to use the
car for normal driving. The dashboard will provide an additional web interface
for when I need to inspect the details of the cars operation.

Dashboard will need to stay on all of the time, but can possibly switch to a
lower power mode when car is not driving/charging.

## Physical dash functionality

1. Show SoC on fuel gauge.

2. Show max of all temps on temp gauge (what temps will be available?)

3. Show car mode on left dash indicator.
  - Orange : ignition on, but inverter not in run mode
  - Green  : ignition on, inverter in run mode
  - Blue   : charging

4. Show car status on right dash indicator.
  - Green  : car healthy
  - Orange : warning message from one of the car systems
  - Red    : critical error from one of the car systems

Note : I could possibly show all of this with one dash light. If so, what would
I use the other one for?

5. Stepper motor to drive speedo/odometer.

6. Data logger.

7. GPS?

## Web dash functionality

1. Provide WiFi hotspot. esp8266 or similar.

2. Show pack voltage.

3. Show pack SoC.

4. Show current power in/out.

5. Charging : status

6. Charging : eta to 80%, 100%

7. Driving : estimated range, time to empty.

8. Logs
