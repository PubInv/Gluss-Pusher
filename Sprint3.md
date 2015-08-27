Monday, August 24, 2015

# Sprint 3

## Status

I have not been maintaining my process discipline very well.  A lot has happened since my Sprint 2.

* I did construct a controllable Gluss Pusher.  You can see it in the video that I posted.
* At considerable effort, I made a 10-minute introductory [video](https://youtu.be/cpzPVwBoE_4) to the project.
* I have created an attractive 3D-printed stator. After much trial and error I am very happy with this. The new stator
and the new carbon-fiber pushrod work very effectively.  I will post a video of this very soon.

## Goals

* Document my 3D-printable design to the level of easy reproducibility
* Move closer to being able to create a 2D Planer Robot with two Gluss Pushers

## Stories

* Publish Fusion 360 designs - done
* Publish STL file at Thing-i-verse - done
* Measure voltages produced by motion against coil in order to see if we can build closed-loop detection of our position.
* Switch to using the motor controller to see if we can get micro-step control.
* Cut Acrylic tube in order to have actuator stability.
* Consider a "shaking" of one coil to see if we can detect other coils.
* Consider possibility of building coil rings into the stator further down in order to provide true positional control.
* Compare possiblity of using coil ring with Hall Effect sensors.

## Log

Experiment #1: Does moving the pushrod by hand produce a measure voltage?

Monday 12:04 : it is seems very clear that we should be able to use the non-active coil to verify each move. In my new stator design, simple movement by hand is easily generating 2V! (Actually, we are probably pay that cost---if we could pump that back into our system, we would be more efficient---but that is a level of control beyond the immdediate need! 

Experiment #2: If we program the Arduino to "Shake" the pushrod without making a move, can we see see the result in the other coil in a way that lets us tell where we are?

Yes, afer doing millisecond sampling it is very clear that we can read the motion of the coil.

DANGER: A sharp motion could produce an overvoltage (more than 5V) and fry the Arduino.
PROBLEM: I need some sort of circuit for sensing negative voltage as well.

However, given the fact that I can apparently sample very quickly and compute all of this, I think we should be able to write a robust "did I move" function or even "apply energy until I move."

Note that we need to protect the system from overvoltage and read negative voltage.  This looks particularly valuable:

http://www.symres.com/files/scalebias.pdf

Tuesday 11:34

Last night I tried to get build a voltage divider to sample the voltage in the non-active coil and it failed miserably and mysteriously.  I suspect that I had something miswired.

I am not sure that reading the inactive coil is in fact the best way to do positioning.  It will never allow you to sense absolute position, for example.  However, I want to debug this to understand what I did wrong.  I supsect that some sort of LED-based direct sensing of rod position will be far better.

It is exciting that we are now addressing the question of reliable motion rather than simply motion itself.

Wednesday Night

Curse me for a fool.  I now know that I designed the coils too far apart in the 3D model, which is why it is uneven, and might cause all manner of other problems.  Also due to weird constraints I have to completely redo it.  I will do that tomorrow to be ready for the Saturday morning trip to Techshop.

However, more importantly is to work on the photo-cell detection idea.  That is what I will work on tomorrow.

Thursday

I've been experimenting with a closed loop solution.  Basically I plan to shine an LED into the stator tube and detect the light level.  My initial experiments suggest that  this will work. I would rather use a white-light LED. However, using a green LED, I can measure resistance values on the scale of 100K ohms, varying pretty smoothly as I move the pushod.  So today I am going to set up an experiment to attempt to do this.

Following my ARDX, I am going to make a voltage divider and try to read this with an Arduino.

3:00 pm

I believe I have had a great success.  I bought a 5mm 7000mcd brightness white LED from RadioShack.  Placing this at 5V from the Arduino with a 546 Ohm resistor. I soldered this onto a wire.  I took a standard photocell (the one that comes with the ARDX, and, as the ARDX suggests, placed it as the lower resistor in a voltage divider.  The 5V from the Arduino is applied to the voltage divider, that then Vout read with a multimeter.  It then very clearly varies between about 2.8 and about 4.5 V as the pushrod is inserted and withdrawn from the tube.

Although I have not yet digitized it with the Arduino, this strongly suggests that at low price ($2 at most) we can read the position of the pushrod.

This technique is probably unreliable in the sense that it requies calibration.  However, are strategy is to use "smarts" in the form of the microcontoller and to avoid extra components in the BOM.  And, our system is already a stepper motor---it should be very easy to auto-calibrate it!  (This will be a teensy programming challenge.)

I wonder if this worth making a video about?

(Actually I just discovered the $20 [motorized potentiometer](https://www.sparkfun.com/products/10976?gclid=Cj0KEQjw6vquBRCow62uo-_J_YYBEiQAMO6HijfyBuLo_aqcKEksxdn2kE-gfHNRWyhovlxQJRjpF4AaAvG_8P8HAQ) at Sparkfun which potentially makes this whole project obsolete. I will have to order some of these to test with. Sigh.)

Maybe I should document the light-based linear position system completely separately.




