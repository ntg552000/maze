#include "Player.h"

Player::Player(sf::RenderWindow * window)
{
	pos_ = sf::Vector2f(40*70, 15*70);
	this->window = window;
	this->Frame = 0;

	column = 0; line = 0;

	width = 30; height = 35;

	count = 4;

	speed = 0.06;

	step = 7;

	blood = 100;

	blueFlagNumber = 40;
	redFlagNumber = 40;

	for (int i = 0; i < count; i++)
		this->Frames.push_back(sf::IntRect(column + width * i, line, width, height));

	status = 1;

	
	redFlag_tex.loadFromFile("Image\\redFlag.png");
	redFlag_sprite.setTexture(redFlag_tex);

	blueFlag_tex.loadFromFile("Image\\blueFlag.png");
	blueFlag_sprite.setTexture(blueFlag_tex);

	heart_tex.loadFromFile("Image\\heart.png");
	heart_sprite.setTexture(heart_tex);

	heartBar_tex.loadFromFile("Image\\heartbar.png");
	heartBar_sprite.setTexture(heartBar_tex);

	
	
	this->Texture_.loadFromFile("Image\\right.png");
	this->Sprite_.setTexture(Texture_);
	this->Sprite_.setTextureRect(this->Frames[0]);
	Sprites_.push_back(Sprite_);

	
	this->Texture1_.loadFromFile("Image\\left.png");
	this->Sprite1_.setTexture(Texture1_);
	this->Sprite1_.setTextureRect(this->Frames[0]);
	Sprites_.push_back(Sprite1_);

	snow_image.loadFromFile("Image\\snow.PNG");
	snow.setTexture(snow_image);

	font.loadFromFile("font.ttf");
	

}

Player::~Player()
{
}

int Player::check_redFlag()
{
	for (int i = 0; i < redFlag_pos.size(); i++)
	{
		if (pos_.x >= redFlag_pos[i].x - 60 && pos_.x <= redFlag_pos[i].x + 60 && pos_.y >= redFlag_pos[i].y - 60 && pos_.y <= redFlag_pos[i].y + 60)
		{
			return i;
		}
	}
	return -1;
}

int Player::check_blueFlag()
{
	for (int i = 0; i < blueFlag_pos.size(); i++)
	{
		if (pos_.x >= blueFlag_pos[i].x - 60 && pos_.x <= blueFlag_pos[i].x + 60 && pos_.y >= blueFlag_pos[i].y - 60 && pos_.y <= blueFlag_pos[i].y + 60)
		{
			return i;
		}
	}
	return -1;
}

void Player::Flag()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Num1) {
				if (pressed == 0) {
					if (check_redFlag() == -1)
					{
						if (redFlagNumber >= 0)
						{
							redFlag_pos.push_back(pos_);
							redFlagNumber = redFlagNumber - 1;
						}
						
					}
					else
					{
						redFlag_pos.erase(redFlag_pos.begin() + check_redFlag());
						redFlagNumber = redFlagNumber + 1;
					}
					pressed = 1;
				}
			}
			if (event.key.code == sf::Keyboard::Num2) {
				if (pressed1 == 0) {
					if (check_blueFlag() == -1)
					{
						if (blueFlagNumber >= 0)
						{
							blueFlag_pos.push_back(pos_);
							blueFlagNumber = blueFlagNumber - 1;
						}
					}
					else
					{
						blueFlag_pos.erase(blueFlag_pos.begin() + check_blueFlag());
						blueFlagNumber = blueFlagNumber + 1;
					}
					pressed1 = 1;
				}
			}
		}
		if (event.type == sf::Event::KeyReleased) {
			if (event.key.code == sf::Keyboard::Num1) {
				if (pressed == 1) {
					pressed = 0;
				}
			}
			if (event.key.code == sf::Keyboard::Num2) {
				if (pressed1 == 1) {
					pressed1 = 0;
				}
			}
		}
	}
}

void Player::Move_left(std::vector<std::string> map)
{
	if (map[pos_.y / 70][(pos_.x - step) / 70] != '2' &&  map[(pos_.y + 35 - 1) / 70][(pos_.x - step) / 70] != '2')
	{
		pos_.x = pos_.x - step;
	}
	else
	{
		int a = (pos_.x - step) / 70 + 1;
		pos_.x = a*70;
	}
}

void Player::Move_right(std::vector<std::string> map)
{
	if (map[pos_.y / 70][(pos_.x + 30 + step - 1) / 70] != '2' &&  map[(pos_.y + 35 - 1) / 70][(pos_.x + 30 + step - 1) / 70] != '2')
	{
		pos_.x = pos_.x + step;
	}
	else
	{
		int a = (pos_.x + 30 + step) / 70;
		pos_.x = a * 70 - 30;
	}
}

void Player::Move_up(std::vector<std::string> map)
{
	if (map[(pos_.y - step) / 70][pos_.x / 70] != '2' &&  map[(pos_.y - step) / 70][(pos_.x + 30 - 1) / 70] != '2')
	{
		pos_.y = pos_.y - step;
	}
	else
	{
		int a = (pos_.y - step) / 70 + 1;
		pos_.y = a * 70;
	}
}

void Player::Move_down(std::vector<std::string> map)
{
	if (map[(pos_.y + 35 + step - 1) / 70][pos_.x / 70] != '2' &&  map[(pos_.y + 35 + step - 1) / 70][(pos_.x + 30 - 1) / 70] != '2')
	{
		pos_.y = pos_.y + step;
	}
	else
	{
		int a = (pos_.y + 35 + step) / 70;
		pos_.y = a * 70 - 35;
	}
}

bool Player::Check_die(std::vector<sf::Vector2f> get_monster_pos)
{
	for (int i = 0; i < get_monster_pos.size(); i++)
	{
		if (pos_.x >= get_monster_pos[i].x && pos_.x <= get_monster_pos[i].x + 40 && pos_.y >= get_monster_pos[i].y && pos_.y <= get_monster_pos[i].y + 40)
		{
			return true;
		}
		
		if (pos_.x + 60 >= get_monster_pos[i].x && pos_.x + 60 <= get_monster_pos[i].x + 40 && pos_.y >= get_monster_pos[i].y && pos_.y <= get_monster_pos[i].y + 40)
		{
			return true;
		}
			
		if (pos_.x >= get_monster_pos[i].x && pos_.x <= get_monster_pos[i].x + 40 && pos_.y + 35 >= get_monster_pos[i].y && pos_.y + 35 <= get_monster_pos[i].y + 40)
		{
			return true;
		}
		if (pos_.x + 60 >= get_monster_pos[i].x && pos_.x + 60 <= get_monster_pos[i].x + 40 && pos_.y + 35 >= get_monster_pos[i].y && pos_.y + 35 <= get_monster_pos[i].y + 40)
		{
			return true;
		}			
	}
	return false;}

void Player::Update(std::vector<std::string> map, std::vector<sf::Vector2f> get_monster_pos, int time)
{
	for (int i = 0; i < Sprites_.size(); i++)
	{
		Sprites_[i].setPosition(pos_);
	}
	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
	{
		status = 2;
		Move_left(map);
		move_type = LEFT;
		
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		status = 1;
		Move_right(map);
		move_type = RIGHT;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		Move_up(map);
		if(status==1)
			move_type = RIGHT; 
		else move_type = LEFT; 
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		Move_down(map);
		if (status == 1)
			move_type = RIGHT; 
		else move_type = LEFT; 
	}


	Flag();

	if (Check_die(get_monster_pos) == true)
	{
		blood = blood - 0.8;
	}

	if (map[pos_.y / 70][pos_.x / 70] == '3')
	{
		if (blood <= 100)
		{
			blood = blood + 0.1;
		}
		
	}

	if (map[pos_.y / 70][pos_.x / 70] == '1' && time>=240)
	{
		blood = blood - 0.5;
		step = 3;
	}

	if (time <= 240)
	{
		step = 7;
	}

		
}

void Player::drawSnow()
{
	snow.setPosition(pos_.x - 450, pos_.y - 337);
	window->draw(snow);
}

void Player::drawInformation()
{
	heart_sprite.setPosition(pos_.x - 390, pos_.y - 290);
	window->draw(heart_sprite);

	heartBar_sprite.setTextureRect(sf::IntRect(0, 0, blood, 30));
	heartBar_sprite.setPosition(pos_.x - 390 +40, pos_.y - 290);
	window->draw(heartBar_sprite);

	redFlag_sprite.setPosition(pos_.x - 100, pos_.y - 290);
	window->draw(redFlag_sprite);
	sf::Text redFlag(std::to_string(redFlagNumber), font, 20);
	redFlag.setPosition(pos_.x - 60, pos_.y - 290);
	window->draw(redFlag);

	blueFlag_sprite.setPosition(pos_.x + 50, pos_.y - 290);
	window->draw(blueFlag_sprite);
	sf::Text blueFlag(std::to_string(blueFlagNumber), font, 20);
	blueFlag.setPosition(pos_.x + 90, pos_.y - 290);
	window->draw(blueFlag);
}




void Player::Draw()
{
	//draw flag
	for (int i = 0; i < redFlag_pos.size(); i++)
	{
		if (redFlag_pos[i].x >= pos_.x - 500 && redFlag_pos[i].x <= pos_.x + 500 && redFlag_pos[i].y >= pos_.y - 400 && redFlag_pos[i].y <= pos_.y + 400)
		{
		redFlag_sprite.setPosition(redFlag_pos[i]);
		window->draw(redFlag_sprite);
		}
	}

	for (int i = 0; i < blueFlag_pos.size(); i++)
	{
		if (blueFlag_pos[i].x >= pos_.x - 500 && blueFlag_pos[i].x <= pos_.x + 500 && blueFlag_pos[i].y >= pos_.y - 400 && blueFlag_pos[i].y <= pos_.y + 400)
		{
			blueFlag_sprite.setPosition(blueFlag_pos[i]);
			window->draw(blueFlag_sprite);
		}
	}

	

	//draw player
	if(move_type == RIGHT) draw(0);
	if(move_type == LEFT) draw(1);


}


