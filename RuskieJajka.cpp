// RuskieJajka.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
//#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Player.h"
#include "Scoreblock.h"
#include "Floor.h"
#include "Menu.h"
#include "Mainclass.h"
#include "Functions.h"
#include "vld.h"

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 800

using namespace sf;
using namespace std;



int scores = 0, lives=2, scores_iterator;
float vel_for_scoreblock = 5.0f;



int main()
{
	srand(time(NULL));								//random num

	RenderWindow window{ VideoMode{SCREEN_WIDTH, SCREEN_HEIGHT}, "Ruskie Jaja" };		//rendering window
	window.setFramerateLimit(60);														//set framerate
	Event event;																		//declaring an event
	Player player1(SCREEN_WIDTH / 2, SCREEN_HEIGHT);									//creating object type player
	Floor floor1(SCREEN_WIDTH / 2, SCREEN_HEIGHT, SCREEN_WIDTH, 1);						//creating object type floor

	unsigned scoreblockWidth{ 30 }, scoreblockHeight{ 30 };
	int rand_position_x = rand() % (SCREEN_WIDTH-20)+10;
	Scoreblock *scoreblock1 = new Scoreblock(rand_position_x, 0, scoreblockWidth, scoreblockHeight);

	
	Font font;
	font.loadFromFile("OpenSans-Regular.ttf");
	Text score_info("", font);
	Text lives_info("", font);
	Text starting_text("Press any key to play...", font);
	Text ending_text("", font);
	load_game_texts(score_info, lives_info, starting_text, ending_text);

	window.clear(Color::White);
	window.pollEvent(event);

	while (event.type != Event::KeyPressed)
	{
		window.pollEvent(event);
		window.draw(starting_text);
		if (event.type == Event::Closed)
		{
			window.close();
			break;
		}
		window.display();
	}

	while (true)
	{
		window.clear(Color::White);
		window.pollEvent(event);

		if (event.type == Event::Closed)
		{
			delete scoreblock1;
			window.close();
			break;
		}

		player1.update(SCREEN_WIDTH);
		window.draw(player1);
		window.draw(floor1);
		scoreblock1->update();
		window.draw(*scoreblock1);
		

		std::stringstream ss1;
		ss1 << lives;
		lives_info.setString("Lives: " + ss1.str());
		window.draw(lives_info);

		std::stringstream ss2;
		ss2 << scores;
		score_info.setString("Score: " + ss2.str());
		window.draw(score_info);

		if (lives == 0)
		{
			end_game(event, window, scores, ending_text);
			delete scoreblock1;
			window.close();
			break;
		}

		if (collisionTest(player1, *scoreblock1, scores, scores_iterator) || collisionTest(floor1, *scoreblock1, lives))
		{
			delete scoreblock1;
			rand_position_x = rand() % (SCREEN_WIDTH-20)+10;
			if (scores_iterator == 3)
			{
				vel_for_scoreblock++;
				scores_iterator = 0;
			}
			scoreblock1 = new Scoreblock(rand_position_x, 0, scoreblockWidth, scoreblockHeight);
			scoreblock1->change_speed(vel_for_scoreblock);
		}
		window.display();
	}
	return 0;
}