#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "Animation.h"


class Object : public Animation
{
public:
	Object();
	Object(sf::RenderWindow* window);
	~Object();

	sf::Vector2f get_pos() const { return pos_; }
	void set_pos(const int&x, const int& y) { pos_ = sf::Vector2f(x, y); }



protected:
	sf::Vector2f pos_;
	
	
};
