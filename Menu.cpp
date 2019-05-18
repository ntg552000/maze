#include "Menu.h"



Menu::Menu(sf::RenderWindow * window)
{
	this->window = window;
	this->Frame = 0;

	column = 0; line = 0;

	width = 800; height = 600;

	count = 10;

	speed = 0.15;

	for (int i = 0; i < count; i++)
		this->Frames.push_back(sf::IntRect(column + width * i, line, width, height));

	this->Texture_.loadFromFile("Image\\menu.png");
	this->Sprite_.setTexture(Texture_);
	this->Sprite_.setTextureRect(this->Frames[0]);
	Sprites_.push_back(Sprite_);

	

}



Menu::~Menu()
{
}
