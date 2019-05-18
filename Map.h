#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <fstream>


class Map
{
public:
	Map(sf::RenderWindow * window, std::string path);
	~Map();

	std::vector<std::string> get_map() const { return map; }

	void Draw(sf::Vector2f pos_);
	void Draw_road(sf::Vector2f pos_);



private:
	sf::RenderWindow* window;
	std::vector<std::string> map;
	sf::Texture tex1, tex2, tex3;
	sf::Sprite wall, road, safezone;
	
};

