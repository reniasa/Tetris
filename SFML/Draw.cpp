#include "stdafx.h"
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
//#include "sourcesManager.h"
#include "draw.h"
using namespace sf;

void Draw::currentBlock(SourcesManager::Point (&currentBlockPosition)[4], int colorNum, SourcesManager &source, RenderWindow &window, Sprite &image)
{
	for (int i = 0; i < 4; i++)
	{
		source.refreshBoard(colorNum, currentBlockPosition[i].x, currentBlockPosition[i].y, window, image);
	}
}

Draw::Draw(SourcesManager::Board &board)
{
	Draw::board = board;
}

void Draw::allBoard(int(&field)[28][19], SourcesManager &source, RenderWindow &window, Sprite &image)
{
	for (int i = 0; i < board.height; i++) {
		for (int j = 0; j < board.width; j++) {
			source.refreshBoard(field[i][j], j, i, window, image);
		}
	}
}

void Draw::removeFullLines(int(&field)[28][19])
{
	int k = board.height - 1;
	for (int i = board.height - 1; i > 0; i--) {
		int count = 0;
		for (int j = 0; j < board.width; j++) {
			if (field[i][j]) count++;
			field[k][j] = field[i][j];
		}
		if (count < board.width) k--;
	}
}

Draw::~Draw()
{
}
