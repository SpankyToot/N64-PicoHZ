# N64-PicoHZ

Switchless overclocking mod for N64 using RP2040Zero

The N64 uses a bus speed multiplier to dictate the CPU's clock frequency.
This multiplier can be controlled by pulling pins 112 \& 116 on the CPU high/low in different combinations.
The stock multiplier of the N64 is 1.5x, this modchip allows the use of 2.0x multiplier to improve performance in some titles, and break others.


## List of required components.

RP2040 Zero.
2x 100ohm Resistors.
1x 5MM Dual colour LED, Common cathode.
Wire of your choice.


## Pinout

Pico     N64      			  LED
2        CPU Pin 112
3        CPU Pin 116
4                				  Anode 1 - With inline resistor
5                				  Anode 2 - With inline resistor
26       PIF Pin 17
3.3V     Any 3.3V source
GND      Any GND source
         LED GND			    Cathode


## Installation instructions.

1: Lift legs CPU legs for pin 112 and 116.
2: Remove stock LED and clean out the GND through hole.
3: Install new led with cathode in GND through hole
4: Place the pico where it wont interfere with the heatsink/shield.
5: Install 100ohm resistors to both Pico points 4 and 5 for the LED Anodes.
6: Connect all points according to pinout above.


## Use

Console will always boot to stock 1.5x multiplier.
Pressing reset will reboot the console as normal.
Holding reset for 0.8sec or more will reboot the console and enable/disable the overclock and change the indicator led to match.
