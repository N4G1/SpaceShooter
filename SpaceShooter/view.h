#pragma once
#include "view.h"
#include <SFML/Graphics.hpp>

class view
{
	sf::RenderWindow window;
	sf::Event event;
public:
	view();
	~view();
	void setFramerate(int fps);
	void draw(sf::Sprite s);
	void clear();
	void display();
};