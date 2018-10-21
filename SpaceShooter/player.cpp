#include "player.h"
#include <iostream>

using namespace sf;


player::player()
{
	movementSpeed = 10;
	attackDamage = 1;
	playershapeWidth = 80;
	playershapeHeight = 80;
	HP = 5;

	sprite = Sprite(TextureHolder::GetTexture("Sprites\\shship.png"));
	sprite.setScale(0.5, 0.5);
	//sf::Texture t = TextureHolder::GetTexture("Sprites\\shship.png");
	//sprite.setTexture(t);
	sprite.setPosition(Vector2f(400, 920));
	sprite.setOrigin(160,160);
	sprite.setColor(Color(200, 100, 150));

	velocity = Vector2f(0, 0);
	acceleration = Vector2f(0, 0);
	accForce = 0.2;
	//std::cout << &playerProjectileArray << " -player" << std::endl;
	spin = 0;
}

player::~player()
{
}

void player::updateMovement()		//broken but still works, UP movement resets its acc only if DOWN is pressed
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (sprite.getPosition().y > 0)
		{
			if (acceleration.y > 0)
				acceleration.y = 0;

			acceleration.y += -accForce;
			velocity.y += acceleration.y;
		}
		else
			sprite.setPosition(Vector2f(sprite.getPosition().x, 0));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (sprite.getPosition().y < 1000 - playershapeHeight)
		{
			if (acceleration.y < 0)
				acceleration.y = 0;

			acceleration.y += accForce;
			velocity.y += acceleration.y;
		}
		else
			sprite.setPosition(Vector2f(sprite.getPosition().x, 1000 - playershapeWidth));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		// Left key is pressed: accelerate left
		if (sprite.getPosition().x > 0)
		{
			if (acceleration.x > 0)
				acceleration.x = 0;

			acceleration.x += -accForce;
			velocity.x += acceleration.x;
		}
		else
			sprite.setPosition(Vector2f(0, sprite.getPosition().y));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		// Right key is pressed: move right
		if (sprite.getPosition().x < 800 - playershapeWidth)
		{
			if (acceleration.x < 0)
				acceleration.x = 0;

			acceleration.x += accForce;
			velocity.x += acceleration.x;
		}
		else
			sprite.setPosition(Vector2f(800 - playershapeHeight, sprite.getPosition().y));
	}


	if (velocity.y < -15)
		velocity.y = -15;
	if (velocity.y > 15)
		velocity.y = 15;
	if (velocity.x < -15)
		velocity.x = -15;
	if (velocity.x > 15)
		velocity.x = 15;
	
	sprite.move(velocity);

	velocity.y *= 0.85;		//friction
	velocity.x *= 0.85;		//friction
}

void player::fire()
{
	elapsed = clock.getElapsedTime();
	if (elapsed.asMilliseconds() >= 300)
	{
		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			pro.getSprite().setPosition(sprite.getPosition().x,sprite.getPosition().y);
			proArray.push_back(pro);
			//pro.getSprite().setColor(Color(clock.getElapsedTime().asMilliseconds()%255, clock.getElapsedTime().asMicroseconds() % 255, clock.getElapsedTime().asMilliseconds() % 255));
			clock.restart();
		}
	}
}

void player::letsSpin()
{
	/*
	if (spin < 10000)
		sprite.setRotation((++spin) % 360);
	else
		spin = 0;
	std::cout << sprite.getRotation() << "\n";
	*/
}

sf::Sprite player::getSprite()
{
	return sprite;
}

std::vector<projectile>& player::getProArray()
{
	return proArray;
}
