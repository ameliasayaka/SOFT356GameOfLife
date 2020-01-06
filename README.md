# SOFT356GameOfLife

In this project, I have attempted to recreate Conways Game of Life.

It  is a cell automaton that follows simple rules:
Any live cell with fewer than two live neighbours dies, as if by underpopulation.
Any live cell with two or three live neighbours lives on to the next generation.
Any live cell with more than three live neighbours dies, as if by overpopulation.
Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

This software creates a grid with random cells being 'alive', the number of which is determined by the user.
Each cell is checked to  see how many of its neighbours is alive, and its next state determined by the aforementioned rules.

The project can be used by running Source.cpp within the solution.

The Source.cpp file is the  main module of the program. game.cpp deals with  finer function, such as drawing the grid and checking each o the cells.

The idea to recreate Conways Game of Life comes from my interest in how simple mathematic rules can lead to complex patterns.
Unfortunately, I was unable to implement unique ideas that I wanted to, such as being able to adjust the rules, and creating your own starting patterns, which is  something I am dissappointed that I couldn't achieve.
