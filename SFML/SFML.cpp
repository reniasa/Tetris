// SFML.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "sourcesManager.h"
#include "PositionManager.h"
#include "draw.h"
using namespace sf;

const int squareSize = 21;
const int blockVariations = 7;
const int blockLenght = 4;
const int colorVariations = 4;
const int BoardHeight = 28;
const int BoardWidth = 19;

int field[BoardHeight][BoardWidth] = { 0 };

SourcesManager::Point currentBlockPosition[blockLenght], lastBlockPosition[blockLenght];
SourcesManager::Board board;

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

bool isStillOnBoard()
{
	for (int i = 0; i < blockLenght; i++)
	{
		if (currentBlockPosition[i].x < 0 || currentBlockPosition[i].x >= BoardWidth || currentBlockPosition[i].y >= BoardHeight) return 0;
		else if (field[currentBlockPosition[i].y][currentBlockPosition[i].x]) return 0;
	}
	return 1;
}

float timer, delay;
int dx, colorNum;
bool rotate;

void resetKeyCodeVariables()
{
	dx = 0; rotate = 0; delay = 0.3;
}

void init() {
	dx = 0; rotate = 0; colorNum = 1;
	timer = 0, delay = 0.3;
	board.width = BoardWidth;
	board.height = BoardHeight;
}

int main()
{
	init();

	SourcesManager source(squareSize);
	PositionManager position(blockLenght, board);
	Draw Draw(board);
	Texture imageTexture;
	Clock clock;
	Event event;

	colorNum = position.drawNewBlock(colorVariations, blockVariations, currentBlockPosition, figures);

	RenderWindow window(VideoMode(399, 588, 32), "Tetris");
	imageTexture.loadFromFile("element.jpg");
	Sprite image(imageTexture);
	image.setTextureRect(IntRect(0, 0, squareSize, squareSize));


	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

			if (event.type == Event::KeyPressed)
				if (event.key.code == Keyboard::Up) rotate = true;
				else if (event.key.code == Keyboard::Left) dx = -1;
				else if (event.key.code == Keyboard::Right) dx = 1;
				else if (event.key.code == Keyboard::Down) delay = 0.05;
		}

		position.move(dx, field, currentBlockPosition, lastBlockPosition);
		if(rotate) { position.rotate(field, currentBlockPosition, lastBlockPosition); };

		if (timer > delay)
		{
			position.goDown(currentBlockPosition, lastBlockPosition);
			if (!isStillOnBoard()) {
				position.colorizeBackground(lastBlockPosition, field, colorNum);
				colorNum = position.drawNewBlock(colorVariations, blockVariations, currentBlockPosition, figures);	
			}
			timer = 0;
		}

		Draw.removeFullLines(field);
		resetKeyCodeVariables();

		Draw.allBoard(field, source, window, image);
		Draw.currentBlock(currentBlockPosition, colorNum, source, window, image);

		window.display();
	}
	return 0;
}

