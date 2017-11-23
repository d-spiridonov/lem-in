# lem-in
School 42 project aimed at implementing Breadth First Search Algorithm and working with graphs

### Project description
We make an ant farm, with tunnels and rooms; we place the ants on one side; and we look at how they find the exit.
We join the rooms to one another with as many tubes as we need. A tube joins two rooms to each other. No more than that. A room can be linked to an infinite number of rooms and by as many tubes as deemed necessary. Then we must bury the ant farm (wherever you want). This is extremely important to ensure that ants don’t cheat and look at your design before before the game starts. The goal of this project is to create a “Hex” simulator. 

### Installing
```
Install the program using makefile
```

### Launching lem-in

```
./lem-in
```

* The program receives the data describing the ant farm from the standard output in the following format:
```
number_of_ants
the_rooms
the_links
```

* The ant farm is defines by the following links:
```
##start 
1 23 3 
2 16 7 
#comment
3 16 3 
4 16 5 
5 9 3
6 1 5 
748 
##end 
0 9 5
0-4
0-6 
1-3
4-3
5-2
3-5
#another comment
4-2
2-1
7-6
7-2
7-4
6-5
```

#### There are two parts:
 1) The rooms, which are defined by: name coord_x coord_y 
 2) The links, which are defined by: name1-name2
 
* All of it is broken by comments, which start with #
* The rooms name are not necessarily numbers
* Rooms coordinates should be integers
* Lines that start with ## are commands modifying the properties of the line that comes right after.
* ##start signals the ant farm’s entrance and ##end its exit.
* If there isn’t enough data to process normally the program displays ERROR
