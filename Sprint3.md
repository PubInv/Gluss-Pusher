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



