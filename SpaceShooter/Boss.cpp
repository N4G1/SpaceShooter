#include "Boss.h"
#include <iostream>

using namespace sf;


Boss::Boss() : enemy()
{
	/*
	//shape.setSize(Vector2f(300, 300));
	//shape.setPosition(Vector2f(400, 200));

	if (!bossTexture.loadFromFile("Sprites\\BossPhase1.png"))
		std::cout << "Fail loading sprite\n";
	//initialize("Sprites\\BossPhase1.png", 2, 2);
	sprite.setScale(sf::Vector2f(1, 1));
	sprite.setTexture(bossTexture);
	sprite.setPosition(Vector2f(400, 300));
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	

	sprite.setRotation(250);	
	spin = 0;
	*/
}

void Boss::letsSpin()
{
	/*
	if (spin < 10000)
		sprite.setRotation((++spin)%360);
	else
		spin = 0;
	std::cout << sprite.getRotation() << "\n";
	*/
}

Boss::~Boss()
{
}