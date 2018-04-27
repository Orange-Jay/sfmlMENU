#include "mainWindow.h"
#include "roles.h"


mainWindow::mainWindow()
{
}


mainWindow::~mainWindow()
{
}
void mainWindow::run()
{
	roles ob1;
	rules ob;
	sf::RenderWindow window(sf::VideoMode(600, 600), "Hello World");
	//test
	Menu menu(window.getSize().x, window.getSize().y);

	sf::Event event;

	sf::Texture texture;
	sf::Texture text;

	sf::Sprite background;
	sf::Sprite logo;
	sf::SoundBuffer buffer;
	//test:music
	sf::Music music;
	if (!music.openFromFile("chick2.ogg"))
	{
		std::cout << "i cannot find. " << std::endl;
	}
	music.setVolume(50);
	music.play();
	music.setLoop(true);

	//test:music
	if (!buffer.loadFromFile("click1.wav"))
	{
		std::cout << "error" << std::endl;
	}
	sf::Sound sound;
	sound.setBuffer(buffer);
	sound.setVolume(10);
	//background info
	if (!texture.loadFromFile("background2.png"))
	{
		std::cout << " i cannot find. " << std::endl;
	}
	else
	{
		std::cout << "It works" << std::endl;
	}

	background.setTexture(texture);
	background.setPosition(-300, 0);

	//background info

	//logo
	if (!text.loadFromFile("plzwork_1.png"))
	{
		std::cout << " i cannot find. " << std::endl;
	}
	else
	{
		std::cout << "It works" << std::endl;
	}

	logo.setTexture(text);
	logo.setPosition(60, -50);


	//logo.setPosition(0, 0);

	//logo
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
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;
				case sf::Keyboard::Down:
					menu.MoveDown();
					break;
				case sf::Keyboard::Return:

					switch (menu.GetPressedItem())
					{
					case 0:
						sound.play();
						std::cout << "Play button has been pressed" << std::endl;

						break;
					case 1:
						sound.play();
						std::cout << "Rules button has been pressed" << std::endl;
						ob.printRules();

						break;
					case 2:
						sound.play();
						std::cout << "Map button has been pressed" << std::endl;
						break;
					case 3:
						sound.play();
						std::cout << "Role button has been pressed" << std::endl;
						ob1.printRoles();
						break;
					case 4:
						sound.play();
						std::cout << "Exit button has been pressed" << std::endl;
						window.close();
						break;

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
		window.draw(logo);
		menu.draw(window);
		window.display();


	}
}