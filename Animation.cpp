#include "Animation.h"


Animation::Animation()
{
}

Animation::Animation(sf::RenderWindow * window)
{
	this->window = window;
	this->Frame = 0;

	for (int i = 0; i < count; i++)
		this->Frames.push_back(sf::IntRect(column + width * i, line, width, height));

	/*this->Texture_.loadFromFile(path);
	this->Sprite_.setTexture(Texture_);
	this->Sprite_.setTextureRect(this->Frames[0]);
	Sprites_.push_back(Sprite_);*/
	
}


Animation::~Animation()
{
}

void Animation::draw(int i)
{
	//this->Sprites_[i].setTextureRect(this->Frames[0]);
	
	this->Frame += this->speed;
	int n = this->Frames.size();
	if (this->Frame >= n)
		this->Frame -= n;
	this->Sprites_[i].setTextureRect(this->Frames[int(this->Frame)]);
	this->window->draw(this->Sprites_[i]);
}
