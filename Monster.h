#pragma once
#include "Object.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

class Monster : public Object
{
public:
	Monster(sf::RenderWindow *window, std::vector<std::string> map);
	~Monster();
	
	std::vector<sf::Vector2f> get_monster_pos() { return monster_pos; }
	

	void Move(std::vector<std::string> map,int i);

	void Update(std::vector<std::string> map, sf::Vector2f pos_);

	void Draw(sf::Vector2f pos_);

	void Random_monster(std::vector<std::string> map);
	



private:
	std::vector<sf::Vector2f> monster_pos;
	
	std::vector<std::string> status;
	int step;
	
	
};

