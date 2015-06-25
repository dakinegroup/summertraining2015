EESchema Schematic File Version 2
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
LIBS:special
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
LIBS:74xx-eu
LIBS:lowvoltage
LIBS:VREG_VOUTCENTER
LIBS:VIN
LIBS:USB
LIBS:TP
LIBS:STM32-48PIN
LIBS:SPST
LIBS:SPST-4PIN
LIBS:SPDT
LIBS:RASPBERRYPI
LIBS:R
LIBS:PWR_FLAG
LIBS:POT
LIBS:PNP
LIBS:PIEZO
LIBS:PHOTO_TRANSISTOR
LIBS:P24
LIBS:P03
LIBS:P02
LIBS:NPN
LIBS:MOSFET-P
LIBS:MOSFET-N
LIBS:MIC2288
LIBS:MECH
LIBS:LM324
LIBS:LED
LIBS:LED-BI
LIBS:JTAG10
LIBS:JTAG
LIBS:INDUCTOR
LIBS:GNDPWR
LIBS:DIODESCH
LIBS:DIODE
LIBS:CVAR
LIBS:CRYSTAL
LIBS:CRYSTAL-14
LIBS:CP
LIBS:C
LIBS:BATTERY
LIBS:AUDIO-JACK-3
LIBS:AP6502
LIBS:+9V
LIBS:+5V
LIBS:+3.3V
LIBS:agilent-infrared
LIBS:traffic_lights-cache
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 5
Title "noname.sch"
Date "24 jun 2015"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L VCC #PWR01
U 1 1 558A4C12
P 1650 4350
F 0 "#PWR01" H 1650 4450 30  0001 C CNN
F 1 "VCC" H 1650 4450 30  0000 C CNN
F 2 "" H 1650 4350 60  0000 C CNN
F 3 "" H 1650 4350 60  0000 C CNN
	1    1650 4350
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR02
U 1 1 558A4C13
P 1550 4050
F 0 "#PWR02" H 1550 4150 30  0001 C CNN
F 1 "VCC" H 1550 4150 30  0000 C CNN
F 2 "" H 1550 4050 60  0000 C CNN
F 3 "" H 1550 4050 60  0000 C CNN
	1    1550 4050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 558A4C14
P 1450 6600
F 0 "#PWR03" H 1450 6600 30  0001 C CNN
F 1 "GND" H 1450 6530 30  0001 C CNN
F 2 "" H 1450 6600 60  0000 C CNN
F 3 "" H 1450 6600 60  0000 C CNN
	1    1450 6600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 558A4C15
P 1550 6600
F 0 "#PWR04" H 1550 6600 30  0001 C CNN
F 1 "GND" H 1550 6530 30  0001 C CNN
F 2 "" H 1550 6600 60  0000 C CNN
F 3 "" H 1550 6600 60  0000 C CNN
	1    1550 6600
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW1
U 1 1 558A4C16
P 7500 6150
F 0 "SW1" H 7650 6260 50  0000 C CNN
F 1 "SW_PUSH" H 7500 6070 50  0000 C CNN
F 2 "~" H 7500 6150 60  0000 C CNN
F 3 "~" H 7500 6150 60  0000 C CNN
	1    7500 6150
	1    0    0    -1  
$EndComp
Text GLabel 4300 5650 2    60   Input ~ 0
RESET_L
Text GLabel 8000 6150 2    60   Input ~ 0
RESET_L
$Comp
L R R1
U 1 1 558A4C17
P 7800 5750
F 0 "R1" V 7880 5750 40  0000 C CNN
F 1 "R" V 7807 5751 40  0000 C CNN
F 2 "~" V 7730 5750 30  0000 C CNN
F 3 "~" H 7800 5750 30  0000 C CNN
	1    7800 5750
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR05
U 1 1 558A4C18
P 7800 5350
F 0 "#PWR05" H 7800 5450 30  0001 C CNN
F 1 "VCC" H 7800 5450 30  0000 C CNN
F 2 "" H 7800 5350 60  0000 C CNN
F 3 "" H 7800 5350 60  0000 C CNN
	1    7800 5350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR06
U 1 1 558A4C19
P 7200 6300
F 0 "#PWR06" H 7200 6300 30  0001 C CNN
F 1 "GND" H 7200 6230 30  0001 C CNN
F 2 "" H 7200 6300 60  0000 C CNN
F 3 "" H 7200 6300 60  0000 C CNN
	1    7200 6300
	1    0    0    -1  
$EndComp
Text GLabel 4300 5000 2    60   Input ~ 0
TC_SER_CLK
$Sheet
S 3850 2200 800  850 
U 558A4BA2
F0 "sensor_module" 50
F1 "sensor1.sch" 50
F2 "SENSOR_TC_1" I L 3850 2300 60 
F3 "SENSOR_TC_2" I L 3850 2500 60 
F4 "SENSOR_TC_3" I L 3850 2700 60 
F5 "SENSOR_TC_4" I L 3850 2900 60 
$EndSheet
Text GLabel 4150 4150 2    60   Input ~ 0
SENSOR_TC_1
Text GLabel 4100 4350 2    60   Input ~ 0
SENSOR_TC_2
Text GLabel 5100 4400 2    60   Input ~ 0
SENSOR_TC_3
Text GLabel 5100 4550 2    60   Input ~ 0
SENSOR_TC_4
Text GLabel 3450 2300 0    60   Input ~ 0
SENSOR_TC_1
Text GLabel 3450 2500 0    60   Input ~ 0
SENSOR_TC_2
Text GLabel 3450 2700 0    60   Input ~ 0
SENSOR_TC_3
Text GLabel 3450 2900 0    60   Input ~ 0
SENSOR_TC_4
$Sheet
S 5650 2200 1350 1000
U 558A7A66
F0 "lcd_module" 50
F1 "lcd_module.sch" 50
F2 "LCD_LATCH_ENABLE" I L 5650 2400 60 
F3 "LCD_STORE_CLK" I L 5650 2550 60 
F4 "LCD_TRANSFER_BYTE_CLK" I L 5650 2700 60 
F5 "LCD_SER_DATA" I L 5650 2850 60 
F6 "LCD_SR_RESET" I L 5650 3000 60 
$EndSheet
$Sheet
S 7950 2350 1200 700 
U 558B3574
F0 "traffic_light_leds" 50
F1 "traffic_light_leds.sch" 50
F2 "TL_SER_DATA" I L 7950 2500 60 
F3 "TL_SER_CLK" I L 7950 2700 60 
F4 "TL_RESET" I L 7950 2900 60 
$EndSheet
Text GLabel 7700 2900 0    60   Input ~ 0
RESET_L
Text GLabel 7700 2700 0    60   Input ~ 0
TC_SER_CLK
Text GLabel 4300 5850 2    60   Input ~ 0
TC_SER_DATA
Text GLabel 7700 2500 0    60   Input ~ 0
TC_SER_DATA
$Comp
L LED D1
U 1 1 558B6812
P 6050 3750
F 0 "D1" H 6050 3850 50  0000 C CNN
F 1 "LED" H 6050 3650 50  0000 C CNN
F 2 "~" H 6050 3750 60  0000 C CNN
F 3 "~" H 6050 3750 60  0000 C CNN
	1    6050 3750
	0    1    1    0   
$EndComp
$Comp
L R R10
U 1 1 558B68B0
P 6050 4300
F 0 "R10" V 6130 4300 40  0000 C CNN
F 1 "R" V 6057 4301 40  0000 C CNN
F 2 "~" V 5980 4300 30  0000 C CNN
F 3 "~" H 6050 4300 30  0000 C CNN
	1    6050 4300
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR07
U 1 1 558B694A
P 6050 3450
F 0 "#PWR07" H 6050 3550 30  0001 C CNN
F 1 "VCC" H 6050 3550 30  0000 C CNN
F 2 "" H 6050 3450 60  0000 C CNN
F 3 "" H 6050 3450 60  0000 C CNN
	1    6050 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 4250 3450 4250
Wire Wire Line
	5000 4100 5000 4250
Wire Wire Line
	5900 4100 5000 4100
Wire Wire Line
	5900 4600 5900 4100
Wire Wire Line
	6050 4600 5900 4600
Wire Wire Line
	6050 4550 6050 4600
Wire Wire Line
	6050 3450 6050 3550
Wire Wire Line
	6050 3950 6050 4050
Wire Wire Line
	4900 4400 5100 4400
Wire Wire Line
	4900 4450 4900 4400
Wire Wire Line
	3450 4450 4900 4450
Wire Wire Line
	7700 2700 7950 2700
Wire Wire Line
	7700 2500 7950 2500
Wire Wire Line
	3850 6150 3450 6150
Wire Wire Line
	3800 5650 4300 5650
Wire Wire Line
	3800 5600 3800 5650
Wire Wire Line
	3450 5850 4300 5850
Wire Wire Line
	7700 2900 7950 2900
Wire Wire Line
	3550 6350 3450 6350
Wire Wire Line
	3550 3650 3550 6350
Wire Wire Line
	5100 3650 3550 3650
Wire Wire Line
	5100 2850 5100 3650
Wire Wire Line
	5650 2850 5100 2850
Wire Wire Line
	4800 2400 4800 3350
Wire Wire Line
	5650 2400 4800 2400
Wire Wire Line
	5000 2700 5650 2700
Wire Wire Line
	5000 3550 5000 2700
Wire Wire Line
	4900 2550 5650 2550
Wire Wire Line
	4900 3450 4900 2550
Wire Wire Line
	5200 3000 5650 3000
Wire Wire Line
	5200 3750 5200 3000
Wire Wire Line
	3450 2900 3850 2900
Wire Wire Line
	3850 2700 3850 2750
Wire Wire Line
	3450 2700 3850 2700
Wire Wire Line
	3850 2500 3450 2500
Wire Wire Line
	3850 2300 3850 2500
Wire Wire Line
	3450 2300 3850 2300
Wire Wire Line
	3450 4550 5100 4550
Wire Wire Line
	3450 4350 4100 4350
Wire Wire Line
	3450 4150 4150 4150
Wire Wire Line
	3650 6250 3450 6250
Wire Wire Line
	3650 3350 3650 6250
Wire Wire Line
	4800 3350 3650 3350
Wire Wire Line
	3850 3550 3850 6150
Wire Wire Line
	3850 3550 5000 3550
Wire Wire Line
	3700 3450 4900 3450
Wire Wire Line
	3700 6050 3700 3450
Wire Wire Line
	3450 6050 3700 6050
Connection ~ 3600 5600
Wire Wire Line
	3600 5400 3600 5600
Wire Wire Line
	3750 5400 3600 5400
Wire Wire Line
	3750 3750 3750 5400
Wire Wire Line
	3750 3750 5200 3750
Wire Wire Line
	3450 5000 4300 5000
Wire Wire Line
	7200 6150 7200 6300
Wire Wire Line
	7800 5350 7800 5500
Wire Wire Line
	7800 6000 7800 6150
Wire Wire Line
	7800 6150 8000 6150
Wire Wire Line
	3450 5600 3800 5600
Wire Wire Line
	1550 6450 1550 6600
Wire Wire Line
	1450 6350 1450 6600
Wire Wire Line
	1550 6350 1450 6350
Wire Wire Line
	1550 4050 1550 4150
$Sheet
S 8200 4200 1150 650 
U 558B748D
F0 "Power Module" 50
F1 "power.sch" 50
$EndSheet
$Comp
L ATMEGA328-P IC1
U 1 1 558A4C11
P 2450 5250
F 0 "IC1" H 1700 6500 40  0000 L BNN
F 1 "ATMEGA328-P" H 2850 3850 40  0000 L BNN
F 2 "DIL28" H 2450 5250 30  0000 C CIN
F 3 "" H 2450 5250 60  0000 C CNN
	1    2450 5250
	1    0    0    -1  
$EndComp
$Comp
L CRYSTAL X1
U 1 1 558AB92D
P 6200 5550
F 0 "X1" H 6200 5700 60  0000 C CNN
F 1 "CRYSTAL" H 6200 5400 60  0000 C CNN
F 2 "~" H 6200 5550 60  0000 C CNN
F 3 "~" H 6200 5550 60  0000 C CNN
	1    6200 5550
	0    -1   -1   0   
$EndComp
$Comp
L C C2
U 1 1 558AB96F
P 6600 5600
F 0 "C2" H 6600 5700 40  0000 L CNN
F 1 "C" H 6606 5515 40  0000 L CNN
F 2 "~" H 6638 5450 30  0000 C CNN
F 3 "~" H 6600 5600 60  0000 C CNN
	1    6600 5600
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 558AB986
P 5800 5600
F 0 "C1" H 5800 5700 40  0000 L CNN
F 1 "C" H 5806 5515 40  0000 L CNN
F 2 "~" H 5838 5450 30  0000 C CNN
F 3 "~" H 5800 5600 60  0000 C CNN
	1    5800 5600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 5400 5800 5150
Wire Wire Line
	5800 5150 6200 5150
Wire Wire Line
	6200 5150 6200 5250
Wire Wire Line
	6600 5800 6600 6000
Wire Wire Line
	6600 6000 6200 6000
Wire Wire Line
	6200 6000 6200 5850
$Comp
L GND #PWR08
U 1 1 558ABC43
P 5800 5950
F 0 "#PWR08" H 5800 5950 30  0001 C CNN
F 1 "GND" H 5800 5880 30  0001 C CNN
F 2 "" H 5800 5950 60  0000 C CNN
F 3 "" H 5800 5950 60  0000 C CNN
	1    5800 5950
	-1   0    0    -1  
$EndComp
$Comp
L GND #PWR09
U 1 1 558ABC83
P 6850 5350
F 0 "#PWR09" H 6850 5350 30  0001 C CNN
F 1 "GND" H 6850 5280 30  0001 C CNN
F 2 "" H 6850 5350 60  0000 C CNN
F 3 "" H 6850 5350 60  0000 C CNN
	1    6850 5350
	-1   0    0    -1  
$EndComp
Wire Wire Line
	5800 5800 5800 5950
Wire Wire Line
	6600 5400 6600 5250
Wire Wire Line
	6600 5250 6850 5250
Wire Wire Line
	6850 5250 6850 5350
Text Label 5950 5150 0    40   ~ 0
XTAL1
Text Label 6350 6000 0    40   ~ 0
XTAL2
Wire Wire Line
	3450 4750 4100 4750
Wire Wire Line
	3450 4850 4100 4850
Text Label 3950 4750 0    40   ~ 0
XTAL1
Text Label 3950 4850 0    40   ~ 0
XTAL2
$EndSCHEMATC
