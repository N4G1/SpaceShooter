#pragma once

#include "projectile.h"
#include <string>
#include "SFML\Graphics.hpp"

class character
{
protected:
	int charHp;
	projectile projectile1;
	std::vector<projectile> playerProjectileArray;
	sf::Clock clock1;
	sf::Time elapsed1;
	sf::Texture texturePlayer;
	sf::Sprite sprite;
public:
	character();
	~character();
	std::vector<projectile>& character::getEnemyProjectileArray();
	void initialize(const std::string &filename, double x, double y);
	void reduceHp();
	int getHp();
	void updateProjectile(sf::RenderWindow &window);
	void checkCollisionAgainstPlayer(character & player);
	void showHpStatus();
	void checkCollisionAgainstEnemy(character & enemy);
};

