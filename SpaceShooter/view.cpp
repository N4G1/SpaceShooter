#include "view.h"

view::view()
{
	//window.create(sf::VideoMode(800, 1000), "Space Shooter"); //creating window
	//window.setPosition(sf::Vector2i((1920 / 2) - (800 / 2), 0));
	//window.setFramerateLimit(60);
}

view::~view()
{
}

void view::setFramerate(int fps)
{
	window.setFramerateLimit(fps);
}

void view::draw(sf::Sprite s)
{
	window.draw(s);
}

void view::clear()
{
	window.clear();
}

void view::display()
{
	if (window.isOpen())
	{
		if (window.pollEvent(event))
		{
			//std::cout << "a";
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				window.close();
		}
		//window.display();
	}
}
