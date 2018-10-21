#include "HUD.h"

HUD::HUD()
{
}

void HUD::displayText()
{
}

sf::Text HUD::returnText(int x, int y, std::string z, int fontSize)
{
	if (!font.loadFromFile("Fonts\\Neon.ttf"))
		//std::cout << "Error loading font\n";
	
	/*if (!backgroundTexture.loadFromFile("Sprites\\Background1.png"))
		std::cout << "Fail loading sprite\n";

	sprite.setTexture(backgroundTexture);
	*/
	text.setFont(font);
	text.setCharacterSize(fontSize);
	text.setFillColor(sf::Color::White);
	text.setPosition(x, y);
	text.setString(z);

	return text;
}

HUD::~HUD()
{
}
