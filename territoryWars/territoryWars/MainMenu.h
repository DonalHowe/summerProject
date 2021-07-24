#pragma once
#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"
#include "ScreenSize.h"
enum sceneSwicther {
	mainScreen,
	instructions,
	credits,
	mapControl,
	GamePlay
};
class MainMenu
{
	sceneSwicther scenes{ sceneSwicther::mainScreen };

	const static int MAX_RECTS = 4;
	int m_rectYpos = 100;
	sf::Font m_font;
	sf::Text menuText;
	sf::Text instructionsText;
	sf::Text mapControlText;
	sf::Text creditsText;
	
	bool mouseClick = false;
	bool mouseUnClick = false;
	void setupText();
	void sceneMove();
public:
	bool switchToGamePlay = false;
	void render(sf::RenderWindow &t_window);
	void update(double dt);
	MainMenu();
	~MainMenu();
private:
	sf::RectangleShape m_rectangles[MAX_RECTS];
};

