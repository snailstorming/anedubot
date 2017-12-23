EESchema Schematic File Version 2
LIBS:PCB_10x10-rescue
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:PCB_10x10-cache
EELAYER 25 0
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
L CONN_01X05 P18
U 1 1 59F476FD
P 3150 1375
F 0 "P18" H 3150 1675 50  0000 C CNN
F 1 "LIDAR_RIGHT" V 3250 1375 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x05" H 3150 1375 50  0001 C CNN
F 3 "" H 3150 1375 50  0000 C CNN
	1    3150 1375
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X05 P16
U 1 1 59F477DB
P 2100 1400
F 0 "P16" H 2100 1700 50  0000 C CNN
F 1 "LIDAR_LEFT" V 2200 1400 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x05" H 2100 1400 50  0001 C CNN
F 3 "" H 2100 1400 50  0000 C CNN
	1    2100 1400
	1    0    0    -1  
$EndComp
$Comp
L CONN_02X03 P17
U 1 1 59F478A1
P 2450 2025
F 0 "P17" H 2450 2225 50  0000 C CNN
F 1 "CONN_02X03" H 2450 1825 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x03" H 2450 825 50  0001 C CNN
F 3 "" H 2450 825 50  0000 C CNN
	1    2450 2025
	1    0    0    -1  
$EndComp
Text GLabel 1900 1200 0    60   Input ~ 0
LID_VIN
Text GLabel 2950 1175 0    60   Input ~ 0
LID_VIN
Text GLabel 1900 1400 0    60   Input ~ 0
LID_SDA
Text GLabel 1900 1500 0    60   Input ~ 0
LID_SCL
Text GLabel 1900 1600 0    60   Input ~ 0
LID_L_XSHUT
Text GLabel 2950 1375 0    60   Input ~ 0
LID_SDA
Text GLabel 2950 1475 0    60   Input ~ 0
LID_SCL
Text GLabel 2950 1575 0    60   Input ~ 0
LID_R_XSHUT
$Comp
L GND #PWR01
U 1 1 59F4837F
P 1900 1300
F 0 "#PWR01" H 1900 1050 50  0001 C CNN
F 1 "GND" H 1900 1150 50  0000 C CNN
F 2 "" H 1900 1300 50  0000 C CNN
F 3 "" H 1900 1300 50  0000 C CNN
	1    1900 1300
	0    1    1    0   
$EndComp
$Comp
L GND #PWR02
U 1 1 59F484A9
P 2950 1275
F 0 "#PWR02" H 2950 1025 50  0001 C CNN
F 1 "GND" H 2950 1125 50  0000 C CNN
F 2 "" H 2950 1275 50  0000 C CNN
F 3 "" H 2950 1275 50  0000 C CNN
	1    2950 1275
	0    1    1    0   
$EndComp
Text GLabel 2200 1925 0    60   Input ~ 0
LID_SCL
Text GLabel 2200 2025 0    60   Input ~ 0
LID_SDA
Text GLabel 2200 2125 0    60   Input ~ 0
LID_L_XSHUT
Text GLabel 2700 1925 2    60   Input ~ 0
LID_VIN
$Comp
L GND #PWR03
U 1 1 59F48C21
P 2700 2025
F 0 "#PWR03" H 2700 1775 50  0001 C CNN
F 1 "GND" H 2700 1875 50  0000 C CNN
F 2 "" H 2700 2025 50  0000 C CNN
F 3 "" H 2700 2025 50  0000 C CNN
	1    2700 2025
	0    -1   -1   0   
$EndComp
Text GLabel 2700 2125 2    60   Input ~ 0
LID_R_XSHUT
$EndSCHEMATC
