#include "Monster.h"



void Monster::Random_monster(std::vector<std::string> map)
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			int a1 = i * 700;
		
			int a2 = j * 700;

			while (true)
			{
				int x = rand() % 700 + a1;
				int y = rand() % 700 + a2;
				if (map[y / 70][x / 70] == '1' && map[y / 70][(x + 25 - 1) / 70] == '1' && map[(y + 25 - 1) / 70][x / 70] == '1' && map[(y + 25 - 1) / 70][(x + 25 - 1) / 70] == '1')
				{
					monster_pos.push_back(sf::Vector2f(x, y));

					int c = rand() % 4 + 1;
					if (c == 1)
					{
						status.push_back("UP_LEFT");
					}
					if (c == 2)
					{
						status.push_back("UP_RIGHT");
					}
					if (c == 3)
					{
						status.push_back("DOWN_LEFT");
					}
					if (c == 4)
					{
						status.push_back("DOWN_RIGHT");
					}
					break;
				}
			}
		}
	}
}



Monster::Monster(sf::RenderWindow *window, std::vector<std::string> map)
{
	this->window = window;
	this->Frame = 0;

	column = 0; line = 0;

	width = 2048/15; height = 227;

	count = 15;

	speed = 0.03;

	for (int i = 0; i < count; i++)
		this->Frames.push_back(sf::IntRect(column + width * i, line, width, height));
	
	step = 2;

	Random_monster(map);
	

	
	this->Texture_.loadFromFile("Image\\fire.png");
	this->Sprite_.setTexture(Texture_);
	this->Sprite_.setTextureRect(this->Frames[0]);
	this->Sprite_.setScale(0.29296875, 0.26431718062);
	Sprites_.push_back(Sprite_);
	
}


Monster::~Monster()
{
}


void Monster::Move(std::vector<std::string> map, int i)
{
	if (status[i] == "UP_LEFT")
	{
		if (map[monster_pos[i].y / 70][(monster_pos[i].x - step) / 70] == '1' &&  map[(monster_pos[i].y + 25 - 1) / 70][(monster_pos[i].x - step) / 70] == '1') //check left
		{
			monster_pos[i].x = monster_pos[i].x - step;
		}
		else
		{
			int a = (monster_pos[i].x - step) / 70 + 1;
			monster_pos[i].x = a * 70;
			status[i] = "UP_RIGHT";
		}
		if (map[(monster_pos[i].y - step) / 70][monster_pos[i].x / 70] == '1' &&  map[(monster_pos[i].y - step) / 70][(monster_pos[i].x + 25 - 1) / 70] == '1') //check up
		{
			monster_pos[i].y = monster_pos[i].y - step;
		}
		else
		{
			int a = (monster_pos[i].y - step) / 70 + 1;
			monster_pos[i].y = a * 70;
			status[i] = "DOWN_LEFT";
		}
	}

	
	
	if (status[i] == "UP_RIGHT")
	{
		if (map[monster_pos[i].y / 70][(monster_pos[i].x + 25 + step - 1) / 70] == '1' &&  map[(monster_pos[i].y + 25 - 1) / 70][(monster_pos[i].x + 25 + step - 1) / 70] == '1') //check right
		{
			monster_pos[i].x = monster_pos[i].x + step;
		}
		else
		{
			int a = (monster_pos[i].x + 25 + step) / 70;
			monster_pos[i].x = a * 70 - 25;
			status[i] = "UP_LEFT";
		}
		if (map[(monster_pos[i].y - step) / 70][monster_pos[i].x / 70] == '1' &&  map[(monster_pos[i].y - step) / 70][(monster_pos[i].x + 25 - 1) / 70] == '1') //check up
		{
			monster_pos[i].y = monster_pos[i].y - step;
		}
		else
		{
			int a = (monster_pos[i].y - step) / 70 + 1;
			monster_pos[i].y = a * 70;
			status[i] = "DOWN_RIGHT";
		}
	}



	if (status[i] == "DOWN_LEFT")
	{
		if (map[monster_pos[i].y / 70][(monster_pos[i].x - step) / 70] == '1' &&  map[(monster_pos[i].y + 25 - 1) / 70][(monster_pos[i].x - step) / 70] == '1') //check left
		{
			monster_pos[i].x = monster_pos[i].x - step;
		}
		else
		{
			int a = (monster_pos[i].x - step) / 70 + 1;
			monster_pos[i].x = a * 70;
			status[i] = "DOWN_RIGHT";
		}
		if (map[(monster_pos[i].y + 25 + step - 1) / 70][monster_pos[i].x / 70] == '1' &&  map[(monster_pos[i].y + 25 + step - 1) / 70][(monster_pos[i].x + 25 - 1) / 70] == '1') //check down
		{
			monster_pos[i].y = monster_pos[i].y + step;
		}
		else
		{
			int a = (monster_pos[i].y + 25 + step) / 70;
			monster_pos[i].y = a * 70 - 25;
			status[i] = "UP_LEFT";
		}
	}



	if (status[i] == "DOWN_RIGHT")
	{
		if (map[monster_pos[i].y / 70][(monster_pos[i].x + 25 + step - 1) / 70] == '1' &&  map[(monster_pos[i].y + 25 - 1) / 70][(monster_pos[i].x + 25 + step - 1) / 70] == '1') //check right
		{
			monster_pos[i].x = monster_pos[i].x + step;
		}
		else
		{
			int a = (monster_pos[i].x + 25 + step) / 70;
			monster_pos[i].x = a * 70 - 25;
			status[i] = "DOWN_LEFT";
		}
		if (map[(monster_pos[i].y + 25 + step - 1) / 70][monster_pos[i].x / 70] == '1' &&  map[(monster_pos[i].y + 25 + step - 1) / 70][(monster_pos[i].x + 25 - 1) / 70] == '1') //check down
		{
			monster_pos[i].y = monster_pos[i].y + step;
		}
		else
		{
			int a = (monster_pos[i].y + 25 + step) / 70;
			monster_pos[i].y = a * 70 - 25;
			status[i] = "UP_RIGHT";
		}
	}
}


void Monster::Update(std::vector<std::string> map, sf::Vector2f pos_)
{
	for (int i = 0; i < monster_pos.size(); i++)
	{
		if (monster_pos[i].x >= pos_.x - 1400 && monster_pos[i].x <= pos_.x + 1400 && monster_pos[i].y >= pos_.y - 1400 && monster_pos[i].y <= pos_.y + 1400)
		{
			Move(map,i);
		}
		
	}
	
}

void Monster::Draw(sf::Vector2f pos_)
{
	for (int i = 0; i < monster_pos.size(); i++)
	{
		if (monster_pos[i].x >= pos_.x - 500 && monster_pos[i].x <= pos_.x + 500 && monster_pos[i].y >= pos_.y - 500 && monster_pos[i].y <= pos_.y + 500)
		{
			Sprites_[0].setPosition(monster_pos[i]);
			draw(0);
		}
	}
	
}





























