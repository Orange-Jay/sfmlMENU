#include "rules.h"


rules::rules()
{

}


rules::rules(float width, float height)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		//handle error
	}
	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Red);
	
	menu[0].setString("Press 'A' key to return to menu" );
	menu[0].setPosition(sf::Vector2f(0, 500));

	menu[0].setCharacterSize(40);
	
	
	selectedItemIndex = 0;
}
void rules::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

rules::~rules()
{
}
void rules::printRules()
{
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
		std::cout << " i cannot find." << std::endl;
	}
	else
	{
		std::cout << "it works" << std::endl;
	}
	sf::Text text;
	sf::Text row1;
	// TITLE
	text.setFont(font);
	text.setString("Rules to Farm Wars");
	text.setCharacterSize(50);
	text.setColor(sf::Color::Red);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text.setPosition(75, 0);
	//TITLE
	//ROW1
	row1.setFont(font);
	row1.setString("1.Controls are W-A-S-D\n2.The highlighted blue boxes are where the units can go\nRed boxes are where the unit can attack\n4.Depending on the unit\nthe attack and potential distance is different\n5.Information relating to each unit will be shown on the top left screen\n6.The side that loses all units first loses");
	row1.setCharacterSize(20);
	row1.setColor(sf::Color::Red);
	row1.setStyle(sf::Text::Bold);
	row1.setPosition(0, 100);
	//ROW1



	sf::RenderWindow window(sf::VideoMode(600, 600), "Rules");


	rules rules(window.getSize().x, window.getSize().y);
	sf::Texture texture;
	sf::Sprite background;

	sf::Texture text1;
	sf::Sprite rules2;

	if (!texture.loadFromFile("background1.jpg"))
	{
		std::cout << " i cannot find. " << std::endl;
	}
	else
	{
		std::cout << "It works" << std::endl;
	}

	background.setTexture(texture);
	background.setPosition(-300, 0);
	if (!text1.loadFromFile("rules.png"))
	{
		std::cout << " i cannot find. " << std::endl;
	}
	else
	{
		std::cout << "It works" << std::endl;
	}

	rules2.setTexture(text1);
	rules2.setPosition(60, 0);
	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::EventType::Closed)
			{
				window.close();
			}
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Return:
					switch (rules.GetPressedItem())
					{
					case 0:
						std::cout << "Press the 'A' key to return to main menu" << std::endl;
						break;
					case sf::Event::TextEntered:
						if (event.text.unicode < 128)
						{

							//why the fuck does 'A'||'a' key close the window
							//i guess i will use this as an intended implementation


							//std::cout << (char)event.text.unicode; ﻿
							printf("%49[^\n]", event.text.unicode);
						}
					

					}
					break;
				case sf::Event::Closed:
					window.close();
					break;
				}
			}

			window.clear();
			window.draw(background);
			//draw 
			//window.draw(text);
			window.draw(row1);
			//draw
			//rules2.setcha

			rules.draw(window);

			window.draw(rules2);
			window.display();
		}
	}

}