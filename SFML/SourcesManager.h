#ifndef SOURCESMANAGER_H
#define SOURCESMANAGER_H

#include "stdafx.h"
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
using namespace sf;

class SourcesManager {
public:
	SourcesManager(int squareSize);
	~SourcesManager();
	void refreshBoard(int moveRight, int x, int y, RenderWindow &window, Sprite &image);
	struct Point { int x, y; };
	struct Board { int width; int height; };
private:
	int squareSize;
};
#endif
