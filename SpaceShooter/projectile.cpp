#include "projectile.h"



projectile::projectile()
{
	projectileLifeTime = 100;
	moveSpeed = 10;
	counter = 0;
	destroy = false;

	sprite = Sprite(TextureHolder::GetTexture("Sprites\\projectile.png"));
	
	sprite.setScale(sf::Vector2f(0.2, 0.2));
	sprite.setOrigin(20,35);
}

projectile::~projectile()
{
}

void projectile::updateProjectileMovement(char playerOrEnemy)
{
	if (playerOrEnemy == 'p')
		sprite.move(0, (-moveSpeed));
	else
		sprite.move(0, (moveSpeed));
	counter++;
	if (counter >= projectileLifeTime)
		destroy = true;
}

int projectile::getMoveSpeed()
{
	return moveSpeed;
}

bool projectile::getStatus()
{
	return destroy;
}

void projectile::setRotation(int degree)
{
	sprite.setRotation(degree);
}

Sprite &projectile::getSprite()
{
	return sprite;
}