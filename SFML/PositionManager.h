#include "sourcesManager.h"


#pragma once
class PositionManager
{
public:
	PositionManager(int blockLenght, SourcesManager::Board &board);
	~PositionManager();
	int drawNewBlock(int colorVariations, int blockVariations, SourcesManager::Point(&currentBlockPosition)[4], int(&figures)[7][4]);
	void move(int dx, int(&field)[28][19], SourcesManager::Point(&currentBlockPosition)[4], SourcesManager::Point(&lastBlockPosition)[4]);
	bool isStillOnBoard(int(&field)[28][19], SourcesManager::Point(&currentBlockPosition)[4]);
	void rotate(int(&field)[28][19], SourcesManager::Point(&currentBlockPosition)[4], SourcesManager::Point(&lastBlockPosition)[4]);
	void goDown(SourcesManager::Point(&currentBlockPosition)[4], SourcesManager::Point(&lastBlockPosition)[4]);
	void colorizeBackground(SourcesManager::Point(&lastBlockPosition)[4], int(&field)[28][19], int colorNum);
private:
	int blockLenght;
	struct SourcesManager::Board board;
};

