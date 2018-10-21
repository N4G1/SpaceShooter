#pragma once
#include "enemy.h"


class Boss : public enemy
{
	sf::Texture bossTexture;
	sf::RectangleShape bossShape;
	sf::Sprite bossSprite;
	int spin;
public:
	Boss();
	void letsSpin();
	~Boss();
};

