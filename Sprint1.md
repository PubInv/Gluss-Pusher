# Sprint 1

There is a wonderful resource that shows that this is in fact rather complicated: http://coilgun.info/about/home.htm. 
I believe it would take me a week or two to fully understand the mathematics of that very valuable site. MIT has
made a contribution as well: http://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-007-electromagnetic-energy-from-motors-to-lasers-spring-2011/lecture-notes/MIT6_007S11_lec14.pdf
which may be simpler.  I have not yet worked through the math.

Note that this is very colsely related to a coil gun, but of course there I am not interested in making a 


In fact magnetism in general is more difficult to compute than electrical effects.

In Sprint 0, I was able to move Neodymium magnets in a carrier effectively with homemade coils.  However, I could 
not control this.  I have since designed an approach with multiple coils that should allow control.  My goal this 
Sprint is to demonstrate this control ability, possibly beginning control via an Arduino.

### Self-doubt

It is very unclear to me that this is worthwhile.  I measure coolness in "Ellsworth" units, and benefit to the world in
"Bucky"s.  I believe this would be a 3 micro-Ellsworth project and 2-Bucky project if successful.  I think
it will take at least two weeks to demostrate this.  The chance of success is aobut 40%, so I the expected goodenss
is 1.2 micro-Ellsworths and 0.8 micro-Buckys. I am unsure that this is worth my time---that is why I would like
to have others comment on this.  However, I believe it is worth moving forward on.

## Stories

* As a skeptical investigator, I would like to prove that I can move the magnet using a multi-coil system. -- basically done now, with my shabby little three coils.
* As an investigator, I would like to prove that I can coordinate two 25-turn coils to move the 1/8" cylindrical magnets -- basically done, thought my equipment right now is terrible.
* As a robot builder, I would like to be able to control the motion of the piston with an Arduino, in whatever a
limited way that may be.
* As a hobbyist, I would like to know how to build an actuator (without consideration of force), for around $10 that
let's me move something with my Arduino.

## Equipment

I have a Seeedstudio Motor Shield V2. In principle, should should be able to drive two of my coils.  It's a little depressing that it takes that much extra hardware---since I am going to have at least 4 coils!  But I suppose I must try to understand this shield instead of trying to build my own MOSFET control board---something that I have been wanting to do for some time.

Unfortunately, all three of my current Adruino Unos are in use in other demo projects, and I would rather not cannbalize one.  However, I have an Esplora, and I suppose that if I use enough jumper cables I should be able to power it in that way.  I THINK I can use my power supply to provide up to 15V power to the Motor Shield and have it power the Esplora, perhaps --- not sure about that.

Once again, all of this is just showing how much I have to learn --- I barely understand how Arduino shields work.

BTW, I'm pretty sure that we can eventually build a simpler (less expensive) system for controlling the coils.

I need to get some thinner magnet wire, and possibly another Uno.

## Project for Tomorrow

So tomorrow I want to try to use my Motor Shield to control two of my coils independently.  I suppose that I should wire it through my Esplora.







