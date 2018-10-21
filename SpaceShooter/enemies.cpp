#include "enemies.h"


enemies::enemies()
{
	//enemyArray.push_back(boss);
	enemy1.spawn(1, 1, 0, 1);
}

enemies::~enemies()
{
}

void enemies::newEnemy(int enemyQty)
{
	for(int i = 0; i < enemyQty; i++)
		enemyArray.push_back(enemy1);
}

void enemies::deleteEnemy(int enemyID)
{
	enemyArray.erase(enemyArray.begin() + enemyID);
}

void enemies::updateAll(sf::RenderWindow *w/*, character player*/)
{
	for (int i = 0; i < enemyArray.size(); i++)
	{
		enemyArray.at(i).fire();
		enemyArray.at(i).updateMovement();
		w->draw(enemyArray.at(i).getSprite());
		//std::cout << &enemyArray.at(i).getSprite() << std::endl;

		if (enemyArray.at(i).getHp() <= 0)
		{
			deleteEnemy(i);
		}
	}
	//w->draw(boss.)
	//boss.letsSpin();
//checkCollisionAgainstPlayer(player);
}

void enemies::updatePro(sf::RenderWindow *w)
{
	/*
	for (enemy e : enemyArray)
	{
		for (projectile p : e.getProArray())
		{
			p.updateProjectileMovement('e');
			w->draw(p.getSprite());
		}
	}*/

	for (int i = 0; i < enemyArray.size(); i++)
	{
		for (int j = 0; j < enemyArray.at(i).getProArray().size(); j++)
		{
			enemyArray.at(i).getProArray().at(j).updateProjectileMovement('e');
			//p.updateProjectileMovement('e');
			//w->draw(p.getSprite());
			w->draw(enemyArray.at(i).getProArray().at(j).getSprite());
		}
	}
}

std::vector<enemy>& enemies::getEnemyArray()
{
	return enemyArray;
}
