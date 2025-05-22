(kicad_pcb_schematic_data)
EESchema Schematic File Version 4
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Energy Harvester"
Date "2025-05-22"
Rev "1.0"
Comp "IX-DroneShowcase"
Comment1 "Energy harvesting schematic for drone power system"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L device:R R1
U 1 1 5A8C9C89
P 1000 1500
F 0 "R1" H 1000 1400 50  0000 C CNN
F 1 "10k" H 1000 1600 50  0000 C CNN
1    1000 1500
1    0    0    -1  
$EndComp
$Comp
L device:C C1
U 1 1 5A8C9C9A
P 1100 1500
F 0 "C1" H 1100 1400 50  0000 C CNN
F 1 "100uF" H 1100 1600 50  0000 C CNN
1    1100 1500
1    0    0    -1  
$EndComp
$Comp
L device:U1 IC1
U 1 1 5A8C9CA3
P 1050 1300
F 0 "IC1" H 1050 1200 50  0000 C CNN
F 1 "MPPT_Controller" H 1050 1400 50  0000 C CNN
1    1050 1300
1    0    0    -1  
$EndComp
$EndSCHEMATC
