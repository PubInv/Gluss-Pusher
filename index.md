---
layout: default
title: Gluss Pusher Main Page
---


# Gluss Pusher

## Mission

Create linear actuators at very low cost so that they can be used in quantities of hundreds in support of [The Gluss Project](http://pubinv.github.io/gluss/).

## Status

Work on this project has primarily shifted to work on The Gluss Project itself, due to the successful use of the Firgelli commericial linear actuators. Development of cheaper actuators remains a valuable research goal, and we may return to this project in the future.


## Motivation

It is perhpas easisest to understand why we need the Gluss Pusher project to make cheaper gluss by watching a demo from the The Gluss Project itself:

 <iframe width="560" height="315" src="https://www.youtube.com/embed/1T8XSMhwKUE" frameborder="0" allowfullscreen></iframe>

A short video of our progress on this specific project can be seen here:

 <iframe width="560" height="315" src="https://www.youtube.com/watch?v=o0czhRU1vQM&feature=youtu.be&t=5s" frameborder="0" allowfullscreen></iframe>

based on the idea of making a simple linear tubular synchronous motor.

If you watch the other vidoes out our <a href="https://www.youtube.com/watch?v=1T8XSMhwKUE">YouTube Channel</a>, you will understand that our goal is to build gluss our of hundreds of actuators. Current actuators cost approximately $80. In order to make building a 100-actuator gluss practical for most amateur researchers we need to decrease the cost by an order of magnitude.



## Goals and Trade-offs

We could research a number of interesting ideas:
* Try to create a [linear induction motor](https://en.wikipedia.org/wiki/Linear_induction_motor) in order to decrease cost. This is not normally done on a small scale, but there is not reason we should not try.
* Attempt to build 3D-printable motors so that we could print a large number in place (that is, in a gluss-style configuration) with very low assembly labor.
* Take the existing gluss design which uses slow, powerful, screw-type actuators and replace them with fast, linear motor type actuators.
* Attempt to build very small linear motors.

## An Initial Design - Gluss Pusher v0.1

The initial design is a tubular permanent magnet motor that comes close to this. I think of this as the 0.1 version of a certain approach to building a cheap gluss pusher.

My basic approach was to create what would technically be called a "tubular permanent magnet motor" using Neodymium magnets. These are 1/2" long magnets, packed into an acrylic rod with 1/2" spacers to create "comb" of opposite magnet poles axially.  (The system is axially symmetric.) Then a simple coil wrapped on a spool around the pusher rod allows you to apply force to the rod by apply a current to the coil.

If you start a random position and a apply a voltage to a coil, it pops to a stable position on the "comb"---the reverse polairity of a position---and stays there.  This system in fact has a dead point.  If you reverse the polarity of the voltage, the coil is unstable at its present position, but may not move until pushed in one direction a little bit.  By adding a second coil that is at a half period (that is 1.5" or 2.5" etc.) from the first we can always initiate motion.

With an appropriate bit of Arduino coding, we have created a linear "stepper" motor that moves 1/2" at at time.

## The Story

Ever since the mid '80s when I learned of the [octet truss](https://www.google.com/patents/US2986241?dq=octet+truss+Buckminster+Fuller&hl=en&sa=X&ved=0CB0Q6AEwAGoVChMIpI3Py6fZxgIVVxmSCh2c9QzE) while reading about Buckminster Fuller I have dreamed about replacing each strut in the octet truss with a component that could change its length. 

<img src="https://patentimages.storage.googleapis.com/pages/US2986241-2.png" alt="Octet Truss from Bucky's 1961 patent" style="width:30%">

 Instead of being a rigid space frame, it would become a shape-changing robot. Imagine if the space frame pictured above could curl and warp. Imagine a corner elongate to become a pseudopod or a tentacle. This would be a truss that could slowly ooze like a slug---"a gluss".  Rather than attempt to biomimic bipedal humanoids, we should mimic the simplest of life forms: molluscs, worms, and amoebae. The notion of a building a robot that uses wheels should be right out.

<img src="https://cloud.githubusercontent.com/assets/5296671/7195220/c062264c-e481-11e4-9de6-ec7c8a77502d.png" alt="2 Dimensional Gluss Reaching Over a Person" >

Many others have proposed building robots out of many interchangable components, even [tensegrity based robots](https://www.youtube.com/watch?v=wR0AlIwEgSE), another Bucky-inspired approach. However, these systems been addressed by Universities and Research labs. I believe the time has come to apply the tremdendous energy and creativity of Maker movement to the construction of glusses.

For this to be practical, we need to be able to obtian a single strust component, which I will call a gluss pusher, for about $20 each, so that 10 or 100 can be obtained for $200 or $2000. We also need to be able to control them widely available micro controllers and power them with cheap, safe levels of power.

A cheap gluss pusher offers many design challenges and each challeng overcome will offer new benefits to humanity in some way.  To paraphrase Freeman Dyson, the problem is infinite in all directions. We can try to make them big, small, precise, strong, sensitive, and rugged. We need a gluss big engouh to span a river, and small enough to slither up a vein to a blood clot or tumor.





