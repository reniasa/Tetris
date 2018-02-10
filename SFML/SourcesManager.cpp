#include "stdafx.h"
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "sourcesManager.h"
using namespace sf;

SourcesManager::SourcesManager(int squareSize) 
{
	SourcesManager::squareSize = squareSize;
}

SourcesManager::~SourcesManager() {}

void SourcesManager::refreshBoard(int moveRight, int x, int y, RenderWindow &window, Sprite &image) {
	image.setTextureRect(IntRect(moveRight*squareSize, 0, squareSize, squareSize));
	image.setPosition(x * squareSize, y * squareSize);
	window.draw(image);
}



