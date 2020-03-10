EESchema Schematic File Version 4
EELAYER 26 0
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
L Connector:DB9_Male J1
U 1 1 5E6AD0CD
P 2500 1500
F 0 "J1" H 2680 1546 50  0000 L CNN
F 1 "DB9_Male" H 2680 1455 50  0000 L CNN
F 2 "Connector_Dsub:DSUB-9_Male_Horizontal_P2.77x2.84mm_EdgePinOffset4.94mm_Housed_MountingHolesOffset7.48mm" H 2500 1500 50  0001 C CNN
F 3 " ~" H 2500 1500 50  0001 C CNN
	1    2500 1500
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x05_Odd_Even J2
U 1 1 5E6AD279
P 2500 2450
F 0 "J2" H 2550 2867 50  0000 C CNN
F 1 "Conn_02x05_Odd_Even" H 2550 2776 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x05_P2.54mm_Vertical" H 2500 2450 50  0001 C CNN
F 3 "~" H 2500 2450 50  0001 C CNN
	1    2500 2450
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H1
U 1 1 5E6AD302
P 3550 1250
F 0 "H1" H 3650 1296 50  0000 L CNN
F 1 "MountingHole" H 3650 1205 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 3550 1250 50  0001 C CNN
F 3 "~" H 3550 1250 50  0001 C CNN
	1    3550 1250
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H2
U 1 1 5E6AD3C9
P 3550 1550
F 0 "H2" H 3650 1596 50  0000 L CNN
F 1 "MountingHole" H 3650 1505 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 3550 1550 50  0001 C CNN
F 3 "~" H 3550 1550 50  0001 C CNN
	1    3550 1550
	1    0    0    -1  
$EndComp
Text GLabel 2200 2250 0    50   Input ~ 0
1
Text GLabel 2200 2350 0    50   Input ~ 0
3
Text GLabel 2200 2450 0    50   Input ~ 0
5
Text GLabel 2200 2550 0    50   Input ~ 0
7
Text GLabel 2200 2650 0    50   Input ~ 0
9
Text GLabel 2100 1900 0    50   Input ~ 0
1
Text GLabel 2100 1500 0    50   Input ~ 0
3
Text GLabel 2100 1100 0    50   Input ~ 0
5
Text GLabel 2100 1600 0    50   Input ~ 0
7
Text GLabel 2100 1200 0    50   Input ~ 0
9
Text GLabel 2900 2250 2    50   Input ~ 0
2
Text GLabel 2900 2350 2    50   Input ~ 0
4
Text GLabel 2900 2450 2    50   Input ~ 0
6
Text GLabel 2900 2550 2    50   Input ~ 0
8
NoConn ~ 2800 2650
Text GLabel 2100 1700 0    50   Input ~ 0
2
Text GLabel 2100 1300 0    50   Input ~ 0
4
Text GLabel 2100 1800 0    50   Input ~ 0
6
Text GLabel 2100 1400 0    50   Input ~ 0
8
Wire Wire Line
	2100 1100 2200 1100
Wire Wire Line
	2200 1200 2100 1200
Wire Wire Line
	2100 1300 2200 1300
Wire Wire Line
	2100 1400 2200 1400
Wire Wire Line
	2100 1500 2200 1500
Wire Wire Line
	2100 1600 2200 1600
Wire Wire Line
	2100 1700 2200 1700
Wire Wire Line
	2100 1800 2200 1800
Wire Wire Line
	2100 1900 2200 1900
Wire Wire Line
	2200 2250 2300 2250
Wire Wire Line
	2200 2350 2300 2350
Wire Wire Line
	2200 2450 2300 2450
Wire Wire Line
	2200 2550 2300 2550
Wire Wire Line
	2200 2650 2300 2650
Wire Wire Line
	2800 2550 2900 2550
Wire Wire Line
	2800 2450 2900 2450
Wire Wire Line
	2800 2350 2900 2350
Wire Wire Line
	2800 2250 2900 2250
$EndSCHEMATC
