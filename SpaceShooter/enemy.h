#pragma once
#include "TextureHolder.h"
#include "projectile.h"

class enemy
{
	int randomArray[11] = {-5,-4,-3,-2,-1,1,2,3,4,5};
	int currentMovement;
	int movementSpeed;
	int attackDamage;
	int HP;

	std::vector<projectile> proArray;
	sf::Sprite sprite;
	projectile pro;
	sf::Clock clock;
	sf::Time elapsed;
	
public:
	enemy();
	~enemy();
	void spawn(float startX, float startY, int type, int seed);
	void fire();
	int getHp();
	sf::Sprite getSprite();
	std::vector<projectile>& getProArray();
	void updateMovement();
};

