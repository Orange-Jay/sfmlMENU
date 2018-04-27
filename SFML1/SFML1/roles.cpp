#include "roles.h"

roles::roles()
{

}

roles::roles(float width, float height)
{

}


roles::~roles()
{
}
void roles::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}
void roles::printRoles()
{
	sf::Font font;
	if (!font.loadFromFile("fff.ttf"))
	{
		std::cout << " i cannot find." << std::endl;
	}
	else
	{
		std::cout << "it works" << std::endl;
	}
	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile("click.wav"))
	{
		std::cout << "error" << std::endl;
	}
	sf::Sound sound;
	sound.setBuffer(buffer);
	sound.setVolume(10);
	sf::Text text;
	sf::Text row1;
	// TITLE
	text.setFont(font);
	text.setString("Roles");
	text.setCharacterSize(50);
	text.setColor(sf::Color::Red);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text.setPosition(75, 0);
	//TITLE
	//ROW1
	row1.setFont(font);
	row1.setString("Thomas:Movement/UI\nMicah:Camera/Game Logic\nTrent:tilemap/ game logic\nBrian:Menu\n\n\n\nPress A to go back\nto main menu\n");
	row1.setCharacterSize(40);
	row1.setColor(sf::Color::Red);
	row1.setStyle(sf::Text::Bold);
	row1.setPosition(0, 150);
	//ROW1
	sf::RenderWindow window(sf::VideoMode(600, 600), "Roles");
	roles roles(window.getSize().x, window.getSize().y);
	sf::Texture texture;
	sf::Sprite background;

	sf::Texture text1;
	sf::Sprite rules2;
	if (!texture.loadFromFile("farm.jpg"))
	{
		std::cout << " i cannot find. " << std::endl;
	}
	else
	{
		std::cout << "It works" << std::endl;
	}
	background.setTexture(texture);
	background.setPosition(-700, 0);
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
					switch (roles.GetPressedItem())
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
							if (event.text.unicode=='a')
							{
								sound.play();
							}
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

			roles.draw(window);

			window.draw(rules2);
			window.display();
		}
	}
}