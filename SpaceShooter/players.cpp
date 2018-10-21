#include "players.h"


//not in use yet
players::players()
{
	playerArray.push_back(playerz);
}

players::~players()
{
}

void players::update()
{
	for (player &p : playerArray)
	{
		p.updateMovement();
		p.fire();
	}
}

std::vector<player>& players::getPlayerArray()
{
	return playerArray;
}
