# Linear-Actuator


### "The purpose fot he Coil Gun Actuator (CGA) is to enable new kinds of modular machines by making components cheap enough for hobbyist to build giant robots."



Attempt to create simple, cheap linear actuator for giant robots and other tasks

This Repo is to hold research related to the invention of a new kind of linear actuator.

As part of the PIFAH project, this is completely open-source (both hardware and software) and everything be released either
under Creative Commons Share Alike, or the GPL.

As explained in the PIFAH/PIFAH repository, we welcome your contributions and participations.  Contact me to see how to
participate.

## Motivation

I would like to build robots based on large numbers of very simple components that can lengthen or shorten themselves.  Buckminster Fuller invented the Octet truss, a beautiful space-filling structure of alternating tetrahedra and octohedra. Or perhaps it would be more accurate to say that the universe invented and Bucky promoted it.

If we imagine a "truss" that acts like a "glass" we get a "gluss" that can move like a "slug".  That is, I want a system that can ooze about like a slug.

Linear actuators are standard components that can be purchased off-the-shelf.  However, they are rather expesnsive, at about $100 a piece. They are also more forceful and more precise that what we need to build an experimental "gluss".  Although it would be wonderful to spend $10K to build a power 100-element gluss, I think it makes more sense to attempt to use simpler components.

I also believe there is value in general for linear actuators in a cheaper, weaker part of the design spectrum.  Such actuators might be called "mechanisms" rather than "machines" in technical parlance. A machine deals with forces, a mechanism is concerned only with positioning.


## Notes

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

I attempted to read this article:

http://eprints.whiterose.ac.uk/852/1/wangjb15.pdf

I'm afraid I don't know enough about magnetism to really follow the equestions.  The purpose of this paper is to provide a model for linear permanent magnet machines.  I think it would be very valuable if you trying to optimize a design, or understand the force/current/voltage relationship. It is hard for me to understand exactly how to use this research.


And so now I must ask the question: Why can't we get a cheap one of these for hobbyist?

This firm seems to make great ones, but doesn't list prices, so one can assume they are expensive:

http://www.linmot.com/fileadmin//user_upload/Downloads/databooks/0185-1100-E_1V0_Product_Overview.pdf

Here is a nice description:

http://machinedesign.com/news/linear-actuators-get-servo-look

So the terms "linear motor", "direct drive actuator", "tubular permantne magnet motor" are all used in this area.  The central rod should probably be called the "thrust rod".


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

* * * 

Sunday, May 31st

I am now using the [SeedStudio Motor Shield v. 2.0](http://www.seeedstudio.com/depot/Motor-Shield-V20-p-1377.html) to apply power to the coil.  This is not particularly interesting, except that it means that I can now control the coils with the Arduino.

I like this shield as a way fo controlling external power.  It is not as well documented as it should be.  It would be nice for someone to create a similar shield with more than 2 channels, or even which allowed multiplexed (non-simultaneous) action.

Note: This particular shield appears to use the external voltage only if the Arduino is not supplied power directly.  I find this weird and unhelpful.  However, doing so, I was able, with some weirdness, to tick-tock my carrier back and forth.  Thus it is in some sense a control, although I must do much more to have a true control of this.  It is also the case that I have some problems:  I need to control 3 coils, not two!  And, secondly, all of this should work better when I get the acrylic rods that I have ordered, which should allow me to make a much better system.

But in a sense this is a breakthrough---I now have an Arduino partially controlling a linear actuator.  So now my purpose must be to obtain full control.

I will attempt to be Agile: I will attempt to make a publishable, open source actuator (however poor it is) at the end of each sprint.

Note: It is possible that with diodes, I could easily multiplex this positive/negative voltage which this shield allows to control four coils especially if we are using an iron core and not a magnet core.  That would allow me to potentially build my initial working prototype.

My basic problem at the moment is how to build a good prototype this sprint.

* * *

July 10, 2015

I put this project down for six weeks because I was working as a consultant and focusing on the [ATX Preemie Warmer](http://pifah.github.io/ATX-Preemie/), including work in two hackathons.

Today, for the first time in six weeks, I have come back to the project, and I am happy to report that with a two-coil solution I now can reliably (almost) move left and right with in 1/2" increments with only 12 V power.

This is not really publication ready---I need to make a breakthrough and explain the control mathematics.  (It is barely worthy of the title mathematics, but it isn't completely trivial.)  This is very exciting.  I need to publish this intermediary result and then figure out what to do next.

Just off the top of my head, there are several directions I go:
* Publish an instructable on how to completely duplicate the work.
* Try to figure out if it is completely trivial or actually interesting.
* Improve the manufacturing/crafting approach.
* Improve the ability to assert position control and handle the problem of when it is off.
* Work on practical solutions.

* * *

Apparently Tensegrity Robots are a thing:

http://creativemachines.cornell.edu/tensegrity




