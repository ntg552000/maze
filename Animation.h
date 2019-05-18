#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Animation
{
public:
	Animation();
	Animation(sf::RenderWindow *window);
	~Animation();
	void draw(int i);

	sf::RenderWindow *window;
	sf::Sprite Sprite_;
	sf::Texture Texture_;

	std::vector <sf::IntRect> Frames;
	std::vector<sf::Sprite> Sprites_;

	int column, line;

	float width, height;

	int count;

	float speed;

	float Frame;
};

