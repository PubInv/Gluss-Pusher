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

The mechanical "stickiness" of the system is very annoying.  It seems to have developed after I epoxyed the Stator tube in place.  This makes it significantly hard to test everything.  If I increase the voltage I can get past the sticking points, but that is a terrible way to deal with this problem.  Unfortunately I have to figure out a better way to make a bearing.  I think linear bearing would be great, but they are normally made of steel, which interacts very badly with my magnet-filled pushrod.

I want a simple solution that will let me test this, rather than having to "invent" a solution.

Possibly I need to start using bearing like these on the ends: http://www.igus.com/iPro/iPro_02_1008_0000_USen.htm?c=US&l=en

But that will not solve the problem of my pushod not going through the hole, which must be tight.

