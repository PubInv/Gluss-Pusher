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

Evening:

I constructed a 10-magnet piston out of acrylic tube.  Unfortunately, it has too much weight and friction, it doesn't slide easily.  I need to both lubricate it better and move to an Acrylic Tube (just a little thinner) and possibly try to improve my coils.  If I could double the number of turns on my coil (which is not trivial), that could really make a big difference.

June 3rd, 2015

Some learnings:

I tried using baby oil as a lubricant for Acrylic-on-PVC.  As far as I can tell, it deosn't help much.  Nor does it make Acrylic-on-Acrylic better. Basically, I need to go to a bearing system of some kind.  This is a huge mechanical complication, though I suppose that I can must do it.

BTW, you can really feel a big difference at 5 amps vs 2 amps.  I suspect 5 amps would overcome a lot of the problems I am having --- but the Motor shield doesn't support that.  So basically I have to either make my own circuit (which is entirely possible, but a cost in time), or possibly by simplying winding a better coil (and taking advantage of a slightly different smaller diameter for my outside pipe to get more windings on there.

Note that at 5 amps my coil gets hot quickly.  The whole idea of this system is to have a low-duty-cycle system, which IS possible with Arduino control, but is hard to do with just my power supply by hand.

And BTW, Acrylic is not a good plastic to use for this kind of work.  It is terribly soft and not very slick.  It looks nice, though.


