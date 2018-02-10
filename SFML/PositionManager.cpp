#include "stdafx.h"
#include "PositionManager.h"
#include "sourcesManager.h"
#include "draw.h"


PositionManager::PositionManager(int blockLenght, SourcesManager::Board &board)
{
	PositionManager::blockLenght = blockLenght;
	PositionManager::board = board;
}

void PositionManager::move(int dx, int(&field)[28][19], SourcesManager::Point(&currentBlockPosition)[4], SourcesManager::Point(&lastBlockPosition)[4])
{
	for (int i = 0; i < blockLenght; i++)
	{
		lastBlockPosition[i] = currentBlockPosition[i];
		currentBlockPosition[i].x += dx;
	}

	if (!isStillOnBoard(field, currentBlockPosition))
	{
		for (int i = 0; i < blockLenght; i++)
		{
			currentBlockPosition[i] = lastBlockPosition[i];
		}
	}

}

int PositionManager::drawNewBlock(int colorVariations, int blockVariations, SourcesManager::Point(&currentBlockPosition)[4], int (&figures)[7][4]) {
	int newBlockType = rand() % blockVariations;
	for (int i = 0; i < blockLenght; i++) {
		currentBlockPosition[i].x = figures[newBlockType][i] % 2;
		currentBlockPosition[i].y = figures[newBlockType][i] / 2;
	}
	return 1 + rand() % colorVariations;

}

bool PositionManager::isStillOnBoard(int(&field)[28][19], SourcesManager::Point(&currentBlockPosition)[4])
{
	for (int i = 0; i < blockLenght; i++)
	{
		if (currentBlockPosition[i].x < 0 || currentBlockPosition[i].x >= board.width || currentBlockPosition[i].y >= board.height) return 0;
		else if (field[currentBlockPosition[i].y][currentBlockPosition[i].x]) return 0;
	}
	return 1;
}

void PositionManager::rotate(int(&field)[28][19], SourcesManager::Point(&currentBlockPosition)[4], SourcesManager::Point(&lastBlockPosition)[4])
{
	SourcesManager::Point rotationCenter = currentBlockPosition[1];
	for (int i = 0; i < blockLenght; i++)
	{
		int x = currentBlockPosition[i].y - rotationCenter.y;
		int y = currentBlockPosition[i].x - rotationCenter.x;
		currentBlockPosition[i].x = rotationCenter.x - x;
		currentBlockPosition[i].y = rotationCenter.y + y;
	}
	if (!isStillOnBoard(field, currentBlockPosition)) for (int i = 0; i < blockLenght; i++)
	{
		currentBlockPosition[i] = lastBlockPosition[i];
	}
}

void PositionManager::goDown(SourcesManager::Point(&currentBlockPosition)[4], SourcesManager::Point(&lastBlockPosition)[4])
{
	for (int i = 0; i < blockLenght; i++) { lastBlockPosition[i] = currentBlockPosition[i];  currentBlockPosition[i].y += 1; }
}

void PositionManager::colorizeBackground(SourcesManager::Point(&lastBlockPosition)[4], int(&field)[28][19], int colorNum)
{
	for (int i = 0; i < blockLenght; i++) {
		field[lastBlockPosition[i].y][lastBlockPosition[i].x] = colorNum;
	}
}

PositionManager::~PositionManager()
{
}
