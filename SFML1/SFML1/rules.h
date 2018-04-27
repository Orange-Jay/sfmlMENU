#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>
#include "SFML\Audio.hpp"
#define MAX_NUMBER_OF_ITEMS 1
class rules
{
public:
	rules();
	rules(float width, float height);
	~rules();
	void printRules();
	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }
private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
	
};

