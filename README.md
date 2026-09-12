# N64-PicoHZ


### This mod could cause damage to your N64 either from improper install or simply the additional heat. I take no responsibility, install at your own risk.

Switchless overclocking mod for N64 using RP2040Zero.

The N64 uses a bus speed multiplier to dictate the CPU's clock frequency.

This multiplier can be controlled by setting pins 112 & 116 on the CPU high/low in different combinations.

The stock multiplier of the N64 is 1.5x, this modchip allows for the additional use of a 2.0x multiplier to improve performance in some titles, and break others.

Bus speed is 62.5mhz, Stock clock is with a 1.5x multiplier giving 93.75mhz clock speed.

The overclock sets the cpu bus multiplier to 2.0x, boosting the cpu clock frequency to 125mhz.

| CPU112 | CPU116 | Multiplier | Clock |
| --- | --- | --- | --- |
| Low | Low | 1.0x | 62.5mhz |
| High | Low | 1.5x Stock | 93.75mhz |
| Low | High | 2.0x | 125mhz |
| High | High | 3.0x | 187.5mhz |



## List of required components.


RP2040 Zero.

2x 100ohm Resistors.

1x 5MM Dual colour LED, Common cathode.

Wire of your choice.




## Pinout


| Pico | N64 | LED |
| --- | --- | --- |
| 2 | CPU Pin 112 | |
| 3 | CPU Pin 116 | |
| 4 | | Anode 1 - With inline resistor |
| 5 | | Anode 2 - With inline resistor |
| 26 | PIF Pin 27 | |
| 3.3V | Any Switched 3.3V | |
| GND | Any GND source | |
| | LED GND | Cathode |


## Installation instructions.


1: Lift legs CPU legs for pin 112 and 116.

![Photo with indicated cpu legs](Install%20Images/CPU%20Pins.jpg)

2: Remove stock LED and clean out the GND through hole.

![photo with indicated LED GND](Install%20Images/LED%20GND.jpg)

3: Install new led with cathode in GND through hole

4: Place the pico where it wont interfere with the heatsink/shield.

5: Install 100ohm resistors to both Pico points 4 and 5 for the LED Anodes.

6: Connect all points according to pinout above.

![Photo with indicated PIF pin 27](Install%20Images/PIF.jpg)
![illustrated diagram with included pictures of N64 components.](Install%20Images/Diagram.jpg)


## Use

Console will always boot to stock 1.5x multiplier.

Pressing reset will reboot the console as normal.

Holding reset for 0.8sec or more will reboot the console and enable/disable the overclock and change the indicator led to match.


## Tested Revisions  
| Revision | Working version |
| --- | --- |
| NUS-CPU(P)-01 | V1.4 |
| NUS-CPU(P)-03-1 | V1.4 |
| NUS-CPU-04 | Pending |


## Future plans
None?

No plan to add 3.0 multiplier support, never had a N64 that could handle it without immediately crashing.

Probably look into long term heat management for longer gaming sessions but i cant hold the controller for more than 2 hours as it is. But this will be a different project.


## Like the project and its low low price of free?  
Consider giving me a tip to help with my tooling upgrades or come watch me stream future mods and repairs!  
[TIPS!](https://streamlabs.com/spankytoot/tip)  
[Twitch](https://www.twitch.tv/spankytoot)  
[Youtube](https://www.youtube.com/@spankytoot)  
