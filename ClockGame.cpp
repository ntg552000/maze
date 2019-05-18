#include "ClockGame.h"



ClockGame::ClockGame(sf::RenderWindow *window, sf::Clock *clock)
{
	this->window = window;
	this->clock = clock;

}


ClockGame::~ClockGame()
{
}

int ClockGame::getTime()
{
	sf::Time elapsed = clock->getElapsedTime();
	int a = elapsed.asSeconds();
	return a;

}