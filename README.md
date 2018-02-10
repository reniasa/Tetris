# Tetris
Tetris game in C++ <br /> <br />
All graphic is made of 21x21px squares stored in this file <br /> <br />
![alt text](https://github.com/reniasa/Tetris/blob/master/SFML/element.jpg)
<br /> <br />
First square is responsible of board color, left are for blocks.
<br />
Blocks are generating from two dimensional array<br/>
int figures[blockVariations][blockLength] =<br/>
{<br/>
	1,3,5,7, // I<br/>
	2,4,5,7, // Z<br/>
	3,5,4,6, // S<br/>
	3,5,4,7, // T<br/>
	2,3,5,7, // L<br/>
	3,5,7,6, // J<br/>
	2,3,4,5, // O<br/>
};<br/>
so block variations and block length are like in classic tetris.

