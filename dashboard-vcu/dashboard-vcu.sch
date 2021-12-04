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
Text GLabel 8450 9100 2    50   Input ~ 0
PWM0
Text GLabel 8450 9200 2    50   Input ~ 0
PWM1
Text GLabel 8450 9500 2    50   Input ~ 0
PWM2
Text GLabel 8450 9600 2    50   Input ~ 0
PWM3
Text GLabel 5950 10500 0    50   Input ~ 0
PWM4
Text GLabel 8450 9400 2    50   Input ~ 0
PWM5
Text GLabel 5950 9400 0    50   Input ~ 0
PWM6
Text GLabel 5950 9500 0    50   Input ~ 0
PWM7
Wire Wire Line
	8050 9100 8450 9100
Wire Wire Line
	8050 9200 8450 9200
Wire Wire Line
	8050 9400 8450 9400
Wire Wire Line
	8050 9500 8450 9500
Wire Wire Line
	8050 9600 8450 9600
Wire Wire Line
	5950 9400 6450 9400
Wire Wire Line
	5950 9500 6450 9500
Wire Wire Line
	5950 10500 6450 10500
Text GLabel 5950 9600 0    50   Input ~ 0
PWM8
Wire Wire Line
	5950 9600 6450 9600
Text GLabel 5950 9700 0    50   Input ~ 0
PWM9
Wire Wire Line
	5950 9700 6450 9700
Text GLabel 8450 6800 2    50   Input ~ 0
PWM10
Wire Wire Line
	8050 6800 8450 6800
Text GLabel 8450 6900 2    50   Input ~ 0
PWM11
Text GLabel 8450 7000 2    50   Input ~ 0
PWM12
Text GLabel 8450 7100 2    50   Input ~ 0
PWM13
Wire Wire Line
	8050 6900 8450 6900
Wire Wire Line
	8050 7000 8450 7000
Wire Wire Line
	8050 7100 8450 7100
Text GLabel 5950 5500 0    50   Input ~ 0
RESET
Wire Wire Line
	5950 5500 6450 5500
Text GLabel 1500 5450 0    50   Input ~ 0
5V
$Comp
L Device:R_US R1
U 1 1 61A6BBF8
P 1800 5450
F 0 "R1" V 1595 5450 50  0000 C CNN
F 1 "10k" V 1686 5450 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 1840 5440 50  0001 C CNN
F 3 "~" H 1800 5450 50  0001 C CNN
	1    1800 5450
	0    1    1    0   
$EndComp
Text GLabel 2450 5450 2    50   Input ~ 0
RESET
Wire Wire Line
	1650 5450 1500 5450
$Comp
L Device:CP1 C1
U 1 1 61A6DAAF
P 2100 5800
F 0 "C1" H 2215 5846 50  0000 L CNN
F 1 "0.1uF" H 2215 5755 50  0000 L CNN
F 2 "Capacitor_SMD:RESC1005X55N" H 2100 5800 50  0001 C CNN
F 3 "~" H 2100 5800 50  0001 C CNN
	1    2100 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 5650 2100 5450
Wire Wire Line
	2100 5450 1950 5450
Wire Wire Line
	2100 5450 2450 5450
Connection ~ 2100 5450
Text GLabel 1500 6400 0    50   Input ~ 0
5V
$Comp
L Device:CP1 C2
U 1 1 61A6F9AC
P 1700 6550
F 0 "C2" H 1815 6596 50  0000 L CNN
F 1 "0.1uF" H 1815 6505 50  0000 L CNN
F 2 "Capacitor_SMD:RESC1005X55N" H 1700 6550 50  0001 C CNN
F 3 "~" H 1700 6550 50  0001 C CNN
	1    1700 6550
	1    0    0    -1  
$EndComp
$Comp
L Device:CP1 C3
U 1 1 61A70362
P 2250 6550
F 0 "C3" H 2365 6596 50  0000 L CNN
F 1 "0.1uF" H 2365 6505 50  0000 L CNN
F 2 "Capacitor_SMD:RESC1005X55N" H 2250 6550 50  0001 C CNN
F 3 "~" H 2250 6550 50  0001 C CNN
	1    2250 6550
	1    0    0    -1  
$EndComp
$Comp
L Device:CP1 C4
U 1 1 61A706FE
P 2750 6550
F 0 "C4" H 2865 6596 50  0000 L CNN
F 1 "0.1uF" H 2865 6505 50  0000 L CNN
F 2 "Capacitor_SMD:RESC1005X55N" H 2750 6550 50  0001 C CNN
F 3 "~" H 2750 6550 50  0001 C CNN
	1    2750 6550
	1    0    0    -1  
$EndComp
Text GLabel 1500 6700 0    50   Input ~ 0
GND
Wire Wire Line
	1500 6400 1700 6400
Wire Wire Line
	1700 6400 2250 6400
Connection ~ 1700 6400
Wire Wire Line
	2250 6400 2750 6400
Connection ~ 2250 6400
Wire Wire Line
	2750 6700 2250 6700
Wire Wire Line
	2250 6700 1700 6700
Connection ~ 2250 6700
Wire Wire Line
	1700 6700 1500 6700
Connection ~ 1700 6700
Text GLabel 1500 7800 0    50   Input ~ 0
GND
$Comp
L Device:R_US R3
U 1 1 61A741FF
P 1800 7800
F 0 "R3" V 1595 7800 50  0000 C CNN
F 1 "1k" V 1686 7800 50  0000 C CNN
F 2 "Resistor_SMD:R_0201_0603Metric" V 1840 7790 50  0001 C CNN
F 3 "~" H 1800 7800 50  0001 C CNN
	1    1800 7800
	0    1    1    0   
$EndComp
$Comp
L Device:LED D2
U 1 1 61A755BB
P 2300 7800
F 0 "D2" H 2293 8017 50  0000 C CNN
F 1 "LED" H 2293 7926 50  0000 C CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 2300 7800 50  0001 C CNN
F 3 "~" H 2300 7800 50  0001 C CNN
	1    2300 7800
	1    0    0    -1  
$EndComp
Text GLabel 5950 9200 0    50   Input ~ 0
ACT_LED
Wire Wire Line
	5950 9200 6450 9200
Text GLabel 2700 7800 2    50   Input ~ 0
ACT_LED
Wire Wire Line
	1500 7800 1650 7800
Wire Wire Line
	1950 7800 2150 7800
Wire Wire Line
	2450 7800 2700 7800
Text GLabel 1500 7350 0    50   Input ~ 0
GND
$Comp
L Device:R_US R2
U 1 1 61A7B9C3
P 1800 7350
F 0 "R2" V 1595 7350 50  0000 C CNN
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
Text GLabel 7350 4800 1    50   Input ~ 0
5V
Text GLabel 7250 4800 1    50   Input ~ 0
5V
Wire Wire Line
	7250 5200 7250 4800
Wire Wire Line
	7350 5200 7350 4800
$Comp
L MCU_Microchip_ATmega:ATmega2560-16AU U1
U 1 1 61A6A8ED
P 7250 8100
F 0 "U1" H 7250 5111 50  0000 C CNN
F 1 "ATmega2560-16AU" H 7250 5020 50  0000 C CNN
F 2 "Package_QFP:TQFP-100_14x14mm_P0.5mm" H 7250 8100 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-2549-8-bit-AVR-Microcontroller-ATmega640-1280-1281-2560-2561_datasheet.pdf" H 7250 8100 50  0001 C CNN
	1    7250 8100
	1    0    0    -1  
$EndComp
Text GLabel 6450 11000 0    50   Input ~ 0
GND
Wire Wire Line
	7250 11000 6450 11000
$Comp
L Device:Resonator Y1
U 1 1 61A8845A
P 1900 8700
F 0 "Y1" H 1900 8948 50  0000 C CNN
F 1 "Resonator" H 1900 8857 50  0000 C CNN
F 2 "RF:CSTNE16M0V530000R0" H 1875 8700 50  0001 C CNN
F 3 "~" H 1875 8700 50  0001 C CNN
	1    1900 8700
	1    0    0    -1  
$EndComp
Text GLabel 1650 9000 0    50   Input ~ 0
GND
Wire Wire Line
	1650 9000 1900 9000
Wire Wire Line
	1900 9000 1900 8900
Text GLabel 1650 8700 0    50   Input ~ 0
XTAL1
Text GLabel 2150 8700 2    50   Input ~ 0
XTAL2
Wire Wire Line
	1650 8700 1750 8700
Wire Wire Line
	2050 8700 2150 8700
Text GLabel 5950 5700 0    50   Input ~ 0
XTAL1
Text GLabel 5950 5900 0    50   Input ~ 0
XTAL2
Wire Wire Line
	5950 5700 6450 5700
Wire Wire Line
	5950 5900 6450 5900
$Comp
L power:XL1509-5.0E1 IC1
U 1 1 61ABFDCF
P 4250 2350
F 0 "IC1" H 4950 2615 50  0000 C CNN
F 1 "XL1509-5.0E1" H 4950 2524 50  0000 C CNN
F 2 "Package_SIP:SOIC127P600X175-8N" H 5500 2450 50  0001 L CNN
F 3 "https://datasheet.lcsc.com/szlcsc/XLSEMI-XL1509-5-0E1_C61063.pdf" H 5500 2350 50  0001 L CNN
F 4 "2A 150KHz 40V Buck DC to DC Converter." H 5500 2250 50  0001 L CNN "Description"
F 5 "1.75" H 5500 2150 50  0001 L CNN "Height"
F 6 "XLSEMI" H 5500 2050 50  0001 L CNN "Manufacturer_Name"
F 7 "XL1509-5.0E1" H 5500 1950 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "" H 5500 1850 50  0001 L CNN "Mouser Part Number"
F 9 "" H 5500 1750 50  0001 L CNN "Mouser Price/Stock"
F 10 "" H 5500 1650 50  0001 L CNN "Arrow Part Number"
F 11 "" H 5500 1550 50  0001 L CNN "Arrow Price/Stock"
	1    4250 2350
	1    0    0    -1  
$EndComp
Text GLabel 2250 3050 0    50   Input ~ 0
GND
Text GLabel 2250 2350 0    50   Input ~ 0
12V
$Comp
L Diode:SS54B D3
U 1 1 61AC53BA
P 3150 2350
F 0 "D3" H 3450 2525 50  0000 C CNN
F 1 "SS54B" H 3450 2526 50  0001 C CNN
F 2 "Diode_SMD:DIOM5336X244N" H 3600 2350 50  0001 L CNN
F 3 "https://datasheet.datasheetarchive.com/originals/distributors/Datasheets-3/DSA-43270.pdf" H 3600 2250 50  0001 L CNN
F 4 "HY Electronic Corp SS54B, SMT Rectifier Schottky Diode, 40V 5A, 2-Pin SMB" H 3600 2150 50  0001 L CNN "Description"
F 5 "2.44" H 3600 2050 50  0001 L CNN "Height"
F 6 "HY Electronic Corp" H 3600 1950 50  0001 L CNN "Manufacturer_Name"
F 7 "SS54B" H 3600 1850 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "" H 3600 1750 50  0001 L CNN "Mouser Part Number"
F 9 "" H 3600 1650 50  0001 L CNN "Mouser Price/Stock"
F 10 "" H 3600 1550 50  0001 L CNN "Arrow Part Number"
F 11 "" H 3600 1450 50  0001 L CNN "Arrow Price/Stock"
	1    3150 2350
	-1   0    0    -1  
$EndComp
Wire Wire Line
	5650 2650 5850 2650
Wire Wire Line
	5850 2650 5850 3050
Wire Wire Line
	5850 3050 4150 3050
Wire Wire Line
	5650 2550 5850 2550
Wire Wire Line
	5850 2550 5850 2650
Connection ~ 5850 2650
Wire Wire Line
	5650 2450 5850 2450
Wire Wire Line
	5850 2450 5850 2550
Connection ~ 5850 2550
Wire Wire Line
	5650 2350 5850 2350
Wire Wire Line
	5850 2350 5850 2450
Connection ~ 5850 2450
Wire Wire Line
	4250 2650 4150 2650
Wire Wire Line
	4150 2650 4150 3050
Connection ~ 4150 3050
Wire Wire Line
	4150 3050 3700 3050
$Comp
L Diode:SS54B D4
U 1 1 61AD7925
P 6200 2400
F 0 "D4" V 6454 2270 50  0000 R CNN
F 1 "SS54B" V 6545 2270 50  0000 R CNN
F 2 "Diode_SMD:DIOM5336X244N" H 6650 2400 50  0001 L CNN
F 3 "https://datasheet.datasheetarchive.com/originals/distributors/Datasheets-3/DSA-43270.pdf" H 6650 2300 50  0001 L CNN
F 4 "HY Electronic Corp SS54B, SMT Rectifier Schottky Diode, 40V 5A, 2-Pin SMB" H 6650 2200 50  0001 L CNN "Description"
F 5 "2.44" H 6650 2100 50  0001 L CNN "Height"
F 6 "HY Electronic Corp" H 6650 2000 50  0001 L CNN "Manufacturer_Name"
F 7 "SS54B" H 6650 1900 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "" H 6650 1800 50  0001 L CNN "Mouser Part Number"
F 9 "" H 6650 1700 50  0001 L CNN "Mouser Price/Stock"
F 10 "" H 6650 1600 50  0001 L CNN "Arrow Part Number"
F 11 "" H 6650 1500 50  0001 L CNN "Arrow Price/Stock"
	1    6200 2400
	0    -1   1    0   
$EndComp
Wire Wire Line
	5850 3050 6200 3050
Wire Wire Line
	6200 3050 6200 3000
Connection ~ 5850 3050
Wire Wire Line
	4250 2450 4150 2450
Wire Wire Line
	4150 2450 4150 1900
Wire Wire Line
	4150 1900 6200 1900
Wire Wire Line
	4250 2350 3700 2350
Wire Wire Line
	2250 2350 2550 2350
$Comp
L Analog:VZH331M1ETT-0810 C5
U 1 1 61AE6A89
P 3200 2450
F 0 "C5" V 3450 2580 50  0000 L CNN
F 1 "VZH331M1ETT-0810" V 3495 2580 50  0001 L CNN
F 2 "Capacitor_SMD:CAPAE830X1050N" H 3550 2500 50  0001 L CNN
F 3 "https://datasheet.lcsc.com/szlcsc/Lelon-VZH331M1ETT-0810_C286135.pdf" H 3550 2400 50  0001 L CNN
F 4 "330uF +/-20% 25V SMD,8x10mm Aluminum Electrolytic Capacitors - SMD RoHS" H 3550 2300 50  0001 L CNN "Description"
F 5 "10.5" H 3550 2200 50  0001 L CNN "Height"
F 6 "Lelon" H 3550 2100 50  0001 L CNN "Manufacturer_Name"
F 7 "VZH331M1ETT-0810" H 3550 2000 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "" H 3550 1900 50  0001 L CNN "Mouser Part Number"
F 9 "" H 3550 1800 50  0001 L CNN "Mouser Price/Stock"
F 10 "" H 3550 1700 50  0001 L CNN "Arrow Part Number"
F 11 "" H 3550 1600 50  0001 L CNN "Arrow Price/Stock"
	1    3200 2450
	0    1    1    0   
$EndComp
Wire Wire Line
	3200 2450 3200 2350
Connection ~ 3200 2350
Wire Wire Line
	3200 2350 3150 2350
Wire Wire Line
	3200 2950 3200 3050
Connection ~ 3200 3050
Wire Wire Line
	3200 3050 2250 3050
$Comp
L Analog:CL21B105KBFNNNE C6
U 1 1 61AF21F5
P 3700 2450
F 0 "C6" V 3950 2578 50  0000 L CNN
F 1 "CL21B105KBFNNNE" V 3995 2578 50  0001 L CNN
F 2 "Capacitor_SMD:CAPC2012X135N" H 4050 2500 50  0001 L CNN
F 3 "https://componentsearchengine.com/Datasheets/2/CL21B105KBFNNNE.pdf" H 4050 2400 50  0001 L CNN
F 4 "SAMSUNG ELECTRO-MECHANICS - CL21B105KBFNNNE - CERAMIC MULTILAYER MLCC CAPACITORS- SMD" H 4050 2300 50  0001 L CNN "Description"
F 5 "1.35" H 4050 2200 50  0001 L CNN "Height"
F 6 "Samsung Electro-Mechanics" H 4050 2100 50  0001 L CNN "Manufacturer_Name"
F 7 "CL21B105KBFNNNE" H 4050 2000 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "187-CL21B105KBFNNNE" H 4050 1900 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Samsung-Electro-Mechanics/CL21B105KBFNNNE?qs=yOVawPpwOwmddQEBPU6Y9A%3D%3D" H 4050 1800 50  0001 L CNN "Mouser Price/Stock"
F 10 "CL21B105KBFNNNE" H 4050 1700 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/cl21b105kbfnnne/samsung-electro-mechanics?region=europe" H 4050 1600 50  0001 L CNN "Arrow Price/Stock"
	1    3700 2450
	0    1    1    0   
$EndComp
Wire Wire Line
	3700 2450 3700 2350
Connection ~ 3700 2350
Wire Wire Line
	3700 2350 3200 2350
Wire Wire Line
	3700 2950 3700 3050
Connection ~ 3700 3050
Wire Wire Line
	3700 3050 3200 3050
$Comp
L pspice:INDUCTOR L1
U 1 1 61AFDB96
P 6800 2350
F 0 "L1" H 6800 2565 50  0000 C CNN
F 1 "INDUCTOR" H 6800 2474 50  0000 C CNN
F 2 "" H 6800 2350 50  0001 C CNN
F 3 "~" H 6800 2350 50  0001 C CNN
	1    6800 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 2550 4050 2550
Wire Wire Line
	4050 2550 4050 1750
Wire Wire Line
	4050 1750 7400 1750
$Comp
L Analog:CL21B105KBFNNNE C7
U 1 1 61B04920
P 7400 2450
F 0 "C7" V 7650 2578 50  0000 L CNN
F 1 "CL21B105KBFNNNE" V 7695 2578 50  0001 L CNN
F 2 "Capacitor_SMD:CAPC2012X135N" H 7750 2500 50  0001 L CNN
F 3 "https://componentsearchengine.com/Datasheets/2/CL21B105KBFNNNE.pdf" H 7750 2400 50  0001 L CNN
F 4 "SAMSUNG ELECTRO-MECHANICS - CL21B105KBFNNNE - CERAMIC MULTILAYER MLCC CAPACITORS- SMD" H 7750 2300 50  0001 L CNN "Description"
F 5 "1.35" H 7750 2200 50  0001 L CNN "Height"
F 6 "Samsung Electro-Mechanics" H 7750 2100 50  0001 L CNN "Manufacturer_Name"
F 7 "CL21B105KBFNNNE" H 7750 2000 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "187-CL21B105KBFNNNE" H 7750 1900 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Samsung-Electro-Mechanics/CL21B105KBFNNNE?qs=yOVawPpwOwmddQEBPU6Y9A%3D%3D" H 7750 1800 50  0001 L CNN "Mouser Price/Stock"
F 10 "CL21B105KBFNNNE" H 7750 1700 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/cl21b105kbfnnne/samsung-electro-mechanics?region=europe" H 7750 1600 50  0001 L CNN "Arrow Price/Stock"
	1    7400 2450
	0    1    1    0   
$EndComp
Wire Wire Line
	6200 3050 7400 3050
Wire Wire Line
	7400 3050 7400 2950
Connection ~ 6200 3050
Wire Wire Line
	6200 1900 6200 2350
Wire Wire Line
	7400 1750 7400 2350
Wire Wire Line
	6550 2350 6200 2350
Connection ~ 6200 2350
Wire Wire Line
	6200 2350 6200 2400
Wire Wire Line
	7050 2350 7400 2350
Connection ~ 7400 2350
Wire Wire Line
	7400 2350 7400 2450
$Comp
L Analog:TAJB107K006RNJV C8
U 1 1 61B1BE23
P 7800 2450
F 0 "C8" V 8050 2580 50  0000 L CNN
F 1 "TAJB107K006RNJV" V 8095 2580 50  0001 L CNN
F 2 "Capacitor_SMD:CAPPM3528X210N" H 8150 2500 50  0001 L CNN
F 3 "http://datasheets.avx.com/TAJ.pdf" H 8150 2400 50  0001 L CNN
F 4 "Tantalum Capacitors - Solid SMD 6V 100uF 10% 1210 ESR = 1.7 Ohms" H 8150 2300 50  0001 L CNN "Description"
F 5 "2.1" H 8150 2200 50  0001 L CNN "Height"
F 6 "AVX" H 8150 2100 50  0001 L CNN "Manufacturer_Name"
F 7 "TAJB107K006RNJV" H 8150 2000 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "581-TAJB107K006RNJV" H 8150 1900 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/AVX/TAJB107K006RNJV?qs=k4kUdCzLgS40BaXg2EcjHA%3D%3D" H 8150 1800 50  0001 L CNN "Mouser Price/Stock"
F 10 "TAJB107K006RNJV" H 8150 1700 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/tajb107k006rnjv/avx?region=nac" H 8150 1600 50  0001 L CNN "Arrow Price/Stock"
	1    7800 2450
	0    1    1    0   
$EndComp
$Comp
L Analog:TAJB107K006RNJV C9
U 1 1 61B2242D
P 8200 2450
F 0 "C9" V 8450 2580 50  0000 L CNN
F 1 "TAJB107K006RNJV" V 8495 2580 50  0001 L CNN
F 2 "Capacitor_SMD:CAPPM3528X210N" H 8550 2500 50  0001 L CNN
F 3 "http://datasheets.avx.com/TAJ.pdf" H 8550 2400 50  0001 L CNN
F 4 "Tantalum Capacitors - Solid SMD 6V 100uF 10% 1210 ESR = 1.7 Ohms" H 8550 2300 50  0001 L CNN "Description"
F 5 "2.1" H 8550 2200 50  0001 L CNN "Height"
F 6 "AVX" H 8550 2100 50  0001 L CNN "Manufacturer_Name"
F 7 "TAJB107K006RNJV" H 8550 2000 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "581-TAJB107K006RNJV" H 8550 1900 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/AVX/TAJB107K006RNJV?qs=k4kUdCzLgS40BaXg2EcjHA%3D%3D" H 8550 1800 50  0001 L CNN "Mouser Price/Stock"
F 10 "TAJB107K006RNJV" H 8550 1700 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/tajb107k006rnjv/avx?region=nac" H 8550 1600 50  0001 L CNN "Arrow Price/Stock"
	1    8200 2450
	0    1    1    0   
$EndComp
$Comp
L Analog:TAJB107K006RNJV C10
U 1 1 61B22DFA
P 8600 2450
F 0 "C10" V 8850 2580 50  0000 L CNN
F 1 "TAJB107K006RNJV" V 8895 2580 50  0001 L CNN
F 2 "Capacitor_SMD:CAPPM3528X210N" H 8950 2500 50  0001 L CNN
F 3 "http://datasheets.avx.com/TAJ.pdf" H 8950 2400 50  0001 L CNN
F 4 "Tantalum Capacitors - Solid SMD 6V 100uF 10% 1210 ESR = 1.7 Ohms" H 8950 2300 50  0001 L CNN "Description"
F 5 "2.1" H 8950 2200 50  0001 L CNN "Height"
F 6 "AVX" H 8950 2100 50  0001 L CNN "Manufacturer_Name"
F 7 "TAJB107K006RNJV" H 8950 2000 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "581-TAJB107K006RNJV" H 8950 1900 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/AVX/TAJB107K006RNJV?qs=k4kUdCzLgS40BaXg2EcjHA%3D%3D" H 8950 1800 50  0001 L CNN "Mouser Price/Stock"
F 10 "TAJB107K006RNJV" H 8950 1700 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/tajb107k006rnjv/avx?region=nac" H 8950 1600 50  0001 L CNN "Arrow Price/Stock"
	1    8600 2450
	0    1    1    0   
$EndComp
$Comp
L Analog:TAJB107K006RNJV C11
U 1 1 61B23B80
P 9050 2450
F 0 "C11" V 9300 2580 50  0000 L CNN
F 1 "TAJB107K006RNJV" V 9345 2580 50  0001 L CNN
F 2 "Capacitor_SMD:CAPPM3528X210N" H 9400 2500 50  0001 L CNN
F 3 "http://datasheets.avx.com/TAJ.pdf" H 9400 2400 50  0001 L CNN
F 4 "Tantalum Capacitors - Solid SMD 6V 100uF 10% 1210 ESR = 1.7 Ohms" H 9400 2300 50  0001 L CNN "Description"
F 5 "2.1" H 9400 2200 50  0001 L CNN "Height"
F 6 "AVX" H 9400 2100 50  0001 L CNN "Manufacturer_Name"
F 7 "TAJB107K006RNJV" H 9400 2000 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "581-TAJB107K006RNJV" H 9400 1900 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/AVX/TAJB107K006RNJV?qs=k4kUdCzLgS40BaXg2EcjHA%3D%3D" H 9400 1800 50  0001 L CNN "Mouser Price/Stock"
F 10 "TAJB107K006RNJV" H 9400 1700 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/tajb107k006rnjv/avx?region=nac" H 9400 1600 50  0001 L CNN "Arrow Price/Stock"
	1    9050 2450
	0    1    1    0   
$EndComp
Wire Wire Line
	7400 2350 7800 2350
Wire Wire Line
	7800 2350 7800 2450
Wire Wire Line
	7800 2350 8200 2350
Wire Wire Line
	8200 2350 8200 2450
Connection ~ 7800 2350
Wire Wire Line
	8200 2350 8600 2350
Wire Wire Line
	8600 2350 8600 2450
Connection ~ 8200 2350
Wire Wire Line
	8600 2350 9050 2350
Wire Wire Line
	9050 2350 9050 2450
Connection ~ 8600 2350
Wire Wire Line
	7400 3050 7800 3050
Wire Wire Line
	7800 3050 7800 2950
Connection ~ 7400 3050
Wire Wire Line
	7800 3050 8200 3050
Wire Wire Line
	8200 3050 8200 2950
Connection ~ 7800 3050
Wire Wire Line
	8200 3050 8600 3050
Wire Wire Line
	8600 3050 8600 2950
Connection ~ 8200 3050
Wire Wire Line
	8600 3050 9050 3050
Wire Wire Line
	9050 3050 9050 2950
Connection ~ 8600 3050
Text GLabel 9700 2350 2    50   Input ~ 0
5V
Wire Wire Line
	9700 2350 9050 2350
Connection ~ 9050 2350
Text Notes 2100 1250 0    79   ~ 0
POWER
$Comp
L Connector:776163-1 J1
U 1 1 61BC48B3
P 1900 12500
F 0 "J1" H 2400 12765 50  0000 C CNN
F 1 "776163-1" H 2400 12674 50  0000 C CNN
F 2 "7761631" H 2750 12600 50  0001 L CNN
F 3 "https://www.te.com/commerce/DocumentDelivery/DDEController?Action=showdoc&DocId=Customer+Drawing%7F776163%7FJ11%7Fpdf%7FEnglish%7FENG_CD_776163_J11.pdf%7F776163-1" H 2750 12500 50  0001 L CNN
F 4 "35P AMPSEAL HDR ASSY W/GASKET" H 2750 12400 50  0001 L CNN "Description"
F 5 "32.3" H 2750 12300 50  0001 L CNN "Height"
F 6 "TE Connectivity" H 2750 12200 50  0001 L CNN "Manufacturer_Name"
F 7 "776163-1" H 2750 12100 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "571-776163-1" H 2750 12000 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/TE-Connectivity/776163-1?qs=YqNA2qefETCFEADUtQCEwA%3D%3D" H 2750 11900 50  0001 L CNN "Mouser Price/Stock"
F 10 "776163-1" H 2750 11800 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/776163-1/te-connectivity?region=nac" H 2750 11700 50  0001 L CNN "Arrow Price/Stock"
	1    1900 12500
	1    0    0    -1  
$EndComp
Text GLabel 2900 13400 2    50   Input ~ 0
12V
Text GLabel 1900 13600 0    50   Input ~ 0
GND
$EndSCHEMATC
