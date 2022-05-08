Circle The Goose
Objective : Circle the goose untill he can't move any more.
===============================================================================
Writen by member 1 = Gal Ein-Dor    id = 209070671    login = galei
Writen by member 2 = David Koplev   id = 208870279    login = davidkop


This program will create a game that will allow the user to press circular
Tiles over the board in which the goose will move around in.
The main goal is to close on the goose untill he can not move any further
which will give the user the win.
If the goose runs away (get off the edges of the board) the user loses
and the game restarts from the same level.
maps are randomized and created on each go unless a loss or reset has
occured, than the map is reseted to the last creation.

-------------------------------------------------------------------------------

Map Build :
-----------
The map is created each time randomly from scratch, randomizes a certain amount
of tiles in the board which will be already colored.
The goose always starts(spawns) in the middle of the board.
in case of loss or reset the board will not randomize again, the board will be
returning to its original state before the user's choice and input.

-------------------------------------------------------------------------------

Game Functionality:
-------------------

undo button - we choose to allow the undo button to go only 1 step back and not
further than that because we don't want the game to be so "easy" or allow any
cheating, your choices are not fully recoverable.
to controll the option to start over we added the reset button functionalty, it
will allow the map to go back to its original state at the beggining of the
level.

-------------------------------------------------------------------------------

File list:
----------
On the Source section:
----------------------
1. Animation.cpp : implementation of Animation's class and the build
of the class and control of the animation's speed and values.

2. Button.cpp : implementation of Button's class and functions such draw\print
to the user and click handling.

3. Enemy.cpp : implementation of Enemy's class and functions, such as the
algorithem of finding the shortest route to victory and the animation movement.

4. GameController.cpp : implementation of GameController's class and functions,
such as the run function which allows the game to run by order and handling of
mouse clicks.

5. Graph.cpp : implementation of Graph's class and functions, such as
draw\print of the graph (game board) and creation of the graph adjacent.

6. main.cpp : main running file, allows the program to start running and building
it's classes.

7. Resources.cpp : implementation of Resources's class and  functions, such as
instance function, getting the font from class, loading buffers, setting sounds
and so on.

8. Tile.cpp : implementation of Tile's class and  functions, such as adding
adjacent to each tile, color and size set and draw\print.



On the Include(headers) section:
--------------------------------
1. Animation.h : Holds the class type and includes, relevant members and mainly
used for the animation of the goose.

2. Button.h : Holds the class type and includes, used for creation and handeling
of screen buttons.

3. Enemy.h : Holds the class type and includes, relevant members such current
location and last location. allows information on the goose.

4. GameControll.h : Holds the class type and includes, relevant members such
as the board (graph) and the goose (enemy).

5. Graph.h : Holds the class type and includes, function declarations.
allows control on the Graph (game board).

6. macros.h : Holds the class type and includes, Game Sounds and enums for
certain values such as directions and enemy state (trapped or not).

7. Resources.h : Holds the class type and includes, hold all resources such as
font, textures, sounds and so on.

8. Tile.h : Holds the class type and includes, relevant members such as
onEdge (if the tile is the outer frame of the board for win condition).


Resources :
-----------
1. bg1.jpg - game's background.

2. font.ttf - game's font.

3. goose.png - the goose animation page.

4. honk.wav - the sound of the goose while moving.

5. loseScreen.png - for the case of losing, pop up image.

6. winScreen.png - for the case of winning, pop up image.



other files:
------------
1. CMakeLists.txt - exist in e variants, 1 in each folder, they allow
the project to use all the other files listed above.
folders holding CMakeLists.txt are : include, src and main folder.

------------------------------------------------------------------------------


Main data bases:
----------------




Note-worthy Algorithm:
----------------------
BFS - for the goose to find the fastest route to victory the algorithm allows
to ceate a list for each tile with its adjacents and through that allows the
algorithm to search the least amount of adjacents needed to visit untill
reaching the destination (the gooses win condition).



Input:
------
For any mouse click on the board, if the circle(tile) isn't already colored,
colors the circle.
if lost, press spacebar or esc to reset the level.
if pressed any button, starts the button's action.

Output:
-------
if undo button is pushed - goes back 1 step.
if reset is pressed - resets the map to its original state.
if the circle(tile) isn't already colored, colors the circle and denys the 
goose's movement on it.
if goose was able to run away - pop up image of "peace was never an option"
if goose was surrounded with circles (win) - "sad goose sounds" pop up image.
for any step the goose takes, there is a sound output from the goose immitating
its voice\sound (honk or quack).

-------------------------------------------------------------------------------

Known issues:

===============================================================================