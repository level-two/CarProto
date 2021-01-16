EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
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
L 74xx:74HC04 U1
U 2 1 5FDF161B
P 2550 1500
F 0 "U1" H 2550 1817 50  0000 C CNN
F 1 "74HC04" H 2550 1726 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm" H 2550 1500 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/74HC_HCT04.pdf" H 2550 1500 50  0001 C CNN
	2    2550 1500
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC04 U1
U 3 1 5FDF2122
P 2550 2500
F 0 "U1" H 2550 2817 50  0000 C CNN
F 1 "74HC04" H 2550 2726 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm" H 2550 2500 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/74HC_HCT04.pdf" H 2550 2500 50  0001 C CNN
	3    2550 2500
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC04 U1
U 4 1 5FDF33C2
P 3350 2500
F 0 "U1" H 3350 2817 50  0000 C CNN
F 1 "74HC04" H 3350 2726 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm" H 3350 2500 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/74HC_HCT04.pdf" H 3350 2500 50  0001 C CNN
	4    3350 2500
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC04 U1
U 5 1 5FDF4928
P 3350 1500
F 0 "U1" H 3350 1817 50  0000 C CNN
F 1 "74HC04" H 3350 1726 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm" H 3350 1500 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/74HC_HCT04.pdf" H 3350 1500 50  0001 C CNN
	5    3350 1500
	1    0    0    -1  
$EndComp
$Comp
L Driver_Motor:L293D U2
U 1 1 5FDF8FB9
P 4850 2100
F 0 "U2" H 4850 3281 50  0000 C CNN
F 1 "74HC04" H 4850 3190 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm" H 5100 1350 50  0001 L CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/74HC_HCT04.pdf" H 4550 2800 50  0001 C CNN
	1    4850 2100
	1    0    0    -1  
$EndComp
$Comp
L Driver_Motor:L293D U3
U 1 1 5FDFB3F3
P 4850 4400
F 0 "U3" H 4850 5581 50  0000 C CNN
F 1 "74HC04" H 4850 5490 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm" H 5100 3650 50  0001 L CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/74HC_HCT04.pdf" H 4550 5100 50  0001 C CNN
	1    4850 4400
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x04_Odd_Even J1
U 1 1 5FE03A5E
P 1300 2050
F 0 "J1" H 1350 2367 50  0000 C CNN
F 1 "Conn_02x04_Odd_Even" H 1350 2276 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x04_P2.54mm_Horizontal" H 1300 2050 50  0001 C CNN
F 3 "~" H 1300 2050 50  0001 C CNN
	1    1300 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 1950 1600 1950
Wire Wire Line
	1000 1950 1100 1950
Wire Wire Line
	1000 2050 1100 2050
Text Label 1600 1950 0    50   ~ 0
En
Text Label 1000 1950 0    50   ~ 0
dir0
Text Label 1000 2050 0    50   ~ 0
dir1
Wire Wire Line
	4350 1900 4200 1900
Wire Wire Line
	4350 4200 4200 4200
Wire Wire Line
	4350 4800 4200 4800
$Comp
L 74xx:74HC04 U1
U 7 1 5FDF71DD
P 1650 5650
F 0 "U1" H 1880 5696 50  0000 L CNN
F 1 "74HC04" H 1880 5605 50  0000 L CNN
F 2 "Package_DIP:DIP-14_W7.62mm" H 1650 5650 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/74HC_HCT04.pdf" H 1650 5650 50  0001 C CNN
	7    1650 5650
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 3800 4050 3800
Wire Wire Line
	2900 4000 3950 4000
Wire Wire Line
	4350 4400 4050 4400
Wire Wire Line
	4050 4400 4050 3800
Connection ~ 4050 3800
Wire Wire Line
	4050 3800 4350 3800
Wire Wire Line
	4350 4600 3950 4600
Wire Wire Line
	3950 4600 3950 4000
Connection ~ 3950 4000
Wire Wire Line
	3950 4000 4350 4000
Wire Wire Line
	2250 1500 2050 1500
Wire Wire Line
	2850 1500 2950 1500
Wire Wire Line
	3650 1500 4100 1500
Wire Wire Line
	4350 1700 4000 1700
Wire Wire Line
	2950 1700 2950 1500
Connection ~ 2950 1500
Wire Wire Line
	2950 1500 3050 1500
Wire Wire Line
	4350 2100 4100 2100
Wire Wire Line
	4100 2100 4100 1500
Connection ~ 4100 1500
Wire Wire Line
	4100 1500 4350 1500
Wire Wire Line
	4350 2300 4000 2300
Wire Wire Line
	4000 2300 4000 1700
Connection ~ 4000 1700
Wire Wire Line
	4000 1700 2950 1700
Text Label 5900 1450 0    50   ~ 0
out_a0
Text Label 5900 1750 0    50   ~ 0
out_a1
Text Label 2050 1500 0    50   ~ 0
dir0
$Comp
L Device:R R1
U 1 1 5FE605CE
P 1100 2900
F 0 "R1" H 1170 2946 50  0000 L CNN
F 1 "10k" H 1170 2855 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 1030 2900 50  0001 C CNN
F 3 "~" H 1100 2900 50  0001 C CNN
	1    1100 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	1100 2750 1100 2600
$Comp
L Device:R R2
U 1 1 5FE632F9
P 1350 2900
F 0 "R2" H 1420 2946 50  0000 L CNN
F 1 "10k" H 1420 2855 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 1280 2900 50  0001 C CNN
F 3 "~" H 1350 2900 50  0001 C CNN
	1    1350 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	1350 2750 1350 2600
$Comp
L Device:R R3
U 1 1 5FE64611
P 1600 2900
F 0 "R3" H 1670 2946 50  0000 L CNN
F 1 "10k" H 1670 2855 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 1530 2900 50  0001 C CNN
F 3 "~" H 1600 2900 50  0001 C CNN
	1    1600 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	1600 2750 1600 2600
$Comp
L Device:C C4
U 1 1 5FE666EB
P 3550 5600
F 0 "C4" H 3665 5646 50  0000 L CNN
F 1 "0.15uF" H 3665 5555 50  0000 L CNN
F 2 "Capacitor_THT:C_Rect_L7.0mm_W2.5mm_P5.00mm" H 3588 5450 50  0001 C CNN
F 3 "~" H 3550 5600 50  0001 C CNN
	1    3550 5600
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C3
U 1 1 5FE6F773
P 3150 5600
F 0 "C3" H 3268 5646 50  0000 L CNN
F 1 "470uF" H 3268 5555 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D10.0mm_P5.00mm" H 3188 5450 50  0001 C CNN
F 3 "~" H 3150 5600 50  0001 C CNN
	1    3150 5600
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C1
U 1 1 5FE75A0A
P 2350 5600
F 0 "C1" H 2468 5646 50  0000 L CNN
F 1 "47uF" H 2468 5555 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.50mm" H 2388 5450 50  0001 C CNN
F 3 "~" H 2350 5600 50  0001 C CNN
	1    2350 5600
	1    0    0    -1  
$EndComp
Text Label 1100 2700 1    50   ~ 0
En
Text Label 1350 2750 1    50   ~ 0
dir0
Text Label 1600 2750 1    50   ~ 0
dir1
$Comp
L Device:C C5
U 1 1 5FE7EBBD
P 5650 1600
F 0 "C5" H 5765 1646 50  0000 L CNN
F 1 "0.15uF" H 5765 1555 50  0000 L CNN
F 2 "Capacitor_THT:C_Rect_L7.0mm_W2.5mm_P5.00mm" H 5688 1450 50  0001 C CNN
F 3 "~" H 5650 1600 50  0001 C CNN
	1    5650 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 1700 5450 1700
Wire Wire Line
	5450 1700 5450 1750
Wire Wire Line
	5450 1750 5650 1750
Connection ~ 5650 1750
Wire Wire Line
	5350 1500 5450 1500
Wire Wire Line
	5450 1500 5450 1450
Wire Wire Line
	5450 1450 5650 1450
Connection ~ 5650 1450
$Comp
L Device:C C6
U 1 1 5FE8C908
P 5650 2200
F 0 "C6" H 5765 2246 50  0000 L CNN
F 1 "0.15uF" H 5765 2155 50  0000 L CNN
F 2 "Capacitor_THT:C_Rect_L7.0mm_W2.5mm_P5.00mm" H 5688 2050 50  0001 C CNN
F 3 "~" H 5650 2200 50  0001 C CNN
	1    5650 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 2300 5450 2300
Wire Wire Line
	5450 2300 5450 2350
Wire Wire Line
	5450 2350 5650 2350
Connection ~ 5650 2350
Wire Wire Line
	5350 2100 5450 2100
Wire Wire Line
	5450 2100 5450 2050
Wire Wire Line
	5450 2050 5650 2050
Connection ~ 5650 2050
$Comp
L Device:C C7
U 1 1 5FE8E42B
P 5650 3900
F 0 "C7" H 5765 3946 50  0000 L CNN
F 1 "0.15uF" H 5765 3855 50  0000 L CNN
F 2 "Capacitor_THT:C_Rect_L7.0mm_W2.5mm_P5.00mm" H 5688 3750 50  0001 C CNN
F 3 "~" H 5650 3900 50  0001 C CNN
	1    5650 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 4000 5450 4000
Wire Wire Line
	5450 4000 5450 4050
Wire Wire Line
	5450 4050 5650 4050
Connection ~ 5650 4050
Wire Wire Line
	5350 3800 5450 3800
Wire Wire Line
	5450 3800 5450 3750
Wire Wire Line
	5450 3750 5650 3750
Connection ~ 5650 3750
$Comp
L Device:C C8
U 1 1 5FE90683
P 5650 4500
F 0 "C8" H 5765 4546 50  0000 L CNN
F 1 "0.15uF" H 5765 4455 50  0000 L CNN
F 2 "Capacitor_THT:C_Rect_L7.0mm_W2.5mm_P5.00mm" H 5688 4350 50  0001 C CNN
F 3 "~" H 5650 4500 50  0001 C CNN
	1    5650 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 4600 5450 4600
Wire Wire Line
	5450 4600 5450 4650
Wire Wire Line
	5450 4650 5650 4650
Connection ~ 5650 4650
Wire Wire Line
	5350 4400 5450 4400
Wire Wire Line
	5450 4400 5450 4350
Wire Wire Line
	5450 4350 5650 4350
Connection ~ 5650 4350
Text Label 5900 2050 0    50   ~ 0
out_b0
Text Label 5900 2350 0    50   ~ 0
out_b1
Text Label 5900 3750 0    50   ~ 0
out_c0
Text Label 5900 4050 0    50   ~ 0
out_c1
Text Label 5900 4350 0    50   ~ 0
out_d0
Text Label 5900 4650 0    50   ~ 0
out_d1
$Comp
L Connector_Generic:Conn_01x02 J2
U 1 1 5FEA9073
P 6600 1750
F 0 "J2" H 6680 1742 50  0000 L CNN
F 1 "Conn_01x02" H 6680 1651 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Horizontal" H 6600 1750 50  0001 C CNN
F 3 "~" H 6600 1750 50  0001 C CNN
	1    6600 1750
	1    0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J3
U 1 1 5FEAF97E
P 6600 2350
F 0 "J3" H 6680 2342 50  0000 L CNN
F 1 "Conn_01x02" H 6680 2251 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Horizontal" H 6600 2350 50  0001 C CNN
F 3 "~" H 6600 2350 50  0001 C CNN
	1    6600 2350
	1    0    0    1   
$EndComp
Wire Wire Line
	6300 1450 6300 1650
Wire Wire Line
	6300 1650 6400 1650
Wire Wire Line
	5650 1450 6300 1450
Wire Wire Line
	5650 1750 6400 1750
Wire Wire Line
	5650 2350 6400 2350
Wire Wire Line
	6400 2250 6300 2250
Wire Wire Line
	6300 2250 6300 2050
Wire Wire Line
	5650 2050 6300 2050
$Comp
L Connector_Generic:Conn_01x02 J5
U 1 1 5FEC2F81
P 6600 4650
F 0 "J5" H 6680 4642 50  0000 L CNN
F 1 "Conn_01x02" H 6680 4551 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Horizontal" H 6600 4650 50  0001 C CNN
F 3 "~" H 6600 4650 50  0001 C CNN
	1    6600 4650
	1    0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J4
U 1 1 5FEC50C2
P 6600 4050
F 0 "J4" H 6680 4042 50  0000 L CNN
F 1 "Conn_01x02" H 6680 3951 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Horizontal" H 6600 4050 50  0001 C CNN
F 3 "~" H 6600 4050 50  0001 C CNN
	1    6600 4050
	1    0    0    1   
$EndComp
Wire Wire Line
	5650 4650 6400 4650
Wire Wire Line
	6400 4550 6300 4550
Wire Wire Line
	6300 4550 6300 4350
Wire Wire Line
	5650 4350 6300 4350
Wire Wire Line
	5650 4050 6400 4050
Wire Wire Line
	6400 3950 6300 3950
Wire Wire Line
	6300 3950 6300 3750
Wire Wire Line
	5650 3750 6300 3750
$Comp
L power:GND #PWR08
U 1 1 5FE085BC
P 1600 2150
F 0 "#PWR08" H 1600 1900 50  0001 C CNN
F 1 "GND" V 1605 2022 50  0000 R CNN
F 2 "" H 1600 2150 50  0001 C CNN
F 3 "" H 1600 2150 50  0001 C CNN
	1    1600 2150
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR07
U 1 1 5FE07753
P 1100 2150
F 0 "#PWR07" H 1100 1900 50  0001 C CNN
F 1 "GND" V 1105 2022 50  0000 R CNN
F 2 "" H 1100 2150 50  0001 C CNN
F 3 "" H 1100 2150 50  0001 C CNN
	1    1100 2150
	0    1    1    0   
$EndComp
$Comp
L power:VCC #PWR02
U 1 1 5FE0685E
P 1600 2250
F 0 "#PWR02" H 1600 2100 50  0001 C CNN
F 1 "VCC" V 1615 2377 50  0000 L CNN
F 2 "" H 1600 2250 50  0001 C CNN
F 3 "" H 1600 2250 50  0001 C CNN
	1    1600 2250
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR01
U 1 1 5FE0519F
P 1100 2250
F 0 "#PWR01" H 1100 2100 50  0001 C CNN
F 1 "+5V" V 1115 2378 50  0000 L CNN
F 2 "" H 1100 2250 50  0001 C CNN
F 3 "" H 1100 2250 50  0001 C CNN
	1    1100 2250
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR031
U 1 1 5FE0E895
P 5050 5200
F 0 "#PWR031" H 5050 4950 50  0001 C CNN
F 1 "GND" H 5055 5027 50  0000 C CNN
F 2 "" H 5050 5200 50  0001 C CNN
F 3 "" H 5050 5200 50  0001 C CNN
	1    5050 5200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR029
U 1 1 5FE0E88F
P 4950 5200
F 0 "#PWR029" H 4950 4950 50  0001 C CNN
F 1 "GND" H 4955 5027 50  0000 C CNN
F 2 "" H 4950 5200 50  0001 C CNN
F 3 "" H 4950 5200 50  0001 C CNN
	1    4950 5200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR025
U 1 1 5FE0D413
P 4750 5200
F 0 "#PWR025" H 4750 4950 50  0001 C CNN
F 1 "GND" H 4755 5027 50  0000 C CNN
F 2 "" H 4750 5200 50  0001 C CNN
F 3 "" H 4750 5200 50  0001 C CNN
	1    4750 5200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR021
U 1 1 5FE0C2E6
P 4650 5200
F 0 "#PWR021" H 4650 4950 50  0001 C CNN
F 1 "GND" H 4655 5027 50  0000 C CNN
F 2 "" H 4650 5200 50  0001 C CNN
F 3 "" H 4650 5200 50  0001 C CNN
	1    4650 5200
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR05
U 1 1 5FE4535C
P 1650 5150
F 0 "#PWR05" H 1650 5000 50  0001 C CNN
F 1 "+5V" H 1665 5323 50  0000 C CNN
F 2 "" H 1650 5150 50  0001 C CNN
F 3 "" H 1650 5150 50  0001 C CNN
	1    1650 5150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR06
U 1 1 5FE4497B
P 1650 6150
F 0 "#PWR06" H 1650 5900 50  0001 C CNN
F 1 "GND" V 1655 6022 50  0000 R CNN
F 2 "" H 1650 6150 50  0001 C CNN
F 3 "" H 1650 6150 50  0001 C CNN
	1    1650 6150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR09
U 1 1 5FE64617
P 1600 3050
F 0 "#PWR09" H 1600 2800 50  0001 C CNN
F 1 "GND" H 1605 2877 50  0000 C CNN
F 2 "" H 1600 3050 50  0001 C CNN
F 3 "" H 1600 3050 50  0001 C CNN
	1    1600 3050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR04
U 1 1 5FE632FF
P 1350 3050
F 0 "#PWR04" H 1350 2800 50  0001 C CNN
F 1 "GND" H 1355 2877 50  0000 C CNN
F 2 "" H 1350 3050 50  0001 C CNN
F 3 "" H 1350 3050 50  0001 C CNN
	1    1350 3050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR03
U 1 1 5FE6122F
P 1100 3050
F 0 "#PWR03" H 1100 2800 50  0001 C CNN
F 1 "GND" H 1105 2877 50  0000 C CNN
F 2 "" H 1100 3050 50  0001 C CNN
F 3 "" H 1100 3050 50  0001 C CNN
	1    1100 3050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR019
U 1 1 5FE78F26
P 3550 5750
F 0 "#PWR019" H 3550 5500 50  0001 C CNN
F 1 "GND" H 3555 5577 50  0000 C CNN
F 2 "" H 3550 5750 50  0001 C CNN
F 3 "" H 3550 5750 50  0001 C CNN
	1    3550 5750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR017
U 1 1 5FE780B0
P 3150 5750
F 0 "#PWR017" H 3150 5500 50  0001 C CNN
F 1 "GND" H 3155 5577 50  0000 C CNN
F 2 "" H 3150 5750 50  0001 C CNN
F 3 "" H 3150 5750 50  0001 C CNN
	1    3150 5750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR015
U 1 1 5FE770FB
P 2750 5750
F 0 "#PWR015" H 2750 5500 50  0001 C CNN
F 1 "GND" H 2755 5577 50  0000 C CNN
F 2 "" H 2750 5750 50  0001 C CNN
F 3 "" H 2750 5750 50  0001 C CNN
	1    2750 5750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR011
U 1 1 5FE76619
P 2350 5750
F 0 "#PWR011" H 2350 5500 50  0001 C CNN
F 1 "GND" H 2355 5577 50  0000 C CNN
F 2 "" H 2350 5750 50  0001 C CNN
F 3 "" H 2350 5750 50  0001 C CNN
	1    2350 5750
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR016
U 1 1 5FE7BB65
P 3150 5450
F 0 "#PWR016" H 3150 5300 50  0001 C CNN
F 1 "VCC" H 3165 5623 50  0000 C CNN
F 2 "" H 3150 5450 50  0001 C CNN
F 3 "" H 3150 5450 50  0001 C CNN
	1    3150 5450
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR010
U 1 1 5FE7A0D8
P 2350 5450
F 0 "#PWR010" H 2350 5300 50  0001 C CNN
F 1 "+5V" H 2365 5623 50  0000 C CNN
F 2 "" H 2350 5450 50  0001 C CNN
F 3 "" H 2350 5450 50  0001 C CNN
	1    2350 5450
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR024
U 1 1 5FE11238
P 4750 3400
F 0 "#PWR024" H 4750 3250 50  0001 C CNN
F 1 "+5V" H 4765 3573 50  0000 C CNN
F 2 "" H 4750 3400 50  0001 C CNN
F 3 "" H 4750 3400 50  0001 C CNN
	1    4750 3400
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR028
U 1 1 5FE10657
P 4950 3400
F 0 "#PWR028" H 4950 3250 50  0001 C CNN
F 1 "VCC" H 4965 3573 50  0000 C CNN
F 2 "" H 4950 3400 50  0001 C CNN
F 3 "" H 4950 3400 50  0001 C CNN
	1    4950 3400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR030
U 1 1 5FE1010F
P 5050 2900
F 0 "#PWR030" H 5050 2650 50  0001 C CNN
F 1 "GND" H 5055 2727 50  0000 C CNN
F 2 "" H 5050 2900 50  0001 C CNN
F 3 "" H 5050 2900 50  0001 C CNN
	1    5050 2900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR027
U 1 1 5FE10109
P 4950 2900
F 0 "#PWR027" H 4950 2650 50  0001 C CNN
F 1 "GND" H 4955 2727 50  0000 C CNN
F 2 "" H 4950 2900 50  0001 C CNN
F 3 "" H 4950 2900 50  0001 C CNN
	1    4950 2900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR023
U 1 1 5FE0F1F2
P 4750 2900
F 0 "#PWR023" H 4750 2650 50  0001 C CNN
F 1 "GND" H 4755 2727 50  0000 C CNN
F 2 "" H 4750 2900 50  0001 C CNN
F 3 "" H 4750 2900 50  0001 C CNN
	1    4750 2900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR020
U 1 1 5FE0F1EC
P 4650 2900
F 0 "#PWR020" H 4650 2650 50  0001 C CNN
F 1 "GND" H 4655 2727 50  0000 C CNN
F 2 "" H 4650 2900 50  0001 C CNN
F 3 "" H 4650 2900 50  0001 C CNN
	1    4650 2900
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR022
U 1 1 5FE14013
P 4750 1100
F 0 "#PWR022" H 4750 950 50  0001 C CNN
F 1 "+5V" H 4765 1273 50  0000 C CNN
F 2 "" H 4750 1100 50  0001 C CNN
F 3 "" H 4750 1100 50  0001 C CNN
	1    4750 1100
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR026
U 1 1 5FE1400D
P 4950 1100
F 0 "#PWR026" H 4950 950 50  0001 C CNN
F 1 "VCC" H 4965 1273 50  0000 C CNN
F 2 "" H 4950 1100 50  0001 C CNN
F 3 "" H 4950 1100 50  0001 C CNN
	1    4950 1100
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 5FE657CA
P 2750 5600
F 0 "C2" H 2865 5646 50  0000 L CNN
F 1 "0.15uF" H 2865 5555 50  0000 L CNN
F 2 "Capacitor_THT:C_Rect_L7.0mm_W2.5mm_P5.00mm" H 2788 5450 50  0001 C CNN
F 3 "~" H 2750 5600 50  0001 C CNN
	1    2750 5600
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR014
U 1 1 5FE7AF68
P 2750 5450
F 0 "#PWR014" H 2750 5300 50  0001 C CNN
F 1 "+5V" H 2765 5623 50  0000 C CNN
F 2 "" H 2750 5450 50  0001 C CNN
F 3 "" H 2750 5450 50  0001 C CNN
	1    2750 5450
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR018
U 1 1 5FE7C74B
P 3550 5450
F 0 "#PWR018" H 3550 5300 50  0001 C CNN
F 1 "VCC" H 3565 5623 50  0000 C CNN
F 2 "" H 3550 5450 50  0001 C CNN
F 3 "" H 3550 5450 50  0001 C CNN
	1    3550 5450
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5FF6FC53
P 950 1000
F 0 "#FLG0101" H 950 1075 50  0001 C CNN
F 1 "PWR_FLAG" H 950 1173 50  0000 C CNN
F 2 "" H 950 1000 50  0001 C CNN
F 3 "~" H 950 1000 50  0001 C CNN
	1    950  1000
	-1   0    0    1   
$EndComp
$Comp
L power:VCC #PWR0101
U 1 1 5FF717C0
P 1100 1000
F 0 "#PWR0101" H 1100 850 50  0001 C CNN
F 1 "VCC" H 1115 1173 50  0000 C CNN
F 2 "" H 1100 1000 50  0001 C CNN
F 3 "" H 1100 1000 50  0001 C CNN
	1    1100 1000
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0102
U 1 1 5FF717C6
P 950 1000
F 0 "#PWR0102" H 950 850 50  0001 C CNN
F 1 "+5V" H 965 1173 50  0000 C CNN
F 2 "" H 950 1000 50  0001 C CNN
F 3 "" H 950 1000 50  0001 C CNN
	1    950  1000
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 5FF78F96
P 1100 1000
F 0 "#FLG0102" H 1100 1075 50  0001 C CNN
F 1 "PWR_FLAG" H 1100 1173 50  0000 C CNN
F 2 "" H 1100 1000 50  0001 C CNN
F 3 "~" H 1100 1000 50  0001 C CNN
	1    1100 1000
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0103
U 1 1 5FF754CD
P 1250 1000
F 0 "#PWR0103" H 1250 750 50  0001 C CNN
F 1 "GND" H 1255 827 50  0000 C CNN
F 2 "" H 1250 1000 50  0001 C CNN
F 3 "" H 1250 1000 50  0001 C CNN
	1    1250 1000
	-1   0    0    1   
$EndComp
$Comp
L power:PWR_FLAG #FLG0103
U 1 1 5FF921A7
P 1250 1000
F 0 "#FLG0103" H 1250 1075 50  0001 C CNN
F 1 "PWR_FLAG" H 1250 1173 50  0000 C CNN
F 2 "" H 1250 1000 50  0001 C CNN
F 3 "~" H 1250 1000 50  0001 C CNN
	1    1250 1000
	-1   0    0    1   
$EndComp
NoConn ~ 1600 2050
Wire Wire Line
	2250 2500 2050 2500
Text Label 2050 2500 0    50   ~ 0
En
Wire Wire Line
	2850 2500 3050 2500
Wire Wire Line
	3650 2500 4200 2500
Wire Wire Line
	4200 1900 4200 2500
Connection ~ 4200 2500
Wire Wire Line
	4200 2500 4350 2500
Wire Wire Line
	4200 2500 4200 4200
Connection ~ 4200 4200
Wire Wire Line
	4200 4200 4200 4800
Wire Wire Line
	2200 3800 2050 3800
Text Label 2050 3800 0    50   ~ 0
dir1
$Comp
L 74xx:74HC04 U1
U 1 1 5FDF087C
P 2500 3800
F 0 "U1" H 2500 4117 50  0000 C CNN
F 1 "74HC04" H 2500 4026 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm" H 2500 3800 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/74HC_HCT04.pdf" H 2500 3800 50  0001 C CNN
	1    2500 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 3800 2900 3800
Wire Wire Line
	2900 3800 2950 3800
Connection ~ 2900 3800
Wire Wire Line
	2900 3800 2900 4000
$Comp
L 74xx:74HC04 U1
U 6 1 5FDF5CC2
P 3250 3800
F 0 "U1" H 3250 4117 50  0000 C CNN
F 1 "74HC04" H 3250 4026 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm" H 3250 3800 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/74HC_HCT04.pdf" H 3250 3800 50  0001 C CNN
	6    3250 3800
	1    0    0    -1  
$EndComp
$EndSCHEMATC
