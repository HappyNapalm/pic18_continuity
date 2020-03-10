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
L Connector_Generic:Conn_02x05_Odd_Even J1
U 1 1 5E6AE3EF
P 2500 2350
F 0 "J1" H 2550 2767 50  0000 C CNN
F 1 "Conn_02x05_Odd_Even" H 2550 2676 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_2x05_P2.54mm_Vertical" H 2500 2350 50  0001 C CNN
F 3 "~" H 2500 2350 50  0001 C CNN
	1    2500 2350
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H1
U 1 1 5E6AE477
P 3650 1200
F 0 "H1" H 3750 1246 50  0000 L CNN
F 1 "MountingHole" H 3750 1155 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 3650 1200 50  0001 C CNN
F 3 "~" H 3650 1200 50  0001 C CNN
	1    3650 1200
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H2
U 1 1 5E6AE4C4
P 3650 1450
F 0 "H2" H 3750 1496 50  0000 L CNN
F 1 "MountingHole" H 3750 1405 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 3650 1450 50  0001 C CNN
F 3 "~" H 3650 1450 50  0001 C CNN
	1    3650 1450
	1    0    0    -1  
$EndComp
$Comp
L Connector:DB9_Female J2
U 1 1 5E6AE526
P 2600 1250
F 0 "J2" H 2779 1296 50  0000 L CNN
F 1 "DB9_Female" H 2779 1205 50  0000 L CNN
F 2 "Connector_Dsub:DSUB-9_Female_Horizontal_P2.77x2.84mm_EdgePinOffset4.94mm_Housed_MountingHolesOffset7.48mm" H 2600 1250 50  0001 C CNN
F 3 " ~" H 2600 1250 50  0001 C CNN
	1    2600 1250
	1    0    0    -1  
$EndComp
Text GLabel 2200 2150 0    50   Input ~ 0
1
Text GLabel 2900 2150 2    50   Input ~ 0
2
Text GLabel 2900 2250 2    50   Input ~ 0
4
Text GLabel 2900 2350 2    50   Input ~ 0
6
Text GLabel 2900 2450 2    50   Input ~ 0
8
Text GLabel 2200 2250 0    50   Input ~ 0
3
Text GLabel 2200 2350 0    50   Input ~ 0
5
Text GLabel 2200 2450 0    50   Input ~ 0
7
Text GLabel 2200 2550 0    50   Input ~ 0
9
Text GLabel 2200 850  0    50   Input ~ 0
1
Text GLabel 2200 1250 0    50   Input ~ 0
3
Text GLabel 2200 1650 0    50   Input ~ 0
5
Text GLabel 2200 1150 0    50   Input ~ 0
7
Text GLabel 2200 1550 0    50   Input ~ 0
9
Text GLabel 2200 1050 0    50   Input ~ 0
2
Text GLabel 2200 1450 0    50   Input ~ 0
4
Text GLabel 2200 950  0    50   Input ~ 0
6
Text GLabel 2200 1350 0    50   Input ~ 0
8
Wire Wire Line
	2200 850  2300 850 
Wire Wire Line
	2300 950  2200 950 
Wire Wire Line
	2200 1050 2300 1050
Wire Wire Line
	2200 1150 2300 1150
Wire Wire Line
	2300 1250 2200 1250
Wire Wire Line
	2200 1350 2300 1350
Wire Wire Line
	2300 1450 2200 1450
Wire Wire Line
	2200 1550 2300 1550
Wire Wire Line
	2300 1650 2200 1650
Wire Wire Line
	2200 2150 2300 2150
Wire Wire Line
	2800 2150 2900 2150
Wire Wire Line
	2900 2250 2800 2250
Wire Wire Line
	2300 2250 2200 2250
Wire Wire Line
	2200 2350 2300 2350
Wire Wire Line
	2300 2450 2200 2450
Wire Wire Line
	2200 2550 2300 2550
Wire Wire Line
	2800 2350 2900 2350
Wire Wire Line
	2900 2450 2800 2450
NoConn ~ 2800 2550
NoConn ~ 5050 1200
$EndSCHEMATC
