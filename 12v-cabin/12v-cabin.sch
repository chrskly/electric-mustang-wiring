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
$Comp
L DZ85AB-5-PCB:DZ85AB-5-PCB IGNITION_RELAY1
U 1 1 619AAF5D
P 2950 1250
F 0 "IGNITION_RELAY1" H 3350 1515 50  0000 C CNN
F 1 "DZ85AB-5-PCB" H 3350 1424 50  0000 C CNN
F 2 "Socket:DZ85AB5PCB" H 3600 1350 50  0001 L CNN
F 3 "https://componentsearchengine.com/Datasheets/2/DZ85AB-5-PCB.pdf" H 3600 1250 50  0001 L CNN
F 4 "Durakool 1 Pin Relay Socket, Plug In for use with Various Series" H 3600 1150 50  0001 L CNN "Description"
F 5 "14.5" H 3600 1050 50  0001 L CNN "Height"
F 6 "DURAKOOL" H 3600 950 50  0001 L CNN "Manufacturer_Name"
F 7 "DZ85AB-5-PCB" H 3600 850 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "" H 3600 750 50  0001 L CNN "Mouser Part Number"
F 9 "" H 3600 650 50  0001 L CNN "Mouser Price/Stock"
F 10 "" H 3600 550 50  0001 L CNN "Arrow Part Number"
F 11 "" H 3600 450 50  0001 L CNN "Arrow Price/Stock"
	1    2950 1250
	1    0    0    -1  
$EndComp
Text GLabel 4000 1350 2    50   Input ~ 0
GND
Wire Wire Line
	3750 1250 4000 1250
Text GLabel 4000 1250 2    50   Input ~ 0
IGNITION_SWITCH_B
Wire Wire Line
	3750 1350 4000 1350
Text GLabel 2700 1250 0    50   Input ~ 0
IGNITION_12V
Wire Wire Line
	2700 2350 1900 2350
$Comp
L DZ85AB-5-PCB:DZ85AB-5-PCB HEADLIGHT_RELAY1
U 1 1 619CD1D3
P 20400 8600
F 0 "HEADLIGHT_RELAY1" H 20800 8865 50  0000 C CNN
F 1 "DZ85AB-5-PCB" H 20800 8774 50  0000 C CNN
F 2 "Socket:DZ85AB5PCB" H 21050 8700 50  0001 L CNN
F 3 "https://componentsearchengine.com/Datasheets/2/DZ85AB-5-PCB.pdf" H 21050 8600 50  0001 L CNN
F 4 "Durakool 1 Pin Relay Socket, Plug In for use with Various Series" H 21050 8500 50  0001 L CNN "Description"
F 5 "14.5" H 21050 8400 50  0001 L CNN "Height"
F 6 "DURAKOOL" H 21050 8300 50  0001 L CNN "Manufacturer_Name"
F 7 "DZ85AB-5-PCB" H 21050 8200 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "" H 21050 8100 50  0001 L CNN "Mouser Part Number"
F 9 "" H 21050 8000 50  0001 L CNN "Mouser Price/Stock"
F 10 "" H 21050 7900 50  0001 L CNN "Arrow Part Number"
F 11 "" H 21050 7800 50  0001 L CNN "Arrow Price/Stock"
	1    20400 8600
	1    0    0    -1  
$EndComp
Text GLabel 20400 8800 0    50   Input ~ 0
HEADLIGHT_12V
Text GLabel 21450 8700 2    50   Input ~ 0
GND
Text GLabel 21450 8600 2    50   Input ~ 0
HEADLIGHT_SWITCH_B
Wire Wire Line
	21200 8600 21450 8600
Wire Wire Line
	21200 8700 21450 8700
$Comp
L Connector:178.6165.0001 HEADLIGHT_FUSE1
U 1 1 619DA752
P 18350 9800
F 0 "HEADLIGHT_FUSE1" H 18750 10065 50  0000 C CNN
F 1 "178.6165.0001" H 18750 9974 50  0000 C CNN
F 2 "Socket:17861650001" H 19000 9900 50  0001 L CNN
F 3 "https://www.mouser.com/datasheet/2/240/Littelfuse-Fuse-Holder-ATO-FLR-pcb-Datasheet-1317199.pdf" H 19000 9800 50  0001 L CNN
F 4 "FLR PCB FUSE HOLDER FOR ATO STYLE BLADE FUSE RATED 58V" H 19000 9700 50  0001 L CNN "Description"
F 5 "17.5" H 19000 9600 50  0001 L CNN "Height"
F 6 "LITTELFUSE" H 19000 9500 50  0001 L CNN "Manufacturer_Name"
F 7 "178.6165.0001" H 19000 9400 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "576-178.6165.0001" H 19000 9300 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Littelfuse/17861650001?qs=CSLd874fYV1KI1oBGU5EQg%3D%3D" H 19000 9200 50  0001 L CNN "Mouser Price/Stock"
F 10 "178.6165.0001" H 19000 9100 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/178.6165.0001/littelfuse" H 19000 9000 50  0001 L CNN "Arrow Price/Stock"
	1    18350 9800
	1    0    0    -1  
$EndComp
$Comp
L DZ85AB-5-PCB:DZ85AB-5-PCB HIGHBEAM_RELAY1
U 1 1 619DC743
P 20800 10100
F 0 "HIGHBEAM_RELAY1" H 21200 10365 50  0000 C CNN
F 1 "DZ85AB-5-PCB" H 21200 10274 50  0000 C CNN
F 2 "Socket:DZ85AB5PCB" H 21450 10200 50  0001 L CNN
F 3 "https://componentsearchengine.com/Datasheets/2/DZ85AB-5-PCB.pdf" H 21450 10100 50  0001 L CNN
F 4 "Durakool 1 Pin Relay Socket, Plug In for use with Various Series" H 21450 10000 50  0001 L CNN "Description"
F 5 "14.5" H 21450 9900 50  0001 L CNN "Height"
F 6 "DURAKOOL" H 21450 9800 50  0001 L CNN "Manufacturer_Name"
F 7 "DZ85AB-5-PCB" H 21450 9700 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "" H 21450 9600 50  0001 L CNN "Mouser Part Number"
F 9 "" H 21450 9500 50  0001 L CNN "Mouser Price/Stock"
F 10 "" H 21450 9400 50  0001 L CNN "Arrow Part Number"
F 11 "" H 21450 9300 50  0001 L CNN "Arrow Price/Stock"
	1    20800 10100
	1    0    0    -1  
$EndComp
Text GLabel 18100 9800 0    50   Input ~ 0
IGNITION_12V
Wire Wire Line
	18100 9800 18350 9800
Connection ~ 18350 9800
Wire Wire Line
	19150 9800 19150 9900
Wire Wire Line
	18350 9800 18350 9900
Wire Wire Line
	18350 10000 18350 10100
Wire Wire Line
	19150 10300 19150 10100
Wire Wire Line
	19150 10000 19150 10100
Connection ~ 19150 10100
Text GLabel 21600 10200 2    50   Input ~ 0
GND
Text GLabel 21600 10100 2    50   Input ~ 0
HIGHBEAM_SWITCH_B
Text GLabel 20250 8600 0    50   Input ~ 0
RH_HEADLIGHT
$Comp
L Connector:178.6165.0001 INVERTER_FUSE1
U 1 1 619E4B09
P 1850 3600
F 0 "INVERTER_FUSE1" H 2250 3865 50  0000 C CNN
F 1 "178.6165.0001" H 2250 3774 50  0000 C CNN
F 2 "Socket:17861650001" H 2500 3700 50  0001 L CNN
F 3 "https://www.mouser.com/datasheet/2/240/Littelfuse-Fuse-Holder-ATO-FLR-pcb-Datasheet-1317199.pdf" H 2500 3600 50  0001 L CNN
F 4 "FLR PCB FUSE HOLDER FOR ATO STYLE BLADE FUSE RATED 58V" H 2500 3500 50  0001 L CNN "Description"
F 5 "17.5" H 2500 3400 50  0001 L CNN "Height"
F 6 "LITTELFUSE" H 2500 3300 50  0001 L CNN "Manufacturer_Name"
F 7 "178.6165.0001" H 2500 3200 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "576-178.6165.0001" H 2500 3100 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Littelfuse/17861650001?qs=CSLd874fYV1KI1oBGU5EQg%3D%3D" H 2500 3000 50  0001 L CNN "Mouser Price/Stock"
F 10 "178.6165.0001" H 2500 2900 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/178.6165.0001/littelfuse" H 2500 2800 50  0001 L CNN "Arrow Price/Stock"
	1    1850 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	1850 3700 1850 3600
Wire Wire Line
	1850 3200 2650 3200
Wire Wire Line
	2650 3200 2650 3600
Wire Wire Line
	2650 3600 2650 3700
Connection ~ 2650 3600
Wire Wire Line
	1850 3200 1850 3600
Connection ~ 1850 3600
Text GLabel 1650 3600 0    50   Input ~ 0
IGNITION_12V
Wire Wire Line
	1650 3600 1850 3600
Text GLabel 3050 3800 2    50   Input ~ 0
INVERTER_12V
Wire Wire Line
	2650 3800 2650 3900
Connection ~ 2650 3800
Wire Wire Line
	2650 3900 2650 4100
Wire Wire Line
	2650 4100 1850 4100
Wire Wire Line
	1850 4100 1850 3900
Connection ~ 2650 3900
Wire Wire Line
	1850 3900 1850 3800
Connection ~ 1850 3900
Wire Wire Line
	2650 3800 3050 3800
$Comp
L Connector:178.6165.0001 HVJB_FUSE1
U 1 1 619F47C4
P 1850 5600
F 0 "HVJB_FUSE1" H 2250 5865 50  0000 C CNN
F 1 "178.6165.0001" H 2250 5774 50  0000 C CNN
F 2 "Socket:17861650001" H 2500 5700 50  0001 L CNN
F 3 "https://www.mouser.com/datasheet/2/240/Littelfuse-Fuse-Holder-ATO-FLR-pcb-Datasheet-1317199.pdf" H 2500 5600 50  0001 L CNN
F 4 "FLR PCB FUSE HOLDER FOR ATO STYLE BLADE FUSE RATED 58V" H 2500 5500 50  0001 L CNN "Description"
F 5 "17.5" H 2500 5400 50  0001 L CNN "Height"
F 6 "LITTELFUSE" H 2500 5300 50  0001 L CNN "Manufacturer_Name"
F 7 "178.6165.0001" H 2500 5200 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "576-178.6165.0001" H 2500 5100 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Littelfuse/17861650001?qs=CSLd874fYV1KI1oBGU5EQg%3D%3D" H 2500 5000 50  0001 L CNN "Mouser Price/Stock"
F 10 "178.6165.0001" H 2500 4900 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/178.6165.0001/littelfuse" H 2500 4800 50  0001 L CNN "Arrow Price/Stock"
	1    1850 5600
	1    0    0    -1  
$EndComp
Wire Wire Line
	1850 5700 1850 5600
Wire Wire Line
	1850 5600 1850 5250
Wire Wire Line
	1850 5250 2650 5250
Wire Wire Line
	2650 5250 2650 5600
Connection ~ 1850 5600
Wire Wire Line
	2650 5600 2650 5700
Connection ~ 2650 5600
Text GLabel 1650 5600 0    50   Input ~ 0
IGNITION_12V
Wire Wire Line
	1650 5600 1850 5600
Text GLabel 3050 5900 2    50   Input ~ 0
HVJB_12V
Wire Wire Line
	2650 5800 2650 5900
Wire Wire Line
	2650 5900 2650 6100
Wire Wire Line
	2650 6100 1850 6100
Wire Wire Line
	1850 6100 1850 5900
Connection ~ 2650 5900
Wire Wire Line
	1850 5900 1850 5800
Connection ~ 1850 5900
Wire Wire Line
	2050 12000 2850 12000
Wire Wire Line
	2650 5900 3050 5900
$Comp
L DZ85AB-5-PCB:DZ85AB-5-PCB FWD_DRIVE_INHIBIT_RELAY1
U 1 1 61A255B6
P 13450 10650
F 0 "FWD_DRIVE_INHIBIT_RELAY1" H 13850 10915 50  0000 C CNN
F 1 "DZ85AB-5-PCB" H 13850 10824 50  0000 C CNN
F 2 "Socket:DZ85AB5PCB" H 14100 10750 50  0001 L CNN
F 3 "https://componentsearchengine.com/Datasheets/2/DZ85AB-5-PCB.pdf" H 14100 10650 50  0001 L CNN
F 4 "Durakool 1 Pin Relay Socket, Plug In for use with Various Series" H 14100 10550 50  0001 L CNN "Description"
F 5 "14.5" H 14100 10450 50  0001 L CNN "Height"
F 6 "DURAKOOL" H 14100 10350 50  0001 L CNN "Manufacturer_Name"
F 7 "DZ85AB-5-PCB" H 14100 10250 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "" H 14100 10150 50  0001 L CNN "Mouser Part Number"
F 9 "" H 14100 10050 50  0001 L CNN "Mouser Price/Stock"
F 10 "" H 14100 9950 50  0001 L CNN "Arrow Part Number"
F 11 "" H 14100 9850 50  0001 L CNN "Arrow Price/Stock"
	1    13450 10650
	1    0    0    -1  
$EndComp
Text GLabel 14450 10750 2    50   Input ~ 0
GND
Text GLabel 14450 10650 2    50   Input ~ 0
DRIVE_INHIBIT
Wire Wire Line
	14250 10650 14450 10650
Wire Wire Line
	14250 10750 14450 10750
Text GLabel 13150 10750 0    50   Input ~ 0
INVERTER_FWD
Wire Wire Line
	13150 10750 13450 10750
Text GLabel 13150 10850 0    50   Input ~ 0
SHIFTER_FWD
Wire Wire Line
	13150 10850 13450 10850
$Comp
L DZ85AB-5-PCB:DZ85AB-5-PCB REV_DRIVE_INHIBIT_RELAY1
U 1 1 61A2EA4F
P 13450 11350
F 0 "REV_DRIVE_INHIBIT_RELAY1" H 13850 11615 50  0000 C CNN
F 1 "DZ85AB-5-PCB" H 13850 11524 50  0000 C CNN
F 2 "Socket:DZ85AB5PCB" H 14100 11450 50  0001 L CNN
F 3 "https://componentsearchengine.com/Datasheets/2/DZ85AB-5-PCB.pdf" H 14100 11350 50  0001 L CNN
F 4 "Durakool 1 Pin Relay Socket, Plug In for use with Various Series" H 14100 11250 50  0001 L CNN "Description"
F 5 "14.5" H 14100 11150 50  0001 L CNN "Height"
F 6 "DURAKOOL" H 14100 11050 50  0001 L CNN "Manufacturer_Name"
F 7 "DZ85AB-5-PCB" H 14100 10950 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "" H 14100 10850 50  0001 L CNN "Mouser Part Number"
F 9 "" H 14100 10750 50  0001 L CNN "Mouser Price/Stock"
F 10 "" H 14100 10650 50  0001 L CNN "Arrow Part Number"
F 11 "" H 14100 10550 50  0001 L CNN "Arrow Price/Stock"
	1    13450 11350
	1    0    0    -1  
$EndComp
Text GLabel 14450 11450 2    50   Input ~ 0
GND
Text GLabel 14450 11350 2    50   Input ~ 0
DRIVE_INHIBIT
Wire Wire Line
	14450 11350 14250 11350
Wire Wire Line
	14450 11450 14250 11450
Text GLabel 12600 11450 0    50   Input ~ 0
INVERTER_REV
Text GLabel 13450 11550 0    50   Input ~ 0
SHIFTER_REV
$Comp
L Connector:178.6165.0001 INTERIOR_LIGHTS_FUSE1
U 1 1 61A9769C
P 19250 6800
F 0 "INTERIOR_LIGHTS_FUSE1" H 19650 7065 50  0000 C CNN
F 1 "178.6165.0001" H 19650 6974 50  0000 C CNN
F 2 "Socket:17861650001" H 19900 6900 50  0001 L CNN
F 3 "https://www.mouser.com/datasheet/2/240/Littelfuse-Fuse-Holder-ATO-FLR-pcb-Datasheet-1317199.pdf" H 19900 6800 50  0001 L CNN
F 4 "FLR PCB FUSE HOLDER FOR ATO STYLE BLADE FUSE RATED 58V" H 19900 6700 50  0001 L CNN "Description"
F 5 "17.5" H 19900 6600 50  0001 L CNN "Height"
F 6 "LITTELFUSE" H 19900 6500 50  0001 L CNN "Manufacturer_Name"
F 7 "178.6165.0001" H 19900 6400 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "576-178.6165.0001" H 19900 6300 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Littelfuse/17861650001?qs=CSLd874fYV1KI1oBGU5EQg%3D%3D" H 19900 6200 50  0001 L CNN "Mouser Price/Stock"
F 10 "178.6165.0001" H 19900 6100 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/178.6165.0001/littelfuse" H 19900 6000 50  0001 L CNN "Arrow Price/Stock"
	1    19250 6800
	1    0    0    -1  
$EndComp
Text GLabel 18750 1700 2    50   Input ~ 0
PERM_12V_REAR
Text GLabel 17850 1600 0    50   Input ~ 0
REAR_BRAKE_SIGNAL
Wire Wire Line
	19250 6800 19150 6800
Wire Wire Line
	20150 6800 20050 6800
Wire Wire Line
	20050 6900 20150 6900
Wire Wire Line
	20150 6900 20150 6800
Wire Wire Line
	19150 6800 19150 6900
Wire Wire Line
	19150 6900 19250 6900
Connection ~ 19150 6800
Wire Wire Line
	19250 7000 19150 7000
Wire Wire Line
	19150 7000 19150 7100
Wire Wire Line
	20150 7300 20150 7100
Wire Wire Line
	20150 7000 20050 7000
Wire Wire Line
	20050 7100 20150 7100
Connection ~ 20150 7100
Wire Wire Line
	20150 7100 20150 7000
Wire Wire Line
	19250 7100 19150 7100
Connection ~ 19150 7100
Wire Wire Line
	19150 7100 19150 7300
Text GLabel 19050 6800 0    50   Input ~ 0
PERM_12V_FRONT
Wire Wire Line
	19050 6800 19150 6800
$Comp
L DZ85AB-5-PCB:DZ85AB-5-PCB INTERIOR_LIGHTS_RELAY1
U 1 1 61B40E1B
P 20450 6250
F 0 "INTERIOR_LIGHTS_RELAY1" H 20850 6515 50  0000 C CNN
F 1 "DZ85AB-5-PCB" H 20850 6424 50  0000 C CNN
F 2 "Socket:DZ85AB5PCB" H 21100 6350 50  0001 L CNN
F 3 "https://componentsearchengine.com/Datasheets/2/DZ85AB-5-PCB.pdf" H 21100 6250 50  0001 L CNN
F 4 "Durakool 1 Pin Relay Socket, Plug In for use with Various Series" H 21100 6150 50  0001 L CNN "Description"
F 5 "14.5" H 21100 6050 50  0001 L CNN "Height"
F 6 "DURAKOOL" H 21100 5950 50  0001 L CNN "Manufacturer_Name"
F 7 "DZ85AB-5-PCB" H 21100 5850 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "" H 21100 5750 50  0001 L CNN "Mouser Part Number"
F 9 "" H 21100 5650 50  0001 L CNN "Mouser Price/Stock"
F 10 "" H 21100 5550 50  0001 L CNN "Arrow Part Number"
F 11 "" H 21100 5450 50  0001 L CNN "Arrow Price/Stock"
	1    20450 6250
	1    0    0    -1  
$EndComp
Text GLabel 20150 6250 0    50   Input ~ 0
INTERIOR_LIGHTS
Text GLabel 21400 6350 2    50   Input ~ 0
GND
Wire Wire Line
	21250 6250 21400 6250
Text GLabel 21400 6250 2    50   Input ~ 0
INTERIOR_LIGHT_SWITCH_B
Wire Wire Line
	21250 6350 21400 6350
Text GLabel 19050 7500 0    50   Input ~ 0
PERM_12V_FRONT
Text GLabel 21350 7500 2    50   Input ~ 0
INTERIOR_LIGHT_SWITCH_A
Wire Wire Line
	19050 7500 21350 7500
Text Notes 16750 15800 0    50   ~ 0
### ToDo ###\n\nBattery tender\nBattery box contactors?\nHigh beam signal\nturn signal signal\nStart switch? ignition\nCriuse\nInverter brake signal\n
Text GLabel 20850 1850 0    50   Input ~ 0
LH_INDICATOR_SWITCH_A
Text GLabel 20850 1950 0    50   Input ~ 0
LH_INDICATOR_SWITCH_B
Text GLabel 20850 2050 0    50   Input ~ 0
RH_INDICATOR_SWITCH_A
Text GLabel 20850 2150 0    50   Input ~ 0
RH_INDICATOR_SWITCH_B
Text GLabel 13200 1400 0    50   Input ~ 0
IGNITION_12V
Text GLabel 13200 1550 0    50   Input ~ 0
IGNITION_12V
Text GLabel 14200 1400 2    50   Input ~ 0
LH_INDICATOR_SWITCH_A
Text GLabel 14200 1550 2    50   Input ~ 0
RH_INDICATOR_SWITCH_A
Wire Wire Line
	13200 1400 14200 1400
Wire Wire Line
	13200 1550 14200 1550
$Comp
L Connector:178.6165.0001 FLASHER_FUSE1
U 1 1 61C3D229
P 13250 2350
F 0 "FLASHER_FUSE1" H 13650 2615 50  0000 C CNN
F 1 "178.6165.0001" H 13650 2524 50  0000 C CNN
F 2 "Socket:17861650001" H 13900 2450 50  0001 L CNN
F 3 "https://www.mouser.com/datasheet/2/240/Littelfuse-Fuse-Holder-ATO-FLR-pcb-Datasheet-1317199.pdf" H 13900 2350 50  0001 L CNN
F 4 "FLR PCB FUSE HOLDER FOR ATO STYLE BLADE FUSE RATED 58V" H 13900 2250 50  0001 L CNN "Description"
F 5 "17.5" H 13900 2150 50  0001 L CNN "Height"
F 6 "LITTELFUSE" H 13900 2050 50  0001 L CNN "Manufacturer_Name"
F 7 "178.6165.0001" H 13900 1950 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "576-178.6165.0001" H 13900 1850 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Littelfuse/17861650001?qs=CSLd874fYV1KI1oBGU5EQg%3D%3D" H 13900 1750 50  0001 L CNN "Mouser Price/Stock"
F 10 "178.6165.0001" H 13900 1650 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/178.6165.0001/littelfuse" H 13900 1550 50  0001 L CNN "Arrow Price/Stock"
	1    13250 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	13250 2450 13250 2350
Wire Wire Line
	13250 2350 13250 2000
Wire Wire Line
	13250 2000 14050 2000
Wire Wire Line
	14050 2000 14050 2350
Connection ~ 13250 2350
Wire Wire Line
	14050 2350 14050 2450
Connection ~ 14050 2350
Wire Wire Line
	13250 2550 13250 2650
Wire Wire Line
	13250 2650 13250 2850
Wire Wire Line
	13250 2850 14050 2850
Wire Wire Line
	14050 2850 14050 2650
Connection ~ 13250 2650
Wire Wire Line
	14050 2650 14050 2550
Connection ~ 14050 2650
Text GLabel 13150 2350 0    50   Input ~ 0
PERM_12V
Wire Wire Line
	13150 2350 13250 2350
Text GLabel 14250 13950 2    50   Input ~ 0
GND
Wire Wire Line
	14150 13850 14250 13850
Text GLabel 14250 13850 2    50   Input ~ 0
HORN_SWITCH_B
Wire Wire Line
	14150 13950 14250 13950
Text GLabel 13100 13850 0    50   Input ~ 0
HORN
Text GLabel 20850 2650 0    50   Input ~ 0
HORN_SWITCH_A
Text GLabel 20850 2750 0    50   Input ~ 0
HORN_SWITCH_B
Text GLabel 20850 1350 0    50   Input ~ 0
IGNITION_SWITCH_B
Text GLabel 20850 1250 0    50   Input ~ 0
IGNITION_SWITCH_A
Wire Wire Line
	1650 7500 1850 7500
Wire Wire Line
	1850 7800 1850 8000
Connection ~ 1850 7800
Wire Wire Line
	1900 7800 1850 7800
Wire Wire Line
	2750 7800 2750 7700
Connection ~ 2750 7800
Wire Wire Line
	2700 7800 2750 7800
Wire Wire Line
	2750 7700 2700 7700
Wire Wire Line
	2750 8000 2750 7800
Wire Wire Line
	1850 8000 2750 8000
Wire Wire Line
	1850 7700 1850 7800
Wire Wire Line
	1900 7700 1850 7700
Connection ~ 1850 7500
Wire Wire Line
	1850 7600 1850 7500
Wire Wire Line
	1900 7600 1850 7600
Wire Wire Line
	2750 7600 2700 7600
Wire Wire Line
	2750 7500 2750 7600
Wire Wire Line
	2750 7500 2700 7500
Wire Wire Line
	1900 7500 1850 7500
$Comp
L Connector:178.6165.0001 VACUUM_PUMP_FUSE1
U 1 1 6215901C
P 1900 7500
F 0 "VACUUM_PUMP_FUSE1" H 2300 7765 50  0000 C CNN
F 1 "178.6165.0001" H 2300 7674 50  0000 C CNN
F 2 "Socket:17861650001" H 2550 7600 50  0001 L CNN
F 3 "https://www.mouser.com/datasheet/2/240/Littelfuse-Fuse-Holder-ATO-FLR-pcb-Datasheet-1317199.pdf" H 2550 7500 50  0001 L CNN
F 4 "FLR PCB FUSE HOLDER FOR ATO STYLE BLADE FUSE RATED 58V" H 2550 7400 50  0001 L CNN "Description"
F 5 "17.5" H 2550 7300 50  0001 L CNN "Height"
F 6 "LITTELFUSE" H 2550 7200 50  0001 L CNN "Manufacturer_Name"
F 7 "178.6165.0001" H 2550 7100 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "576-178.6165.0001" H 2550 7000 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Littelfuse/17861650001?qs=CSLd874fYV1KI1oBGU5EQg%3D%3D" H 2550 6900 50  0001 L CNN "Mouser Price/Stock"
F 10 "178.6165.0001" H 2550 6800 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/178.6165.0001/littelfuse" H 2550 6700 50  0001 L CNN "Arrow Price/Stock"
	1    1900 7500
	1    0    0    -1  
$EndComp
Text GLabel 3000 9100 0    50   Input ~ 0
COOLANT_PUMP
Wire Wire Line
	1950 9700 2200 9700
Connection ~ 3000 10000
Wire Wire Line
	3000 10000 3000 9900
Connection ~ 2200 10000
Wire Wire Line
	3000 10200 3000 10000
Wire Wire Line
	2200 10200 3000 10200
Wire Wire Line
	2200 10000 2200 10200
Wire Wire Line
	2200 9900 2200 10000
Connection ~ 2200 9700
Wire Wire Line
	2200 9800 2200 9700
Connection ~ 3000 9700
Wire Wire Line
	3000 9700 3000 9800
Wire Wire Line
	3000 9300 3000 9700
Wire Wire Line
	2200 9300 3000 9300
Wire Wire Line
	2200 9700 2200 9300
$Comp
L Connector:178.6165.0001 COOLANT_PUMP_FUSE1
U 1 1 6204DDFD
P 2200 9700
F 0 "COOLANT_PUMP_FUSE1" H 2600 9965 50  0000 C CNN
F 1 "178.6165.0001" H 2600 9874 50  0000 C CNN
F 2 "Socket:17861650001" H 2850 9800 50  0001 L CNN
F 3 "https://www.mouser.com/datasheet/2/240/Littelfuse-Fuse-Holder-ATO-FLR-pcb-Datasheet-1317199.pdf" H 2850 9700 50  0001 L CNN
F 4 "FLR PCB FUSE HOLDER FOR ATO STYLE BLADE FUSE RATED 58V" H 2850 9600 50  0001 L CNN "Description"
F 5 "17.5" H 2850 9500 50  0001 L CNN "Height"
F 6 "LITTELFUSE" H 2850 9400 50  0001 L CNN "Manufacturer_Name"
F 7 "178.6165.0001" H 2850 9300 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "576-178.6165.0001" H 2850 9200 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Littelfuse/17861650001?qs=CSLd874fYV1KI1oBGU5EQg%3D%3D" H 2850 9100 50  0001 L CNN "Mouser Price/Stock"
F 10 "178.6165.0001" H 2850 9000 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/178.6165.0001/littelfuse" H 2850 8900 50  0001 L CNN "Arrow Price/Stock"
	1    2200 9700
	1    0    0    -1  
$EndComp
Wire Wire Line
	2850 12700 3000 12700
Wire Wire Line
	1850 12400 2050 12400
Text GLabel 3850 11800 2    50   Input ~ 0
IGNITION_12V
Connection ~ 2850 12700
Wire Wire Line
	2850 12700 2850 12600
Connection ~ 2050 12700
Wire Wire Line
	2850 12900 2850 12700
Wire Wire Line
	2050 12900 2850 12900
Wire Wire Line
	2050 12700 2050 12900
Wire Wire Line
	2050 12600 2050 12700
Connection ~ 2850 12400
Wire Wire Line
	2850 12400 2850 12500
Connection ~ 2050 12400
Wire Wire Line
	2850 12000 2850 12400
Wire Wire Line
	2050 12400 2050 12000
Wire Wire Line
	2050 12500 2050 12400
$Comp
L Connector:178.6165.0001 RADIO_FUSE1
U 1 1 61A090EC
P 2050 12400
F 0 "RADIO_FUSE1" H 2450 12665 50  0000 C CNN
F 1 "178.6165.0001" H 2450 12574 50  0000 C CNN
F 2 "Socket:17861650001" H 2700 12500 50  0001 L CNN
F 3 "https://www.mouser.com/datasheet/2/240/Littelfuse-Fuse-Holder-ATO-FLR-pcb-Datasheet-1317199.pdf" H 2700 12400 50  0001 L CNN
F 4 "FLR PCB FUSE HOLDER FOR ATO STYLE BLADE FUSE RATED 58V" H 2700 12300 50  0001 L CNN "Description"
F 5 "17.5" H 2700 12200 50  0001 L CNN "Height"
F 6 "LITTELFUSE" H 2700 12100 50  0001 L CNN "Manufacturer_Name"
F 7 "178.6165.0001" H 2700 12000 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "576-178.6165.0001" H 2700 11900 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Littelfuse/17861650001?qs=CSLd874fYV1KI1oBGU5EQg%3D%3D" H 2700 11800 50  0001 L CNN "Mouser Price/Stock"
F 10 "178.6165.0001" H 2700 11700 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/178.6165.0001/littelfuse" H 2700 11600 50  0001 L CNN "Arrow Price/Stock"
	1    2050 12400
	1    0    0    -1  
$EndComp
Text GLabel 20850 1650 0    50   Input ~ 0
HIGHBEAM_SWITCH_A
Text GLabel 20850 1750 0    50   Input ~ 0
HIGHBEAM_SWITCH_B
Text GLabel 19150 10500 0    50   Input ~ 0
IGNITION_12V
Text GLabel 21600 10500 2    50   Input ~ 0
HIGHBEAM_SWITCH_A
Wire Wire Line
	19150 10500 21600 10500
Text GLabel 21450 9000 2    50   Input ~ 0
HEADLIGHT_SWITCH_A
Text GLabel 19000 9000 0    50   Input ~ 0
IGNITION_12V
Wire Wire Line
	19000 9000 21450 9000
Wire Wire Line
	18350 9800 18350 9450
Wire Wire Line
	18350 9450 19150 9450
Wire Wire Line
	19150 9450 19150 9800
Connection ~ 19150 9800
Wire Wire Line
	19150 6800 19150 6450
Wire Wire Line
	20150 6450 20150 6800
Connection ~ 20150 6800
Text GLabel 20850 1450 0    50   Input ~ 0
HEADLIGHT_SWITCH_A
Text GLabel 20850 1550 0    50   Input ~ 0
HEADLIGHT_SWITCH_B
Wire Wire Line
	3000 10000 3150 10000
Text GLabel 20850 2550 0    50   Input ~ 0
INTERIOR_LIGHT_SWITCH_B
Text GLabel 20850 2450 0    50   Input ~ 0
INTERIOR_LIGHT_SWITCH_A
Text GLabel 21850 1050 2    50   Input ~ 0
INTERIOR_LIGHTS
Text GLabel 17250 2450 0    50   Input ~ 0
DASHBOARD_12V
Text GLabel 21850 1250 2    50   Input ~ 0
RADIO_12V
Text GLabel 17250 2550 0    50   Input ~ 0
DASH_INDICATOR_INDICATOR
Text GLabel 20850 1050 0    50   Input ~ 0
HAZARD_SWITCH_A
Text GLabel 20850 1150 0    50   Input ~ 0
HAZARD_SWITCH_B
Wire Wire Line
	2900 7800 2750 7800
Text GLabel 17250 2650 0    50   Input ~ 0
DASHBOARD_GND
Text GLabel 1650 4250 0    50   Input ~ 0
INVERTER_GND
Text GLabel 3050 4250 2    50   Input ~ 0
GND
Wire Wire Line
	1650 4250 3050 4250
Text GLabel 1650 6250 0    50   Input ~ 0
HVJB_GND
Text GLabel 3050 6250 2    50   Input ~ 0
GND
Wire Wire Line
	1650 6250 3050 6250
$Comp
L Connector:178.6165.0001 HEATER_FAN_FUSE1
U 1 1 62A58892
P 7200 12150
F 0 "HEATER_FAN_FUSE1" H 7600 12415 50  0000 C CNN
F 1 "178.6165.0001" H 7600 12324 50  0000 C CNN
F 2 "Socket:17861650001" H 7850 12250 50  0001 L CNN
F 3 "https://www.mouser.com/datasheet/2/240/Littelfuse-Fuse-Holder-ATO-FLR-pcb-Datasheet-1317199.pdf" H 7850 12150 50  0001 L CNN
F 4 "FLR PCB FUSE HOLDER FOR ATO STYLE BLADE FUSE RATED 58V" H 7850 12050 50  0001 L CNN "Description"
F 5 "17.5" H 7850 11950 50  0001 L CNN "Height"
F 6 "LITTELFUSE" H 7850 11850 50  0001 L CNN "Manufacturer_Name"
F 7 "178.6165.0001" H 7850 11750 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "576-178.6165.0001" H 7850 11650 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Littelfuse/17861650001?qs=CSLd874fYV1KI1oBGU5EQg%3D%3D" H 7850 11550 50  0001 L CNN "Mouser Price/Stock"
F 10 "178.6165.0001" H 7850 11450 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/178.6165.0001/littelfuse" H 7850 11350 50  0001 L CNN "Arrow Price/Stock"
	1    7200 12150
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 12250 7200 12150
Wire Wire Line
	7200 12150 7200 11750
Wire Wire Line
	7200 11750 8000 11750
Wire Wire Line
	8000 11750 8000 12150
Connection ~ 7200 12150
Wire Wire Line
	8000 12150 8000 12250
Connection ~ 8000 12150
Wire Wire Line
	7200 12350 7200 12450
Wire Wire Line
	7200 12450 7200 12650
Wire Wire Line
	7200 12650 8000 12650
Wire Wire Line
	8000 12650 8000 12450
Connection ~ 7200 12450
Wire Wire Line
	8000 12450 8000 12350
Connection ~ 8000 12450
Text GLabel 7000 12150 0    50   Input ~ 0
IGNITION_12V
Wire Wire Line
	7000 12150 7200 12150
Text GLabel 8250 12450 2    50   Input ~ 0
HEATER_FAN_12V
Wire Wire Line
	8000 12450 8250 12450
$Comp
L Mechanical:MountingHole H1
U 1 1 62B406FE
P 18700 14500
F 0 "H1" H 18800 14546 50  0000 L CNN
F 1 "MountingHole" H 18800 14455 50  0000 L CNN
F 2 "MountingHole:MountingHole_3mm" H 18700 14500 50  0001 C CNN
F 3 "~" H 18700 14500 50  0001 C CNN
	1    18700 14500
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H2
U 1 1 62B41D12
P 19450 14500
F 0 "H2" H 19550 14546 50  0000 L CNN
F 1 "MountingHole" H 19550 14455 50  0000 L CNN
F 2 "MountingHole:MountingHole_3mm" H 19450 14500 50  0001 C CNN
F 3 "~" H 19450 14500 50  0001 C CNN
	1    19450 14500
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H4
U 1 1 62B615E9
P 20950 14500
F 0 "H4" H 21050 14546 50  0000 L CNN
F 1 "MountingHole" H 21050 14455 50  0000 L CNN
F 2 "MountingHole:MountingHole_3mm" H 20950 14500 50  0001 C CNN
F 3 "~" H 20950 14500 50  0001 C CNN
	1    20950 14500
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H3
U 1 1 62B61F4D
P 20200 14500
F 0 "H3" H 20300 14546 50  0000 L CNN
F 1 "MountingHole" H 20300 14455 50  0000 L CNN
F 2 "MountingHole:MountingHole_3mm" H 20200 14500 50  0001 C CNN
F 3 "~" H 20200 14500 50  0001 C CNN
	1    20200 14500
	1    0    0    -1  
$EndComp
Text GLabel 12600 11550 0    50   Input ~ 0
REVERSE_SIGNAL
Wire Wire Line
	12700 11450 12700 11550
Wire Wire Line
	12700 11550 12600 11550
Connection ~ 12700 11450
Wire Wire Line
	12700 11450 12600 11450
Text GLabel 17850 1700 0    50   Input ~ 0
REVERSE_SIGNAL
Text GLabel 20850 2250 0    50   Input ~ 0
BRAKE_SWITCH_A
Text GLabel 20850 2350 0    50   Input ~ 0
BRAKE_SWITCH_B
Text GLabel 7300 14050 0    50   Input ~ 0
IGNITION_12V
Text GLabel 7750 14050 2    50   Input ~ 0
BRAKE_SWITCH_A
Wire Wire Line
	7300 14050 7750 14050
Text GLabel 7300 14150 0    50   Input ~ 0
BRAKE_SWITCH_B
Text GLabel 7750 14150 2    50   Input ~ 0
REAR_BRAKE_SIGNAL
Wire Wire Line
	7300 14150 7650 14150
Text GLabel 7750 14250 2    50   Input ~ 0
INVERTER_BRAKE_SIGNAL
Wire Wire Line
	7750 14250 7650 14250
Wire Wire Line
	7650 14250 7650 14150
Connection ~ 7650 14150
Wire Wire Line
	7650 14150 7750 14150
Text GLabel 17850 1500 0    50   Input ~ 0
CHARGER_ON_SIGNAL
Wire Wire Line
	7150 2750 7700 2750
Text GLabel 7700 2750 2    50   Input ~ 0
GND
Text GLabel 7150 2750 0    50   Input ~ 0
DASHBOARD_GND
Wire Wire Line
	2150 15700 2400 15700
Text GLabel 2800 15700 2    50   Input ~ 0
GND
Text GLabel 2150 15700 0    50   Input ~ 0
BMS_FRONT_GND
Wire Wire Line
	13550 4750 13750 4750
Wire Wire Line
	12800 4750 12950 4750
Text GLabel 12800 4750 0    50   Input ~ 0
DASH_INDICATOR_INDICATOR
Wire Wire Line
	13100 5200 14050 5200
Wire Wire Line
	13100 5000 13750 5000
$Comp
L Diode:10A10 D10
U 1 1 623366B3
P 12950 4750
F 0 "D10" H 13250 5017 50  0000 C CNN
F 1 "10A10" H 13250 4926 50  0000 C CNN
F 2 "Diode_THT:DIOAD1165W56L425D185" H 13400 4750 50  0001 L CNN
F 3 "https://www.rectron.com/data_sheets/10a05-10a10.pdf" H 13400 4650 50  0001 L CNN
F 4 "10A10" H 13400 4550 50  0001 L CNN "Description"
F 5 "Rectron" H 13400 4350 50  0001 L CNN "Manufacturer_Name"
F 6 "10A10" H 13400 4250 50  0001 L CNN "Manufacturer_Part_Number"
F 7 "10A10" H 13400 3950 50  0001 L CNN "Arrow Part Number"
F 8 "https://www.arrow.com/en/products/10a10/rectron" H 13400 3850 50  0001 L CNN "Arrow Price/Stock"
	1    12950 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	13450 3950 14400 3950
Wire Wire Line
	13450 3750 14050 3750
Wire Wire Line
	13100 3450 13300 3450
Text GLabel 13100 3450 0    50   Input ~ 0
DASH_INDICATOR_INDICATOR
Wire Wire Line
	14050 3450 13900 3450
$Comp
L Diode:10A10 D9
U 1 1 62273542
P 13300 3450
F 0 "D9" H 13600 3717 50  0000 C CNN
F 1 "10A10" H 13600 3626 50  0000 C CNN
F 2 "Diode_THT:DIOAD1165W56L425D185" H 13750 3450 50  0001 L CNN
F 3 "https://www.rectron.com/data_sheets/10a05-10a10.pdf" H 13750 3350 50  0001 L CNN
F 4 "10A10" H 13750 3250 50  0001 L CNN "Description"
F 5 "Rectron" H 13750 3050 50  0001 L CNN "Manufacturer_Name"
F 6 "10A10" H 13750 2950 50  0001 L CNN "Manufacturer_Part_Number"
F 7 "10A10" H 13750 2650 50  0001 L CNN "Arrow Part Number"
F 8 "https://www.arrow.com/en/products/10a10/rectron" H 13750 2550 50  0001 L CNN "Arrow Price/Stock"
	1    13300 3450
	1    0    0    -1  
$EndComp
Text GLabel 13450 3750 0    50   Input ~ 0
LH_FRONT_INDICATOR
Text GLabel 7700 1500 0    50   Input ~ 0
DASHBOARD_12V
Text GLabel 3050 11800 0    50   Input ~ 0
RADIO_12V
$Comp
L Diode:10A10 D8
U 1 1 61E6E87E
P 4450 15750
F 0 "D8" H 4750 16017 50  0000 C CNN
F 1 "10A10" H 4750 15926 50  0000 C CNN
F 2 "Diode_THT:DIOAD1165W56L425D185" H 4900 15750 50  0001 L CNN
F 3 "https://www.rectron.com/data_sheets/10a05-10a10.pdf" H 4900 15650 50  0001 L CNN
F 4 "10A10" H 4900 15550 50  0001 L CNN "Description"
F 5 "Rectron" H 4900 15350 50  0001 L CNN "Manufacturer_Name"
F 6 "10A10" H 4900 15250 50  0001 L CNN "Manufacturer_Part_Number"
F 7 "10A10" H 4900 14950 50  0001 L CNN "Arrow Part Number"
F 8 "https://www.arrow.com/en/products/10a10/rectron" H 4900 14850 50  0001 L CNN "Arrow Price/Stock"
	1    4450 15750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 15300 4400 14950
Connection ~ 4400 15300
Wire Wire Line
	4450 15300 4400 15300
Wire Wire Line
	4400 15750 4400 15300
Wire Wire Line
	4450 15750 4400 15750
Wire Wire Line
	5150 15750 5050 15750
Wire Wire Line
	5150 15300 5050 15300
Text GLabel 5150 15750 2    50   Input ~ 0
CHARGER_ON_SIGNAL
Text GLabel 5150 15300 2    50   Input ~ 0
IGNITION_12V
$Comp
L Diode:10A10 D7
U 1 1 61E46E3E
P 4450 15300
F 0 "D7" H 4750 15567 50  0000 C CNN
F 1 "10A10" H 4750 15476 50  0000 C CNN
F 2 "Diode_THT:DIOAD1165W56L425D185" H 4900 15300 50  0001 L CNN
F 3 "https://www.rectron.com/data_sheets/10a05-10a10.pdf" H 4900 15200 50  0001 L CNN
F 4 "10A10" H 4900 15100 50  0001 L CNN "Description"
F 5 "Rectron" H 4900 14900 50  0001 L CNN "Manufacturer_Name"
F 6 "10A10" H 4900 14800 50  0001 L CNN "Manufacturer_Part_Number"
F 7 "10A10" H 4900 14500 50  0001 L CNN "Arrow Part Number"
F 8 "https://www.arrow.com/en/products/10a10/rectron" H 4900 14400 50  0001 L CNN "Arrow Price/Stock"
	1    4450 15300
	1    0    0    -1  
$EndComp
Text GLabel 3950 15050 2    50   Input ~ 0
GND
Text GLabel 3050 14950 0    50   Input ~ 0
BMS_REAR_12V
Connection ~ 2300 15150
$Comp
L DZ85AB-5-PCB:DZ85AB-5-PCB BMS_RELAY1
U 1 1 61E2135A
P 3150 14950
F 0 "BMS_RELAY1" H 3550 15215 50  0000 C CNN
F 1 "DZ85AB-5-PCB" H 3550 15124 50  0000 C CNN
F 2 "Socket:DZ85AB5PCB" H 3800 15050 50  0001 L CNN
F 3 "https://componentsearchengine.com/Datasheets/2/DZ85AB-5-PCB.pdf" H 3800 14950 50  0001 L CNN
F 4 "Durakool 1 Pin Relay Socket, Plug In for use with Various Series" H 3800 14850 50  0001 L CNN "Description"
F 5 "14.5" H 3800 14750 50  0001 L CNN "Height"
F 6 "DURAKOOL" H 3800 14650 50  0001 L CNN "Manufacturer_Name"
F 7 "DZ85AB-5-PCB" H 3800 14550 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "" H 3800 14450 50  0001 L CNN "Mouser Part Number"
F 9 "" H 3800 14350 50  0001 L CNN "Mouser Price/Stock"
F 10 "" H 3800 14250 50  0001 L CNN "Arrow Part Number"
F 11 "" H 3800 14150 50  0001 L CNN "Arrow Price/Stock"
	1    3150 14950
	1    0    0    -1  
$EndComp
Wire Wire Line
	1300 14550 1500 14550
Text GLabel 1300 14550 0    50   Input ~ 0
PERM_12V
Connection ~ 2300 14950
Wire Wire Line
	2300 14950 2300 14850
Connection ~ 1500 14950
Wire Wire Line
	2300 15150 2300 14950
Wire Wire Line
	1500 15150 2300 15150
Wire Wire Line
	1500 14950 1500 15150
Wire Wire Line
	1500 14850 1500 14950
Connection ~ 1500 14550
Wire Wire Line
	1500 14550 1500 14650
Wire Wire Line
	1500 14150 2300 14150
Wire Wire Line
	1500 14550 1500 14150
$Comp
L Connector:178.6165.0001 BMS_FUSE1
U 1 1 61DD02E0
P 1500 14650
F 0 "BMS_FUSE1" H 1900 14915 50  0000 C CNN
F 1 "178.6165.0001" H 1900 14824 50  0000 C CNN
F 2 "Socket:17861650001" H 2150 14750 50  0001 L CNN
F 3 "https://www.mouser.com/datasheet/2/240/Littelfuse-Fuse-Holder-ATO-FLR-pcb-Datasheet-1317199.pdf" H 2150 14650 50  0001 L CNN
F 4 "FLR PCB FUSE HOLDER FOR ATO STYLE BLADE FUSE RATED 58V" H 2150 14550 50  0001 L CNN "Description"
F 5 "17.5" H 2150 14450 50  0001 L CNN "Height"
F 6 "LITTELFUSE" H 2150 14350 50  0001 L CNN "Manufacturer_Name"
F 7 "178.6165.0001" H 2150 14250 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "576-178.6165.0001" H 2150 14150 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Littelfuse/17861650001?qs=CSLd874fYV1KI1oBGU5EQg%3D%3D" H 2150 14050 50  0001 L CNN "Mouser Price/Stock"
F 10 "178.6165.0001" H 2150 13950 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/178.6165.0001/littelfuse" H 2150 13850 50  0001 L CNN "Arrow Price/Stock"
	1    1500 14650
	1    0    0    -1  
$EndComp
Text GLabel 13100 5000 0    50   Input ~ 0
RH_FRONT_INDICATOR
Text GLabel 16300 3750 2    50   Input ~ 0
LH_INDICATOR_SWITCH_B
Text GLabel 13100 5200 0    50   Input ~ 0
FLASHER_B
Text GLabel 13450 3950 0    50   Input ~ 0
FLASHER_B
$Comp
L DZ85AB-5-PCB:DZ85AB-5-PCB RH_INDICATOR_RELAY1
U 1 1 619D6071
P 14050 5000
F 0 "RH_INDICATOR_RELAY1" H 14450 5265 50  0000 C CNN
F 1 "DZ85AB-5-PCB" H 14450 5174 50  0000 C CNN
F 2 "Socket:DZ85AB5PCB" H 14700 5100 50  0001 L CNN
F 3 "https://componentsearchengine.com/Datasheets/2/DZ85AB-5-PCB.pdf" H 14700 5000 50  0001 L CNN
F 4 "Durakool 1 Pin Relay Socket, Plug In for use with Various Series" H 14700 4900 50  0001 L CNN "Description"
F 5 "14.5" H 14700 4800 50  0001 L CNN "Height"
F 6 "DURAKOOL" H 14700 4700 50  0001 L CNN "Manufacturer_Name"
F 7 "DZ85AB-5-PCB" H 14700 4600 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "" H 14700 4500 50  0001 L CNN "Mouser Part Number"
F 9 "" H 14700 4400 50  0001 L CNN "Mouser Price/Stock"
F 10 "" H 14700 4300 50  0001 L CNN "Arrow Part Number"
F 11 "" H 14700 4200 50  0001 L CNN "Arrow Price/Stock"
	1    14050 5000
	1    0    0    -1  
$EndComp
$Comp
L DZ85AB-5-PCB:DZ85AB-5-PCB LH_INDICATOR_RELAY1
U 1 1 619D5B0E
P 14400 3750
F 0 "LH_INDICATOR_RELAY1" H 14800 4015 50  0000 C CNN
F 1 "DZ85AB-5-PCB" H 14800 3924 50  0000 C CNN
F 2 "Socket:DZ85AB5PCB" H 15050 3850 50  0001 L CNN
F 3 "https://componentsearchengine.com/Datasheets/2/DZ85AB-5-PCB.pdf" H 15050 3750 50  0001 L CNN
F 4 "Durakool 1 Pin Relay Socket, Plug In for use with Various Series" H 15050 3650 50  0001 L CNN "Description"
F 5 "14.5" H 15050 3550 50  0001 L CNN "Height"
F 6 "DURAKOOL" H 15050 3450 50  0001 L CNN "Manufacturer_Name"
F 7 "DZ85AB-5-PCB" H 15050 3350 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "" H 15050 3250 50  0001 L CNN "Mouser Part Number"
F 9 "" H 15050 3150 50  0001 L CNN "Mouser Price/Stock"
F 10 "" H 15050 3050 50  0001 L CNN "Arrow Part Number"
F 11 "" H 15050 2950 50  0001 L CNN "Arrow Price/Stock"
	1    14400 3750
	1    0    0    -1  
$EndComp
Text GLabel 8850 1600 2    50   Input ~ 0
GND
Wire Wire Line
	6800 2050 7000 2050
Text GLabel 6800 2050 0    50   Input ~ 0
PERM_12V
Connection ~ 7800 2350
Wire Wire Line
	7800 2350 7800 2250
Connection ~ 7000 2350
Wire Wire Line
	7800 2550 7800 2350
Wire Wire Line
	7000 2550 7800 2550
Wire Wire Line
	7000 2350 7000 2550
Wire Wire Line
	7000 2250 7000 2350
Connection ~ 7000 2050
Wire Wire Line
	7000 2150 7000 2050
Connection ~ 7800 2050
Wire Wire Line
	7800 2050 7800 2150
Wire Wire Line
	7800 1700 7800 2050
Wire Wire Line
	7000 1700 7800 1700
Wire Wire Line
	7000 2050 7000 1700
$Comp
L Connector:178.6165.0001 DASHBOARD_FUSE1
U 1 1 61B6FF00
P 7000 2050
F 0 "DASHBOARD_FUSE1" H 7400 2315 50  0000 C CNN
F 1 "178.6165.0001" H 7400 2224 50  0000 C CNN
F 2 "Socket:17861650001" H 7650 2150 50  0001 L CNN
F 3 "https://www.mouser.com/datasheet/2/240/Littelfuse-Fuse-Holder-ATO-FLR-pcb-Datasheet-1317199.pdf" H 7650 2050 50  0001 L CNN
F 4 "FLR PCB FUSE HOLDER FOR ATO STYLE BLADE FUSE RATED 58V" H 7650 1950 50  0001 L CNN "Description"
F 5 "17.5" H 7650 1850 50  0001 L CNN "Height"
F 6 "LITTELFUSE" H 7650 1750 50  0001 L CNN "Manufacturer_Name"
F 7 "178.6165.0001" H 7650 1650 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "576-178.6165.0001" H 7650 1550 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Littelfuse/17861650001?qs=CSLd874fYV1KI1oBGU5EQg%3D%3D" H 7650 1450 50  0001 L CNN "Mouser Price/Stock"
F 10 "178.6165.0001" H 7650 1350 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/178.6165.0001/littelfuse" H 7650 1250 50  0001 L CNN "Arrow Price/Stock"
	1    7000 2050
	1    0    0    -1  
$EndComp
Text GLabel 18250 3750 0    50   Input ~ 0
SHIFTER_12V
Text GLabel 16350 1350 0    50   Input ~ 0
12V_BATT
Text GLabel 16350 1150 0    50   Input ~ 0
FLASHER_B
Text GLabel 16350 1050 0    50   Input ~ 0
FLASHER_A
Text GLabel 20900 4150 0    50   Input ~ 0
INVERTER_FWD
Text GLabel 20900 4250 0    50   Input ~ 0
INVERTER_REV
Text GLabel 18250 3950 0    50   Input ~ 0
SHIFTER_FWD
Text GLabel 18250 3850 0    50   Input ~ 0
SHIFTER_REV
Text GLabel 20900 4050 0    50   Input ~ 0
INVERTER_BRAKE_SIGNAL
Text GLabel 20900 3950 0    50   Input ~ 0
INVERTER_GND
Text GLabel 21800 4250 2    50   Input ~ 0
HVJB_GND
Text GLabel 20900 3750 0    50   Input ~ 0
BMS_FRONT_GND
Text GLabel 20900 3650 0    50   Input ~ 0
BMS_FRONT_12V
Text GLabel 21800 4150 2    50   Input ~ 0
HVJB_12V
Text GLabel 20900 3850 0    50   Input ~ 0
INVERTER_12V
Text GLabel 17850 1300 0    50   Input ~ 0
LH_REAR_INDICATOR
Text GLabel 21800 3950 2    50   Input ~ 0
RH_FRONT_INDICATOR
Text GLabel 20900 4650 0    50   Input ~ 0
LH_HEADLIGHT
Text GLabel 21800 3650 2    50   Input ~ 0
LH_HIGHBEAM
Text GLabel 16350 1450 0    50   Input ~ 0
GND
Text GLabel 21800 4050 2    50   Input ~ 0
HORN
Text GLabel 20900 4550 0    50   Input ~ 0
COOLANT_PUMP
Text GLabel 20900 4350 0    50   Input ~ 0
VACUUM_PUMP
Text Notes 16750 14550 0    50   ~ 0
CHARGER_ON_SIGNAL - signal from rear\nbox to indicate charging has been initiated.\nTurns on dashboard so it can show charge\nstatus.
Text Notes 12400 950  0    118  ~ 0
INDICATORS / HAZARDS
Text GLabel 14200 1700 2    50   Input ~ 0
HAZARD_SWITCH_A
Text GLabel 13200 1700 0    50   Input ~ 0
PERM_12V
Wire Wire Line
	13200 1700 14200 1700
Text GLabel 14200 2650 2    50   Input ~ 0
FLASHER_A
$Comp
L Diode:10A10 D11
U 1 1 6478ACFE
P 15700 3750
F 0 "D11" H 16000 4017 50  0000 C CNN
F 1 "10A10" H 16000 3926 50  0000 C CNN
F 2 "Diode_THT:DIOAD1165W56L425D185" H 16150 3750 50  0001 L CNN
F 3 "https://www.rectron.com/data_sheets/10a05-10a10.pdf" H 16150 3650 50  0001 L CNN
F 4 "10A10" H 16150 3550 50  0001 L CNN "Description"
F 5 "Rectron" H 16150 3350 50  0001 L CNN "Manufacturer_Name"
F 6 "10A10" H 16150 3250 50  0001 L CNN "Manufacturer_Part_Number"
F 7 "10A10" H 16150 2950 50  0001 L CNN "Arrow Part Number"
F 8 "https://www.arrow.com/en/products/10a10/rectron" H 16150 2850 50  0001 L CNN "Arrow Price/Stock"
	1    15700 3750
	1    0    0    -1  
$EndComp
$Comp
L Diode:10A10 D12
U 1 1 647C89BA
P 15700 4250
F 0 "D12" H 16000 4517 50  0000 C CNN
F 1 "10A10" H 16000 4426 50  0000 C CNN
F 2 "Diode_THT:DIOAD1165W56L425D185" H 16150 4250 50  0001 L CNN
F 3 "https://www.rectron.com/data_sheets/10a05-10a10.pdf" H 16150 4150 50  0001 L CNN
F 4 "10A10" H 16150 4050 50  0001 L CNN "Description"
F 5 "Rectron" H 16150 3850 50  0001 L CNN "Manufacturer_Name"
F 6 "10A10" H 16150 3750 50  0001 L CNN "Manufacturer_Part_Number"
F 7 "10A10" H 16150 3450 50  0001 L CNN "Arrow Part Number"
F 8 "https://www.arrow.com/en/products/10a10/rectron" H 16150 3350 50  0001 L CNN "Arrow Price/Stock"
	1    15700 4250
	1    0    0    -1  
$EndComp
Text GLabel 16300 4250 2    50   Input ~ 0
HAZARD_SWITCH_B
Wire Wire Line
	15700 3750 15700 4250
Connection ~ 15700 3750
Wire Wire Line
	14050 2650 14200 2650
Text GLabel 15200 3850 2    50   Input ~ 0
GND
Text GLabel 14850 5100 2    50   Input ~ 0
GND
$Comp
L Diode:10A10 D13
U 1 1 64924F75
P 15350 5000
F 0 "D13" H 15650 5267 50  0000 C CNN
F 1 "10A10" H 15650 5176 50  0000 C CNN
F 2 "Diode_THT:DIOAD1165W56L425D185" H 15800 5000 50  0001 L CNN
F 3 "https://www.rectron.com/data_sheets/10a05-10a10.pdf" H 15800 4900 50  0001 L CNN
F 4 "10A10" H 15800 4800 50  0001 L CNN "Description"
F 5 "Rectron" H 15800 4600 50  0001 L CNN "Manufacturer_Name"
F 6 "10A10" H 15800 4500 50  0001 L CNN "Manufacturer_Part_Number"
F 7 "10A10" H 15800 4200 50  0001 L CNN "Arrow Part Number"
F 8 "https://www.arrow.com/en/products/10a10/rectron" H 15800 4100 50  0001 L CNN "Arrow Price/Stock"
	1    15350 5000
	1    0    0    -1  
$EndComp
$Comp
L Diode:10A10 D14
U 1 1 649253D4
P 15350 5500
F 0 "D14" H 15650 5767 50  0000 C CNN
F 1 "10A10" H 15650 5676 50  0000 C CNN
F 2 "Diode_THT:DIOAD1165W56L425D185" H 15800 5500 50  0001 L CNN
F 3 "https://www.rectron.com/data_sheets/10a05-10a10.pdf" H 15800 5400 50  0001 L CNN
F 4 "10A10" H 15800 5300 50  0001 L CNN "Description"
F 5 "Rectron" H 15800 5100 50  0001 L CNN "Manufacturer_Name"
F 6 "10A10" H 15800 5000 50  0001 L CNN "Manufacturer_Part_Number"
F 7 "10A10" H 15800 4700 50  0001 L CNN "Arrow Part Number"
F 8 "https://www.arrow.com/en/products/10a10/rectron" H 15800 4600 50  0001 L CNN "Arrow Price/Stock"
	1    15350 5500
	1    0    0    -1  
$EndComp
Text GLabel 15950 5000 2    50   Input ~ 0
RH_INDICATOR_SWITCH_B
Text GLabel 15950 5500 2    50   Input ~ 0
HAZARD_SWITCH_B
Wire Wire Line
	15350 5500 15350 5000
Connection ~ 15350 5000
Text GLabel 20900 4450 0    50   Input ~ 0
HEATER_FAN_12V
Text GLabel 17250 2750 0    50   Input ~ 0
DASH_HIGHBEAM_INDICATOR
Text GLabel 13600 12050 0    50   Input ~ 0
SHIFTER_12V
Text GLabel 13800 12050 2    50   Input ~ 0
IGNITION_12V
Wire Wire Line
	13600 12050 13800 12050
Text Notes 850  13700 0    118  ~ 0
BMS
Wire Wire Line
	2300 14150 2300 14650
Text Notes 12550 10200 0    118  ~ 0
DRIVE INHIBIT
Text Notes 7050 900  0    118  ~ 0
DASHBOARD
Text Notes 12350 13650 0    118  ~ 0
HORN
Text Notes 19100 8150 0    118  ~ 0
HEADLIGHT
Text Notes 1050 850  0    118  ~ 0
IGNITION
Text Notes 18750 5850 0    118  ~ 0
INTERIOR LIGHTS
Text Notes 1250 3000 0    118  ~ 0
INVERTER
Text Notes 1200 5000 0    118  ~ 0
HVJB
Text Notes 1100 11550 0    118  ~ 0
RADIO
Text Notes 1000 6800 0    118  ~ 0
VACUUM
Text Notes 1150 8600 0    118  ~ 0
COOLANT PUMP
Text Notes 7000 11350 0    118  ~ 0
HEATER FAN
Text Notes 7050 13650 0    118  ~ 0
BRAKES
Wire Wire Line
	12000 14450 12300 14450
Text GLabel 12000 14450 0    50   Input ~ 0
IGNITION_12V
Connection ~ 13100 14750
Wire Wire Line
	13100 14750 13100 14650
Connection ~ 12300 14750
Wire Wire Line
	13100 14950 13100 14750
Wire Wire Line
	12300 14950 13100 14950
Wire Wire Line
	12300 14750 12300 14950
Wire Wire Line
	12300 14650 12300 14750
Connection ~ 13100 14450
Wire Wire Line
	13100 14550 13100 14450
Connection ~ 12300 14450
Wire Wire Line
	13100 14050 13100 14450
Wire Wire Line
	12300 14450 12300 14050
Wire Wire Line
	12300 14550 12300 14450
$Comp
L Connector:178.6165.0001 HORN_FUSE1
U 1 1 61F7900E
P 12300 14450
F 0 "HORN_FUSE1" H 12700 14715 50  0000 C CNN
F 1 "178.6165.0001" H 12700 14624 50  0000 C CNN
F 2 "Socket:17861650001" H 12950 14550 50  0001 L CNN
F 3 "https://www.mouser.com/datasheet/2/240/Littelfuse-Fuse-Holder-ATO-FLR-pcb-Datasheet-1317199.pdf" H 12950 14450 50  0001 L CNN
F 4 "FLR PCB FUSE HOLDER FOR ATO STYLE BLADE FUSE RATED 58V" H 12950 14350 50  0001 L CNN "Description"
F 5 "17.5" H 12950 14250 50  0001 L CNN "Height"
F 6 "LITTELFUSE" H 12950 14150 50  0001 L CNN "Manufacturer_Name"
F 7 "178.6165.0001" H 12950 14050 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "576-178.6165.0001" H 12950 13950 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Littelfuse/17861650001?qs=CSLd874fYV1KI1oBGU5EQg%3D%3D" H 12950 13850 50  0001 L CNN "Mouser Price/Stock"
F 10 "178.6165.0001" H 12950 13750 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/178.6165.0001/littelfuse" H 12950 13650 50  0001 L CNN "Arrow Price/Stock"
	1    12300 14450
	1    0    0    -1  
$EndComp
Connection ~ 18350 10100
Text GLabel 20600 10100 0    50   Input ~ 0
DASH_HIGHBEAM_INDICATOR
Wire Wire Line
	18350 10100 18350 10300
Wire Wire Line
	18350 10300 19150 10300
Text GLabel 20600 10200 0    50   Input ~ 0
HEADLIGHT_12V
Text GLabel 20600 10000 0    50   Input ~ 0
RH_HIGHBEAM
Wire Wire Line
	20800 10200 20600 10200
Wire Wire Line
	20800 10100 20700 10100
Wire Wire Line
	20700 10100 20700 10000
Wire Wire Line
	20700 10000 20600 10000
Connection ~ 20700 10100
Wire Wire Line
	20700 10100 20600 10100
Wire Wire Line
	20800 10300 19150 10300
Connection ~ 19150 10300
$Comp
L DZ85AB-5-PCB:DZ85AB-5-PCB DASHBOARD_RELAY1
U 1 1 61B911B9
P 8050 1500
F 0 "DASHBOARD_RELAY1" H 8450 1765 50  0000 C CNN
F 1 "DZ85AB-5-PCB" H 8450 1674 50  0000 C CNN
F 2 "Socket:DZ85AB5PCB" H 8700 1600 50  0001 L CNN
F 3 "https://componentsearchengine.com/Datasheets/2/DZ85AB-5-PCB.pdf" H 8700 1500 50  0001 L CNN
F 4 "Durakool 1 Pin Relay Socket, Plug In for use with Various Series" H 8700 1400 50  0001 L CNN "Description"
F 5 "14.5" H 8700 1300 50  0001 L CNN "Height"
F 6 "DURAKOOL" H 8700 1200 50  0001 L CNN "Manufacturer_Name"
F 7 "DZ85AB-5-PCB" H 8700 1100 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "" H 8700 1000 50  0001 L CNN "Mouser Part Number"
F 9 "" H 8700 900 50  0001 L CNN "Mouser Price/Stock"
F 10 "" H 8700 800 50  0001 L CNN "Arrow Part Number"
F 11 "" H 8700 700 50  0001 L CNN "Arrow Price/Stock"
	1    8050 1500
	1    0    0    -1  
$EndComp
$Comp
L Diode:10A10 D1
U 1 1 61BAA06F
P 9250 1500
F 0 "D1" H 9550 1767 50  0000 C CNN
F 1 "10A10" H 9550 1676 50  0000 C CNN
F 2 "Diode_THT:DIOAD1165W56L425D185" H 9700 1500 50  0001 L CNN
F 3 "https://www.rectron.com/data_sheets/10a05-10a10.pdf" H 9700 1400 50  0001 L CNN
F 4 "10A10" H 9700 1300 50  0001 L CNN "Description"
F 5 "Rectron" H 9700 1100 50  0001 L CNN "Manufacturer_Name"
F 6 "10A10" H 9700 1000 50  0001 L CNN "Manufacturer_Part_Number"
F 7 "10A10" H 9700 700 50  0001 L CNN "Arrow Part Number"
F 8 "https://www.arrow.com/en/products/10a10/rectron" H 9700 600 50  0001 L CNN "Arrow Price/Stock"
	1    9250 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	9200 1500 9250 1500
$Comp
L Diode:10A10 D2
U 1 1 61BB0644
P 9250 2000
F 0 "D2" H 9550 2267 50  0000 C CNN
F 1 "10A10" H 9550 2176 50  0000 C CNN
F 2 "Diode_THT:DIOAD1165W56L425D185" H 9700 2000 50  0001 L CNN
F 3 "https://www.rectron.com/data_sheets/10a05-10a10.pdf" H 9700 1900 50  0001 L CNN
F 4 "10A10" H 9700 1800 50  0001 L CNN "Description"
F 5 "Rectron" H 9700 1600 50  0001 L CNN "Manufacturer_Name"
F 6 "10A10" H 9700 1500 50  0001 L CNN "Manufacturer_Part_Number"
F 7 "10A10" H 9700 1200 50  0001 L CNN "Arrow Part Number"
F 8 "https://www.arrow.com/en/products/10a10/rectron" H 9700 1100 50  0001 L CNN "Arrow Price/Stock"
	1    9250 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	9200 1500 9200 2000
Wire Wire Line
	9200 2000 9250 2000
Connection ~ 9200 1500
Text GLabel 10000 1500 2    50   Input ~ 0
IGNITION_12V
Wire Wire Line
	10000 1500 9850 1500
Text GLabel 10000 2000 2    50   Input ~ 0
CHARGER_ON_SIGNAL
Wire Wire Line
	9850 2000 10000 2000
Wire Wire Line
	8850 1500 9200 1500
Connection ~ 1900 2150
Connection ~ 2700 2150
Wire Wire Line
	1900 2150 1900 2050
Wire Wire Line
	1900 2350 1900 2150
Wire Wire Line
	2700 2150 2700 2050
Text GLabel 4000 2050 2    50   Input ~ 0
PERM_12V_REAR
Text GLabel 4000 2150 2    50   Input ~ 0
IGNITION_SWITCH_A
Connection ~ 2700 1850
Wire Wire Line
	2700 1950 2700 1850
Connection ~ 1900 1850
Wire Wire Line
	1900 1950 1900 1850
Wire Wire Line
	2700 1450 2700 1850
Wire Wire Line
	1900 1450 2700 1450
Wire Wire Line
	1900 1850 1900 1450
$Comp
L Connector:178.6165.0001 IGNITION_FUSE1
U 1 1 619BD52A
P 1900 1850
F 0 "IGNITION_FUSE1" H 2300 2115 50  0000 C CNN
F 1 "178.6165.0001" H 2300 2024 50  0000 C CNN
F 2 "Socket:17861650001" H 2550 1950 50  0001 L CNN
F 3 "https://www.mouser.com/datasheet/2/240/Littelfuse-Fuse-Holder-ATO-FLR-pcb-Datasheet-1317199.pdf" H 2550 1850 50  0001 L CNN
F 4 "FLR PCB FUSE HOLDER FOR ATO STYLE BLADE FUSE RATED 58V" H 2550 1750 50  0001 L CNN "Description"
F 5 "17.5" H 2550 1650 50  0001 L CNN "Height"
F 6 "LITTELFUSE" H 2550 1550 50  0001 L CNN "Manufacturer_Name"
F 7 "178.6165.0001" H 2550 1450 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "576-178.6165.0001" H 2550 1350 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Littelfuse/17861650001?qs=CSLd874fYV1KI1oBGU5EQg%3D%3D" H 2550 1250 50  0001 L CNN "Mouser Price/Stock"
F 10 "178.6165.0001" H 2550 1150 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/178.6165.0001/littelfuse" H 2550 1050 50  0001 L CNN "Arrow Price/Stock"
	1    1900 1850
	1    0    0    -1  
$EndComp
Text GLabel 1650 1850 0    50   Input ~ 0
12V_BATT
Wire Wire Line
	19150 7300 20150 7300
Wire Wire Line
	12700 11450 13450 11450
Wire Wire Line
	15200 3750 15700 3750
Wire Wire Line
	14050 3450 14050 3750
Connection ~ 14050 3750
Wire Wire Line
	14050 3750 14400 3750
Wire Wire Line
	13750 4750 13750 5000
Connection ~ 13750 5000
Wire Wire Line
	13750 5000 14050 5000
Wire Wire Line
	14850 5000 15350 5000
Wire Wire Line
	3950 14950 4400 14950
Wire Wire Line
	2700 2050 2800 2050
Connection ~ 2700 2050
Wire Wire Line
	2700 1250 2950 1250
Wire Wire Line
	2800 2050 2800 1450
Wire Wire Line
	2800 1450 2950 1450
Wire Wire Line
	7800 2250 7950 2250
Wire Wire Line
	7950 2250 7950 1700
Wire Wire Line
	7950 1700 8050 1700
Connection ~ 7800 2250
Wire Wire Line
	7700 1500 8050 1500
Wire Wire Line
	19150 6450 20150 6450
Wire Wire Line
	20150 7000 20300 7000
Wire Wire Line
	20300 7000 20300 6450
Wire Wire Line
	20300 6450 20450 6450
Connection ~ 20150 7000
Wire Wire Line
	20150 6250 20450 6250
$Comp
L DZ85AB-5-PCB:DZ85AB-5-PCB HORN_RELAY1
U 1 1 61FD7703
P 13350 13850
F 0 "HORN_RELAY1" H 13750 14115 50  0000 C CNN
F 1 "DZ85AB-5-PCB" H 13750 14024 50  0000 C CNN
F 2 "Socket:DZ85AB5PCB" H 14000 13950 50  0001 L CNN
F 3 "https://componentsearchengine.com/Datasheets/2/DZ85AB-5-PCB.pdf" H 14000 13850 50  0001 L CNN
F 4 "Durakool 1 Pin Relay Socket, Plug In for use with Various Series" H 14000 13750 50  0001 L CNN "Description"
F 5 "14.5" H 14000 13650 50  0001 L CNN "Height"
F 6 "DURAKOOL" H 14000 13550 50  0001 L CNN "Manufacturer_Name"
F 7 "DZ85AB-5-PCB" H 14000 13450 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "" H 14000 13350 50  0001 L CNN "Mouser Part Number"
F 9 "" H 14000 13250 50  0001 L CNN "Mouser Price/Stock"
F 10 "" H 14000 13150 50  0001 L CNN "Arrow Part Number"
F 11 "" H 14000 13050 50  0001 L CNN "Arrow Price/Stock"
	1    13350 13850
	1    0    0    -1  
$EndComp
Wire Wire Line
	12000 15100 14150 15100
Text GLabel 14150 15100 2    50   Input ~ 0
HORN_SWITCH_A
Text GLabel 12000 15100 0    50   Input ~ 0
IGNITION_12V
Wire Wire Line
	12300 14050 13100 14050
Wire Wire Line
	13100 14650 13200 14650
Wire Wire Line
	13200 14650 13200 14050
Wire Wire Line
	13200 14050 13350 14050
Connection ~ 13100 14650
Wire Wire Line
	13100 13850 13350 13850
Wire Wire Line
	2300 15150 3150 15150
Text GLabel 3050 14850 0    50   Input ~ 0
BMS_FRONT_12V
Wire Wire Line
	3050 14950 3150 14950
Wire Wire Line
	3050 14850 3150 14850
Wire Wire Line
	3150 14850 3150 14950
Connection ~ 3150 14950
Text GLabel 2150 15800 0    50   Input ~ 0
BMS_REAR_GND
Wire Wire Line
	2150 15800 2400 15800
Wire Wire Line
	2400 15800 2400 15700
Connection ~ 2400 15700
Wire Wire Line
	2400 15700 2800 15700
Text GLabel 17850 1100 0    50   Input ~ 0
BMS_REAR_12V
Text GLabel 17850 1200 0    50   Input ~ 0
BMS_REAR_GND
Text GLabel 13450 3850 0    50   Input ~ 0
LH_REAR_INDICATOR
Wire Wire Line
	13450 3850 14050 3850
Wire Wire Line
	14050 3850 14050 3750
Text GLabel 13100 5100 0    50   Input ~ 0
RH_REAR_INDICATOR
Wire Wire Line
	13100 5100 13750 5100
Wire Wire Line
	13750 5100 13750 5000
Text GLabel 17850 1400 0    50   Input ~ 0
RH_REAR_INDICATOR
Text GLabel 21800 3850 2    50   Input ~ 0
LH_FRONT_INDICATOR
Wire Wire Line
	1650 1850 1900 1850
Wire Wire Line
	2800 2050 4000 2050
Connection ~ 2800 2050
Wire Wire Line
	2700 2150 2700 2250
Wire Wire Line
	2700 2150 4000 2150
Text GLabel 4000 2250 2    50   Input ~ 0
PERM_12V_FRONT
Wire Wire Line
	4000 2250 2700 2250
Connection ~ 2700 2250
Wire Wire Line
	2700 2250 2700 2350
$Comp
L DZ85AB-5-PCB:DZ85AB-5-PCB COOLANT_PUMP_RELAY1
U 1 1 639387E9
P 3300 9100
F 0 "COOLANT_PUMP_RELAY1" H 3700 9365 50  0000 C CNN
F 1 "DZ85AB-5-PCB" H 3700 9274 50  0000 C CNN
F 2 "Socket:DZ85AB5PCB" H 3950 9200 50  0001 L CNN
F 3 "https://componentsearchengine.com/Datasheets/2/DZ85AB-5-PCB.pdf" H 3950 9100 50  0001 L CNN
F 4 "Durakool 1 Pin Relay Socket, Plug In for use with Various Series" H 3950 9000 50  0001 L CNN "Description"
F 5 "14.5" H 3950 8900 50  0001 L CNN "Height"
F 6 "DURAKOOL" H 3950 8800 50  0001 L CNN "Manufacturer_Name"
F 7 "DZ85AB-5-PCB" H 3950 8700 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "" H 3950 8600 50  0001 L CNN "Mouser Part Number"
F 9 "" H 3950 8500 50  0001 L CNN "Mouser Price/Stock"
F 10 "" H 3950 8400 50  0001 L CNN "Arrow Part Number"
F 11 "" H 3950 8300 50  0001 L CNN "Arrow Price/Stock"
	1    3300 9100
	1    0    0    -1  
$EndComp
Text GLabel 1950 9700 0    50   Input ~ 0
PERM_12V_FRONT
Wire Wire Line
	3000 9100 3300 9100
Wire Wire Line
	3300 9300 3150 9300
Wire Wire Line
	3150 9300 3150 10000
Wire Wire Line
	4100 9200 4350 9200
Text GLabel 4350 9200 2    50   Input ~ 0
GND
Text Notes 3100 5400 0    50   ~ 0
12v + gnd to shunt\n12v + gnd to negative contactor\ngnd to precharge and main contactors
$Comp
L DZ85AB-5-PCB:DZ85AB-5-PCB RADIO_RELAY1
U 1 1 63BC4C35
P 3050 11800
F 0 "RADIO_RELAY1" H 3450 12065 50  0000 C CNN
F 1 "DZ85AB-5-PCB" H 3450 11974 50  0000 C CNN
F 2 "Socket:DZ85AB5PCB" H 3700 11900 50  0001 L CNN
F 3 "https://componentsearchengine.com/Datasheets/2/DZ85AB-5-PCB.pdf" H 3700 11800 50  0001 L CNN
F 4 "Durakool 1 Pin Relay Socket, Plug In for use with Various Series" H 3700 11700 50  0001 L CNN "Description"
F 5 "14.5" H 3700 11600 50  0001 L CNN "Height"
F 6 "DURAKOOL" H 3700 11500 50  0001 L CNN "Manufacturer_Name"
F 7 "DZ85AB-5-PCB" H 3700 11400 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "" H 3700 11300 50  0001 L CNN "Mouser Part Number"
F 9 "" H 3700 11200 50  0001 L CNN "Mouser Price/Stock"
F 10 "" H 3700 11100 50  0001 L CNN "Arrow Part Number"
F 11 "" H 3700 11000 50  0001 L CNN "Arrow Price/Stock"
	1    3050 11800
	1    0    0    -1  
$EndComp
Text GLabel 3850 11900 2    50   Input ~ 0
GND
Wire Wire Line
	3050 12000 3000 12000
Wire Wire Line
	3000 12000 3000 12700
Text GLabel 1850 12400 0    50   Input ~ 0
PERM_12V_FRONT
Text Notes 1150 8950 0    50   ~ 0
Inverter\nTesla OBC\n\nStarted in drive mode and charge mode
Connection ~ 2750 7500
Wire Wire Line
	1850 7500 1850 7100
Wire Wire Line
	1850 7100 2750 7100
Wire Wire Line
	2750 7100 2750 7500
Text GLabel 1650 7500 0    50   Input ~ 0
IGNITION_12V
Text GLabel 2900 7800 2    50   Input ~ 0
VACUUM_PUMP
$Comp
L Diode:10A10 D4
U 1 1 63E5B8AB
P 4700 9550
F 0 "D4" H 5000 9817 50  0000 C CNN
F 1 "10A10" H 5000 9726 50  0000 C CNN
F 2 "Diode_THT:DIOAD1165W56L425D185" H 5150 9550 50  0001 L CNN
F 3 "https://www.rectron.com/data_sheets/10a05-10a10.pdf" H 5150 9450 50  0001 L CNN
F 4 "10A10" H 5150 9350 50  0001 L CNN "Description"
F 5 "Rectron" H 5150 9150 50  0001 L CNN "Manufacturer_Name"
F 6 "10A10" H 5150 9050 50  0001 L CNN "Manufacturer_Part_Number"
F 7 "10A10" H 5150 8750 50  0001 L CNN "Arrow Part Number"
F 8 "https://www.arrow.com/en/products/10a10/rectron" H 5150 8650 50  0001 L CNN "Arrow Price/Stock"
	1    4700 9550
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 9550 5300 9550
Wire Wire Line
	5400 9100 5300 9100
Text GLabel 5400 9550 2    50   Input ~ 0
CHARGER_ON_SIGNAL
Text GLabel 5400 9100 2    50   Input ~ 0
IGNITION_12V
$Comp
L Diode:10A10 D3
U 1 1 63E5B8C3
P 4700 9100
F 0 "D3" H 5000 9367 50  0000 C CNN
F 1 "10A10" H 5000 9276 50  0000 C CNN
F 2 "Diode_THT:DIOAD1165W56L425D185" H 5150 9100 50  0001 L CNN
F 3 "https://www.rectron.com/data_sheets/10a05-10a10.pdf" H 5150 9000 50  0001 L CNN
F 4 "10A10" H 5150 8900 50  0001 L CNN "Description"
F 5 "Rectron" H 5150 8700 50  0001 L CNN "Manufacturer_Name"
F 6 "10A10" H 5150 8600 50  0001 L CNN "Manufacturer_Part_Number"
F 7 "10A10" H 5150 8300 50  0001 L CNN "Arrow Part Number"
F 8 "https://www.arrow.com/en/products/10a10/rectron" H 5150 8200 50  0001 L CNN "Arrow Price/Stock"
	1    4700 9100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 9100 4100 9100
Connection ~ 4700 9100
Wire Wire Line
	4700 9100 4700 9550
Text Notes 900  13850 0    50   ~ 0
Turns on in drive mode and charge mode
Wire Wire Line
	2300 14750 2300 14650
Connection ~ 2300 14650
Wire Wire Line
	1500 14750 1500 14650
Connection ~ 1500 14650
Text Notes 18250 750  0    50   ~ 0
REAR\n
Text Notes 7100 15000 0    118  ~ 0
BRAKES
Text GLabel 7350 15250 0    50   Input ~ 0
IGNITION_12V
Text GLabel 7800 15250 2    50   Input ~ 0
CRUISE_SWITCH_A
Wire Wire Line
	7350 15250 7800 15250
Text GLabel 7350 15350 0    50   Input ~ 0
CRUISE_SWITCH_B
Text GLabel 7800 15350 2    50   Input ~ 0
CRUISE_SIGNAL
Wire Wire Line
	7350 15350 7800 15350
Text GLabel 21850 1450 2    50   Input ~ 0
CRUISE_SWITCH_B
Text GLabel 21850 1350 2    50   Input ~ 0
CRUISE_SWITCH_A
Text GLabel 21850 1150 2    50   Input ~ 0
CRUISE_SIGNAL
Text Notes 21250 700  0    50   ~ 0
CABIN
Text Notes 17600 2100 0    50   ~ 0
DASH
$Comp
L Connector:1-776180-1 J1
U 1 1 6437C97E
P 20850 1050
F 0 "J1" H 21350 1315 50  0000 C CNN
F 1 "1-776180-1" H 21350 1224 50  0000 C CNN
F 2 "17761801" H 21700 1150 50  0001 L CNN
F 3 "https://datasheet.datasheetarchive.com/originals/distributors/Datasheets-DGA22/2139312.pdf" H 21700 1050 50  0001 L CNN
F 4 "Header Rigth Angle 35 way Pin AmpSeal" H 21700 950 50  0001 L CNN "Description"
F 5 "28.6" H 21700 850 50  0001 L CNN "Height"
F 6 "TE Connectivity" H 21700 750 50  0001 L CNN "Manufacturer_Name"
F 7 "1-776180-1" H 21700 650 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "571-1-776180-1" H 21700 550 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/TE-Connectivity-AMP/1-776180-1?qs=3aug5cyrIbeXXPMJFPzneQ%3D%3D" H 21700 450 50  0001 L CNN "Mouser Price/Stock"
F 10 "1-776180-1" H 21700 350 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/1-776180-1/te-connectivity?region=nac" H 21700 250 50  0001 L CNN "Arrow Price/Stock"
	1    20850 1050
	1    0    0    -1  
$EndComp
Text GLabel 20250 8500 0    50   Input ~ 0
LH_HEADLIGHT
Wire Wire Line
	20250 8600 20350 8600
Wire Wire Line
	20250 8500 20350 8500
Wire Wire Line
	20350 8500 20350 8600
Connection ~ 20350 8600
Wire Wire Line
	20350 8600 20400 8600
Text GLabel 20600 9900 0    50   Input ~ 0
LH_HIGHBEAM
Wire Wire Line
	20600 9900 20700 9900
Wire Wire Line
	20700 9900 20700 10000
Connection ~ 20700 10000
Text GLabel 20900 4750 0    50   Input ~ 0
RH_HEADLIGHT
Text GLabel 21800 3750 2    50   Input ~ 0
RH_HIGHBEAM
$Comp
L Connector:776087-4 J2
U 1 1 645582CB
P 20900 3650
F 0 "J2" H 21350 3915 50  0000 C CNN
F 1 "776087-4" H 21350 3824 50  0000 C CNN
F 2 "7760874" H 21650 3750 50  0001 L CNN
F 3 "https://www.te.com/commerce/DocumentDelivery/DDEController?Action=srchrtrv&DocNm=1-1773979-2&DocType=Data+Sheet&DocLang=English&PartCntxt=776087-4&DocFormat=pdf" H 21650 3650 50  0001 L CNN
F 4 "Header Right Angle 23 way Pin AmpSeal" H 21650 3550 50  0001 L CNN "Description"
F 5 "32.3" H 21650 3450 50  0001 L CNN "Height"
F 6 "TE Connectivity" H 21650 3350 50  0001 L CNN "Manufacturer_Name"
F 7 "776087-4" H 21650 3250 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "571-776087-4" H 21650 3150 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/TE-Connectivity/776087-4?qs=qXO2HHLAcoLN9TNcejrsmg%3D%3D" H 21650 3050 50  0001 L CNN "Mouser Price/Stock"
F 10 "776087-4" H 21650 2950 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/776087-4/te-connectivity" H 21650 2850 50  0001 L CNN "Arrow Price/Stock"
	1    20900 3650
	1    0    0    -1  
$EndComp
Text Notes 21250 3300 0    50   ~ 0
FRONT
$Comp
L Connector:776267-1 J3
U 1 1 646BF49A
P 17850 1100
F 0 "J3" H 18300 1365 50  0000 C CNN
F 1 "776267-1" H 18300 1274 50  0000 C CNN
F 2 "776267-1" H 18600 1200 50  0001 L CNN
F 3 "http://www.te.com/commerce/DocumentDelivery/DDEController?Action=srchrtrv&DocNm=776267&DocType=Customer+Drawing&DocLang=English" H 18600 1100 50  0001 L CNN
F 4 "14 POS RT ANG HDR ASSY W/GASKE" H 18600 1000 50  0001 L CNN "Description"
F 5 "" H 18600 900 50  0001 L CNN "Height"
F 6 "TE Connectivity" H 18600 800 50  0001 L CNN "Manufacturer_Name"
F 7 "776267-1" H 18600 700 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "571-776267-1" H 18600 600 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/TE-Connectivity/776267-1?qs=tLAa1RwIH6fSgzpmDTOXQA%3D%3D" H 18600 500 50  0001 L CNN "Mouser Price/Stock"
F 10 "776267-1" H 18600 400 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/776267-1/te-connectivity?region=nac" H 18600 300 50  0001 L CNN "Arrow Price/Stock"
	1    17850 1100
	1    0    0    -1  
$EndComp
Text GLabel 18750 1100 2    50   Input ~ 0
DRIVE_INHIBIT
$Comp
L Connector:1-776280-1 J4
U 1 1 647C978A
P 17250 2450
F 0 "J4" H 17700 2715 50  0000 C CNN
F 1 "1-776280-1" H 17700 2624 50  0000 C CNN
F 2 "17762801" H 18000 2550 50  0001 L CNN
F 3 "http://www.te.com/commerce/DocumentDelivery/DDEController?Action=srchrtrv&DocNm=776280&DocType=Customer+Drawing&DocLang=English" H 18000 2450 50  0001 L CNN
F 4 "Header Right Angle 8 way Pin AmpSeal" H 18000 2350 50  0001 L CNN "Description"
F 5 "32.1" H 18000 2250 50  0001 L CNN "Height"
F 6 "TE Connectivity" H 18000 2150 50  0001 L CNN "Manufacturer_Name"
F 7 "1-776280-1" H 18000 2050 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "571-1-776280-1" H 18000 1950 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/TE-Connectivity/1-776280-1?qs=tLAa1RwIH6eAcibenGXn4g%3D%3D" H 18000 1850 50  0001 L CNN "Mouser Price/Stock"
F 10 "1-776280-1" H 18000 1750 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/1-776280-1/te-connectivity" H 18000 1650 50  0001 L CNN "Arrow Price/Stock"
	1    17250 2450
	1    0    0    -1  
$EndComp
$Comp
L DZ85AB-5-PCB:DZ85AB-5-PCB DASHBOARD_RELAY2
U 1 1 6481867A
P 8050 3550
F 0 "DASHBOARD_RELAY2" H 8450 3815 50  0000 C CNN
F 1 "DZ85AB-5-PCB" H 8450 3724 50  0000 C CNN
F 2 "Socket:DZ85AB5PCB" H 8700 3650 50  0001 L CNN
F 3 "https://componentsearchengine.com/Datasheets/2/DZ85AB-5-PCB.pdf" H 8700 3550 50  0001 L CNN
F 4 "Durakool 1 Pin Relay Socket, Plug In for use with Various Series" H 8700 3450 50  0001 L CNN "Description"
F 5 "14.5" H 8700 3350 50  0001 L CNN "Height"
F 6 "DURAKOOL" H 8700 3250 50  0001 L CNN "Manufacturer_Name"
F 7 "DZ85AB-5-PCB" H 8700 3150 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "" H 8700 3050 50  0001 L CNN "Mouser Part Number"
F 9 "" H 8700 2950 50  0001 L CNN "Mouser Price/Stock"
F 10 "" H 8700 2850 50  0001 L CNN "Arrow Part Number"
F 11 "" H 8700 2750 50  0001 L CNN "Arrow Price/Stock"
	1    8050 3550
	1    0    0    -1  
$EndComp
Text GLabel 8850 3550 2    50   Input ~ 0
CHARGER_ON_SIGNAL
Text GLabel 8850 3650 2    50   Input ~ 0
GND
Text GLabel 8050 3550 0    50   Input ~ 0
DASHBOARD_5V
Text GLabel 8050 3750 0    50   Input ~ 0
DASHBOARD_CHARGER_ON_SIGNAL
Text GLabel 18150 2550 2    50   Input ~ 0
DASHBOARD_5V
Text GLabel 18150 2650 2    50   Input ~ 0
DASHBOARD_CHARGER_ON_SIGNAL
$Comp
L Connector:1-776280-1 J5
U 1 1 64903351
P 18250 3750
F 0 "J5" H 18700 4015 50  0000 C CNN
F 1 "1-776280-1" H 18700 3924 50  0000 C CNN
F 2 "17762801" H 19000 3850 50  0001 L CNN
F 3 "http://www.te.com/commerce/DocumentDelivery/DDEController?Action=srchrtrv&DocNm=776280&DocType=Customer+Drawing&DocLang=English" H 19000 3750 50  0001 L CNN
F 4 "Header Right Angle 8 way Pin AmpSeal" H 19000 3650 50  0001 L CNN "Description"
F 5 "32.1" H 19000 3550 50  0001 L CNN "Height"
F 6 "TE Connectivity" H 19000 3450 50  0001 L CNN "Manufacturer_Name"
F 7 "1-776280-1" H 19000 3350 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "571-1-776280-1" H 19000 3250 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/TE-Connectivity/1-776280-1?qs=tLAa1RwIH6eAcibenGXn4g%3D%3D" H 19000 3150 50  0001 L CNN "Mouser Price/Stock"
F 10 "1-776280-1" H 19000 3050 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/1-776280-1/te-connectivity" H 19000 2950 50  0001 L CNN "Arrow Price/Stock"
	1    18250 3750
	1    0    0    -1  
$EndComp
Text Notes 18600 3400 0    50   ~ 0
SHIFTER
Text Label 3800 1350 0    50   ~ 0
GND
$EndSCHEMATC
