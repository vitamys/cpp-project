# cpp-project
December 2023

how to use this repo:

main branch:
fully functional Game of Life, playable in four quadrants. Colors of the patterns are per type of pattern

observerpattern:
experimental implementation of an observer pattern. this implementation is not stable! it shows the exploration of topics during the project.

### Game of Life
The game of life is a cellular automaton created by John Horton Conway in 1970. As
soon as the game has started, there is no further input by the player. It consists of an grid of cells, where every cell can either be alive or dead and is updated
every generation, according to its interaction with its eight neighbours. This interaction is determined by rules, which define whether a cell will stay alive or die in
the next generation.

#### Rules 
They work as following:
* A live cell surrounded by fewer than two living cells dies, because of underpopulation.
* A live cell surrounded by two or three living cells stays alive.
* A live cell surrounded by more than three living cells dies, because of overpopulation.
* A dead cell surrounded by exactly three living cells becomes alive, due to reproduction.​

To make the game more interesting, there will be different patterns of alive and dead
cells, which can be chosen at the beginning of the game. These patterns will then
change over generations, according to the specified rules.

#### Patterns
There are different types of patterns, that are grouped by how they move over generations in the grid.

##### Still lifes
These are non-moving patterns. Here, all these patterns are shown in generation 1:
![image](https://github.com/vitamys/cpp-project/assets/115620523/091962f0-7bcc-4cea-9bc9-cc43fba3e507)

##### Oscillators
These are moving patterns which will return to their initial state after a certain number of generations.
![image](https://github.com/vitamys/cpp-project/assets/115620523/1676363d-7df0-443b-b35e-f985ee195d52)

##### Spaceships
These patterns are similar to the Oscillators, they will also return to their inital state after a certain number of generations, however on a different location on the grid.
![image](https://github.com/vitamys/cpp-project/assets/115620523/41ba85f8-4b80-4105-828c-b917d3f948c2)

##### Methuselahs
These are moving patterns which evolve for a long period of generations before stabilizing themselves.
<img width="900" alt="image" src="https://github.com/vitamys/cpp-project/assets/115620523/ea1d3f7a-339f-42f0-b37e-48b051678535">

