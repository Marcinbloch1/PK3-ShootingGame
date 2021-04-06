#include "pch.h"
#include "Functions.h"

template <class T1, class T2> bool isIntersecting(T1 &a, T2 &b)
{
	return a.right() >= b.left()
		&& a.left() <= b.right()
		&& a.bottom() >= b.top()
		&& a.top() <= b.bottom();
}

bool collisionTest(Player &player, Scoreblock &scoreblock, int &scores, int &scores_iterator)
{
	if (!isIntersecting(player, scoreblock)) return false;
	else
	{
		scoreblock.gain();
		scores++;
		scores_iterator++;
	}
}

bool collisionTest(Floor &floor, Scoreblock &scoreblock, int &lives)
{
	if (!isIntersecting(floor, scoreblock)) return false;

	else
	{
		scoreblock.gain();
		lives--;
	}
}

void load_game_texts(Text & score_info, Text & lives_info, Text & starting_text, Text & ending_text)
{
	score_info.setFillColor(Color::Black);
	score_info.setCharacterSize(30);
	score_info.setPosition(200, 10);

	lives_info.setFillColor(Color::Red);
	lives_info.setCharacterSize(30);
	lives_info.setPosition(30, 10);

	starting_text.setFillColor(Color::Black);
	starting_text.setCharacterSize(40);
	starting_text.setPosition(sf::Vector2f((1200 / 2) - (starting_text.getLocalBounds().width / 2), 200));

	ending_text.setFillColor(Color::Black);
	ending_text.setCharacterSize(40);
}

void end_game(Event event, RenderWindow & window, int & scores, Text ending_text)
{
	while (event.type != Event::MouseButtonPressed)
	{
		window.clear(Color::White);
		window.pollEvent(event);
		std::stringstream ss3;
		ss3 << scores;
		ending_text.setString("Your score: " + ss3.str() + "\nClick your mouse on window to end...");
		ending_text.setPosition(sf::Vector2f((1200 / 2) - (ending_text.getLocalBounds().width / 2), 200));
		window.draw(ending_text);
		if (event.type == Event::Closed)
		{
			window.close();
			break;
		}
		window.display();
	}
}
