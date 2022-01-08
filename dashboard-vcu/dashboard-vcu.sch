EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A2 23386 16535
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 20600 1900 0    50   ~ 0
Features\n\n* Fuel PWM\n* Temperature PWM\n* LH RGB - (3x pwm pins)\n* RH RGB - (3x pwm pins)\n* CAN bus\n* Stepper motor (speedo/odometer)\n* Power for backlights
Text GLabel 1500 7350 0    50   Input ~ 0
GND
$Comp
L Device:R_US R1
U 1 1 61A7B9C3
P 1800 7350
F 0 "R1" V 1595 7350 50  0000 C CNN
F 1 "1k" V 1686 7350 50  0000 C CNN
F 2 "Resistor_SMD:R_0201_0603Metric" V 1840 7340 50  0001 C CNN
F 3 "~" H 1800 7350 50  0001 C CNN
	1    1800 7350
	0    1    1    0   
$EndComp
$Comp
L Device:LED D1
U 1 1 61A7B9CD
P 2300 7350
F 0 "D1" H 2293 7567 50  0000 C CNN
F 1 "LED" H 2293 7476 50  0000 C CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 2300 7350 50  0001 C CNN
F 3 "~" H 2300 7350 50  0001 C CNN
	1    2300 7350
	1    0    0    -1  
$EndComp
Text GLabel 2700 7350 2    50   Input ~ 0
5V
Wire Wire Line
	1500 7350 1650 7350
Wire Wire Line
	1950 7350 2150 7350
Wire Wire Line
	2450 7350 2700 7350
Text GLabel 4050 12700 0    50   Input ~ 0
12V
Text GLabel 4950 12700 2    50   Input ~ 0
GND
$Comp
L Transistor_BJT:TIP102 IC2
U 1 1 61BEAF3E
P 6500 4600
F 0 "IC2" H 7128 4546 50  0000 L CNN
F 1 "TIP102" H 7128 4455 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO270P460X1020X2008-3P" H 7150 4700 50  0001 L CNN
F 3 "http://www.st.com/web/en/resource/technical/document/datasheet/CD00001234.pdf" H 7150 4600 50  0001 L CNN
F 4 "TIP102, Darlington Transistor, NPN 8 A 100 V HFE:200, 3-Pin, TO-220" H 7150 4500 50  0001 L CNN "Description"
F 5 "4.6" H 7150 4400 50  0001 L CNN "Height"
F 6 "STMicroelectronics" H 7150 4300 50  0001 L CNN "Manufacturer_Name"
F 7 "TIP102" H 7150 4200 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "511-TIP102" H 7150 4100 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/STMicroelectronics/TIP102?qs=ljbEvF4DwONmWw0zLDYvVw%3D%3D" H 7150 4000 50  0001 L CNN "Mouser Price/Stock"
F 10 "TIP102" H 7150 3900 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/tip102/stmicroelectronics?region=nac" H 7150 3800 50  0001 L CNN "Arrow Price/Stock"
	1    6500 4600
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R2
U 1 1 61BEC522
P 6150 4600
F 0 "R2" V 5945 4600 50  0000 C CNN
F 1 "2k2" V 6036 4600 50  0000 C CNN
F 2 "Resistor_SMD:R_0201_0603Metric" V 6190 4590 50  0001 C CNN
F 3 "~" H 6150 4600 50  0001 C CNN
	1    6150 4600
	0    1    1    0   
$EndComp
Wire Wire Line
	6300 4600 6500 4600
Text GLabel 5800 4600 0    50   Input ~ 0
PWM2
Wire Wire Line
	6000 4600 5800 4600
Text GLabel 5800 4800 0    50   Input ~ 0
GND
Text GLabel 5800 4700 0    50   Input ~ 0
FUEL_GAUGE
Wire Wire Line
	5800 4700 6500 4700
Wire Wire Line
	5800 4800 6500 4800
Text GLabel 4050 12600 0    50   Input ~ 0
FUEL_GAUGE
$Comp
L Transistor_BJT:TIP102 IC3
U 1 1 61C0C4F8
P 6500 5350
F 0 "IC3" H 7128 5296 50  0000 L CNN
F 1 "TIP102" H 7128 5205 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO270P460X1020X2008-3P" H 7150 5450 50  0001 L CNN
F 3 "http://www.st.com/web/en/resource/technical/document/datasheet/CD00001234.pdf" H 7150 5350 50  0001 L CNN
F 4 "TIP102, Darlington Transistor, NPN 8 A 100 V HFE:200, 3-Pin, TO-220" H 7150 5250 50  0001 L CNN "Description"
F 5 "4.6" H 7150 5150 50  0001 L CNN "Height"
F 6 "STMicroelectronics" H 7150 5050 50  0001 L CNN "Manufacturer_Name"
F 7 "TIP102" H 7150 4950 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "511-TIP102" H 7150 4850 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/STMicroelectronics/TIP102?qs=ljbEvF4DwONmWw0zLDYvVw%3D%3D" H 7150 4750 50  0001 L CNN "Mouser Price/Stock"
F 10 "TIP102" H 7150 4650 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/tip102/stmicroelectronics?region=nac" H 7150 4550 50  0001 L CNN "Arrow Price/Stock"
	1    6500 5350
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R3
U 1 1 61C0C502
P 6150 5350
F 0 "R3" V 5945 5350 50  0000 C CNN
F 1 "2k2" V 6036 5350 50  0000 C CNN
F 2 "Resistor_SMD:R_0201_0603Metric" V 6190 5340 50  0001 C CNN
F 3 "~" H 6150 5350 50  0001 C CNN
	1    6150 5350
	0    1    1    0   
$EndComp
Wire Wire Line
	6300 5350 6500 5350
Text GLabel 5800 5350 0    50   Input ~ 0
PWM3
Wire Wire Line
	6000 5350 5800 5350
Text GLabel 5800 5550 0    50   Input ~ 0
GND
Text GLabel 5800 5450 0    50   Input ~ 0
TEMP_GAUGE
Wire Wire Line
	5800 5450 6500 5450
Wire Wire Line
	5800 5550 6500 5550
Text GLabel 4050 12500 0    50   Input ~ 0
TEMP_GAUGE
$Comp
L Device:R_US R4
U 1 1 61C7825A
P 5500 9400
F 0 "R4" V 5295 9400 50  0000 C CNN
F 1 "220" V 5386 9400 50  0000 C CNN
F 2 "Resistor_SMD:R_0201_0603Metric" V 5540 9390 50  0001 C CNN
F 3 "~" H 5500 9400 50  0001 C CNN
	1    5500 9400
	0    1    1    0   
$EndComp
Text GLabel 5800 9400 2    50   Input ~ 0
STATUS_A_R
Wire Wire Line
	5650 9400 5800 9400
Text GLabel 5200 9400 0    50   Input ~ 0
PWM4
Wire Wire Line
	5200 9400 5350 9400
$Comp
L Device:R_US R5
U 1 1 61C8B9DB
P 5500 9750
F 0 "R5" V 5295 9750 50  0000 C CNN
F 1 "220" V 5386 9750 50  0000 C CNN
F 2 "Resistor_SMD:R_0201_0603Metric" V 5540 9740 50  0001 C CNN
F 3 "~" H 5500 9750 50  0001 C CNN
	1    5500 9750
	0    1    1    0   
$EndComp
Text GLabel 5800 9750 2    50   Input ~ 0
STATUS_A_G
Wire Wire Line
	5650 9750 5800 9750
Text GLabel 5200 9750 0    50   Input ~ 0
PWM5
Wire Wire Line
	5200 9750 5350 9750
$Comp
L Device:R_US R6
U 1 1 61C8FAE4
P 5500 10100
F 0 "R6" V 5295 10100 50  0000 C CNN
F 1 "220" V 5386 10100 50  0000 C CNN
F 2 "Resistor_SMD:R_0201_0603Metric" V 5540 10090 50  0001 C CNN
F 3 "~" H 5500 10100 50  0001 C CNN
	1    5500 10100
	0    1    1    0   
$EndComp
Text GLabel 5800 10100 2    50   Input ~ 0
STATUS_A_B
Wire Wire Line
	5650 10100 5800 10100
Text GLabel 5200 10100 0    50   Input ~ 0
PWM6
Wire Wire Line
	5200 10100 5350 10100
Text GLabel 4950 12100 2    50   Input ~ 0
STATUS_A_R
Text GLabel 4950 12200 2    50   Input ~ 0
STATUS_A_G
Text GLabel 4950 12300 2    50   Input ~ 0
STATUS_A_B
$Comp
L Device:R_US R7
U 1 1 61CD4145
P 7200 9400
F 0 "R7" V 6995 9400 50  0000 C CNN
F 1 "220" V 7086 9400 50  0000 C CNN
F 2 "Resistor_SMD:R_0201_0603Metric" V 7240 9390 50  0001 C CNN
F 3 "~" H 7200 9400 50  0001 C CNN
	1    7200 9400
	0    1    1    0   
$EndComp
Text GLabel 7500 9400 2    50   Input ~ 0
STATUS_B_R
Wire Wire Line
	7350 9400 7500 9400
Text GLabel 6900 9400 0    50   Input ~ 0
PWM7
Wire Wire Line
	6900 9400 7050 9400
$Comp
L Device:R_US R8
U 1 1 61CD4167
P 7200 9750
F 0 "R8" V 6995 9750 50  0000 C CNN
F 1 "220" V 7086 9750 50  0000 C CNN
F 2 "Resistor_SMD:R_0201_0603Metric" V 7240 9740 50  0001 C CNN
F 3 "~" H 7200 9750 50  0001 C CNN
	1    7200 9750
	0    1    1    0   
$EndComp
Text GLabel 7500 9750 2    50   Input ~ 0
STATUS_B_G
Wire Wire Line
	7350 9750 7500 9750
Text GLabel 6900 9750 0    50   Input ~ 0
PWM8
Wire Wire Line
	6900 9750 7050 9750
$Comp
L Device:R_US R9
U 1 1 61CD4175
P 7200 10100
F 0 "R9" V 6995 10100 50  0000 C CNN
F 1 "220" V 7086 10100 50  0000 C CNN
F 2 "Resistor_SMD:R_0201_0603Metric" V 7240 10090 50  0001 C CNN
F 3 "~" H 7200 10100 50  0001 C CNN
	1    7200 10100
	0    1    1    0   
$EndComp
Text GLabel 7500 10100 2    50   Input ~ 0
STATUS_B_B
Wire Wire Line
	7350 10100 7500 10100
Text GLabel 6900 10100 0    50   Input ~ 0
PWM9
Wire Wire Line
	6900 10100 7050 10100
Text GLabel 4950 12400 2    50   Input ~ 0
STATUS_B_R
Text GLabel 4950 12500 2    50   Input ~ 0
STATUS_B_G
Text GLabel 4950 12600 2    50   Input ~ 0
STATUS_B_B
$Comp
L MCU_Module:Pico U1
U 1 1 61C6CC5E
P 6500 7450
F 0 "U1" H 6500 8665 50  0000 C CNN
F 1 "Pico" H 6500 8574 50  0000 C CNN
F 2 "Module:RPi_Pico_SMD_TH" V 6500 7450 50  0001 C CNN
F 3 "" H 6500 7450 50  0001 C CNN
	1    6500 7450
	1    0    0    -1  
$EndComp
Text GLabel 5800 6700 0    50   Input ~ 0
GND
Text GLabel 5800 7200 0    50   Input ~ 0
GND
Text GLabel 5800 7700 0    50   Input ~ 0
GND
Text GLabel 5800 8200 0    50   Input ~ 0
GND
Text GLabel 7200 6700 2    50   Input ~ 0
GND
Text GLabel 7200 7700 2    50   Input ~ 0
GND
Text GLabel 7200 8200 2    50   Input ~ 0
GND
Text GLabel 7200 7200 2    50   Input ~ 0
GND
Text GLabel 5550 7100 0    50   Input ~ 0
SPI0_CS
Text GLabel 5550 6900 0    50   Input ~ 0
SPI0_TX
Text GLabel 5550 7000 0    50   Input ~ 0
SPI0_RX
Text GLabel 5550 8000 0    50   Input ~ 0
SPI1_RX
Text GLabel 5550 8100 0    50   Input ~ 0
SPI1_CS
Text GLabel 5550 7800 0    50   Input ~ 0
SPI1_CLK
Text GLabel 5550 7900 0    50   Input ~ 0
SPI1_TX
Text GLabel 5550 6800 0    50   Input ~ 0
SPI0_CLK
Text GLabel 6500 8600 3    50   Input ~ 0
GND
Wire Wire Line
	5550 6800 5800 6800
Wire Wire Line
	5550 6900 5800 6900
Wire Wire Line
	5550 7000 5800 7000
Wire Wire Line
	5550 7100 5800 7100
Wire Wire Line
	5550 7800 5800 7800
Wire Wire Line
	5550 7900 5800 7900
Wire Wire Line
	5550 8000 5800 8000
Wire Wire Line
	5550 8100 5800 8100
Text GLabel 5550 8400 0    50   Input ~ 0
PWM2
Text GLabel 5550 8300 0    50   Input ~ 0
PWM3
Text GLabel 7450 8400 2    50   Input ~ 0
PWM4
Text GLabel 7450 8300 2    50   Input ~ 0
PWM5
Text GLabel 7450 8100 2    50   Input ~ 0
PWM6
Text GLabel 7450 8000 2    50   Input ~ 0
PWM7
Text GLabel 7450 7900 2    50   Input ~ 0
PWM8
Text GLabel 7450 7800 2    50   Input ~ 0
PWM9
$Comp
L Diode:SS54B D2
U 1 1 61D50E44
P 7450 6600
F 0 "D2" H 7750 6867 50  0000 C CNN
F 1 "SS54B" H 7750 6776 50  0000 C CNN
F 2 "Diode_SMD:DIOM5336X244N" H 7900 6600 50  0001 L CNN
F 3 "https://datasheet.datasheetarchive.com/originals/distributors/Datasheets-3/DSA-43270.pdf" H 7900 6500 50  0001 L CNN
F 4 "HY Electronic Corp SS54B, SMT Rectifier Schottky Diode, 40V 5A, 2-Pin SMB" H 7900 6400 50  0001 L CNN "Description"
F 5 "2.44" H 7900 6300 50  0001 L CNN "Height"
F 6 "HY Electronic Corp" H 7900 6200 50  0001 L CNN "Manufacturer_Name"
F 7 "SS54B" H 7900 6100 50  0001 L CNN "Manufacturer_Part_Number"
	1    7450 6600
	1    0    0    -1  
$EndComp
Text GLabel 8050 6600 2    50   Input ~ 0
5V
Wire Wire Line
	7200 8400 7450 8400
Wire Wire Line
	7200 8300 7450 8300
Wire Wire Line
	7200 8100 7450 8100
Wire Wire Line
	7200 8000 7450 8000
Wire Wire Line
	7200 7900 7450 7900
Wire Wire Line
	7200 7800 7450 7800
Wire Wire Line
	5550 8300 5800 8300
Wire Wire Line
	5550 8400 5800 8400
Wire Wire Line
	7200 6600 7450 6600
$Comp
L MCU_Module:TPS62160DGKT PS1
U 1 1 61D80EC6
P 10300 6700
F 0 "PS1" H 10850 6965 50  0000 C CNN
F 1 "TPS62160DGKT" H 10850 6874 50  0000 C CNN
F 2 "Module:SOP65P490X110-8N" H 11250 6800 50  0001 L CNN
F 3 "http://www.ti.com/lit/gpn/tps62160" H 11250 6700 50  0001 L CNN
F 4 "3V-17V 1A Step-Down Converters with DCS-Control&#153;" H 11250 6600 50  0001 L CNN "Description"
F 5 "1.1" H 11250 6500 50  0001 L CNN "Height"
F 6 "Texas Instruments" H 11250 6400 50  0001 L CNN "Manufacturer_Name"
F 7 "TPS62160DGKT" H 11250 6300 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "595-TPS62160DGKT" H 11250 6200 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Texas-Instruments/TPS62160DGKT?qs=2UFnnMkojnVQry4yr%2Fdsnw%3D%3D" H 11250 6100 50  0001 L CNN "Mouser Price/Stock"
F 10 "TPS62160DGKT" H 11250 6000 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/tps62160dgkt/texas-instruments" H 11250 5900 50  0001 L CNN "Arrow Price/Stock"
	1    10300 6700
	1    0    0    -1  
$EndComp
Text GLabel 9650 6800 0    50   Input ~ 0
12V
Wire Wire Line
	10150 6800 10150 6900
Wire Wire Line
	10150 6900 10300 6900
Wire Wire Line
	10150 6800 10300 6800
$Comp
L Device:C_Small C1
U 1 1 61D8A55C
P 9800 7050
F 0 "C1" H 9892 7096 50  0000 L CNN
F 1 "10uF" H 9892 7005 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 9800 7050 50  0001 C CNN
F 3 "~" H 9800 7050 50  0001 C CNN
	1    9800 7050
	1    0    0    -1  
$EndComp
Wire Wire Line
	10300 6700 9400 6700
Wire Wire Line
	9400 6700 9400 7400
Wire Wire Line
	9400 7400 9800 7400
Wire Wire Line
	10300 7400 10300 7000
Wire Wire Line
	9650 6800 9800 6800
Connection ~ 10150 6800
Wire Wire Line
	9800 6950 9800 6800
Connection ~ 9800 6800
Wire Wire Line
	9800 6800 10150 6800
Wire Wire Line
	9800 7150 9800 7400
Connection ~ 9800 7400
Wire Wire Line
	9800 7400 10300 7400
$Comp
L pspice:INDUCTOR L1
U 1 1 61DAB10A
P 12100 6800
F 0 "L1" H 12100 7015 50  0000 C CNN
F 1 "2.2uH" H 12100 6924 50  0000 C CNN
F 2 "Inductor_SMD:NR6028T220M" H 12100 6800 50  0001 C CNN
F 3 "~" H 12100 6800 50  0001 C CNN
	1    12100 6800
	1    0    0    -1  
$EndComp
Wire Wire Line
	11400 6800 11850 6800
$Comp
L Device:R R10
U 1 1 61DB179A
P 11550 6400
F 0 "R10" H 11620 6446 50  0000 L CNN
F 1 "100k" H 11620 6355 50  0000 L CNN
F 2 "Resistor_SMD:R_0201_0603Metric" V 11480 6400 50  0001 C CNN
F 3 "~" H 11550 6400 50  0001 C CNN
	1    11550 6400
	1    0    0    -1  
$EndComp
Wire Wire Line
	11400 6700 11550 6700
Wire Wire Line
	11550 6700 11550 6550
Text GLabel 12050 6150 2    50   Input ~ 0
5V
Wire Wire Line
	12050 6150 11550 6150
Wire Wire Line
	11550 6150 11550 6250
Wire Wire Line
	11400 6900 12550 6900
Wire Wire Line
	12550 6900 12550 6800
Wire Wire Line
	12550 6800 12350 6800
$Comp
L Device:R R11
U 1 1 61DC0C9F
P 12550 7150
F 0 "R11" H 12620 7196 50  0000 L CNN
F 1 "220k" H 12620 7105 50  0000 L CNN
F 2 "Resistor_SMD:R_0201_0603Metric" V 12480 7150 50  0001 C CNN
F 3 "~" H 12550 7150 50  0001 C CNN
	1    12550 7150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R12
U 1 1 61DC13AA
P 12550 7550
F 0 "R12" H 12620 7596 50  0000 L CNN
F 1 "47k" H 12620 7505 50  0000 L CNN
F 2 "Resistor_SMD:R_0201_0603Metric" V 12480 7550 50  0001 C CNN
F 3 "~" H 12550 7550 50  0001 C CNN
	1    12550 7550
	1    0    0    -1  
$EndComp
Wire Wire Line
	12550 7300 12550 7350
Wire Wire Line
	12550 7000 12550 6900
Connection ~ 12550 6900
Wire Wire Line
	11400 7000 12100 7000
Wire Wire Line
	12100 7000 12100 7350
Wire Wire Line
	12100 7350 12550 7350
Connection ~ 12550 7350
Wire Wire Line
	12550 7350 12550 7400
Wire Wire Line
	10300 7400 11650 7400
Wire Wire Line
	11650 7800 12550 7800
Wire Wire Line
	12550 7800 12550 7700
Wire Wire Line
	11650 7400 11650 7800
Connection ~ 10300 7400
$Comp
L Device:C_Small C2
U 1 1 61DD76CE
P 13000 7250
F 0 "C2" H 13092 7296 50  0000 L CNN
F 1 "22uF" H 13092 7205 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 13000 7250 50  0001 C CNN
F 3 "~" H 13000 7250 50  0001 C CNN
	1    13000 7250
	1    0    0    -1  
$EndComp
Wire Wire Line
	12550 6800 13000 6800
Wire Wire Line
	13000 6800 13000 7150
Connection ~ 12550 6800
Wire Wire Line
	12550 7800 13000 7800
Wire Wire Line
	13000 7800 13000 7350
Connection ~ 12550 7800
Text GLabel 13200 6800 2    50   Input ~ 0
5V
Wire Wire Line
	13000 6800 13200 6800
Connection ~ 13000 6800
$Comp
L Connector:39300140 J1
U 1 1 61E6C691
P 4050 12100
F 0 "J1" H 4500 12365 50  0000 C CNN
F 1 "39300140" H 4500 12274 50  0000 C CNN
F 2 "Connector:39300140" H 4800 12200 50  0001 L CNN
F 3 "https://www.molex.com/pdm_docs/sd/039300020_sd.pdf" H 4800 12100 50  0001 L CNN
F 4 "Mini-Fit Jr. Header, Dual Row, Right-Angle, with Snap-in Plastic Peg PCB Lock, 14 Circuits, PA Polyamide Nylon 6/6 94V-0, 2.54&micro;m Matte Tin (Sn) Plating" H 4800 12000 50  0001 L CNN "Description"
F 5 "10" H 4800 11900 50  0001 L CNN "Height"
F 6 "Molex" H 4800 11800 50  0001 L CNN "Manufacturer_Name"
F 7 "39300140" H 4800 11700 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "" H 4800 11600 50  0001 L CNN "Mouser Part Number"
F 9 "" H 4800 11500 50  0001 L CNN "Mouser Price/Stock"
F 10 "" H 4800 11400 50  0001 L CNN "Arrow Part Number"
F 11 "" H 4800 11300 50  0001 L CNN "Arrow Price/Stock"
	1    4050 12100
	1    0    0    -1  
$EndComp
Text GLabel 4050 12100 0    50   Input ~ 0
CAN_H
Text GLabel 4050 12200 0    50   Input ~ 0
CAN_L
$Comp
L Interface_CAN_LIN:MCP2515-xSO U2
U 1 1 61EA0A9E
P 11350 9750
F 0 "U2" H 11350 10731 50  0000 C CNN
F 1 "MCP2515-xSO" H 11350 10640 50  0000 C CNN
F 2 "Package_SO:SOIC-18W_7.5x11.6mm_P1.27mm" H 11350 8850 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/21801e.pdf" H 11450 8950 50  0001 C CNN
	1    11350 9750
	1    0    0    -1  
$EndComp
Text GLabel 11950 9150 2    50   Input ~ 0
CAN_RX
Text GLabel 11950 9250 2    50   Input ~ 0
CAN_TX
Text GLabel 7200 6900 2    50   Input ~ 0
3V
Text GLabel 11950 8950 2    50   Input ~ 0
3V
Wire Wire Line
	11350 8950 11950 8950
Text GLabel 11950 10550 2    50   Input ~ 0
GND
Wire Wire Line
	11350 10550 11950 10550
Text GLabel 10750 9450 0    50   Input ~ 0
SPI0_CLK
Text GLabel 10750 9150 0    50   Input ~ 0
SPI0_TX
Text GLabel 10750 9250 0    50   Input ~ 0
SPI0_RX
Text GLabel 10750 9350 0    50   Input ~ 0
SPI0_CS
Text GLabel 5550 7300 0    50   Input ~ 0
8MHz
Wire Wire Line
	5550 7300 5800 7300
Text GLabel 10750 10050 0    50   Input ~ 0
8MHz
$Comp
L Interface_CAN_LIN:SN65HVD230 U3
U 1 1 61EBF451
P 11400 11400
F 0 "U3" H 11400 11881 50  0000 C CNN
F 1 "SN65HVD230" H 11400 11790 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 11400 10900 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn65hvd230.pdf" H 11300 11800 50  0001 C CNN
	1    11400 11400
	1    0    0    -1  
$EndComp
Text GLabel 11000 11400 0    50   Input ~ 0
CAN_RX
Text GLabel 11000 11300 0    50   Input ~ 0
CAN_TX
Text GLabel 11000 11600 0    50   Input ~ 0
GND
Wire Wire Line
	11400 11800 11000 11800
Wire Wire Line
	11000 11800 11000 11600
Text GLabel 11800 11400 2    50   Input ~ 0
CAN_H
Text GLabel 11800 11500 2    50   Input ~ 0
CAN_L
Text GLabel 11800 11100 2    50   Input ~ 0
3V
Wire Wire Line
	11400 11100 11800 11100
$Comp
L Device:C_Small C3
U 1 1 61ED193A
P 12600 9550
F 0 "C3" H 12692 9596 50  0000 L CNN
F 1 "100nF" H 12692 9505 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 12600 9550 50  0001 C CNN
F 3 "~" H 12600 9550 50  0001 C CNN
	1    12600 9550
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C4
U 1 1 61ED321B
P 13050 9550
F 0 "C4" H 13142 9596 50  0000 L CNN
F 1 "100nF" H 13142 9505 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 13050 9550 50  0001 C CNN
F 3 "~" H 13050 9550 50  0001 C CNN
	1    13050 9550
	1    0    0    -1  
$EndComp
Text GLabel 13400 9400 2    50   Input ~ 0
3V
Text GLabel 13400 9700 2    50   Input ~ 0
GND
Wire Wire Line
	12600 9450 12600 9400
Wire Wire Line
	12600 9400 13050 9400
Wire Wire Line
	13400 9700 13050 9700
Wire Wire Line
	12600 9700 12600 9650
Wire Wire Line
	13050 9650 13050 9700
Connection ~ 13050 9700
Wire Wire Line
	13050 9700 12600 9700
Wire Wire Line
	13050 9450 13050 9400
Connection ~ 13050 9400
Wire Wire Line
	13050 9400 13400 9400
$EndSCHEMATC
