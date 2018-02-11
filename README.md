# Tetris
Tetris game in C++ using SFML <br /> <br />
All graphic is made from 21x21px squares stored in this file <br /> <br />
![alt text](https://github.com/reniasa/Tetris/blob/master/SFML/element.jpg)
<br /> <br />
First square is responsible for board color, left are for the shapes.
<br />
Shapes, called also as blocks are generating from two dimensional array<br/>
```c#
int figures[blockVariations][blockLength] =
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
<br/>
Idea behind the array is explained here
<br /> <br />
![alt text](https://github.com/reniasa/Tetris/blob/master/SFML/Screenshots/example.jpg) etc.
<br /> <br />
Game is starting after run the application and have no end condition. <br/>
Lines are checked always before generating new block to control, so when the line from the blocks is completed, it will vanish and moving the remaining blocks downwards for each vanish line.<br/>
![alt text](https://github.com/reniasa/Tetris/blob/master/SFML/Screenshots/Screenshot_1.png)
