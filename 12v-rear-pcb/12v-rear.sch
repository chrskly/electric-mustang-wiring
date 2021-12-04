EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A3 16535 11693
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
$Comp
L Connector:282836-6 FRONT_1
U 1 1 619BE10A
P 5750 1150
F 0 "FRONT_1" H 6378 946 50  0000 L CNN
F 1 "282836-6" H 6378 855 50  0000 L CNN
F 2 "Socket:2828366" H 6400 1250 50  0001 L CNN
F 3 "https://www.te.com/commerce/DocumentDelivery/DDEController?Action=showdoc&DocId=Customer+Drawing%7F282836%7FJ%7Fpdf%7FEnglish%7FENG_CD_282836_J.pdf%7F282836-6" H 6400 1150 50  0001 L CNN
F 4 "Fixed Terminal Blocks 5.0MM PCB MOUNT 6P" H 6400 1050 50  0001 L CNN "Description"
F 5 "10.2" H 6400 950 50  0001 L CNN "Height"
F 6 "TE Connectivity" H 6400 850 50  0001 L CNN "Manufacturer_Name"
F 7 "282836-6" H 6400 750 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "571-2828366" H 6400 650 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/TE-Connectivity/282836-6/?qs=A%252Bip%252BNCYi6MsYFpaQLKbfg%3D%3D" H 6400 550 50  0001 L CNN "Mouser Price/Stock"
F 10 "282836-6" H 6400 450 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/282836-6/te-connectivity" H 6400 350 50  0001 L CNN "Arrow Price/Stock"
	1    5750 1150
	1    0    0    -1  
$EndComp
Text GLabel 5750 1650 0    50   Input ~ 0
PERM_12V
Text GLabel 5750 1150 0    50   Input ~ 0
IGNITION_12V
$Comp
L Connector:178.6165.0001 TESLA_FUSE1
U 1 1 619C0619
P 1450 1500
F 0 "TESLA_FUSE1" H 1850 1765 50  0000 C CNN
F 1 "178.6165.0001" H 1850 1674 50  0000 C CNN
F 2 "Socket:17861650001" H 2100 1600 50  0001 L CNN
F 3 "https://www.mouser.com/datasheet/2/240/Littelfuse-Fuse-Holder-ATO-FLR-pcb-Datasheet-1317199.pdf" H 2100 1500 50  0001 L CNN
F 4 "FLR PCB FUSE HOLDER FOR ATO STYLE BLADE FUSE RATED 58V" H 2100 1400 50  0001 L CNN "Description"
F 5 "17.5" H 2100 1300 50  0001 L CNN "Height"
F 6 "LITTELFUSE" H 2100 1200 50  0001 L CNN "Manufacturer_Name"
F 7 "178.6165.0001" H 2100 1100 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "576-178.6165.0001" H 2100 1000 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Littelfuse/17861650001?qs=CSLd874fYV1KI1oBGU5EQg%3D%3D" H 2100 900 50  0001 L CNN "Mouser Price/Stock"
F 10 "178.6165.0001" H 2100 800 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/178.6165.0001/littelfuse" H 2100 700 50  0001 L CNN "Arrow Price/Stock"
	1    1450 1500
	1    0    0    -1  
$EndComp
$Comp
L DZ85AB-5-PCB:DZ85AB-5-PCB TESLA_RELAY1
U 1 1 619C1CB6
P 2400 2000
F 0 "TESLA_RELAY1" H 2800 2265 50  0000 C CNN
F 1 "DZ85AB-5-PCB" H 2800 2174 50  0000 C CNN
F 2 "Socket:DZ85AB5PCB" H 3050 2100 50  0001 L CNN
F 3 "https://componentsearchengine.com/Datasheets/2/DZ85AB-5-PCB.pdf" H 3050 2000 50  0001 L CNN
F 4 "Durakool 1 Pin Relay Socket, Plug In for use with Various Series" H 3050 1900 50  0001 L CNN "Description"
F 5 "14.5" H 3050 1800 50  0001 L CNN "Height"
F 6 "DURAKOOL" H 3050 1700 50  0001 L CNN "Manufacturer_Name"
F 7 "DZ85AB-5-PCB" H 3050 1600 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "" H 3050 1500 50  0001 L CNN "Mouser Part Number"
F 9 "" H 3050 1400 50  0001 L CNN "Mouser Price/Stock"
F 10 "" H 3050 1300 50  0001 L CNN "Arrow Part Number"
F 11 "" H 3050 1200 50  0001 L CNN "Arrow Price/Stock"
	1    2400 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 1600 1450 1500
Wire Wire Line
	1450 1500 1450 1150
Wire Wire Line
	1450 1150 2250 1150
Wire Wire Line
	2250 1150 2250 1500
Connection ~ 1450 1500
Wire Wire Line
	2250 1500 2250 1600
Connection ~ 2250 1500
Wire Wire Line
	1450 1700 1450 1800
Wire Wire Line
	1450 1800 1450 2000
Wire Wire Line
	1450 2000 2250 2000
Wire Wire Line
	2250 2000 2250 1800
Connection ~ 1450 1800
Wire Wire Line
	2250 1800 2250 1700
Connection ~ 2250 1800
Wire Wire Line
	2250 2000 2400 2000
Connection ~ 2250 2000
Text GLabel 3350 2000 2    50   Input ~ 0
GND
Wire Wire Line
	3350 2000 3200 2000
Text GLabel 3350 2100 2    50   Input ~ 0
CHARGER_SWITCH_B
Wire Wire Line
	3200 2100 3350 2100
Text GLabel 3350 1000 2    50   Input ~ 0
CHARGER_SWITCH_A
Text GLabel 1200 1500 0    50   Input ~ 0
PERM_12V
Wire Wire Line
	1200 1500 1450 1500
Text GLabel 1200 2200 0    50   Input ~ 0
TESLA_12V
Wire Wire Line
	2400 2200 1200 2200
$Comp
L Connector:178.6165.0001 LIM_FUSE1
U 1 1 619C5534
P 1500 3550
F 0 "LIM_FUSE1" H 1900 3815 50  0000 C CNN
F 1 "178.6165.0001" H 1900 3724 50  0000 C CNN
F 2 "Socket:17861650001" H 2150 3650 50  0001 L CNN
F 3 "https://www.mouser.com/datasheet/2/240/Littelfuse-Fuse-Holder-ATO-FLR-pcb-Datasheet-1317199.pdf" H 2150 3550 50  0001 L CNN
F 4 "FLR PCB FUSE HOLDER FOR ATO STYLE BLADE FUSE RATED 58V" H 2150 3450 50  0001 L CNN "Description"
F 5 "17.5" H 2150 3350 50  0001 L CNN "Height"
F 6 "LITTELFUSE" H 2150 3250 50  0001 L CNN "Manufacturer_Name"
F 7 "178.6165.0001" H 2150 3150 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "576-178.6165.0001" H 2150 3050 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Littelfuse/17861650001?qs=CSLd874fYV1KI1oBGU5EQg%3D%3D" H 2150 2950 50  0001 L CNN "Mouser Price/Stock"
F 10 "178.6165.0001" H 2150 2850 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/178.6165.0001/littelfuse" H 2150 2750 50  0001 L CNN "Arrow Price/Stock"
	1    1500 3550
	1    0    0    -1  
$EndComp
Text GLabel 1250 3550 0    50   Input ~ 0
PERM_12V
Text GLabel 1250 4250 0    50   Input ~ 0
LIM_12V
Wire Wire Line
	1500 3650 1500 3550
Wire Wire Line
	1500 3550 1500 3200
Wire Wire Line
	1500 3200 2300 3200
Connection ~ 1500 3550
Wire Wire Line
	2300 3200 2300 3550
Connection ~ 2300 3550
Wire Wire Line
	2300 3550 2300 3650
Wire Wire Line
	1500 3750 1500 3850
Wire Wire Line
	1500 3850 1500 4050
Wire Wire Line
	1500 4050 2300 4050
Wire Wire Line
	2300 4050 2300 3850
Connection ~ 1500 3850
Wire Wire Line
	2300 3750 2300 3850
Connection ~ 2300 3850
$Comp
L DZ85AB-5-PCB:DZ85AB-5-PCB LIM_RELAY1
U 1 1 619C7BD3
P 2450 4050
F 0 "LIM_RELAY1" H 2850 4315 50  0000 C CNN
F 1 "DZ85AB-5-PCB" H 2850 4224 50  0000 C CNN
F 2 "Socket:DZ85AB5PCB" H 3100 4150 50  0001 L CNN
F 3 "https://componentsearchengine.com/Datasheets/2/DZ85AB-5-PCB.pdf" H 3100 4050 50  0001 L CNN
F 4 "Durakool 1 Pin Relay Socket, Plug In for use with Various Series" H 3100 3950 50  0001 L CNN "Description"
F 5 "14.5" H 3100 3850 50  0001 L CNN "Height"
F 6 "DURAKOOL" H 3100 3750 50  0001 L CNN "Manufacturer_Name"
F 7 "DZ85AB-5-PCB" H 3100 3650 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "" H 3100 3550 50  0001 L CNN "Mouser Part Number"
F 9 "" H 3100 3450 50  0001 L CNN "Mouser Price/Stock"
F 10 "" H 3100 3350 50  0001 L CNN "Arrow Part Number"
F 11 "" H 3100 3250 50  0001 L CNN "Arrow Price/Stock"
	1    2450 4050
	1    0    0    -1  
$EndComp
Connection ~ 2300 4050
Wire Wire Line
	2300 4050 2450 4050
Text GLabel 3400 4050 2    50   Input ~ 0
GND
Text GLabel 3400 4150 2    50   Input ~ 0
CHARGER_SWITCH_B
Wire Wire Line
	3400 4050 3250 4050
Wire Wire Line
	3400 4150 3250 4150
Wire Wire Line
	2450 4250 1250 4250
Wire Wire Line
	1500 3550 1250 3550
$Comp
L Connector:178.6165.0001 REVERSE_LIGHT_FUSE1
U 1 1 619CC443
P 1600 6000
F 0 "REVERSE_LIGHT_FUSE1" H 2000 6265 50  0000 C CNN
F 1 "178.6165.0001" H 2000 6174 50  0000 C CNN
F 2 "Socket:17861650001" H 2250 6100 50  0001 L CNN
F 3 "https://www.mouser.com/datasheet/2/240/Littelfuse-Fuse-Holder-ATO-FLR-pcb-Datasheet-1317199.pdf" H 2250 6000 50  0001 L CNN
F 4 "FLR PCB FUSE HOLDER FOR ATO STYLE BLADE FUSE RATED 58V" H 2250 5900 50  0001 L CNN "Description"
F 5 "17.5" H 2250 5800 50  0001 L CNN "Height"
F 6 "LITTELFUSE" H 2250 5700 50  0001 L CNN "Manufacturer_Name"
F 7 "178.6165.0001" H 2250 5600 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "576-178.6165.0001" H 2250 5500 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Littelfuse/17861650001?qs=CSLd874fYV1KI1oBGU5EQg%3D%3D" H 2250 5400 50  0001 L CNN "Mouser Price/Stock"
F 10 "178.6165.0001" H 2250 5300 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/178.6165.0001/littelfuse" H 2250 5200 50  0001 L CNN "Arrow Price/Stock"
	1    1600 6000
	1    0    0    -1  
$EndComp
$Comp
L DZ85AB-5-PCB:DZ85AB-5-PCB REVERSE_LIGHT_RELAY1
U 1 1 619CD1ED
P 2600 6500
F 0 "REVERSE_LIGHT_RELAY1" H 3000 6765 50  0000 C CNN
F 1 "DZ85AB-5-PCB" H 3000 6674 50  0000 C CNN
F 2 "Socket:DZ85AB5PCB" H 3250 6600 50  0001 L CNN
F 3 "https://componentsearchengine.com/Datasheets/2/DZ85AB-5-PCB.pdf" H 3250 6500 50  0001 L CNN
F 4 "Durakool 1 Pin Relay Socket, Plug In for use with Various Series" H 3250 6400 50  0001 L CNN "Description"
F 5 "14.5" H 3250 6300 50  0001 L CNN "Height"
F 6 "DURAKOOL" H 3250 6200 50  0001 L CNN "Manufacturer_Name"
F 7 "DZ85AB-5-PCB" H 3250 6100 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "" H 3250 6000 50  0001 L CNN "Mouser Part Number"
F 9 "" H 3250 5900 50  0001 L CNN "Mouser Price/Stock"
F 10 "" H 3250 5800 50  0001 L CNN "Arrow Part Number"
F 11 "" H 3250 5700 50  0001 L CNN "Arrow Price/Stock"
	1    2600 6500
	1    0    0    -1  
$EndComp
Wire Wire Line
	1600 6000 1550 6000
Wire Wire Line
	1550 6000 1550 5600
Wire Wire Line
	1550 5600 2450 5600
Wire Wire Line
	2450 5600 2450 6000
Wire Wire Line
	2450 6000 2400 6000
Wire Wire Line
	2400 6100 2450 6100
Wire Wire Line
	2450 6100 2450 6000
Connection ~ 2450 6000
Wire Wire Line
	1600 6100 1550 6100
Wire Wire Line
	1550 6100 1550 6000
Connection ~ 1550 6000
Wire Wire Line
	1600 6200 1550 6200
Wire Wire Line
	1550 6200 1550 6300
Wire Wire Line
	1550 6500 2450 6500
Wire Wire Line
	2450 6500 2450 6300
Wire Wire Line
	2450 6200 2400 6200
Wire Wire Line
	2400 6300 2450 6300
Connection ~ 2450 6300
Wire Wire Line
	2450 6300 2450 6200
Wire Wire Line
	1600 6300 1550 6300
Connection ~ 1550 6300
Wire Wire Line
	1550 6300 1550 6500
Text GLabel 1350 6000 0    50   Input ~ 0
IGNITION_12V
Wire Wire Line
	1350 6000 1550 6000
Wire Wire Line
	2450 6500 2600 6500
Connection ~ 2450 6500
Text GLabel 3500 6500 2    50   Input ~ 0
GND
Wire Wire Line
	3400 6500 3500 6500
Text GLabel 3500 6600 2    50   Input ~ 0
REVERSE_SIGNAL
Wire Wire Line
	3400 6600 3500 6600
Text GLabel 1350 6700 0    50   Input ~ 0
REVERSE_LIGHT
Wire Wire Line
	2600 6700 1350 6700
Text GLabel 7750 1450 0    50   Input ~ 0
REVERSE_SIGNAL
Text GLabel 7750 1150 0    50   Input ~ 0
CHARGER_ON_SIGNAL
$Comp
L Connector:282836-6 REAR_1
U 1 1 619E0788
P 5750 2550
F 0 "REAR_1" H 6378 2346 50  0000 L CNN
F 1 "282836-6" H 6378 2255 50  0000 L CNN
F 2 "Socket:2828366" H 6400 2650 50  0001 L CNN
F 3 "https://www.te.com/commerce/DocumentDelivery/DDEController?Action=showdoc&DocId=Customer+Drawing%7F282836%7FJ%7Fpdf%7FEnglish%7FENG_CD_282836_J.pdf%7F282836-6" H 6400 2550 50  0001 L CNN
F 4 "Fixed Terminal Blocks 5.0MM PCB MOUNT 6P" H 6400 2450 50  0001 L CNN "Description"
F 5 "10.2" H 6400 2350 50  0001 L CNN "Height"
F 6 "TE Connectivity" H 6400 2250 50  0001 L CNN "Manufacturer_Name"
F 7 "282836-6" H 6400 2150 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "571-2828366" H 6400 2050 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/TE-Connectivity/282836-6/?qs=A%252Bip%252BNCYi6MsYFpaQLKbfg%3D%3D" H 6400 1950 50  0001 L CNN "Mouser Price/Stock"
F 10 "282836-6" H 6400 1850 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/282836-6/te-connectivity" H 6400 1750 50  0001 L CNN "Arrow Price/Stock"
	1    5750 2550
	1    0    0    -1  
$EndComp
Text GLabel 5550 2550 0    50   Input ~ 0
TESLA_12V
Wire Wire Line
	5550 2550 5750 2550
Text GLabel 5550 2750 0    50   Input ~ 0
LIM_12V
Wire Wire Line
	5550 2650 5750 2650
Text GLabel 5600 4550 0    50   Input ~ 0
CHARGER_ON_SIGNAL
Text GLabel 6550 4550 2    50   Input ~ 0
CHARGER_SWITCH_B
Text GLabel 7750 2650 0    50   Input ~ 0
CHARGER_SWITCH_A
Text GLabel 7750 2550 0    50   Input ~ 0
CHARGER_SWITCH_B
Wire Wire Line
	5550 2750 5750 2750
Wire Wire Line
	5550 2850 5750 2850
$Comp
L Diode:10A10 D1
U 1 1 619F6166
P 5750 4550
F 0 "D1" H 6050 4817 50  0000 C CNN
F 1 "10A10" H 6050 4726 50  0000 C CNN
F 2 "Diode_THT:DIOAD1165W56L425D185" H 6200 4550 50  0001 L CNN
F 3 "https://www.rectron.com/data_sheets/10a05-10a10.pdf" H 6200 4450 50  0001 L CNN
F 4 "10A10" H 6200 4350 50  0001 L CNN "Description"
F 5 "Rectron" H 6200 4150 50  0001 L CNN "Manufacturer_Name"
F 6 "10A10" H 6200 4050 50  0001 L CNN "Manufacturer_Part_Number"
F 7 "10A10" H 6200 3750 50  0001 L CNN "Arrow Part Number"
F 8 "https://www.arrow.com/en/products/10a10/rectron" H 6200 3650 50  0001 L CNN "Arrow Price/Stock"
	1    5750 4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 4550 5750 4550
Wire Wire Line
	6350 4550 6550 4550
Text GLabel 5550 3050 0    50   Input ~ 0
GND
Wire Wire Line
	5550 2950 5750 2950
Wire Wire Line
	5550 3050 5750 3050
$Comp
L Connector:282836-6 REAR_2
U 1 1 619F70DC
P 7750 2550
F 0 "REAR_2" H 8378 2346 50  0000 L CNN
F 1 "282836-6" H 8378 2255 50  0000 L CNN
F 2 "Socket:2828366" H 8400 2650 50  0001 L CNN
F 3 "https://www.te.com/commerce/DocumentDelivery/DDEController?Action=showdoc&DocId=Customer+Drawing%7F282836%7FJ%7Fpdf%7FEnglish%7FENG_CD_282836_J.pdf%7F282836-6" H 8400 2550 50  0001 L CNN
F 4 "Fixed Terminal Blocks 5.0MM PCB MOUNT 6P" H 8400 2450 50  0001 L CNN "Description"
F 5 "10.2" H 8400 2350 50  0001 L CNN "Height"
F 6 "TE Connectivity" H 8400 2250 50  0001 L CNN "Manufacturer_Name"
F 7 "282836-6" H 8400 2150 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "571-2828366" H 8400 2050 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/TE-Connectivity/282836-6/?qs=A%252Bip%252BNCYi6MsYFpaQLKbfg%3D%3D" H 8400 1950 50  0001 L CNN "Mouser Price/Stock"
F 10 "282836-6" H 8400 1850 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/282836-6/te-connectivity" H 8400 1750 50  0001 L CNN "Arrow Price/Stock"
	1    7750 2550
	1    0    0    -1  
$EndComp
Text GLabel 5550 2950 0    50   Input ~ 0
REVERSE_LIGHT
Text Notes 4950 2300 0    50   ~ 0
### Signals from front box which go directly to target ###\n\n* BRAKE_LIGHT\n* LH_REAR_INDICATOR\n* RH_REAR_INDICATOR\n* BMS 12V
$Comp
L Connector:282836-6 FRONT_2
U 1 1 62CF20E3
P 7750 1150
F 0 "FRONT_2" H 8378 946 50  0000 L CNN
F 1 "282836-6" H 8378 855 50  0000 L CNN
F 2 "Socket:2828366" H 8400 1250 50  0001 L CNN
F 3 "https://www.te.com/commerce/DocumentDelivery/DDEController?Action=showdoc&DocId=Customer+Drawing%7F282836%7FJ%7Fpdf%7FEnglish%7FENG_CD_282836_J.pdf%7F282836-6" H 8400 1150 50  0001 L CNN
F 4 "Fixed Terminal Blocks 5.0MM PCB MOUNT 6P" H 8400 1050 50  0001 L CNN "Description"
F 5 "10.2" H 8400 950 50  0001 L CNN "Height"
F 6 "TE Connectivity" H 8400 850 50  0001 L CNN "Manufacturer_Name"
F 7 "282836-6" H 8400 750 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "571-2828366" H 8400 650 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/TE-Connectivity/282836-6/?qs=A%252Bip%252BNCYi6MsYFpaQLKbfg%3D%3D" H 8400 550 50  0001 L CNN "Mouser Price/Stock"
F 10 "282836-6" H 8400 450 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/282836-6/te-connectivity" H 8400 350 50  0001 L CNN "Arrow Price/Stock"
	1    7750 1150
	1    0    0    -1  
$EndComp
Text GLabel 7750 1350 0    50   Input ~ 0
BMS_GND
Text GLabel 7750 1250 0    50   Input ~ 0
BMS_12V
Text GLabel 9850 1350 0    50   Input ~ 0
RH_REAR_INDICATOR
Text GLabel 5750 1550 0    50   Input ~ 0
BRAKE_LIGHT
Text GLabel 9850 1250 0    50   Input ~ 0
LH_REAR_INDICATOR
Text GLabel 5550 2650 0    50   Input ~ 0
TESLA_GND
Text GLabel 5550 2850 0    50   Input ~ 0
LIM_GND
Text GLabel 1200 1000 0    50   Input ~ 0
PERM_12V
Wire Wire Line
	1200 1000 3350 1000
Text GLabel 1200 2350 0    50   Input ~ 0
TESLA_GND
Text GLabel 3350 2350 2    50   Input ~ 0
GND
Wire Wire Line
	1200 2350 3350 2350
Text Notes 800  800  0    118  ~ 0
TESLA
Text Notes 850  3050 0    118  ~ 0
LIM
Text Notes 850  5400 0    118  ~ 0
REVERSE
Text GLabel 3400 4450 2    50   Input ~ 0
GND
Text GLabel 1250 4450 0    50   Input ~ 0
LIM_GND
Wire Wire Line
	3400 4450 1250 4450
$Comp
L Mechanical:MountingHole H1
U 1 1 61AB741D
P 12050 9700
F 0 "H1" H 12150 9746 50  0000 L CNN
F 1 "MountingHole" H 12150 9655 50  0000 L CNN
F 2 "MountingHole:MountingHole_3mm" H 12050 9700 50  0001 C CNN
F 3 "~" H 12050 9700 50  0001 C CNN
	1    12050 9700
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H2
U 1 1 61AB79CE
P 12900 9700
F 0 "H2" H 13000 9746 50  0000 L CNN
F 1 "MountingHole" H 13000 9655 50  0000 L CNN
F 2 "MountingHole:MountingHole_3mm" H 12900 9700 50  0001 C CNN
F 3 "~" H 12900 9700 50  0001 C CNN
	1    12900 9700
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H3
U 1 1 61AB7EEF
P 13700 9700
F 0 "H3" H 13800 9746 50  0000 L CNN
F 1 "MountingHole" H 13800 9655 50  0000 L CNN
F 2 "MountingHole:MountingHole_3mm" H 13700 9700 50  0001 C CNN
F 3 "~" H 13700 9700 50  0001 C CNN
	1    13700 9700
	1    0    0    -1  
$EndComp
$EndSCHEMATC
