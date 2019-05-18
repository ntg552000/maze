#include "Map.h"



Map::Map(sf::RenderWindow * window, std::string path)
{
	
	this->window = window;
	
	
	std::fstream f;
	f.open(path);
	std::string a;
	while (!f.eof())
	{
		getline(f, a);
		map.push_back(a);
	}
	f.close();

	tex1.loadFromFile("Image\\Wall.png");
	tex2.loadFromFile("Image\\Road.png");
	tex3.loadFromFile("Image\\Road.png");

	wall.setTexture(tex1);
	road.setTexture(tex2);
	safezone.setTexture(tex3);
}


Map::~Map()
{
}

void Map::Draw(sf::Vector2f pos_) 
{
	int x1 = (pos_.x - 500) / 70;
	int x2 = x1 + 14;
	int y1 = (pos_.y - 400) / 70;
	int y2 = y1 + 11;
	for (int i = y1; i < y2; i++) {
		for (int j = x1; j < x2; j++) {
			if ((i >= 0 && i < map.size() && j >= 0 && j < map[i].size()) && map[i][j] == '1') {
				road.setPosition(j * 70, i * 70);
				window->draw(road);
			}
			if ((i >= 0 && i < map.size() && j >= 0 && j < map[i].size()) && map[i][j] == '3') {
				safezone.setPosition(j * 70, i * 70);
				window->draw(safezone);
			}
		}
	}
}

void Map::Draw_road(sf::Vector2f pos_)
{
	int x1 = (pos_.x - 500) / 70;
	int x2 = x1 + 14;
	int y1 = (pos_.y - 400) / 70;
	int y2 = y1 + 11;
	for (int i = y1; i < y2; i++) {
		for (int j = x1; j < x2; j++) {
			if ((i >= 0 && i < map.size() && j >= 0 && j < map[i].size()) && map[i][j] == '2') {
				wall.setPosition(j * 70, i * 70 - 20);
				window->draw(wall);
			}
		}
	}
}


