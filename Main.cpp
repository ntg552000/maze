#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Windows.h>
#include <iostream>
#include "Object.h"
#include "Player.h"
#include "Map.h"
#include "Animation.h"
#include "Monster.h"
#include "ClockGame.h"
#include "Menu.h"

// create the window
sf::RenderWindow window(sf::VideoMode(800, 600), "MAZE Nguyen Truong Giang CACLC1");



void newGame(sf::RenderWindow* window)
{
	sf::View currentView = window->getView();
	
	Map maze(window, "Map\\map.txt");
	Player player(window);
	Monster monster(window, maze.get_map());

	sf::Font font;
	font.loadFromFile("font.ttf");
	

	sf::View view;
	view.setSize(800, 600);

	sf::Clock clock; // starts the clock

	ClockGame clockGame(window, &clock);
	int time = -1;

	bool pressed = 0;

	// run the program as long as the window is open
	while (window->isOpen())
	{
	

		if (clockGame.getTime() >= 270)
		{
			clock.restart();
		}

		if (player.get_blood() == 0)
		{
			break;
		}

		view.setCenter(player.get_pos());
		window->setView(view);
		// clear the window with black color
		window->clear(sf::Color::Black);

		//update
		player.Update(maze.get_map(), monster.get_monster_pos(), clockGame.getTime());
		monster.Update(maze.get_map(), player.get_pos());

		// draw 
		maze.Draw(player.get_pos());
		player.Draw();
		monster.Draw(player.get_pos());
		maze.Draw_road(player.get_pos());
		if (maze.get_map()[player.get_pos().y / 70][player.get_pos().x / 70] == '1' && clockGame.getTime() >= 240)
		{
			player.drawSnow();
		}
		player.drawInformation();

		if (clockGame.getTime() >= 240)
		{
			sf::Text text(std::to_string(270-clockGame.getTime()), font, 25);
			text.setPosition(player.get_pos().x + 360, player.get_pos().y - 280);
			text.setFillColor(sf::Color::Red);
			window->draw(text);
		}
		else
		{
			sf::Text text(std::to_string(clockGame.getTime()), font, 25);
			text.setPosition(player.get_pos().x + 360, player.get_pos().y - 280);
			window->draw(text);
		}

		
		// end the current frame
		window->display();

	}
	window->setView(currentView);
}


int main()
{
	sf::Texture Texture1_;
	Texture1_.loadFromFile("Image\\dead.png");
	sf::Sprite Sprite1_(Texture1_);

	sf::Music music;
	music.openFromFile("Audio/menu.ogg");
	music.play();
	
	srand(time(NULL));

	window.setFramerateLimit(70);

	Menu menu(&window);
	sf::Event Events;
	
//	DrawOver(&window);
	

	while (window.isOpen())
	{
		while (window.pollEvent(Events))
		{
		}
		window.clear(sf::Color::Blue);
		menu.draw(0);
		window.display();
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			music.openFromFile("Audio/gameAudio.ogg");
			music.play();
			music.setLoop(true);
			newGame(&window);	
			while (true)
			{ 
				window.clear();
				window.draw(Sprite1_);
				window.display();
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					break;
				}
			}
		}
	}
	
	
	return 0;
}