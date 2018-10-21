#pragma once

#include "player.h"
#include "enemies.h"
#include "HUD.h"

class gameLogic
{
	sf::RenderWindow* window;
	player player;
	enemies enemies;
	HUD hud;
	sf::Event event;
public:
	gameLogic();
	void startGame();
	~gameLogic();
};

