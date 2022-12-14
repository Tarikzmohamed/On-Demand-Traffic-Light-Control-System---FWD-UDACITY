# On-Demand-Traffic-Light-Control-System---FWD-UDACITY
Project_2 System Design and Description is illustrated in detail in FWD_TRAFFIC_LIGHT_CONTROL_PROJECT.pdf
located in Project_2 System Design and Description folder

System Description:
This project is an on-demand traffic lights system. It consists of three LEDs for the cars, three LEDs for
the pedestrians and a button for pedestrians which allows them to pass the road.
The system has two modes. The first mode, the system operates under normal conditions where there are
no pedestrian Request Pressed and the traffic lights cycles through green, yellow and red then yellow
again, where the yellow LED blinks. The second mode, the system operates when a pedestrian presses a
button which allows them to pass the road depending on the stage at which the first mode was at. Then,
after the second mode is executed, the system returns back to the first mode.

System Design
2.1 Hardware requirements:
The system consists of:
1. AVR ATmega32 (1MHz) microcontroller
2. One push button connected to INT0 pin for pedestrian
3. Three LEDs for cars - Green, Yellow, and Red, connected on port A, pins 0, 1, and 2
4. Three LEDs for pedestrians - Green, Yellow, and Red, connected on port B, pins 0, 1, and 2
5. One LED for Test Purpose – Orange Connected on Port D Pin 7.
6. 7 x 300 Ohm resistors
7. 1 x 10K Ohm resistor

Software Operation requirements:
In normal mode:
1. Cars' LEDs will be changed every five seconds starting from Green then yellow then red then yellow
then Green.
2. The Yellow LED will blink for five seconds before moving to Green or Red LEDs.
In pedestrian mode:
1. Change from normal mode to pedestrian mode when the pedestrian button is pressed.
2. If pressed when the cars' Red LED is on, the pedestrian's Green LED and the cars' Red LEDs will be on
for five seconds, this means that pedestrians can cross the street while the pedestrian's Green LED is on.
3. If pressed when the cars' Green LED is on or the cars' Yellow LED is blinking, the pedestrian Red LED
will be on then both Yellow LEDs start to blink for five seconds, then the cars' Red LED and pedestrian
Green LEDs are on for five seconds, this means that pedestrian must wait until the Green LED is on.
4. At the end of the two states, the cars' Red LED will be off and both Yellow LEDs start blinking for 5
seconds and the pedestrian's Green LED is still on.
5. After the five seconds the pedestrian Green LED will be off and both the pedestrian Red LED and the
cars' Green LED will be on.
6. Traffic lights signals are going to the normal mode again.

System Drivers
The system has five drivers. LED Driver, Button Driver, DIO Driver , Timer Driver, and Interrupt Driver
or API. The DIO Driver and Timer Driver are located at the ECUAL Layer as well as Interrupt Driver.
The LED Driver and Button Driver are located at the MCAL Layer. At the Utilities layer there are three
APIs, bit manipulation, MC_REGISTERS and typedef. At the Application Layer there is a driver that
controls the logic of the system.
![System flow chart](https://user-images.githubusercontent.com/113884712/207631629-75c05f17-aa06-4d50-a0f1-3a612f2e780a.png)

System Constrains
This system has a constrain at which if the pedestrian button is pressed, no further action is taken if the
button was pressed again. The button needs to only have a short press not a long press. Pressing Button
Long will not be detected because Button and Interrupt work on rising Edge only, so it will not be
Detected and will only detected as short Press.
Timing constraints: each mode remains only 5 seconds
Pedestrians have the priority over the cars
Pressing Button before Normal Mode start or Pressing Multiple will be ignored.
