#include "Object.h"


Object::Object()
{
	
}

Object::Object(sf::RenderWindow * window)
{
	pos_ = sf::Vector2f(0, 0);
	this->window = window;
	this->Frame = 0;

	for (int i = 0; i < count; i++)
		this->Frames.push_back(sf::IntRect(column + width * i, line, width, height));
}

Object::~Object()
{
}


