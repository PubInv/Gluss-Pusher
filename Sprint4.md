# Sprint 4

## Theme

Trying to get motion reliable with new stators.

## Stories

* Clean and wind the newly 3D-printed stators and see if motion is reliable.
* Use larger potentiomter somehow to make an easier to control system.
* Test the position sensing with the newly created white pushord caps
* Order some bigger (and more) carbon fiber tubes from RC foam.
* If successful, make a new video documentin everything
* If successful, publish new designs at Thingiverse

## log

Tuesday, 2:37 pm

I have wound the new stators.  They work fine.  Positiong sensing also works great!

However, I have two very annoying problems that are stymiing further process:

My Arduino (or relay shield) seems to lock up.  Often the Arduino is still listening to the serial bus but a relay is stuck in the "on" position, which means that we are heating up one of the coils.  Possibly this melted my stator a little, which is why I now have mechanical problems.

After going for a run, I am now convinced that I need to redesign the Stator YET AGAIN. I don't know what that means...I am in favor of iterative development, but perhaps more Big Design Up Front would have been better.

Basically, I think it is time:

* To put the two coils closer together, in order to minimize the distance that we have to touch the push rod.
* Remove the colimating part of the stator for the pushrod, so that as much as possilbe the pushrod is supported by the rear end cap and a single point (unfortunately about an 1.5 inches long) at the coils.
* Make the Stator reach back as far as possible to have a ring to hold the stator tube in position.  This should be done with a truss-like structure to make it stiff and still get a reasonable print time.

I am close with the calibration code, I hate to take the time to redesign and re-print the stator. However, I don't have any good way of disassembling the current pusher to solve the stickiness problem.

I could try going up to 24V in the short term, I suppose.

I guess I really need to make a short video of this.

The mechanical "stickiness" of the system is very annoying.  It seems to have developed after I epoxyed the Stator tube in place.  This makes it significantly hard to test everything.  If I increase the voltage I can get past the sticking points, but that is a terrible way to deal with this problem.  Unfortunately I have to figure out a better way to make a bearing.  I think linear bearing would be great, but they are normally made of steel, which interacts very badly with my magnet-filled pushrod.

I want a simple solution that will let me test this, rather than having to "invent" a solution.

Possibly I need to start using bearing like these on the ends: http://www.igus.com/iPro/iPro_02_1008_0000_USen.htm?c=US&l=en

But that will not solve the problem of my pushod not going through the hole, which must be tight.

### Wednesday Morning

Yesterday I took the laser cutter class at tech shop.  I am tempted to redesign the stator yet again.  However, I think it is more important that I make a video showing my current work, by work or by crook, first.

The redesign needs to focus on several points:

* I don't want to have to epoxy things, as this makes it impossible to disassemble.
* I want to start designing a way to put the Arduino, and possibly the breadboard, onto the system.
* I need to design the end cap to held the electronics in a reasonable way.

### Wednesday Afternoon, 1:00 pm

Okay, video made. 

I think before I do the redesign, I really need to use the new positioning system to prove its value.  There are several approaches (or at least experiments):

* Experiment: Kick a coil and simply start reading the voltage value, and see what happens if we turn the coil off right when we reach the correct position.  I expect it will overshoot significantly.
* Experiment: Write a function that reads the position, and turns on "Hold Position" as we deviate from that position.
* Experiment: Change the "P" function (absolute positioning) to read the arbitraty position and try to move to that position, whatever happens!

## Wednesday Afternoon, about tea-time.

Great progress.  I fixed a stupid software bug that was adding confusion.  I am now reliably (unless I get stuck!) moving to various positions. I have written a "smart hold" function---that is, the system will monitor its position, and if you pull the pushrod out of position correctly attempts to restore it!  That is a very enabling feature, partially making up for the fact that we don't have a physcial locking mode.

It is now the case that is is a COMBINED position sensor and linear actuator.

Still plagued by stickiness in fully retracted and extended positions.  Also, I am generally operating at 18V, which is very unfortunate.

I now believe there are three tasks to be done:

* I want to make the motion between multiple stops smooth.  That is, now that we know (approximately) when we can cross a threshold, there is no reason to move in short stops. So we should be be able to have fast, smooth motion. In a deluxe mode, we would actually model the velocity of the pushrod and build a model of forces for acceleration and deceleration!
* We need a systematic study of the best way to generate the MMF. I know a lot about coils but there remain some questions, some of which need to be verified experimentally.  At present, the system is of marginal usefulness. I'm estimating it exerts about 12 ounces of force.  If we can get that up to 5 pounds we will have a much more reasonable system. Of course, that is possible with more coils and more power (or even more magents) but those increase our costs.
* I do believe we need a better physical design.  I don't want a system that relies on epoxying the stator tube in place, as I do now.

### Thursday morning

I got the "hold position" function working.  This is actually TREMENDOUS progress.  Unfortunately I seem to be sick. But nonetheless yesterday, although exhausting, I got an enormous amount of stuff done. 





