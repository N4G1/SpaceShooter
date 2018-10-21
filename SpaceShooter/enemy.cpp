#include "enemy.h"

using namespace sf;
using namespace std;

enemy::enemy()
{
	srand(time(nullptr));
	currentMovement = randomArray[rand() % 10];

	pro.getSprite().setRotation(180);
}

enemy::~enemy()
{
}

void enemy::spawn(float startX, float startY, int type, int seed)
{
	switch (type)
	{
	case 0:
		// Default
		sprite = Sprite(TextureHolder::GetTexture("Sprites\\alien1b.png"));
		movementSpeed = 10;
		attackDamage = 1;
		HP = 10;
		break;
		/*
	case 1:
		// Chaser
		m_Sprite = Sprite(TextureHolder::GetTexture(
			"graphics/chaser.png"));

		m_Speed = 70;
		m_Health = 1;
		break;

	case 2:
		// Crawler
		m_Sprite = Sprite(TextureHolder::GetTexture(
			"graphics/crawler.png"));

		m_Speed = 20;
		m_Health = 3;
		break;
		*/
	}

	// Modify the speed to make the zombie unique
	// Every zombie is unique. Create a speed modifier
	//srand((int)time(0) * seed);
	// Somewhere between 80 an 100
	//float modifier = (rand() % MAX_VARRIANCE) + OFFSET;
	// Express as a fraction of 1
	//modifier /= 100; // Now equals between .7 and 1
	//m_Speed *= modifier;

	//m_Position.x = startX;
	//m_Position.y = startY;

	sprite.setOrigin(67,90);
	sprite.setPosition(400,100);
}

void enemy::updateMovement()
{
	elapsed = clock.getElapsedTime();
	if (elapsed.asMilliseconds() >= 300)
	{
		clock.restart();
		if (currentMovement < 0)
		{
			if (sprite.getPosition().x > 0)
				sprite.move(Vector2f(-movementSpeed, 0));
			else
				sprite.setPosition(Vector2f(0, sprite.getPosition().y));
			currentMovement++;
		}
		else if (currentMovement > 0)
		{
			if (sprite.getPosition().x < 800 - 80/2)
				sprite.move(Vector2f(movementSpeed, 0));
			else
				sprite.setPosition(Vector2f(800 - 80/2, sprite.getPosition().y));
			currentMovement--;
		}
		else
			currentMovement = randomArray[rand() % 10];
	}
}

void enemy::fire() //TODO colorfull projectiles
{
	elapsed = clock.getElapsedTime();
	if (elapsed.asMilliseconds() >= 200)
	{
		pro.getSprite().setPosition(sprite.getPosition().x, sprite.getPosition().y);
		proArray.push_back(pro);
		clock.restart();
	}
}

int enemy::getHp()
{
	return HP;
}

sf::Sprite enemy::getSprite()
{
	return sprite;
}

std::vector<projectile>& enemy::getProArray()
{
	return proArray;
}