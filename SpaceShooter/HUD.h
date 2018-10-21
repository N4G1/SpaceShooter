#pragma once
#include <sstream>
#include "SFML\Graphics.hpp"

class HUD
{
	sf::Font font;
	sf::Text text;
	
	float levelTime;	//how long does it take to finish the lvl, highscore etc.
public:
	HUD();
	void displayText();
	sf::Text returnText(int x, int y, std::string z, int fontSize);
	~HUD();
};

