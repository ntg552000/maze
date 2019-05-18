#pragma once

#include "Object.h"
#include <iostream>




class Player : public Object
{
public:
	Player(sf::RenderWindow * window);
	~Player();

	void Move_left(std::vector<std::string> map);
	void Move_right(std::vector<std::string> map);
	void Move_up(std::vector<std::string> map);
	void Move_down(std::vector<std::string> map);
	
	bool Check_die(std::vector<sf::Vector2f> get_monster_pos);

	int check_redFlag();
	int check_blueFlag();
	
	void Flag();

	void Update(std::vector<std::string> map, std::vector<sf::Vector2f> get_monster_pos, int time);
	void Draw();

	void drawInformation();

	void drawSnow();

	int get_blood() { return blood; }

	sf::Sprite Sprite1_;
	sf::Texture Texture1_;

	sf::Texture snow_image;
	sf::Sprite snow;

	





private:
	int step;
	
	int status;

	int blueFlagNumber;
	int redFlagNumber;
	
	float blood;

	std::vector<sf::Vector2f> redFlag_pos;
	std::vector<sf::Vector2f> blueFlag_pos;
	
	bool pressed = 0;
	bool pressed1 = 0;
	
	sf::Texture redFlag_tex;
	sf::Sprite redFlag_sprite;
	sf::Texture blueFlag_tex;
	sf::Sprite blueFlag_sprite;

	sf::Texture heart_tex;
	sf::Sprite heart_sprite;

	sf::Texture heartBar_tex;
	sf::Sprite heartBar_sprite;

	sf::Font font;
	

	enum {LEFT, RIGHT, UP, DOWN} move_type;

	
	
	

};

