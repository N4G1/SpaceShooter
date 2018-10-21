#include "character.h"
#include <iostream>

using namespace sf;
using namespace std;
static vector<projectile> enemyProjectileArray;

character::character()
{
}

character::~character()
{
}

std::vector<projectile>& character::getEnemyProjectileArray()
{
	return enemyProjectileArray;
}

void character::initialize(const string &filename, double x, double y)
{
	if (!texturePlayer.loadFromFile(filename))
		cout << "Fail loading playerTexture" << endl;

	sprite.setTexture(texturePlayer);
	sprite.setScale(sf::Vector2f(x, y));
}

void character::reduceHp()
{
	charHp--;
}

void character::showHpStatus()
{
	cout << charHp;
}

int character::getHp()
{
	return charHp;
}

void character::updateProjectile(RenderWindow &window)
{
	//std::cout <<  enemyProjectileArray.size() << std::endl;
	//std::cout << playerProjectileArray.size() << std::endl;
	for (projectile &p : playerProjectileArray)
	{
		p.updateProjectileMovement('p');
		//window.draw(p.sprite);
	}
	//std::cout << getEnemyProjectileArray().size() << "asd" << std::endl;
	for (projectile &e : enemyProjectileArray)
	{
		e.updateProjectileMovement('e');
		//window.draw(e.sprite);
	}
}

void character::checkCollisionAgainstPlayer(character &player)
{
	//loops through whole array
	//draw and update projectile for each iteration
	for (int i = 0; i < enemyProjectileArray.size(); i++)
	{
		if (enemyProjectileArray.at(i).getStatus() == true)
		{
			enemyProjectileArray.erase(enemyProjectileArray.begin() + i);
			break;
		}
		//if (enemyProjectileArray.at(i).sprite.getGlobalBounds().intersects(player.sprite.getGlobalBounds()))
		{
			cout << "collision with player detected" << endl;
			player.reduceHp();
			player.showHpStatus();
			enemyProjectileArray.erase(enemyProjectileArray.begin() + i);	//it might happen that this method will try to erase object
		}														//which is alleready deleted by the .getstatus() function and cause crash, needs fixing
	}
}

void character::checkCollisionAgainstEnemy(character &enemy)
{
	//loops through whole array
	//draw and update projectile for each iteration
	for (int i = 0; i < playerProjectileArray.size(); i++)
	{
		if (playerProjectileArray.at(i).getStatus() == true)
		{
			playerProjectileArray.erase(playerProjectileArray.begin() + i);
			break;
		}
		//if (playerProjectileArray.at(i).sprite.getGlobalBounds().intersects(enemy.sprite.getGlobalBounds()))
		{
			cout << "collision with enemy detected" << endl;
			enemy.reduceHp();
			enemy.showHpStatus();
			playerProjectileArray.erase(playerProjectileArray.begin() + i);	//it might happen that this method will try to erase object
		}														//which is alleready deleted by the .getstatus() function and cause crash, needs fixing
	}
}