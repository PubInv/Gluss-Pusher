# Linear-Actuator

Attempt to create simple, cheap linear actuator for giant robots and other tasks

This Repo is to hold research related to the invention of a new kind of linear actuator.

As part of the PIFAH project, this is completely open-source (both hardware and software) and everything be released either
under Creative Commons Share Alike, or the GPL.

As explained in the PIFAH/PIFAH repository, we welcome your contributions and participations.  Contact me to see how to
participate.

* * *

I have a prototype that does some simple stuff---I can move magnets around in various linear stable positions.
I would not say it works very well yet.  I will try to publish photos and other work more fully tomorrow.

My mind is currently in a maelstrom with several half-baked ideas.

One idea is the possibility of building multipolar magnetic devices (by which I mean they rest in several distinct 
stable states) which never "pinch" -- that is, never have magnets attract each other to the point of contact.  Another 
way of saying that is to develop mechanism that are like unto magnetic bearings---they operate on proximity but 
not contact, in order to provide robustness, low cost, and low maintenance.



* * *

This seems particularly relevant:

http://en.wikipedia.org/wiki/Halbach_array

I don't understand why there isn't a good online simulator---perhaps I should write one.  This looks like it might work:

http://www.mare.ee/indrek/ephi/

But does not seem to be oriented toward permanent magnets.

* * *

Basically I reinvented this:

http://en.wikipedia.org/wiki/Tubular_linear_motor

And so now I must ask the question: Why can't we get a cheap one of these for hobbyist?

This firm seems to make great ones, but doesn't list prices, so one can assume they are expensive:

http://www.linmot.com/fileadmin//user_upload/Downloads/databooks/0185-1100-E_1V0_Product_Overview.pdf

* * *

I apologize for not putting all my notes up immediately---things change rather rapidly. (I have now put photos and notes in the Sprint0.md file.

Basically I believe there is room for a $10 "coil gun" type actuator that I don't believe anyone has built yet.  It
will not be a forceful as a linear motor, nor as precise, and so in a way it will be a "poor" actuator.  I believe 
technically it will be a "mechanism" rather than a "machine" --- a mechanism positions, but a machine applies force.
Furtermore, it will offer relatively poor control of the positioning.  Basically it will jerk itself into position, and then latch itself there with no power.

Imagine the following application: An earthquake has knocked down a bridge.  We need to span the river to allow trucks to cross.  In this application we don't actually have to LIFT anything except ourselves---IF we can then lock ourselves into place and our locked strength is sufficient to support the weight of a truck.

So this is a system designed to be both cheap and also not a "motor" in the sense that it is not expected to move much---it is expected to move into a shape and stay there for a while before moving again.

I think at least this is an unexplored point in the design spectrum.  Certainly, it would be a lot more fun to 
build a giant robot out of 100 $10 mechansims than 100 $100 machines.  Before you spent the $10K on the machines you 
would probably want to prove that you could coordinate motion for the $1000 inexpensive solution anyway.


* * *

Note that a major problem in what I am proposing, the "coil gun" approach, and try to stay under $10, is that it requires precise control, and yet most sensors cost more than $10!

But, we have a highly, highly constrained linear geometry.  it seems to me that we can likely put an LED and simple
photocell resistor at one end of the pipe and find a way to calibrate it to position.  As the plunger moves down the stator, (I need better terms---as the piston moves down the cylinder?) it moves away from the LED, and more of the light that is reflected into the photocell should be absorbed by the walls.  This may not be precise, but hopefully it will be an elegant solution.

