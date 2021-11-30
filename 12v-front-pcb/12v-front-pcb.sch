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
P 2950 2200
F 0 "IGNITION_RELAY1" H 3350 2465 50  0000 C CNN
F 1 "DZ85AB-5-PCB" H 3350 2374 50  0000 C CNN
F 2 "Socket:DZ85AB5PCB" H 3600 2300 50  0001 L CNN
F 3 "https://componentsearchengine.com/Datasheets/2/DZ85AB-5-PCB.pdf" H 3600 2200 50  0001 L CNN
F 4 "Durakool 1 Pin Relay Socket, Plug In for use with Various Series" H 3600 2100 50  0001 L CNN "Description"
F 5 "14.5" H 3600 2000 50  0001 L CNN "Height"
F 6 "DURAKOOL" H 3600 1900 50  0001 L CNN "Manufacturer_Name"
F 7 "DZ85AB-5-PCB" H 3600 1800 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "" H 3600 1700 50  0001 L CNN "Mouser Part Number"
F 9 "" H 3600 1600 50  0001 L CNN "Mouser Price/Stock"
F 10 "" H 3600 1500 50  0001 L CNN "Arrow Part Number"
F 11 "" H 3600 1400 50  0001 L CNN "Arrow Price/Stock"
	1    2950 2200
	1    0    0    -1  
$EndComp
Text GLabel 1550 1700 0    50   Input ~ 0
12V_BATT
Text GLabel 4000 2200 2    50   Input ~ 0
GND
Wire Wire Line
	3750 2200 4000 2200
Text GLabel 4000 2300 2    50   Input ~ 0
IGNITION_SWITCH_B
Wire Wire Line
	3750 2300 4000 2300
Text GLabel 1550 2400 0    50   Input ~ 0
IGNITION_12V
$Comp
L Connector:178.6165.0001 IGNITION_FUSE1
U 1 1 619BD52A
P 1800 1700
F 0 "IGNITION_FUSE1" H 2200 1965 50  0000 C CNN
F 1 "178.6165.0001" H 2200 1874 50  0000 C CNN
F 2 "Socket:17861650001" H 2450 1800 50  0001 L CNN
F 3 "https://www.mouser.com/datasheet/2/240/Littelfuse-Fuse-Holder-ATO-FLR-pcb-Datasheet-1317199.pdf" H 2450 1700 50  0001 L CNN
F 4 "FLR PCB FUSE HOLDER FOR ATO STYLE BLADE FUSE RATED 58V" H 2450 1600 50  0001 L CNN "Description"
F 5 "17.5" H 2450 1500 50  0001 L CNN "Height"
F 6 "LITTELFUSE" H 2450 1400 50  0001 L CNN "Manufacturer_Name"
F 7 "178.6165.0001" H 2450 1300 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "576-178.6165.0001" H 2450 1200 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Littelfuse/17861650001?qs=CSLd874fYV1KI1oBGU5EQg%3D%3D" H 2450 1100 50  0001 L CNN "Mouser Price/Stock"
F 10 "178.6165.0001" H 2450 1000 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/178.6165.0001/littelfuse" H 2450 900 50  0001 L CNN "Arrow Price/Stock"
	1    1800 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	1800 1700 1800 1300
Wire Wire Line
	1800 1300 2600 1300
Wire Wire Line
	2600 1300 2600 1700
Wire Wire Line
	1800 1800 1800 1700
Connection ~ 1800 1700
Wire Wire Line
	2600 1800 2600 1700
Connection ~ 2600 1700
Wire Wire Line
	1800 1700 1550 1700
Wire Wire Line
	2600 2000 2600 2200
Wire Wire Line
	2600 2200 1800 2200
Wire Wire Line
	1800 2200 1800 2000
Wire Wire Line
	2600 2000 2600 1900
Connection ~ 2600 2000
Wire Wire Line
	1800 2000 1800 1900
Connection ~ 1800 2000
Wire Wire Line
	2600 2200 2950 2200
Connection ~ 2600 2200
Text GLabel 2900 1700 2    50   Input ~ 0
IGNITION_SWITCH_A
Wire Wire Line
	2600 1700 2750 1700
$Comp
L DZ85AB-5-PCB:DZ85AB-5-PCB HEADLIGHT_RELAY1
U 1 1 619CD1D3
P 8400 6400
F 0 "HEADLIGHT_RELAY1" H 8800 6665 50  0000 C CNN
F 1 "DZ85AB-5-PCB" H 8800 6574 50  0000 C CNN
F 2 "Socket:DZ85AB5PCB" H 9050 6500 50  0001 L CNN
F 3 "https://componentsearchengine.com/Datasheets/2/DZ85AB-5-PCB.pdf" H 9050 6400 50  0001 L CNN
F 4 "Durakool 1 Pin Relay Socket, Plug In for use with Various Series" H 9050 6300 50  0001 L CNN "Description"
F 5 "14.5" H 9050 6200 50  0001 L CNN "Height"
F 6 "DURAKOOL" H 9050 6100 50  0001 L CNN "Manufacturer_Name"
F 7 "DZ85AB-5-PCB" H 9050 6000 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "" H 9050 5900 50  0001 L CNN "Mouser Part Number"
F 9 "" H 9050 5800 50  0001 L CNN "Mouser Price/Stock"
F 10 "" H 9050 5700 50  0001 L CNN "Arrow Part Number"
F 11 "" H 9050 5600 50  0001 L CNN "Arrow Price/Stock"
	1    8400 6400
	1    0    0    -1  
$EndComp
Text GLabel 7050 6400 0    50   Input ~ 0
HEADLIGHT_12V
Wire Wire Line
	1550 2400 2950 2400
Text GLabel 9450 6400 2    50   Input ~ 0
GND
Text GLabel 9450 6500 2    50   Input ~ 0
HEADLIGHT_SWITCH_B
Wire Wire Line
	9200 6400 9450 6400
Wire Wire Line
	9200 6500 9450 6500
$Comp
L Connector:178.6165.0001 HEADLIGHT_FUSE1
U 1 1 619DA752
P 7250 7350
F 0 "HEADLIGHT_FUSE1" H 7650 7615 50  0000 C CNN
F 1 "178.6165.0001" H 7650 7524 50  0000 C CNN
F 2 "Socket:17861650001" H 7900 7450 50  0001 L CNN
F 3 "https://www.mouser.com/datasheet/2/240/Littelfuse-Fuse-Holder-ATO-FLR-pcb-Datasheet-1317199.pdf" H 7900 7350 50  0001 L CNN
F 4 "FLR PCB FUSE HOLDER FOR ATO STYLE BLADE FUSE RATED 58V" H 7900 7250 50  0001 L CNN "Description"
F 5 "17.5" H 7900 7150 50  0001 L CNN "Height"
F 6 "LITTELFUSE" H 7900 7050 50  0001 L CNN "Manufacturer_Name"
F 7 "178.6165.0001" H 7900 6950 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "576-178.6165.0001" H 7900 6850 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Littelfuse/17861650001?qs=CSLd874fYV1KI1oBGU5EQg%3D%3D" H 7900 6750 50  0001 L CNN "Mouser Price/Stock"
F 10 "178.6165.0001" H 7900 6650 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/178.6165.0001/littelfuse" H 7900 6550 50  0001 L CNN "Arrow Price/Stock"
	1    7250 7350
	1    0    0    -1  
$EndComp
$Comp
L DZ85AB-5-PCB:DZ85AB-5-PCB HIGHBEAM_RELAY1
U 1 1 619DC743
P 8400 7850
F 0 "HIGHBEAM_RELAY1" H 8800 8115 50  0000 C CNN
F 1 "DZ85AB-5-PCB" H 8800 8024 50  0000 C CNN
F 2 "Socket:DZ85AB5PCB" H 9050 7950 50  0001 L CNN
F 3 "https://componentsearchengine.com/Datasheets/2/DZ85AB-5-PCB.pdf" H 9050 7850 50  0001 L CNN
F 4 "Durakool 1 Pin Relay Socket, Plug In for use with Various Series" H 9050 7750 50  0001 L CNN "Description"
F 5 "14.5" H 9050 7650 50  0001 L CNN "Height"
F 6 "DURAKOOL" H 9050 7550 50  0001 L CNN "Manufacturer_Name"
F 7 "DZ85AB-5-PCB" H 9050 7450 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "" H 9050 7350 50  0001 L CNN "Mouser Part Number"
F 9 "" H 9050 7250 50  0001 L CNN "Mouser Price/Stock"
F 10 "" H 9050 7150 50  0001 L CNN "Arrow Part Number"
F 11 "" H 9050 7050 50  0001 L CNN "Arrow Price/Stock"
	1    8400 7850
	1    0    0    -1  
$EndComp
Text GLabel 7000 7350 0    50   Input ~ 0
IGNITION_12V
Wire Wire Line
	7000 7350 7250 7350
Connection ~ 7250 7350
Wire Wire Line
	8050 7350 8050 7450
Wire Wire Line
	7250 7350 7250 7450
Wire Wire Line
	7250 7550 7250 7650
Wire Wire Line
	8050 7850 8050 7650
Wire Wire Line
	8050 7550 8050 7650
Connection ~ 8050 7650
Wire Wire Line
	8050 7850 8400 7850
Text GLabel 9450 7850 2    50   Input ~ 0
GND
Text GLabel 9450 7950 2    50   Input ~ 0
HIGHBEAM_SWITCH_B
Wire Wire Line
	9200 7850 9450 7850
Wire Wire Line
	9200 7950 9450 7950
Text GLabel 7000 6600 0    50   Input ~ 0
HEADLIGHTS
Text GLabel 7000 8050 0    50   Input ~ 0
HIGHBEAM
Wire Wire Line
	7000 8050 7150 8050
$Comp
L Connector:178.6165.0001 INVERTER_FUSE1
U 1 1 619E4B09
P 1800 6150
F 0 "INVERTER_FUSE1" H 2200 6415 50  0000 C CNN
F 1 "178.6165.0001" H 2200 6324 50  0000 C CNN
F 2 "Socket:17861650001" H 2450 6250 50  0001 L CNN
F 3 "https://www.mouser.com/datasheet/2/240/Littelfuse-Fuse-Holder-ATO-FLR-pcb-Datasheet-1317199.pdf" H 2450 6150 50  0001 L CNN
F 4 "FLR PCB FUSE HOLDER FOR ATO STYLE BLADE FUSE RATED 58V" H 2450 6050 50  0001 L CNN "Description"
F 5 "17.5" H 2450 5950 50  0001 L CNN "Height"
F 6 "LITTELFUSE" H 2450 5850 50  0001 L CNN "Manufacturer_Name"
F 7 "178.6165.0001" H 2450 5750 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "576-178.6165.0001" H 2450 5650 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Littelfuse/17861650001?qs=CSLd874fYV1KI1oBGU5EQg%3D%3D" H 2450 5550 50  0001 L CNN "Mouser Price/Stock"
F 10 "178.6165.0001" H 2450 5450 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/178.6165.0001/littelfuse" H 2450 5350 50  0001 L CNN "Arrow Price/Stock"
	1    1800 6150
	1    0    0    -1  
$EndComp
Wire Wire Line
	1800 6250 1800 6150
Wire Wire Line
	1800 5750 2600 5750
Wire Wire Line
	2600 5750 2600 6150
Wire Wire Line
	2600 6150 2600 6250
Connection ~ 2600 6150
Wire Wire Line
	1800 5750 1800 6150
Connection ~ 1800 6150
Text GLabel 1600 6150 0    50   Input ~ 0
IGNITION_12V
Wire Wire Line
	1600 6150 1800 6150
Text GLabel 3000 6350 2    50   Input ~ 0
INVERTER_12V
Wire Wire Line
	2600 6350 2600 6450
Connection ~ 2600 6350
Wire Wire Line
	2600 6450 2600 6650
Wire Wire Line
	2600 6650 1800 6650
Wire Wire Line
	1800 6650 1800 6450
Connection ~ 2600 6450
Wire Wire Line
	1800 6450 1800 6350
Connection ~ 1800 6450
Wire Wire Line
	2600 6350 3000 6350
$Comp
L Connector:178.6165.0001 HVJB_FUSE1
U 1 1 619F47C4
P 1800 8200
F 0 "HVJB_FUSE1" H 2200 8465 50  0000 C CNN
F 1 "178.6165.0001" H 2200 8374 50  0000 C CNN
F 2 "Socket:17861650001" H 2450 8300 50  0001 L CNN
F 3 "https://www.mouser.com/datasheet/2/240/Littelfuse-Fuse-Holder-ATO-FLR-pcb-Datasheet-1317199.pdf" H 2450 8200 50  0001 L CNN
F 4 "FLR PCB FUSE HOLDER FOR ATO STYLE BLADE FUSE RATED 58V" H 2450 8100 50  0001 L CNN "Description"
F 5 "17.5" H 2450 8000 50  0001 L CNN "Height"
F 6 "LITTELFUSE" H 2450 7900 50  0001 L CNN "Manufacturer_Name"
F 7 "178.6165.0001" H 2450 7800 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "576-178.6165.0001" H 2450 7700 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Littelfuse/17861650001?qs=CSLd874fYV1KI1oBGU5EQg%3D%3D" H 2450 7600 50  0001 L CNN "Mouser Price/Stock"
F 10 "178.6165.0001" H 2450 7500 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/178.6165.0001/littelfuse" H 2450 7400 50  0001 L CNN "Arrow Price/Stock"
	1    1800 8200
	1    0    0    -1  
$EndComp
Wire Wire Line
	1800 8300 1800 8200
Wire Wire Line
	1800 8200 1800 7850
Wire Wire Line
	1800 7850 2600 7850
Wire Wire Line
	2600 7850 2600 8200
Connection ~ 1800 8200
Wire Wire Line
	2600 8200 2600 8300
Connection ~ 2600 8200
Text GLabel 1600 8200 0    50   Input ~ 0
IGNITION_12V
Wire Wire Line
	1600 8200 1800 8200
Text GLabel 3000 8500 2    50   Input ~ 0
HVJB_12V
Wire Wire Line
	2600 8400 2600 8500
Wire Wire Line
	2600 8500 2600 8700
Wire Wire Line
	2600 8700 1800 8700
Wire Wire Line
	1800 8700 1800 8500
Connection ~ 2600 8500
Wire Wire Line
	1800 8500 1800 8400
Connection ~ 1800 8500
Wire Wire Line
	1800 9850 2600 9850
Wire Wire Line
	2600 8500 3000 8500
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
Text GLabel 14450 10650 2    50   Input ~ 0
GND
Text GLabel 14450 10750 2    50   Input ~ 0
DRIVE_INHIBIT
Wire Wire Line
	14250 10650 14450 10650
Wire Wire Line
	14250 10750 14450 10750
Text GLabel 13150 10750 0    50   Input ~ 0
INVERTER_FWD
Wire Wire Line
	13150 10650 13450 10650
Text GLabel 13150 10650 0    50   Input ~ 0
SHIFTER_FWD
Wire Wire Line
	13150 10750 13450 10750
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
Text GLabel 14450 11350 2    50   Input ~ 0
GND
Text GLabel 14450 11450 2    50   Input ~ 0
DRIVE_INHIBIT
Wire Wire Line
	14450 11350 14250 11350
Wire Wire Line
	14450 11450 14250 11450
Text GLabel 13150 11450 0    50   Input ~ 0
INVERTER_REV
Text GLabel 13150 11350 0    50   Input ~ 0
SHIFTER_REV
Wire Wire Line
	13150 11350 13450 11350
Wire Wire Line
	13450 11450 13250 11450
Text GLabel 2900 1600 2    50   Input ~ 0
PERM_12V
Wire Wire Line
	2900 1600 2750 1600
Wire Wire Line
	2750 1600 2750 1700
Connection ~ 2750 1700
Wire Wire Line
	2750 1700 2900 1700
$Comp
L Connector:178.6165.0001 INTERIOR_LIGHTS_FUSE1
U 1 1 61A9769C
P 1700 3900
F 0 "INTERIOR_LIGHTS_FUSE1" H 2100 4165 50  0000 C CNN
F 1 "178.6165.0001" H 2100 4074 50  0000 C CNN
F 2 "Socket:17861650001" H 2350 4000 50  0001 L CNN
F 3 "https://www.mouser.com/datasheet/2/240/Littelfuse-Fuse-Holder-ATO-FLR-pcb-Datasheet-1317199.pdf" H 2350 3900 50  0001 L CNN
F 4 "FLR PCB FUSE HOLDER FOR ATO STYLE BLADE FUSE RATED 58V" H 2350 3800 50  0001 L CNN "Description"
F 5 "17.5" H 2350 3700 50  0001 L CNN "Height"
F 6 "LITTELFUSE" H 2350 3600 50  0001 L CNN "Manufacturer_Name"
F 7 "178.6165.0001" H 2350 3500 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "576-178.6165.0001" H 2350 3400 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Littelfuse/17861650001?qs=CSLd874fYV1KI1oBGU5EQg%3D%3D" H 2350 3300 50  0001 L CNN "Mouser Price/Stock"
F 10 "178.6165.0001" H 2350 3200 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/178.6165.0001/littelfuse" H 2350 3100 50  0001 L CNN "Arrow Price/Stock"
	1    1700 3900
	1    0    0    -1  
$EndComp
Text GLabel 21350 1450 0    50   Input ~ 0
PERM_12V
Text GLabel 21500 4750 0    50   Input ~ 0
BRAKE_LIGHT
$Comp
L Connector:282836-6 B8
U 1 1 61AB3438
P 21350 1950
F 0 "B8" H 21978 1746 50  0000 L CNN
F 1 "282836-6" H 21978 1655 50  0000 L CNN
F 2 "Socket:2828366" H 22000 2050 50  0001 L CNN
F 3 "https://www.te.com/commerce/DocumentDelivery/DDEController?Action=showdoc&DocId=Customer+Drawing%7F282836%7FJ%7Fpdf%7FEnglish%7FENG_CD_282836_J.pdf%7F282836-6" H 22000 1950 50  0001 L CNN
F 4 "Fixed Terminal Blocks 5.0MM PCB MOUNT 6P" H 22000 1850 50  0001 L CNN "Description"
F 5 "10.2" H 22000 1750 50  0001 L CNN "Height"
F 6 "TE Connectivity" H 22000 1650 50  0001 L CNN "Manufacturer_Name"
F 7 "282836-6" H 22000 1550 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "571-2828366" H 22000 1450 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/TE-Connectivity/282836-6/?qs=A%252Bip%252BNCYi6MsYFpaQLKbfg%3D%3D" H 22000 1350 50  0001 L CNN "Mouser Price/Stock"
F 10 "282836-6" H 22000 1250 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/282836-6/te-connectivity" H 22000 1150 50  0001 L CNN "Arrow Price/Stock"
	1    21350 1950
	1    0    0    -1  
$EndComp
Text GLabel 19000 5450 0    50   Input ~ 0
DRIVE_INHIBIT
Wire Wire Line
	1700 3900 1600 3900
Wire Wire Line
	2600 3900 2500 3900
Wire Wire Line
	2500 4000 2600 4000
Wire Wire Line
	2600 4000 2600 3900
Wire Wire Line
	1600 3900 1600 4000
Wire Wire Line
	1600 4000 1700 4000
Connection ~ 1600 3900
Wire Wire Line
	1700 4100 1600 4100
Wire Wire Line
	1600 4100 1600 4200
Wire Wire Line
	1600 4400 2600 4400
Wire Wire Line
	2600 4400 2600 4200
Wire Wire Line
	2600 4100 2500 4100
Wire Wire Line
	2500 4200 2600 4200
Connection ~ 2600 4200
Wire Wire Line
	2600 4200 2600 4100
Wire Wire Line
	1700 4200 1600 4200
Connection ~ 1600 4200
Wire Wire Line
	1600 4200 1600 4400
Text GLabel 1500 3900 0    50   Input ~ 0
PERM_12V
Wire Wire Line
	1500 3900 1600 3900
$Comp
L DZ85AB-5-PCB:DZ85AB-5-PCB INTERIOR_LIGHTS_RELAY1
U 1 1 61B40E1B
P 2850 4400
F 0 "INTERIOR_LIGHTS_RELAY1" H 3250 4665 50  0000 C CNN
F 1 "DZ85AB-5-PCB" H 3250 4574 50  0000 C CNN
F 2 "Socket:DZ85AB5PCB" H 3500 4500 50  0001 L CNN
F 3 "https://componentsearchengine.com/Datasheets/2/DZ85AB-5-PCB.pdf" H 3500 4400 50  0001 L CNN
F 4 "Durakool 1 Pin Relay Socket, Plug In for use with Various Series" H 3500 4300 50  0001 L CNN "Description"
F 5 "14.5" H 3500 4200 50  0001 L CNN "Height"
F 6 "DURAKOOL" H 3500 4100 50  0001 L CNN "Manufacturer_Name"
F 7 "DZ85AB-5-PCB" H 3500 4000 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "" H 3500 3900 50  0001 L CNN "Mouser Part Number"
F 9 "" H 3500 3800 50  0001 L CNN "Mouser Price/Stock"
F 10 "" H 3500 3700 50  0001 L CNN "Arrow Part Number"
F 11 "" H 3500 3600 50  0001 L CNN "Arrow Price/Stock"
	1    2850 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 4400 2850 4400
Connection ~ 2600 4400
Text GLabel 1500 4600 0    50   Input ~ 0
INTERIOR_LIGHTS
Wire Wire Line
	1500 4600 2850 4600
Text GLabel 3800 4400 2    50   Input ~ 0
GND
Wire Wire Line
	3650 4400 3800 4400
Text GLabel 3800 4500 2    50   Input ~ 0
INTERIOR_LIGHT_SWITCH_B
Wire Wire Line
	3650 4500 3800 4500
Text GLabel 1500 4750 0    50   Input ~ 0
PERM_12V
Text GLabel 3800 4750 2    50   Input ~ 0
INTERIOR_LIGHT_SWITCH_A
Wire Wire Line
	1500 4750 3800 4750
Text Notes 19600 11500 0    50   ~ 0
### ToDo ###\n\nBattery tender\nBattery box contactors?\nHigh beam signal\nturn signal signal\nStart switch? ignition\nCriuse\nInverter brake signal\n
Text GLabel 19000 2750 0    50   Input ~ 0
LH_INDICATOR_SWITCH_A
Text GLabel 19000 1250 0    50   Input ~ 0
LH_INDICATOR_SWITCH_B
Text GLabel 19000 2850 0    50   Input ~ 0
RH_INDICATOR_SWITCH_A
Text GLabel 19000 1450 0    50   Input ~ 0
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
L Connector:282836-6 B6
U 1 1 61BB81A5
P 19000 5150
F 0 "B6" H 19628 4946 50  0000 L CNN
F 1 "282836-6" H 19628 4855 50  0000 L CNN
F 2 "Socket:2828366" H 19650 5250 50  0001 L CNN
F 3 "https://www.te.com/commerce/DocumentDelivery/DDEController?Action=showdoc&DocId=Customer+Drawing%7F282836%7FJ%7Fpdf%7FEnglish%7FENG_CD_282836_J.pdf%7F282836-6" H 19650 5150 50  0001 L CNN
F 4 "Fixed Terminal Blocks 5.0MM PCB MOUNT 6P" H 19650 5050 50  0001 L CNN "Description"
F 5 "10.2" H 19650 4950 50  0001 L CNN "Height"
F 6 "TE Connectivity" H 19650 4850 50  0001 L CNN "Manufacturer_Name"
F 7 "282836-6" H 19650 4750 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "571-2828366" H 19650 4650 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/TE-Connectivity/282836-6/?qs=A%252Bip%252BNCYi6MsYFpaQLKbfg%3D%3D" H 19650 4550 50  0001 L CNN "Mouser Price/Stock"
F 10 "282836-6" H 19650 4450 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/282836-6/te-connectivity" H 19650 4350 50  0001 L CNN "Arrow Price/Stock"
	1    19000 5150
	1    0    0    -1  
$EndComp
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
$Comp
L Connector:178.6165.0001 HORN_FUSE1
U 1 1 61F7900E
P 7350 4100
F 0 "HORN_FUSE1" H 7750 4365 50  0000 C CNN
F 1 "178.6165.0001" H 7750 4274 50  0000 C CNN
F 2 "Socket:17861650001" H 8000 4200 50  0001 L CNN
F 3 "https://www.mouser.com/datasheet/2/240/Littelfuse-Fuse-Holder-ATO-FLR-pcb-Datasheet-1317199.pdf" H 8000 4100 50  0001 L CNN
F 4 "FLR PCB FUSE HOLDER FOR ATO STYLE BLADE FUSE RATED 58V" H 8000 4000 50  0001 L CNN "Description"
F 5 "17.5" H 8000 3900 50  0001 L CNN "Height"
F 6 "LITTELFUSE" H 8000 3800 50  0001 L CNN "Manufacturer_Name"
F 7 "178.6165.0001" H 8000 3700 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "576-178.6165.0001" H 8000 3600 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Littelfuse/17861650001?qs=CSLd874fYV1KI1oBGU5EQg%3D%3D" H 8000 3500 50  0001 L CNN "Mouser Price/Stock"
F 10 "178.6165.0001" H 8000 3400 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/178.6165.0001/littelfuse" H 8000 3300 50  0001 L CNN "Arrow Price/Stock"
	1    7350 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	7350 4200 7350 4100
Wire Wire Line
	7350 4100 7350 3700
Wire Wire Line
	7350 3700 8150 3700
Wire Wire Line
	8150 3700 8150 4100
Connection ~ 7350 4100
Wire Wire Line
	8150 4200 8150 4100
Connection ~ 8150 4100
Wire Wire Line
	7350 4300 7350 4400
Wire Wire Line
	7350 4400 7350 4600
Wire Wire Line
	7350 4600 8150 4600
Wire Wire Line
	8150 4600 8150 4400
Connection ~ 7350 4400
Wire Wire Line
	8150 4400 8150 4300
Connection ~ 8150 4400
Text GLabel 7050 4100 0    50   Input ~ 0
IGNITION_12V
Wire Wire Line
	7050 4100 7350 4100
$Comp
L DZ85AB-5-PCB:DZ85AB-5-PCB HORN_RELAY1
U 1 1 61FD7703
P 8300 4600
F 0 "HORN_RELAY1" H 8700 4865 50  0000 C CNN
F 1 "DZ85AB-5-PCB" H 8700 4774 50  0000 C CNN
F 2 "Socket:DZ85AB5PCB" H 8950 4700 50  0001 L CNN
F 3 "https://componentsearchengine.com/Datasheets/2/DZ85AB-5-PCB.pdf" H 8950 4600 50  0001 L CNN
F 4 "Durakool 1 Pin Relay Socket, Plug In for use with Various Series" H 8950 4500 50  0001 L CNN "Description"
F 5 "14.5" H 8950 4400 50  0001 L CNN "Height"
F 6 "DURAKOOL" H 8950 4300 50  0001 L CNN "Manufacturer_Name"
F 7 "DZ85AB-5-PCB" H 8950 4200 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "" H 8950 4100 50  0001 L CNN "Mouser Part Number"
F 9 "" H 8950 4000 50  0001 L CNN "Mouser Price/Stock"
F 10 "" H 8950 3900 50  0001 L CNN "Arrow Part Number"
F 11 "" H 8950 3800 50  0001 L CNN "Arrow Price/Stock"
	1    8300 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	8150 4600 8300 4600
Connection ~ 8150 4600
Text GLabel 9200 4600 2    50   Input ~ 0
GND
Wire Wire Line
	9100 4600 9200 4600
Text GLabel 9200 4700 2    50   Input ~ 0
HORN_SWITCH_B
Wire Wire Line
	9100 4700 9200 4700
Text GLabel 7050 4800 0    50   Input ~ 0
HORN
Text GLabel 7050 5000 0    50   Input ~ 0
IGNITION_12V
Text GLabel 9200 5000 2    50   Input ~ 0
HORN_SWITCH_A
Wire Wire Line
	7050 5000 9200 5000
Wire Wire Line
	7050 4800 8300 4800
Text GLabel 19000 2350 0    50   Input ~ 0
HORN_SWITCH_A
Text GLabel 19000 2150 0    50   Input ~ 0
HORN_SWITCH_B
Text GLabel 19000 4850 0    50   Input ~ 0
IGNITION_SWITCH_B
Text GLabel 21350 1250 0    50   Input ~ 0
IGNITION_SWITCH_A
Wire Wire Line
	1550 12000 1750 12000
Text GLabel 2900 12000 2    50   Input ~ 0
VACUUM_PUMP
Text GLabel 1550 12000 0    50   Input ~ 0
IGNITION_12V
Wire Wire Line
	1750 12300 1750 12500
Connection ~ 1750 12300
Wire Wire Line
	1800 12300 1750 12300
Wire Wire Line
	2650 12300 2650 12200
Connection ~ 2650 12300
Wire Wire Line
	2600 12300 2650 12300
Wire Wire Line
	2650 12200 2600 12200
Wire Wire Line
	2650 12500 2650 12300
Wire Wire Line
	1750 12500 2650 12500
Wire Wire Line
	1750 12200 1750 12300
Wire Wire Line
	1800 12200 1750 12200
Connection ~ 1750 12000
Wire Wire Line
	1750 12100 1750 12000
Wire Wire Line
	1800 12100 1750 12100
Connection ~ 2650 12000
Wire Wire Line
	2650 12100 2600 12100
Wire Wire Line
	2650 12000 2650 12100
Wire Wire Line
	2650 12000 2600 12000
Wire Wire Line
	2650 11600 2650 12000
Wire Wire Line
	1750 11600 2650 11600
Wire Wire Line
	1750 12000 1750 11600
Wire Wire Line
	1800 12000 1750 12000
$Comp
L Connector:178.6165.0001 VACUUM_PUMP_FUSE1
U 1 1 6215901C
P 1800 12000
F 0 "VACUUM_PUMP_FUSE1" H 2200 12265 50  0000 C CNN
F 1 "178.6165.0001" H 2200 12174 50  0000 C CNN
F 2 "Socket:17861650001" H 2450 12100 50  0001 L CNN
F 3 "https://www.mouser.com/datasheet/2/240/Littelfuse-Fuse-Holder-ATO-FLR-pcb-Datasheet-1317199.pdf" H 2450 12000 50  0001 L CNN
F 4 "FLR PCB FUSE HOLDER FOR ATO STYLE BLADE FUSE RATED 58V" H 2450 11900 50  0001 L CNN "Description"
F 5 "17.5" H 2450 11800 50  0001 L CNN "Height"
F 6 "LITTELFUSE" H 2450 11700 50  0001 L CNN "Manufacturer_Name"
F 7 "178.6165.0001" H 2450 11600 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "576-178.6165.0001" H 2450 11500 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Littelfuse/17861650001?qs=CSLd874fYV1KI1oBGU5EQg%3D%3D" H 2450 11400 50  0001 L CNN "Mouser Price/Stock"
F 10 "178.6165.0001" H 2450 11300 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/178.6165.0001/littelfuse" H 2450 11200 50  0001 L CNN "Arrow Price/Stock"
	1    1800 12000
	1    0    0    -1  
$EndComp
Text GLabel 2700 13850 2    50   Input ~ 0
COOLANT_PUMP
Wire Wire Line
	1450 13550 1700 13550
Text GLabel 1450 13550 0    50   Input ~ 0
IGNITION_12V
Connection ~ 2500 13850
Wire Wire Line
	2500 13850 2500 13750
Connection ~ 1700 13850
Wire Wire Line
	2500 14050 2500 13850
Wire Wire Line
	1700 14050 2500 14050
Wire Wire Line
	1700 13850 1700 14050
Wire Wire Line
	1700 13750 1700 13850
Connection ~ 1700 13550
Wire Wire Line
	1700 13650 1700 13550
Connection ~ 2500 13550
Wire Wire Line
	2500 13550 2500 13650
Wire Wire Line
	2500 13150 2500 13550
Wire Wire Line
	1700 13150 2500 13150
Wire Wire Line
	1700 13550 1700 13150
$Comp
L Connector:178.6165.0001 WATER_PUMP_FUSE1
U 1 1 6204DDFD
P 1700 13550
F 0 "WATER_PUMP_FUSE1" H 2100 13815 50  0000 C CNN
F 1 "178.6165.0001" H 2100 13724 50  0000 C CNN
F 2 "Socket:17861650001" H 2350 13650 50  0001 L CNN
F 3 "https://www.mouser.com/datasheet/2/240/Littelfuse-Fuse-Holder-ATO-FLR-pcb-Datasheet-1317199.pdf" H 2350 13550 50  0001 L CNN
F 4 "FLR PCB FUSE HOLDER FOR ATO STYLE BLADE FUSE RATED 58V" H 2350 13450 50  0001 L CNN "Description"
F 5 "17.5" H 2350 13350 50  0001 L CNN "Height"
F 6 "LITTELFUSE" H 2350 13250 50  0001 L CNN "Manufacturer_Name"
F 7 "178.6165.0001" H 2350 13150 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "576-178.6165.0001" H 2350 13050 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Littelfuse/17861650001?qs=CSLd874fYV1KI1oBGU5EQg%3D%3D" H 2350 12950 50  0001 L CNN "Mouser Price/Stock"
F 10 "178.6165.0001" H 2350 12850 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/178.6165.0001/littelfuse" H 2350 12750 50  0001 L CNN "Arrow Price/Stock"
	1    1700 13550
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 10550 3000 10550
Wire Wire Line
	1600 10250 1800 10250
Text GLabel 1600 10250 0    50   Input ~ 0
IGNITION_12V
Connection ~ 2600 10550
Wire Wire Line
	2600 10550 2600 10450
Connection ~ 1800 10550
Wire Wire Line
	2600 10750 2600 10550
Wire Wire Line
	1800 10750 2600 10750
Wire Wire Line
	1800 10550 1800 10750
Wire Wire Line
	1800 10450 1800 10550
Connection ~ 2600 10250
Wire Wire Line
	2600 10250 2600 10350
Connection ~ 1800 10250
Wire Wire Line
	2600 9850 2600 10250
Wire Wire Line
	1800 10250 1800 9850
Wire Wire Line
	1800 10350 1800 10250
$Comp
L Connector:178.6165.0001 RADIO_FUSE1
U 1 1 61A090EC
P 1800 10250
F 0 "RADIO_FUSE1" H 2200 10515 50  0000 C CNN
F 1 "178.6165.0001" H 2200 10424 50  0000 C CNN
F 2 "Socket:17861650001" H 2450 10350 50  0001 L CNN
F 3 "https://www.mouser.com/datasheet/2/240/Littelfuse-Fuse-Holder-ATO-FLR-pcb-Datasheet-1317199.pdf" H 2450 10250 50  0001 L CNN
F 4 "FLR PCB FUSE HOLDER FOR ATO STYLE BLADE FUSE RATED 58V" H 2450 10150 50  0001 L CNN "Description"
F 5 "17.5" H 2450 10050 50  0001 L CNN "Height"
F 6 "LITTELFUSE" H 2450 9950 50  0001 L CNN "Manufacturer_Name"
F 7 "178.6165.0001" H 2450 9850 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "576-178.6165.0001" H 2450 9750 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Littelfuse/17861650001?qs=CSLd874fYV1KI1oBGU5EQg%3D%3D" H 2450 9650 50  0001 L CNN "Mouser Price/Stock"
F 10 "178.6165.0001" H 2450 9550 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/178.6165.0001/littelfuse" H 2450 9450 50  0001 L CNN "Arrow Price/Stock"
	1    1800 10250
	1    0    0    -1  
$EndComp
Text GLabel 7000 7950 0    50   Input ~ 0
HEADLIGHT_12V
Wire Wire Line
	7000 7950 8400 7950
Wire Wire Line
	7050 6400 8400 6400
Text GLabel 19000 2950 0    50   Input ~ 0
HIGHBEAM_SWITCH_A
Text GLabel 19000 4750 0    50   Input ~ 0
HIGHBEAM_SWITCH_B
Text GLabel 7000 8250 0    50   Input ~ 0
IGNITION_12V
Text GLabel 9450 8250 2    50   Input ~ 0
HIGHBEAM_SWITCH_A
Wire Wire Line
	7000 8250 9450 8250
Text GLabel 9450 6800 2    50   Input ~ 0
HEADLIGHT_SWITCH_A
Text GLabel 7000 6800 0    50   Input ~ 0
IGNITION_12V
Wire Wire Line
	7000 6800 9450 6800
Wire Wire Line
	7250 7350 7250 7000
Wire Wire Line
	7250 7000 8050 7000
Wire Wire Line
	8050 7000 8050 7350
Connection ~ 8050 7350
Wire Wire Line
	7250 7850 8050 7850
Wire Wire Line
	7250 7650 7250 7850
Connection ~ 7250 7650
Connection ~ 8050 7850
Wire Wire Line
	1600 3900 1600 3550
Wire Wire Line
	1600 3550 2600 3550
Wire Wire Line
	2600 3550 2600 3900
Connection ~ 2600 3900
Text GLabel 19000 3050 0    50   Input ~ 0
HEADLIGHT_SWITCH_A
Text GLabel 19000 3250 0    50   Input ~ 0
HEADLIGHT_SWITCH_B
Wire Wire Line
	2500 13850 2700 13850
Text GLabel 7000 8150 0    50   Input ~ 0
DASH_HIGHBEAM_INDICATOR
Wire Wire Line
	7000 8150 7150 8150
Wire Wire Line
	7150 8150 7150 8050
Connection ~ 7150 8050
Wire Wire Line
	7150 8050 8400 8050
Text GLabel 21350 4050 0    50   Input ~ 0
INTERIOR_LIGHT_SWITCH_B
Text GLabel 21350 1350 0    50   Input ~ 0
INTERIOR_LIGHT_SWITCH_A
Text GLabel 21350 3950 0    50   Input ~ 0
INTERIOR_LIGHTS
Text GLabel 21350 3850 0    50   Input ~ 0
DASHBOARD_12V
Text GLabel 21350 2150 0    50   Input ~ 0
RADIO_12V
$Comp
L Connector:282836-6 B7
U 1 1 61AAAC55
P 21350 1150
F 0 "B7" H 21978 946 50  0000 L CNN
F 1 "282836-6" H 21978 855 50  0000 L CNN
F 2 "Socket:2828366" H 22000 1250 50  0001 L CNN
F 3 "https://www.te.com/commerce/DocumentDelivery/DDEController?Action=showdoc&DocId=Customer+Drawing%7F282836%7FJ%7Fpdf%7FEnglish%7FENG_CD_282836_J.pdf%7F282836-6" H 22000 1150 50  0001 L CNN
F 4 "Fixed Terminal Blocks 5.0MM PCB MOUNT 6P" H 22000 1050 50  0001 L CNN "Description"
F 5 "10.2" H 22000 950 50  0001 L CNN "Height"
F 6 "TE Connectivity" H 22000 850 50  0001 L CNN "Manufacturer_Name"
F 7 "282836-6" H 22000 750 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "571-2828366" H 22000 650 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/TE-Connectivity/282836-6/?qs=A%252Bip%252BNCYi6MsYFpaQLKbfg%3D%3D" H 22000 550 50  0001 L CNN "Mouser Price/Stock"
F 10 "282836-6" H 22000 450 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/282836-6/te-connectivity" H 22000 350 50  0001 L CNN "Arrow Price/Stock"
	1    21350 1150
	1    0    0    -1  
$EndComp
$Comp
L Connector:282836-6 B4
U 1 1 621F3BC2
P 19000 3550
F 0 "B4" H 19628 3346 50  0000 L CNN
F 1 "282836-6" H 19628 3255 50  0000 L CNN
F 2 "Socket:2828366" H 19650 3650 50  0001 L CNN
F 3 "https://www.te.com/commerce/DocumentDelivery/DDEController?Action=showdoc&DocId=Customer+Drawing%7F282836%7FJ%7Fpdf%7FEnglish%7FENG_CD_282836_J.pdf%7F282836-6" H 19650 3550 50  0001 L CNN
F 4 "Fixed Terminal Blocks 5.0MM PCB MOUNT 6P" H 19650 3450 50  0001 L CNN "Description"
F 5 "10.2" H 19650 3350 50  0001 L CNN "Height"
F 6 "TE Connectivity" H 19650 3250 50  0001 L CNN "Manufacturer_Name"
F 7 "282836-6" H 19650 3150 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "571-2828366" H 19650 3050 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/TE-Connectivity/282836-6/?qs=A%252Bip%252BNCYi6MsYFpaQLKbfg%3D%3D" H 19650 2950 50  0001 L CNN "Mouser Price/Stock"
F 10 "282836-6" H 19650 2850 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/282836-6/te-connectivity" H 19650 2750 50  0001 L CNN "Arrow Price/Stock"
	1    19000 3550
	1    0    0    -1  
$EndComp
Text GLabel 19000 1650 0    50   Input ~ 0
DASH_INDICATOR_INDICATOR
Text GLabel 21350 1150 0    50   Input ~ 0
HAZARD_SWITCH_A
Text GLabel 19000 1350 0    50   Input ~ 0
HAZARD_SWITCH_B
Wire Wire Line
	2900 12000 2800 12000
Wire Wire Line
	2800 12000 2800 12300
Wire Wire Line
	2800 12300 2650 12300
Text GLabel 19000 3950 0    50   Input ~ 0
DASHBOARD_GND
Text GLabel 1600 6800 0    50   Input ~ 0
INVERTER_GND
Text GLabel 3000 6800 2    50   Input ~ 0
GND
Wire Wire Line
	1600 6800 3000 6800
Text GLabel 1600 8850 0    50   Input ~ 0
HVJB_GND
Text GLabel 3000 8850 2    50   Input ~ 0
GND
Wire Wire Line
	1600 8850 3000 8850
$Comp
L Connector:178.6165.0001 HEATER_FAN_FUSE1
U 1 1 62A58892
P 7300 10050
F 0 "HEATER_FAN_FUSE1" H 7700 10315 50  0000 C CNN
F 1 "178.6165.0001" H 7700 10224 50  0000 C CNN
F 2 "Socket:17861650001" H 7950 10150 50  0001 L CNN
F 3 "https://www.mouser.com/datasheet/2/240/Littelfuse-Fuse-Holder-ATO-FLR-pcb-Datasheet-1317199.pdf" H 7950 10050 50  0001 L CNN
F 4 "FLR PCB FUSE HOLDER FOR ATO STYLE BLADE FUSE RATED 58V" H 7950 9950 50  0001 L CNN "Description"
F 5 "17.5" H 7950 9850 50  0001 L CNN "Height"
F 6 "LITTELFUSE" H 7950 9750 50  0001 L CNN "Manufacturer_Name"
F 7 "178.6165.0001" H 7950 9650 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "576-178.6165.0001" H 7950 9550 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Littelfuse/17861650001?qs=CSLd874fYV1KI1oBGU5EQg%3D%3D" H 7950 9450 50  0001 L CNN "Mouser Price/Stock"
F 10 "178.6165.0001" H 7950 9350 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/178.6165.0001/littelfuse" H 7950 9250 50  0001 L CNN "Arrow Price/Stock"
	1    7300 10050
	1    0    0    -1  
$EndComp
Wire Wire Line
	7300 10150 7300 10050
Wire Wire Line
	7300 10050 7300 9650
Wire Wire Line
	7300 9650 8100 9650
Wire Wire Line
	8100 9650 8100 10050
Connection ~ 7300 10050
Wire Wire Line
	8100 10050 8100 10150
Connection ~ 8100 10050
Wire Wire Line
	7300 10250 7300 10350
Wire Wire Line
	7300 10350 7300 10550
Wire Wire Line
	7300 10550 8100 10550
Wire Wire Line
	8100 10550 8100 10350
Connection ~ 7300 10350
Wire Wire Line
	8100 10350 8100 10250
Connection ~ 8100 10350
Text GLabel 7100 10050 0    50   Input ~ 0
IGNITION_12V
Wire Wire Line
	7100 10050 7300 10050
Text GLabel 8350 10350 2    50   Input ~ 0
HEATER_FAN_12V
Wire Wire Line
	8100 10350 8350 10350
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
Text GLabel 13150 11550 0    50   Input ~ 0
REVERSE_SIGNAL
Wire Wire Line
	13250 11450 13250 11550
Wire Wire Line
	13250 11550 13150 11550
Connection ~ 13250 11450
Wire Wire Line
	13250 11450 13150 11450
Text GLabel 19000 5350 0    50   Input ~ 0
REVERSE_SIGNAL
$Comp
L Connector:282836-6 B5
U 1 1 62DE5077
P 19000 4350
F 0 "B5" H 19628 4146 50  0000 L CNN
F 1 "282836-6" H 19628 4055 50  0000 L CNN
F 2 "Socket:2828366" H 19650 4450 50  0001 L CNN
F 3 "https://www.te.com/commerce/DocumentDelivery/DDEController?Action=showdoc&DocId=Customer+Drawing%7F282836%7FJ%7Fpdf%7FEnglish%7FENG_CD_282836_J.pdf%7F282836-6" H 19650 4350 50  0001 L CNN
F 4 "Fixed Terminal Blocks 5.0MM PCB MOUNT 6P" H 19650 4250 50  0001 L CNN "Description"
F 5 "10.2" H 19650 4150 50  0001 L CNN "Height"
F 6 "TE Connectivity" H 19650 4050 50  0001 L CNN "Manufacturer_Name"
F 7 "282836-6" H 19650 3950 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "571-2828366" H 19650 3850 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/TE-Connectivity/282836-6/?qs=A%252Bip%252BNCYi6MsYFpaQLKbfg%3D%3D" H 19650 3750 50  0001 L CNN "Mouser Price/Stock"
F 10 "282836-6" H 19650 3650 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/282836-6/te-connectivity" H 19650 3550 50  0001 L CNN "Arrow Price/Stock"
	1    19000 4350
	1    0    0    -1  
$EndComp
Text GLabel 21350 3650 0    50   Input ~ 0
BRAKE_SWITCH_A
Text GLabel 21500 4650 0    50   Input ~ 0
BRAKE_SWITCH_B
Text GLabel 7400 11950 0    50   Input ~ 0
IGNITION_12V
Text GLabel 7850 11950 2    50   Input ~ 0
BRAKE_SWITCH_A
Wire Wire Line
	7400 11950 7850 11950
Text GLabel 7400 12050 0    50   Input ~ 0
BRAKE_SWITCH_B
Text GLabel 7850 12050 2    50   Input ~ 0
BRAKE_SIGNAL
Wire Wire Line
	7400 12050 7750 12050
Text GLabel 7850 12150 2    50   Input ~ 0
INVERTER_BRAKE_SIGNAL
Wire Wire Line
	7850 12150 7750 12150
Wire Wire Line
	7750 12150 7750 12050
Connection ~ 7750 12050
Wire Wire Line
	7750 12050 7850 12050
Text GLabel 21350 3750 0    50   Input ~ 0
CHARGER_ON_SIGNAL
Wire Wire Line
	6900 2250 7450 2250
Text GLabel 7450 2250 2    50   Input ~ 0
GND
Text GLabel 6900 2250 0    50   Input ~ 0
DASHBOARD_GND
Wire Wire Line
	13350 6700 14000 6700
Text GLabel 14000 6700 2    50   Input ~ 0
GND
Text GLabel 13350 6700 0    50   Input ~ 0
BMS_GND
Wire Wire Line
	13850 5700 14050 5700
Wire Wire Line
	13100 5700 13250 5700
Text GLabel 13100 5700 0    50   Input ~ 0
DASH_INDICATOR_INDICATOR
Wire Wire Line
	13100 5200 14050 5200
Wire Wire Line
	13100 5000 14050 5000
$Comp
L Diode:10A10 D10
U 1 1 623366B3
P 13250 5700
F 0 "D10" H 13550 5967 50  0000 C CNN
F 1 "10A10" H 13550 5876 50  0000 C CNN
F 2 "Diode_THT:DIOAD1165W56L425D185" H 13700 5700 50  0001 L CNN
F 3 "https://www.rectron.com/data_sheets/10a05-10a10.pdf" H 13700 5600 50  0001 L CNN
F 4 "10A10" H 13700 5500 50  0001 L CNN "Description"
F 5 "Rectron" H 13700 5300 50  0001 L CNN "Manufacturer_Name"
F 6 "10A10" H 13700 5200 50  0001 L CNN "Manufacturer_Part_Number"
F 7 "10A10" H 13700 4900 50  0001 L CNN "Arrow Part Number"
F 8 "https://www.arrow.com/en/products/10a10/rectron" H 13700 4800 50  0001 L CNN "Arrow Price/Stock"
	1    13250 5700
	1    0    0    -1  
$EndComp
Wire Wire Line
	13100 3600 14050 3600
Wire Wire Line
	13100 3400 14050 3400
Wire Wire Line
	13100 4100 13300 4100
Text GLabel 13100 4100 0    50   Input ~ 0
DASH_INDICATOR_INDICATOR
Wire Wire Line
	14050 4100 13900 4100
$Comp
L Diode:10A10 D9
U 1 1 62273542
P 13300 4100
F 0 "D9" H 13600 4367 50  0000 C CNN
F 1 "10A10" H 13600 4276 50  0000 C CNN
F 2 "Diode_THT:DIOAD1165W56L425D185" H 13750 4100 50  0001 L CNN
F 3 "https://www.rectron.com/data_sheets/10a05-10a10.pdf" H 13750 4000 50  0001 L CNN
F 4 "10A10" H 13750 3900 50  0001 L CNN "Description"
F 5 "Rectron" H 13750 3700 50  0001 L CNN "Manufacturer_Name"
F 6 "10A10" H 13750 3600 50  0001 L CNN "Manufacturer_Part_Number"
F 7 "10A10" H 13750 3300 50  0001 L CNN "Arrow Part Number"
F 8 "https://www.arrow.com/en/products/10a10/rectron" H 13750 3200 50  0001 L CNN "Arrow Price/Stock"
	1    13300 4100
	1    0    0    -1  
$EndComp
Text GLabel 13100 3600 0    50   Input ~ 0
LH_INDICATOR
Text GLabel 6900 2150 0    50   Input ~ 0
DASHBOARD_12V
Text GLabel 3000 10550 2    50   Input ~ 0
RADIO_12V
$Comp
L Diode:10A10 D8
U 1 1 61E6E87E
P 14850 8800
F 0 "D8" H 15150 9067 50  0000 C CNN
F 1 "10A10" H 15150 8976 50  0000 C CNN
F 2 "Diode_THT:DIOAD1165W56L425D185" H 15300 8800 50  0001 L CNN
F 3 "https://www.rectron.com/data_sheets/10a05-10a10.pdf" H 15300 8700 50  0001 L CNN
F 4 "10A10" H 15300 8600 50  0001 L CNN "Description"
F 5 "Rectron" H 15300 8400 50  0001 L CNN "Manufacturer_Name"
F 6 "10A10" H 15300 8300 50  0001 L CNN "Manufacturer_Part_Number"
F 7 "10A10" H 15300 8000 50  0001 L CNN "Arrow Part Number"
F 8 "https://www.arrow.com/en/products/10a10/rectron" H 15300 7900 50  0001 L CNN "Arrow Price/Stock"
	1    14850 8800
	1    0    0    -1  
$EndComp
Wire Wire Line
	14800 8350 14800 8000
Connection ~ 14800 8350
Wire Wire Line
	14850 8350 14800 8350
Wire Wire Line
	14800 8000 14700 8000
Wire Wire Line
	14800 8800 14800 8350
Wire Wire Line
	14850 8800 14800 8800
Wire Wire Line
	15550 8800 15450 8800
Wire Wire Line
	15550 8350 15450 8350
Text GLabel 15550 8800 2    50   Input ~ 0
CHARGER_ON_SIGNAL
Text GLabel 15550 8350 2    50   Input ~ 0
IGNITION_12V
$Comp
L Diode:10A10 D7
U 1 1 61E46E3E
P 14850 8350
F 0 "D7" H 15150 8617 50  0000 C CNN
F 1 "10A10" H 15150 8526 50  0000 C CNN
F 2 "Diode_THT:DIOAD1165W56L425D185" H 15300 8350 50  0001 L CNN
F 3 "https://www.rectron.com/data_sheets/10a05-10a10.pdf" H 15300 8250 50  0001 L CNN
F 4 "10A10" H 15300 8150 50  0001 L CNN "Description"
F 5 "Rectron" H 15300 7950 50  0001 L CNN "Manufacturer_Name"
F 6 "10A10" H 15300 7850 50  0001 L CNN "Manufacturer_Part_Number"
F 7 "10A10" H 15300 7550 50  0001 L CNN "Arrow Part Number"
F 8 "https://www.arrow.com/en/products/10a10/rectron" H 15300 7450 50  0001 L CNN "Arrow Price/Stock"
	1    14850 8350
	1    0    0    -1  
$EndComp
Wire Wire Line
	14700 7900 15000 7900
Text GLabel 15000 7900 2    50   Input ~ 0
GND
Wire Wire Line
	12700 8100 13900 8100
Text GLabel 12700 8100 0    50   Input ~ 0
BMS_12V
Connection ~ 13700 7900
Wire Wire Line
	13700 7900 13900 7900
$Comp
L DZ85AB-5-PCB:DZ85AB-5-PCB BMS_RELAY1
U 1 1 61E2135A
P 13900 7900
F 0 "BMS_RELAY1" H 14300 8165 50  0000 C CNN
F 1 "DZ85AB-5-PCB" H 14300 8074 50  0000 C CNN
F 2 "Socket:DZ85AB5PCB" H 14550 8000 50  0001 L CNN
F 3 "https://componentsearchengine.com/Datasheets/2/DZ85AB-5-PCB.pdf" H 14550 7900 50  0001 L CNN
F 4 "Durakool 1 Pin Relay Socket, Plug In for use with Various Series" H 14550 7800 50  0001 L CNN "Description"
F 5 "14.5" H 14550 7700 50  0001 L CNN "Height"
F 6 "DURAKOOL" H 14550 7600 50  0001 L CNN "Manufacturer_Name"
F 7 "DZ85AB-5-PCB" H 14550 7500 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "" H 14550 7400 50  0001 L CNN "Mouser Part Number"
F 9 "" H 14550 7300 50  0001 L CNN "Mouser Price/Stock"
F 10 "" H 14550 7200 50  0001 L CNN "Arrow Part Number"
F 11 "" H 14550 7100 50  0001 L CNN "Arrow Price/Stock"
	1    13900 7900
	1    0    0    -1  
$EndComp
Wire Wire Line
	12700 7300 12900 7300
Text GLabel 12700 7300 0    50   Input ~ 0
PERM_12V
Connection ~ 13700 7700
Wire Wire Line
	13700 7700 13700 7600
Connection ~ 12900 7700
Wire Wire Line
	13700 7900 13700 7700
Wire Wire Line
	12900 7900 13700 7900
Wire Wire Line
	12900 7700 12900 7900
Wire Wire Line
	12900 7600 12900 7700
Connection ~ 12900 7300
Wire Wire Line
	12900 7300 12900 7400
Wire Wire Line
	12900 6900 13700 6900
Wire Wire Line
	12900 7300 12900 6900
$Comp
L Connector:178.6165.0001 BMS_FUSE1
U 1 1 61DD02E0
P 12900 7400
F 0 "BMS_FUSE1" H 13300 7665 50  0000 C CNN
F 1 "178.6165.0001" H 13300 7574 50  0000 C CNN
F 2 "Socket:17861650001" H 13550 7500 50  0001 L CNN
F 3 "https://www.mouser.com/datasheet/2/240/Littelfuse-Fuse-Holder-ATO-FLR-pcb-Datasheet-1317199.pdf" H 13550 7400 50  0001 L CNN
F 4 "FLR PCB FUSE HOLDER FOR ATO STYLE BLADE FUSE RATED 58V" H 13550 7300 50  0001 L CNN "Description"
F 5 "17.5" H 13550 7200 50  0001 L CNN "Height"
F 6 "LITTELFUSE" H 13550 7100 50  0001 L CNN "Manufacturer_Name"
F 7 "178.6165.0001" H 13550 7000 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "576-178.6165.0001" H 13550 6900 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Littelfuse/17861650001?qs=CSLd874fYV1KI1oBGU5EQg%3D%3D" H 13550 6800 50  0001 L CNN "Mouser Price/Stock"
F 10 "178.6165.0001" H 13550 6700 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/178.6165.0001/littelfuse" H 13550 6600 50  0001 L CNN "Arrow Price/Stock"
	1    12900 7400
	1    0    0    -1  
$EndComp
Connection ~ 14050 5200
Connection ~ 14050 3600
Text GLabel 13100 5200 0    50   Input ~ 0
RH_INDICATOR
Text GLabel 15700 3500 2    50   Input ~ 0
LH_INDICATOR_SWITCH_B
Text GLabel 13100 5000 0    50   Input ~ 0
FLASHER_B
Text GLabel 13100 3400 0    50   Input ~ 0
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
P 14050 3400
F 0 "LH_INDICATOR_RELAY1" H 14450 3665 50  0000 C CNN
F 1 "DZ85AB-5-PCB" H 14450 3574 50  0000 C CNN
F 2 "Socket:DZ85AB5PCB" H 14700 3500 50  0001 L CNN
F 3 "https://componentsearchengine.com/Datasheets/2/DZ85AB-5-PCB.pdf" H 14700 3400 50  0001 L CNN
F 4 "Durakool 1 Pin Relay Socket, Plug In for use with Various Series" H 14700 3300 50  0001 L CNN "Description"
F 5 "14.5" H 14700 3200 50  0001 L CNN "Height"
F 6 "DURAKOOL" H 14700 3100 50  0001 L CNN "Manufacturer_Name"
F 7 "DZ85AB-5-PCB" H 14700 3000 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "" H 14700 2900 50  0001 L CNN "Mouser Part Number"
F 9 "" H 14700 2800 50  0001 L CNN "Mouser Price/Stock"
F 10 "" H 14700 2700 50  0001 L CNN "Arrow Part Number"
F 11 "" H 14700 2600 50  0001 L CNN "Arrow Price/Stock"
	1    14050 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	9550 2900 9700 2900
Text GLabel 9700 2900 2    50   Input ~ 0
CHARGER_ON_SIGNAL
Wire Wire Line
	9700 2400 9550 2400
Text GLabel 9700 2400 2    50   Input ~ 0
IGNITION_12V
Connection ~ 8900 2400
Wire Wire Line
	8900 2900 8950 2900
Wire Wire Line
	8900 2400 8900 2900
$Comp
L Diode:10A10 D2
U 1 1 61BB0644
P 8950 2900
F 0 "D2" H 9250 3167 50  0000 C CNN
F 1 "10A10" H 9250 3076 50  0000 C CNN
F 2 "Diode_THT:DIOAD1165W56L425D185" H 9400 2900 50  0001 L CNN
F 3 "https://www.rectron.com/data_sheets/10a05-10a10.pdf" H 9400 2800 50  0001 L CNN
F 4 "10A10" H 9400 2700 50  0001 L CNN "Description"
F 5 "Rectron" H 9400 2500 50  0001 L CNN "Manufacturer_Name"
F 6 "10A10" H 9400 2400 50  0001 L CNN "Manufacturer_Part_Number"
F 7 "10A10" H 9400 2100 50  0001 L CNN "Arrow Part Number"
F 8 "https://www.arrow.com/en/products/10a10/rectron" H 9400 2000 50  0001 L CNN "Arrow Price/Stock"
	1    8950 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	8900 2400 8950 2400
Wire Wire Line
	8900 2050 8900 2400
Wire Wire Line
	8850 2050 8900 2050
$Comp
L Diode:10A10 D1
U 1 1 61BAA06F
P 8950 2400
F 0 "D1" H 9250 2667 50  0000 C CNN
F 1 "10A10" H 9250 2576 50  0000 C CNN
F 2 "Diode_THT:DIOAD1165W56L425D185" H 9400 2400 50  0001 L CNN
F 3 "https://www.rectron.com/data_sheets/10a05-10a10.pdf" H 9400 2300 50  0001 L CNN
F 4 "10A10" H 9400 2200 50  0001 L CNN "Description"
F 5 "Rectron" H 9400 2000 50  0001 L CNN "Manufacturer_Name"
F 6 "10A10" H 9400 1900 50  0001 L CNN "Manufacturer_Part_Number"
F 7 "10A10" H 9400 1600 50  0001 L CNN "Arrow Part Number"
F 8 "https://www.arrow.com/en/products/10a10/rectron" H 9400 1500 50  0001 L CNN "Arrow Price/Stock"
	1    8950 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	6900 2150 8050 2150
Wire Wire Line
	8850 1950 9000 1950
Text GLabel 9000 1950 2    50   Input ~ 0
GND
Connection ~ 7900 1950
Wire Wire Line
	7900 1950 8050 1950
$Comp
L DZ85AB-5-PCB:DZ85AB-5-PCB DASHBOARD_RELAY1
U 1 1 61B911B9
P 8050 1950
F 0 "DASHBOARD_RELAY1" H 8450 2215 50  0000 C CNN
F 1 "DZ85AB-5-PCB" H 8450 2124 50  0000 C CNN
F 2 "Socket:DZ85AB5PCB" H 8700 2050 50  0001 L CNN
F 3 "https://componentsearchengine.com/Datasheets/2/DZ85AB-5-PCB.pdf" H 8700 1950 50  0001 L CNN
F 4 "Durakool 1 Pin Relay Socket, Plug In for use with Various Series" H 8700 1850 50  0001 L CNN "Description"
F 5 "14.5" H 8700 1750 50  0001 L CNN "Height"
F 6 "DURAKOOL" H 8700 1650 50  0001 L CNN "Manufacturer_Name"
F 7 "DZ85AB-5-PCB" H 8700 1550 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "" H 8700 1450 50  0001 L CNN "Mouser Part Number"
F 9 "" H 8700 1350 50  0001 L CNN "Mouser Price/Stock"
F 10 "" H 8700 1250 50  0001 L CNN "Arrow Part Number"
F 11 "" H 8700 1150 50  0001 L CNN "Arrow Price/Stock"
	1    8050 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	6900 1450 7100 1450
Text GLabel 6900 1450 0    50   Input ~ 0
PERM_12V
Connection ~ 7900 1750
Wire Wire Line
	7900 1750 7900 1650
Connection ~ 7100 1750
Wire Wire Line
	7900 1950 7900 1750
Wire Wire Line
	7100 1950 7900 1950
Wire Wire Line
	7100 1750 7100 1950
Wire Wire Line
	7100 1650 7100 1750
Connection ~ 7100 1450
Wire Wire Line
	7100 1550 7100 1450
Connection ~ 7900 1450
Wire Wire Line
	7900 1450 7900 1550
Wire Wire Line
	7900 1100 7900 1450
Wire Wire Line
	7100 1100 7900 1100
Wire Wire Line
	7100 1450 7100 1100
$Comp
L Connector:178.6165.0001 DASHBOARD_FUSE1
U 1 1 61B6FF00
P 7100 1450
F 0 "DASHBOARD_FUSE1" H 7500 1715 50  0000 C CNN
F 1 "178.6165.0001" H 7500 1624 50  0000 C CNN
F 2 "Socket:17861650001" H 7750 1550 50  0001 L CNN
F 3 "https://www.mouser.com/datasheet/2/240/Littelfuse-Fuse-Holder-ATO-FLR-pcb-Datasheet-1317199.pdf" H 7750 1450 50  0001 L CNN
F 4 "FLR PCB FUSE HOLDER FOR ATO STYLE BLADE FUSE RATED 58V" H 7750 1350 50  0001 L CNN "Description"
F 5 "17.5" H 7750 1250 50  0001 L CNN "Height"
F 6 "LITTELFUSE" H 7750 1150 50  0001 L CNN "Manufacturer_Name"
F 7 "178.6165.0001" H 7750 1050 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "576-178.6165.0001" H 7750 950 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Littelfuse/17861650001?qs=CSLd874fYV1KI1oBGU5EQg%3D%3D" H 7750 850 50  0001 L CNN "Mouser Price/Stock"
F 10 "178.6165.0001" H 7750 750 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/178.6165.0001/littelfuse" H 7750 650 50  0001 L CNN "Arrow Price/Stock"
	1    7100 1450
	1    0    0    -1  
$EndComp
Text GLabel 19000 2450 0    50   Input ~ 0
SHIFTER_12V
$Comp
L Connector:282836-6 B9
U 1 1 63505A9D
P 21350 2750
F 0 "B9" H 21978 2546 50  0000 L CNN
F 1 "282836-6" H 21978 2455 50  0000 L CNN
F 2 "Socket:2828366" H 22000 2850 50  0001 L CNN
F 3 "https://www.te.com/commerce/DocumentDelivery/DDEController?Action=showdoc&DocId=Customer+Drawing%7F282836%7FJ%7Fpdf%7FEnglish%7FENG_CD_282836_J.pdf%7F282836-6" H 22000 2750 50  0001 L CNN
F 4 "Fixed Terminal Blocks 5.0MM PCB MOUNT 6P" H 22000 2650 50  0001 L CNN "Description"
F 5 "10.2" H 22000 2550 50  0001 L CNN "Height"
F 6 "TE Connectivity" H 22000 2450 50  0001 L CNN "Manufacturer_Name"
F 7 "282836-6" H 22000 2350 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "571-2828366" H 22000 2250 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/TE-Connectivity/282836-6/?qs=A%252Bip%252BNCYi6MsYFpaQLKbfg%3D%3D" H 22000 2150 50  0001 L CNN "Mouser Price/Stock"
F 10 "282836-6" H 22000 2050 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/282836-6/te-connectivity" H 22000 1950 50  0001 L CNN "Arrow Price/Stock"
	1    21350 2750
	1    0    0    -1  
$EndComp
Text GLabel 21350 1650 0    50   Input ~ 0
12V_BATT
Text GLabel 19000 1150 0    50   Input ~ 0
FLASHER_B
Text GLabel 21350 2750 0    50   Input ~ 0
FLASHER_A
$Comp
L Connector:282836-6 B2
U 1 1 619D4548
P 19000 1950
F 0 "B2" H 19628 1746 50  0000 L CNN
F 1 "282836-6" H 19628 1655 50  0000 L CNN
F 2 "Socket:2828366" H 19650 2050 50  0001 L CNN
F 3 "https://www.te.com/commerce/DocumentDelivery/DDEController?Action=showdoc&DocId=Customer+Drawing%7F282836%7FJ%7Fpdf%7FEnglish%7FENG_CD_282836_J.pdf%7F282836-6" H 19650 1950 50  0001 L CNN
F 4 "Fixed Terminal Blocks 5.0MM PCB MOUNT 6P" H 19650 1850 50  0001 L CNN "Description"
F 5 "10.2" H 19650 1750 50  0001 L CNN "Height"
F 6 "TE Connectivity" H 19650 1650 50  0001 L CNN "Manufacturer_Name"
F 7 "282836-6" H 19650 1550 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "571-2828366" H 19650 1450 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/TE-Connectivity/282836-6/?qs=A%252Bip%252BNCYi6MsYFpaQLKbfg%3D%3D" H 19650 1350 50  0001 L CNN "Mouser Price/Stock"
F 10 "282836-6" H 19650 1250 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/282836-6/te-connectivity" H 19650 1150 50  0001 L CNN "Arrow Price/Stock"
	1    19000 1950
	1    0    0    -1  
$EndComp
$Comp
L Connector:282836-6 B3
U 1 1 6217BA9E
P 19000 2750
F 0 "B3" H 19628 2546 50  0000 L CNN
F 1 "282836-6" H 19628 2455 50  0000 L CNN
F 2 "Socket:2828366" H 19650 2850 50  0001 L CNN
F 3 "https://www.te.com/commerce/DocumentDelivery/DDEController?Action=showdoc&DocId=Customer+Drawing%7F282836%7FJ%7Fpdf%7FEnglish%7FENG_CD_282836_J.pdf%7F282836-6" H 19650 2750 50  0001 L CNN
F 4 "Fixed Terminal Blocks 5.0MM PCB MOUNT 6P" H 19650 2650 50  0001 L CNN "Description"
F 5 "10.2" H 19650 2550 50  0001 L CNN "Height"
F 6 "TE Connectivity" H 19650 2450 50  0001 L CNN "Manufacturer_Name"
F 7 "282836-6" H 19650 2350 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "571-2828366" H 19650 2250 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/TE-Connectivity/282836-6/?qs=A%252Bip%252BNCYi6MsYFpaQLKbfg%3D%3D" H 19650 2150 50  0001 L CNN "Mouser Price/Stock"
F 10 "282836-6" H 19650 2050 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/282836-6/te-connectivity" H 19650 1950 50  0001 L CNN "Arrow Price/Stock"
	1    19000 2750
	1    0    0    -1  
$EndComp
$Comp
L Connector:282836-6 B10
U 1 1 62781FA2
P 21350 3550
F 0 "B10" H 21978 3346 50  0000 L CNN
F 1 "282836-6" H 21978 3255 50  0000 L CNN
F 2 "Socket:2828366" H 22000 3650 50  0001 L CNN
F 3 "https://www.te.com/commerce/DocumentDelivery/DDEController?Action=showdoc&DocId=Customer+Drawing%7F282836%7FJ%7Fpdf%7FEnglish%7FENG_CD_282836_J.pdf%7F282836-6" H 22000 3550 50  0001 L CNN
F 4 "Fixed Terminal Blocks 5.0MM PCB MOUNT 6P" H 22000 3450 50  0001 L CNN "Description"
F 5 "10.2" H 22000 3350 50  0001 L CNN "Height"
F 6 "TE Connectivity" H 22000 3250 50  0001 L CNN "Manufacturer_Name"
F 7 "282836-6" H 22000 3150 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "571-2828366" H 22000 3050 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/TE-Connectivity/282836-6/?qs=A%252Bip%252BNCYi6MsYFpaQLKbfg%3D%3D" H 22000 2950 50  0001 L CNN "Mouser Price/Stock"
F 10 "282836-6" H 22000 2850 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/282836-6/te-connectivity" H 22000 2750 50  0001 L CNN "Arrow Price/Stock"
	1    21350 3550
	1    0    0    -1  
$EndComp
Text GLabel 19000 5650 0    50   Input ~ 0
INVERTER_FWD
Text GLabel 19000 5250 0    50   Input ~ 0
INVERTER_REV
Text GLabel 19000 5550 0    50   Input ~ 0
SHIFTER_FWD
Text GLabel 19000 5150 0    50   Input ~ 0
SHIFTER_REV
Text GLabel 21500 4550 0    50   Input ~ 0
INVERTER_BRAKE_SIGNAL
Text GLabel 19000 3650 0    50   Input ~ 0
INVERTER_GND
Text GLabel 19000 3850 0    50   Input ~ 0
HVJB_GND
Text GLabel 19000 3750 0    50   Input ~ 0
BMS_GND
Text GLabel 21350 3550 0    50   Input ~ 0
BMS_12V
Text GLabel 21350 2050 0    50   Input ~ 0
HVJB_12V
Text GLabel 21350 2350 0    50   Input ~ 0
INVERTER_12V
$Comp
L Connector:282836-6 B1
U 1 1 61BA2930
P 19000 1150
F 0 "B1" H 19628 946 50  0000 L CNN
F 1 "282836-6" H 19628 855 50  0000 L CNN
F 2 "Socket:2828366" H 19650 1250 50  0001 L CNN
F 3 "https://www.te.com/commerce/DocumentDelivery/DDEController?Action=showdoc&DocId=Customer+Drawing%7F282836%7FJ%7Fpdf%7FEnglish%7FENG_CD_282836_J.pdf%7F282836-6" H 19650 1150 50  0001 L CNN
F 4 "Fixed Terminal Blocks 5.0MM PCB MOUNT 6P" H 19650 1050 50  0001 L CNN "Description"
F 5 "10.2" H 19650 950 50  0001 L CNN "Height"
F 6 "TE Connectivity" H 19650 850 50  0001 L CNN "Manufacturer_Name"
F 7 "282836-6" H 19650 750 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "571-2828366" H 19650 650 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/TE-Connectivity/282836-6/?qs=A%252Bip%252BNCYi6MsYFpaQLKbfg%3D%3D" H 19650 550 50  0001 L CNN "Mouser Price/Stock"
F 10 "282836-6" H 19650 450 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/282836-6/te-connectivity" H 19650 350 50  0001 L CNN "Arrow Price/Stock"
	1    19000 1150
	1    0    0    -1  
$EndComp
Text GLabel 19000 1550 0    50   Input ~ 0
LH_INDICATOR
Text GLabel 19000 1950 0    50   Input ~ 0
RH_INDICATOR
Text GLabel 19000 3150 0    50   Input ~ 0
HEADLIGHTS
Text GLabel 19000 4450 0    50   Input ~ 0
HIGHBEAM
Text GLabel 19000 3550 0    50   Input ~ 0
GND
Text GLabel 19000 2050 0    50   Input ~ 0
HORN
Text GLabel 19000 2250 0    50   Input ~ 0
COOLANT_PUMP
Text GLabel 21350 2250 0    50   Input ~ 0
VACUUM_PUMP
Text Notes 19600 10250 0    50   ~ 0
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
P 15100 3500
F 0 "D11" H 15400 3767 50  0000 C CNN
F 1 "10A10" H 15400 3676 50  0000 C CNN
F 2 "Diode_THT:DIOAD1165W56L425D185" H 15550 3500 50  0001 L CNN
F 3 "https://www.rectron.com/data_sheets/10a05-10a10.pdf" H 15550 3400 50  0001 L CNN
F 4 "10A10" H 15550 3300 50  0001 L CNN "Description"
F 5 "Rectron" H 15550 3100 50  0001 L CNN "Manufacturer_Name"
F 6 "10A10" H 15550 3000 50  0001 L CNN "Manufacturer_Part_Number"
F 7 "10A10" H 15550 2700 50  0001 L CNN "Arrow Part Number"
F 8 "https://www.arrow.com/en/products/10a10/rectron" H 15550 2600 50  0001 L CNN "Arrow Price/Stock"
	1    15100 3500
	1    0    0    -1  
$EndComp
$Comp
L Diode:10A10 D12
U 1 1 647C89BA
P 15100 4000
F 0 "D12" H 15400 4267 50  0000 C CNN
F 1 "10A10" H 15400 4176 50  0000 C CNN
F 2 "Diode_THT:DIOAD1165W56L425D185" H 15550 4000 50  0001 L CNN
F 3 "https://www.rectron.com/data_sheets/10a05-10a10.pdf" H 15550 3900 50  0001 L CNN
F 4 "10A10" H 15550 3800 50  0001 L CNN "Description"
F 5 "Rectron" H 15550 3600 50  0001 L CNN "Manufacturer_Name"
F 6 "10A10" H 15550 3500 50  0001 L CNN "Manufacturer_Part_Number"
F 7 "10A10" H 15550 3200 50  0001 L CNN "Arrow Part Number"
F 8 "https://www.arrow.com/en/products/10a10/rectron" H 15550 3100 50  0001 L CNN "Arrow Price/Stock"
	1    15100 4000
	1    0    0    -1  
$EndComp
Text GLabel 15700 4000 2    50   Input ~ 0
HAZARD_SWITCH_B
Wire Wire Line
	15100 3500 15100 4000
Connection ~ 15100 3500
Wire Wire Line
	14850 3500 15100 3500
Wire Wire Line
	14850 3400 15100 3400
Wire Wire Line
	14050 2650 14200 2650
Wire Wire Line
	15100 3400 15100 3000
Wire Wire Line
	15100 3000 15350 3000
Text GLabel 15350 3000 2    50   Input ~ 0
GND
Text GLabel 15350 4600 2    50   Input ~ 0
GND
$Comp
L Diode:10A10 D13
U 1 1 64924F75
P 15100 5100
F 0 "D13" H 15400 5367 50  0000 C CNN
F 1 "10A10" H 15400 5276 50  0000 C CNN
F 2 "Diode_THT:DIOAD1165W56L425D185" H 15550 5100 50  0001 L CNN
F 3 "https://www.rectron.com/data_sheets/10a05-10a10.pdf" H 15550 5000 50  0001 L CNN
F 4 "10A10" H 15550 4900 50  0001 L CNN "Description"
F 5 "Rectron" H 15550 4700 50  0001 L CNN "Manufacturer_Name"
F 6 "10A10" H 15550 4600 50  0001 L CNN "Manufacturer_Part_Number"
F 7 "10A10" H 15550 4300 50  0001 L CNN "Arrow Part Number"
F 8 "https://www.arrow.com/en/products/10a10/rectron" H 15550 4200 50  0001 L CNN "Arrow Price/Stock"
	1    15100 5100
	1    0    0    -1  
$EndComp
$Comp
L Diode:10A10 D14
U 1 1 649253D4
P 15100 5600
F 0 "D14" H 15400 5867 50  0000 C CNN
F 1 "10A10" H 15400 5776 50  0000 C CNN
F 2 "Diode_THT:DIOAD1165W56L425D185" H 15550 5600 50  0001 L CNN
F 3 "https://www.rectron.com/data_sheets/10a05-10a10.pdf" H 15550 5500 50  0001 L CNN
F 4 "10A10" H 15550 5400 50  0001 L CNN "Description"
F 5 "Rectron" H 15550 5200 50  0001 L CNN "Manufacturer_Name"
F 6 "10A10" H 15550 5100 50  0001 L CNN "Manufacturer_Part_Number"
F 7 "10A10" H 15550 4800 50  0001 L CNN "Arrow Part Number"
F 8 "https://www.arrow.com/en/products/10a10/rectron" H 15550 4700 50  0001 L CNN "Arrow Price/Stock"
	1    15100 5600
	1    0    0    -1  
$EndComp
Text GLabel 15700 5100 2    50   Input ~ 0
RH_INDICATOR_SWITCH_B
Text GLabel 15700 5600 2    50   Input ~ 0
HAZARD_SWITCH_B
Wire Wire Line
	15100 4600 15350 4600
Wire Wire Line
	14850 5100 15100 5100
Wire Wire Line
	14850 5000 15100 5000
Wire Wire Line
	15100 5000 15100 4600
Wire Wire Line
	15100 5600 15100 5100
Connection ~ 15100 5100
Text GLabel 21350 2450 0    50   Input ~ 0
HEATER_FAN_12V
Wire Wire Line
	7000 6600 8400 6600
Text GLabel 19000 4350 0    50   Input ~ 0
DASH_HIGHBEAM_INDICATOR
Text GLabel 13600 12050 0    50   Input ~ 0
SHIFTER_12V
Text GLabel 13800 12050 2    50   Input ~ 0
IGNITION_12V
Wire Wire Line
	13600 12050 13800 12050
Wire Wire Line
	14050 3600 14050 4100
Wire Wire Line
	14050 5200 14050 5700
Text Notes 12450 6500 0    118  ~ 0
DASHBOARD
Wire Wire Line
	13700 6900 13700 7400
Text Notes 12550 10200 0    118  ~ 0
DRIVE INHIBIT
Text Notes 7050 900  0    118  ~ 0
DASHBOARD
Text Notes 7050 3500 0    118  ~ 0
HORN
Text Notes 7100 5950 0    118  ~ 0
HEADLIGHT
Text Notes 1200 900  0    118  ~ 0
IGNITION
Text Notes 1200 3350 0    118  ~ 0
INTERIOR LIGHTS
Text Notes 1200 5550 0    118  ~ 0
INVERTER
Text Notes 1150 7600 0    118  ~ 0
HVJB
Text Notes 1150 9650 0    118  ~ 0
RADIO
Text Notes 1200 11300 0    118  ~ 0
VACUUM
Text Notes 1200 13000 0    118  ~ 0
WATER PUMP
Text Notes 7100 9250 0    118  ~ 0
HEATER FAN
Text Notes 7150 11550 0    118  ~ 0
BRAKES
$EndSCHEMATC
