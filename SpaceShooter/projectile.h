#pragma once
#include <iostream>
#include "SFML\Graphics.hpp"
#include "TextureHolder.h"

class projectile
{
	int damage;
	int moveSpeed;
	int counter;
	int projectileLifeTime;
	bool destroy;
	sf::Texture projectileTexture;
	sf::Sprite sprite;
public:
	projectile();
	bool getStatus();
	int getMoveSpeed();
	void setRotation(int degree);
	Sprite &getSprite();
	void updateProjectileMovement(char playerOrEnemy);
	~projectile();
};

