#include "gameLogic.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

gameLogic::gameLogic()
{
	window = new RenderWindow(sf::VideoMode(800, 1000), "Space Shooter");
	window->setPosition(Vector2i((1920 / 2) - (800 / 2), 0));
	window->setFramerateLimit(60);
}

gameLogic::~gameLogic()
{
	delete window;
}

void gameLogic::startGame()
{
	sf::Clock clock;
	sf::Clock clock1;
	sf::Time elapsed;
	sf::Time elapsed1;
	
	int counter = 0;

	//main game loop
	while (window->isOpen())
	{
		if (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				window->close();
		}
		elapsed = clock.getElapsedTime();
		elapsed1 = clock1.getElapsedTime();
		
		if (elapsed1.asSeconds() > 1 && counter != 3)
		{
			enemies.newEnemy(1);
			clock1.restart();
			counter++;
		}

		window->clear();

		//update player movement
		player.updateMovement();
		player.fire();
		//player.letsSpin();
		

		for (int i = 0; i < player.getProArray().size(); i++)
		{
			window->draw(player.getProArray().at(i).getSprite());
			player.getProArray().at(i).updateProjectileMovement('p');
		}

		enemies.updateAll(window);
		enemies.updatePro(window);
		window->draw(player.getSprite());
		
		//draw objects
		//window->draw(player.sprite);

		//draw HUD
		//window->draw(hud.returnText(20, 20, "Score: " + std::to_string(hud.getScore()), 20));
		//window->draw(hud.returnText(20, 50, "Time: " + std::to_string((int)elapsed.asSeconds()), 20));

		//if (player.getHp() <= 0)
		//{
			//window->draw(hud.returnText(800 / 2 - 170, 1000 / 2, "U LOSE", 100));
		//}
		window->display();
		//display all previously drawn objects
		//window->display();
	}
}