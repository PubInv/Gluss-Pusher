# Goal: A working controllable acutator

My general hypothesis is that with a non-polarized core I should be able to make an Arduino controllable actuator.
It is not entirely obvious that I can do this without some control circuitry to determin position, but presumably if
I substitute human control for this, I can make it work.

For example, at the end of this sprint I would like a system consisting of:
* An Actuator,
* An External Power source,
* An Arduino, and
* a couple of buttons,
which allows the actuator to move in two directions based on pushing the buttons.

June 1st,2015

I have now played with the Seeedstudio v2 Motor shield.  The fact that it is limited to 2 amps seems a hindrance, 
although the fact that it allows polar control of two motors seems pretty useful.

However, I am going back to using my 1/2" Neodymium magnets and my large tube, at least until the acrylic gets in.

Using the arduino, I can now pop the carrier back and forth, though with only one coil I can't control it.  The 2 amp limit is no problem with the bigger magnets.  Occasionally the carrier gets stuck in one place, and slight touch moves it.  I hope to improve that.  Unfortunately, I have to take my machine apart in order to do that.

June 2nd, 2015

I now tried using the second "kicker" coil.  It DOES indeed seem to allow me to control the direction of motion.  Using this coil turned on for 100 ms before and after firing the main coil, I can make it go completely to the left or completely to he right (by switching the terminals on the second coil.)  It is not 100% reliable, but it does work. 

I am now tempted to make the acrylic piston, in order to avoid the slight friction inherent in my taped-up magnet carrier.

NOTE: By reducing the duty cycle on the second coil (to 20% in the case above), I greatly abate the problem of overheating of that coil (I used very thin wire on that coil.)

NOTE: I would now like to use a button press to initiate left and right action. I bought a kit that has two buttons (tiny, and weird), which I have not used.  I will have to put them on a breadboard, but let me use that.


