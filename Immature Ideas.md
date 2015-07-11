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
