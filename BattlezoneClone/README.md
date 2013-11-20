#Battlezone Clone
##Adam Cumiskey
- - -
This project is a clone of the 1980 classic Battlezone, by Atari. You
control a tank which traverses a plane with primative objects trying to
destroy other tanks while avoiding getting shot yourself.
- - - 
## Current Status
For collisions, I'm using a QuadTree datastructure to store the location
of each object in a node so that at each frame, collidable objects only
check for intersections with objects in the same node.

The next step is to make an abstract Collidable class which all of my
collidable objects will inherit from which will contain the data and
methods needed to check collisions.
