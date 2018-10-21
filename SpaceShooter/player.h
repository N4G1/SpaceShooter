#pragma once
#include "character.h"
#include "TextureHolder.h"
#include "projectile.h"

using namespace sf;

class player
{
	std::vector<projectile> proArray;
	projectile pro;
	sf::Clock clock;
	sf::Time elapsed;
	Vector2f velocity;
	Vector2f acceleration;
	sf::Sprite sprite;

	float accForce;
	int movementSpeed;
	int attackDamage;
	int playershapeWidth;
	int playershapeHeight;
	int spin;
	int HP;
public:
	player();
	~player();
	void updateMovement();
	void fire();
	void letsSpin();
	sf::Sprite getSprite();
	std::vector<projectile>& player::getProArray();
};

