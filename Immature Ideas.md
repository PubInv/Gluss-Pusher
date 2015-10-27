# Idea: Use a Ferrofluid to create a simple actuator

I recenctly purchased and played around a bit with a ferrofluid. Because it is attracted to a magnetism, it seems
likely that if we put ferrofluid in a cylindrical bladder, we could apply a field to draw the fluid into a lump
(perhaps in the middle) thereby shortenining the cylinder.

# Idea: Can we use a simple air-gap filling apporach

I now wonder if we could modify the geometry of a solenoid to make a "long-throw" solenoid.  I believe the
basic prinicple that iron will be pulled in to fill an magnetized air gap could be used.

In this approach, we produce relative long magnets and use a relatively long iron core.  I don't know 
how much force is exerted in this "long model", but if enough is exerted, this could be a very elegant solution.
I think I can test this very quickly with the equipment that I have, though it will be hard to 
quantify---I need to get scientific and skilled at quanitfying these forces.

* * *

After a simple test, this seems not to be very useful.  the force for a piece of iron to be equalized between the two poles of a magnet seems either nonexistent or so low as to not be useful.  I suppose that my intuition was simply wrong about this.

# Idea: Using symmetric coils as both sensing and forced drivers.

It seems to me that if I have a set of symmetric coils arranged on the magnetic comb at something other than the comb periodicity, it should be able to detect where we are without additional sensors by applying slight currents to one comb while listening to voltage change in the other combs.  It would be very elegant in this way if we could determine our physical state.  This is simpler if you imagine a toroidal comb, rather than a linear comb, but the point is perhaps the same.

If you know where you are, you know which coil(s) to drive and which direction to drive them.  As an experiment, we could see if we can listen with an Arduino for slight motion --- even sonic frequency vibrations!

This is very elegant, because you are using more "smarts" --- putting more intelligence into the microcrontroller, without the need for hall-effect sensors (which could be used as well.)

The whole system is also thus becoming more "alive" --- it could tell when it is pushed.  It could even be pushed again something and perhaps determine how yielding it is. It is also inexpensive. Such a system could avoid the need for locking with a solenoid, by replacing it with active locking and active resistance.  This could be an extraordinarily elegant system.

# Idea: Universal rotation system

It would be really lovely if we got the above system working and then builded a true 3-degree of rotational freedom joint using the principle of geodesic dome construction to produce radail "combs" that could interact in the same way.  Imagine an omni-triangulated robot that had true 3-DOF manipulators!  All basically built with nothing but magnets and coils.  The geometric design freedom would be tremendous.

# Idea: (For Demonstration) An winged man costume...

This is sort of a cosplay idea.  Build a chest harness that has a back or chest keel.  Attach wings.  Have the linear actuator drive the wings based on buttons actuated by the hands (or in a harness.)

# Idea: Using Ferrofluid in a tube to extend the reach of the linear motor...

A fundamental problem with my current desigs is that you can only have so many magnets in contact with some many coils.  The higher the number in proximity, the more efficiency you have, but the lower stroke length.  The higher the stroke length, the more magnets or coils are wasted.  This could be changed by some complicated repositioning, but it would seem only at the expense of great complication to the moving parts.

However, what if ferrofluid confined to a tube would allow us to to make a magent of essentially changing length?  Then we could magnetize the thing with a single coil in a static position, but move the end (and the point of greatest flux change) to any position within the tube.

# Idea: use the comb and rotational magnets to produce latches....

Probably these need to latch in both directions to get the wedge effect, but that should be entirely possible.  I believe that by placing extra magnets in the carrier (not the push rod) and simply having them rotate out of the way in the presence of an applied B-field (which is easy to achieve), we should be able to make a physically strong latching system, at the cost of some increased weight in the carrier.  This would make a capactitor based "pump-and-rest" system more reasonable, and avoid us enterring a heavy duty cycle.

# Idea: using a twisting motion of the pushrod to lock it in place.

The Gluss Pusher currently doesn't have a way to lock the pushrod in place.  One way would be to have tabs added to the push rod, and grooves in the channel with slots.  By rotating the pushrod, you would free it for vertical motion, and by rotating it back you would lock it in place.  The rotation could be done with magnets in the push rod, or even rollers.  I think this would make it a lot less elegant however.

## Idea: Robotic Massage

One of the things that could be done with a 3-Gluss-member system is to make a massage robot.  The idea would be perhaps to put a ball or wheel at the end to a tetrahedron and have it pummel and roll the client. No doubt it would require a bit more sensing to be comfortable and a control mechanism, but in principle it should be possible with my system at low cost.

## Idea: Fire-Hose Robot

A Gluss could potentially climb into the window of a burning building, carrrying a fire hose.  (This idea came from a conversation with Jacqueline Kazil.) This could be controlled by a firefighter on the ground controlling a model. This would potentially allow water or a flame-retardant to be delivered more precisely to the source of fire.

## Idea: Tent Setup

This idea also came from a conversation with Jackie Kazil.  Imagine a gluss used to automatically setup a tent frame very quickly.

## Idea: (Important)

I believe we could construct an augmented octahedron. That is, make an octahedron, and add 4 tetahedron that will act as legs or pseudopods. The point that aims upward can shift to shift weight so that one of the legs may be lifted. I suspect in this way we could build an effective, and relatively inexpensive, walking robot, that would remain would have the advantages of gluss.  That is, it would be capable of other configurations as well, while remaining completely polymorphic.  Note: Possibly this would require a different a rotor, which would not be too hard---not sure about that, I have to check the math. 

This would require 1 octahedron (12 glussions), plus 4 legs, each requires 3 additional glussions --- so a total of 24 glussions.  At current prices this would cost one about $2400, which seems rather expensive.

Note that this geometry the center point would touch the ground in the most relaxed position --- although if they maintained some eccentricity, this might not be a problem, it is possible that better designs exist. For example, we could easily adjust the platform---but then we would be deviated from our basic principle of using only standard glussions.  Perhaps it is best just to use standard glussions and accept the eccentricity.  I don't particularly relish spending $2500 to test this idea --- but note that the resulting robot would be much larger and possibly capable of carrying much more than most robots.

## Idea: Maybe we can make really cheap by making a linear induction motor....

Last night I did the math and it requires 13 octet pairs to build a mast capable of forming a circle with a Q of 1.5. That works out to 108 glussions. At $70 a piece, that's a lot of change. My permanent magnet based system can potentionally lower that price, but only so much.  If we could use a linear induction motor instead, we could start to get really cheap---possibly $15 per glussion.  Of course, the controller will still be needed, and such a system won't hold its position without additional hardware or constant power---but still, a 5-fold cost reduction is worth exploring.  After all, the screw-type actuators also collapse under a sufficently high backdrive force (31 Newtons, in the case of the Firgelli model I am using.)


<a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-sa/4.0/88x31.png" /></a><br /><span xmlns:dct="http://purl.org/dc/terms/" href="http://purl.org/dc/dcmitype/Text" property="dct:title" rel="dct:type">PIFAH: Immature Ideas</span> by <a xmlns:cc="http://creativecommons.org/ns#" href="https://github.com/PIFAH/PIFAH" property="cc:attributionName" rel="cc:attributionURL">Robert L. Read</a> is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/">Creative Commons Attribution-ShareAlike 4.0 International License</a>.<br />Based on a work at <a xmlns:dct="http://purl.org/dc/terms/" href="https://github.com/PIFAH/PIFAH" rel="dct:source">https://github.com/PIFAH/PIFAH</a>.
