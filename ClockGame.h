#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class ClockGame
{
public:
	ClockGame(sf::RenderWindow *window, sf::Clock *clock);
	~ClockGame();
	
	sf::RenderWindow *window;
	sf::Clock *clock;
	
	int getTime();

};

