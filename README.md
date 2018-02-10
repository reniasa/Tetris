# Tetris
Tetris game in C++ <br /> <br />
All graphic is made of 21x21px squares stored in this file <br /> <br />
![alt text](https://github.com/reniasa/Tetris/blob/master/SFML/element.jpg)
<br /> <br />
First square is responsible of board color, left are for blocks.
<br />
Blocks are generating from two dimensional array<br/>
```c#
int figures[blockVariations][blockLenght] =
{
	1,3,5,7, // I
	2,4,5,7, // Z
	3,5,4,6, // S
	3,5,4,7, // T
	2,3,5,7, // L
	3,5,7,6, // J
	2,3,4,5, // O
};
```
so block variations and block length are like in classic tetris.

