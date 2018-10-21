#pragma once
#include "player.h"


class players
{
	std::vector<player> playerArray;
	player playerz;
public:
	players();
	~players();
	void players::update();
	std::vector<player>& players::getPlayerArray();
};

