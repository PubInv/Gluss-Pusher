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




