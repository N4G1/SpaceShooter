#pragma once
#include "enemy.h"

class enemies
{
	std::vector<enemy> enemyArray;
	enemy enemy1;
	//Boss boss;
	//HUD hud;
public:
	enemies();
	~enemies();
	void newEnemy(int enemyQty);
	void deleteEnemy(int enemyID);
	void updateAll(sf::RenderWindow *w/*, character player*/);
	void updatePro(sf::RenderWindow *w);
	std::vector<enemy>& enemies::getEnemyArray();
};