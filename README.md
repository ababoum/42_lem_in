# 42_lem_in 🐜
Elementary algorithmic project: code an ant farm manager

In this 42 school project, we designed and implemented an algorithm to solve a special case of a maximum flow problem in graph theory.
The goal is to find the optimal flow of ants through an anthill that minimizes the number of rounds needed to traverse the anthill.
An anthill is described as a network composed of 'rooms' (graph nodes) and 'tunnels' (edges) linking the rooms together, with all ants starting and finishing at two precise rooms.
The real trouble begins when each room can welcome only one ant at a time (except for the start and end rooms).
A round ends when no more ants are able to start or move any further in the anthill.


# Algorithm

The algorithm that we have chosen to solve the problem is a algorithm with a strong constraint: each room can only be used in a single path. This reduces the weight of managing the path overlapping, while still offering very good results in terms of performance.

* Step 1: find the possible paths, and sort them from the shortest to the longest one
* Step 2: send each ant in a path, while always comparing what would be better between a given path with its current occupancy, and a ready-to-enter path.
* Step 3: display the results!
