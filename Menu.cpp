#include "pch.h"
#include "Menu.h"
#include <iostream>


Menu::Menu(float t_Width, float t_Height)
{
	if (!font.loadFromFile("OpenSans-Regular.ttf"))
		std::cout << "Error: Can't load font";

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Play");
	//menu[0].setPosition(sf::Vector2f(t_Width / 2.20, t_Height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
	menu[0].setPosition(sf::Vector2f((t_Width/2)-(menu[0].getLocalBounds().width/2), t_Height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::Black);
	menu[1].setString("Exit");
	menu[1].setPosition(sf::Vector2f((t_Width / 2) - (menu[1].getLocalBounds().width / 2), t_Height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	/*menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::Black);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(t_Width / 2.20, t_Height / (MAX_NUMBER_OF_ITEMS + 1) * 3));*/


	selectedItemIndex = 0;

	
}


Menu::~Menu()
{
}


void Menu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}


void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::Black);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::Black);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}