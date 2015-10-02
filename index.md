---
layout: default
title: Gluss Pusher Main Page
---

# Gluss Pusher

## Mission

Enable makers to build new kinds of machines and robots form cheap easy-to-control modular linear motors, or pushers.

## Demo

A [short video](https://youtu.be/o0czhRU1vQM?t=5s) shows our current progress.

<iframe width="560" height="315" src="https://www.youtube.com/embed/o0czhRU1vQM" frameborder="0" allowfullscreen></iframe>

A [longer video](https://youtu.be/cpzPVwBoE_4) gives a more complete introduction to the project.

<iframe width="560" height="315" src="https://www.youtube.com/embed/cpzPVwBoE_4" frameborder="0" allowfullscreen></iframe>

A [longish video](https://youtu.be/nshgcpDxygw) explaining an original invention, the "turret joint". 

<iframe width="560" height="315" src="https://www.youtube.com/embed/nshgcpDxygw" frameborder="0" allowfullscreen></iframe>

## The Story

Ever since the mid '80s when I learned of the [octet truss](https://www.google.com/patents/US2986241?dq=octet+truss+Buckminster+Fuller&hl=en&sa=X&ved=0CB0Q6AEwAGoVChMIpI3Py6fZxgIVVxmSCh2c9QzE) while reading about Buckminster Fuller I have dreamed about replacing each strut in the octet truss with a component that could change its length. 

<img src="https://patentimages.storage.googleapis.com/pages/US2986241-2.png" alt="Octet Truss from Bucky's 1961 patent" style="width:50%">

 Instead of being a rigid space frame, it would become a shape-changing robot. Imagine if the space frame pictured above could curl and warp. Imagine a corner elongate to become a pseudopod or a tentacle. This would be a truss that could slowly ooze like a slug---"a gluss".  Rather than attempt to biomimic bipedal humanoids, we should mimic the simplest of life forms: molluscs, worms, and amoebae. The notion of a building a robot that uses wheels should be right out.

<img src="https://cloud.githubusercontent.com/assets/5296671/7195220/c062264c-e481-11e4-9de6-ec7c8a77502d.png" alt="2 Dimensional Gluss Reaching Over a Person" >

Many others have proposed building robots out of many interchangable components, even [tensegrity based robots](https://www.youtube.com/watch?v=wR0AlIwEgSE), another Bucky-inspired approach. However, these systems been addressed by Universities and Research labs. I believe the time has come to apply the tremdendous energy and creativity of Maker movement to the construction of glusses.

For this to be practical, we need to be able to obtian a single strust component, which I will call a gluss pusher, for about $20 each, so that 10 or 100 can be obtained for $200 or $2000. We also need to be able to control them widely available micro controllers and power them with cheap, safe levels of power.

A cheap gluss pusher offers many design challenges and each challeng overcome will offer new benefits to humanity in some way.  To paraphrase Freeman Dyson, the problem is infinite in all directions. We can try to make them big, small, precise, strong, sensitive, and rugged. We need a gluss big engouh to span a river, and small enough to slither up a vein to a blood clot or tumor.


## An Initial Design - Gluss Pusher v0.1

To initiate the project, I am publishing a design for a tubular permanent magnet motor that comes close to this. I think of this as the 0.1 version of a certain approach to building a cheap gluss pusher.

My basic approach was to create what would technically be called a "tubular permanent magnet motor" using Neodymium magnets. These are 1/2" long magnets, packed into an acrylic rod with 1/2" spacers to create "comb" of opposite magnet poles axially.  (The system is axially symmetric.) Then a simple coil wrapped on a spool around the pusher rod allows you to apply force to the rod by apply a current to the coil.

If you start a random position and a apply a voltage to a coil, it pops to a stable position on the "comb"---the reverse polairity of a position---and stays there.  This system in fact has a dead point.  If you reverse the polarity of the voltage, the coil is unstable at its present position, but may not move until pushed in one direction a little bit.  By adding a second coil that is at a half period (that is 1.5" or 2.5" etc.) from the first we can always initiate motion.

With an appropriate bit of Arduino coding, we have created a linear "stepper" motor that moves 1/2" at at time.

## Specific Challenges

We should avoid creating solutions in search of a problem.  But we should also not be afraid to play.  This is a playful project; I don't feel compelled to figure out exactly what the best use of the Gluss Pusher might have.

Nonetheless, here are some ideas:

* Let's build a Gluss that can act as a pedestrian bridge across a road that can be quickly installed.  In Austin, this is needed all the time---we have festivals that bring out ten thousand pedestrians who have to cross a road.  I think something that could fit inside the bed of an F150 pickup truck, unroll itself to form a bridge spanning a good distance with a good height and hold position long enough for "cotter pins" to be stuck into the pushers so they will hold position without power would be very useful.
* A cheap plotter could be made by taking two Gluss Pushers and forming a triangle with a rigid member. This could be hung on a wall with a sheet of paper behind it.  The intersection of the two moving Gluss Pushers could then be controlled to draw/scribe/cut/paint whatever shape you want.  It is easy to see how this idea could be expanded to 3-space to make a 3D printer, and so on.
* Let's build a burrowing robot that is capable of burrowing throught sand and mud, for example at the beach, to take samples of the benthum as a reasearch tool.
* I believe a system of Gluss Pushers could make an excellent Robot Leg.
* Build a machine that you position above ground like a tripod (but wider). From the center of the machine, Gluss Pushers, or some other actuator, comes down and operates on the earth. You can use it to dig a garden or a part of a trench, turn a compost pile, weed a garden (if you program the senors well enough), pull carrots, scour concrete, etc. We could build this out of existing actuators to show it working first with control before attempting to decrease the cost by using our own linear motors.




## Getting Involved

As you can see, the initial design is primitive. You are probably thinking of myriad improvements and possibilities. We need thinkers, artitists, writers, tinkes, electrical engineers, programmerns and other makers that I can't imagine.

The Gluss Pusher project is part of [Public Invention for All Humanity (PIFAH)](https://github.com/PIFAH/PIFAH), and is therefore dedicated to publishing everything as free and open source--both hardware designs and software. PIFAH is dedicated to the benefit of all humanity.

## Current TODO

At present, I believe that we can control the position precisely by controlling the force on the two coils in dynamic balance.  Unfortunately, I do not have a proper servo control that is both sufficiently powerful and which provides analog control.

I have used a SeeedStudio Relay shield to allow greater power to be applied (which has been successful). However, this does not allow analog control---you either turn it on or off.

Furthermore, although I have nice programmable power supply, it is limited to 2 amps, which is not enough in this circumstance to provide the force that I desire.

So my current list of things TODO is:

* Get a power supply that allows me to draw up to 4 amps (approximately 13 V at my current coil resistance.)
* Test my ability to interact through the serial port with the arduino to allow interactive control.
* Add Hall effect sensors to detect when we have failed to move correctly.
* Construct an actuator shaft.
* Write a drive that will tell you position based on the sesnors (through serial port, I suppose.)
* Make a 3-D printer design for the coils and sensors.
* I would like to do better engineering and measure the efficiency of the machine in terms of force in Newtons applied at a given voltage (or wattage.)
* Make a scalable address system that allows us to coordinate several Gluss Pushers jointly.
* I believe that for $450 I could build the earth-moving robot based on Phidgets [components](http://www.phidgets.com/products.php?product_id=3548) which would be very educational.  However, I don't think you could build a 30-component Gluss very effectively with that system.  But perhaps it is a duty to try that first.

All of this is driving toward a single goal: producing a demo and a set of replication instructions that allows others to build Gluss Pushers reliably and at low cost.


## Sprints

We work in an "Agile" fashion. The sprints be found at the [main repo](https://github.com/PIFAH/Gluss-Pusher).