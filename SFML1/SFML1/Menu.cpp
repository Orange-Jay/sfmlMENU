#include "Menu.h"



Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		//handle error
	}
	//play
	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Magenta);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(265,350));
	menu[0].setCharacterSize(50);
	
	//rules
	menu[1].setFont(font);
	menu[1].setColor(sf::Color::White);
	menu[1].setString("Rules");
	menu[1].setPosition(sf::Vector2f(265, 400));
	menu[1].setCharacterSize(50);
	//Maps
	menu[2].setFont(font);
	menu[2].setColor(sf::Color::White);
	menu[2].setString("Maps");
	menu[2].setPosition(sf::Vector2f(265, 450));
	menu[2].setCharacterSize(50);
	//roles
	menu[3].setFont(font);
	menu[3].setColor(sf::Color::White);
	menu[3].setString("Roles");
	menu[3].setPosition(sf::Vector2f(265, 500));
	menu[3].setCharacterSize(50);
	//quit
	menu[4].setFont(font);
	menu[4].setColor(sf::Color::White);
	menu[4].setString("Exit");
	menu[4].setPosition(sf::Vector2f(265, 550));
	menu[4].setCharacterSize(50);
	
	
	
	
	
	
	
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
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(sf::Color::Magenta);
	}
}
void Menu::MoveDown()
{
	if (selectedItemIndex + 1 <MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(sf::Color::Magenta);
	}
}