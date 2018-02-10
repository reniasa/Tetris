#ifndef DRAW_H
#define DRAW_H


#include "stdafx.h"
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "sourcesManager.h"

using namespace sf;
class Draw
{
public:
	Draw::Draw(SourcesManager::Board &board);
	void Draw::removeFullLines(int(&field)[28][19]);
	void Draw::currentBlock(SourcesManager::Point(&currentBlockPosition)[4], int colorNum, SourcesManager &source, RenderWindow &window, Sprite &image);
	void Draw::allBoard(int (&field)[28][19], SourcesManager &source, RenderWindow &window, Sprite &image);
	Draw::~Draw();
private:
	struct SourcesManager::Board board;
};
#endif