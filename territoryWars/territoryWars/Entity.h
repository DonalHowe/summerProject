#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include "ScreenSize.h"
class Entity
{
	void movement();
	void energyBar();
public:
	void update(double dt);
	void render(sf::RenderWindow & t_window);
	sf::Texture m_playerTexture;
	sf::Sprite m_playerSprites;
	std::vector<sf::Sprite> spriteVector;
	sf::RectangleShape m_energy;
	bool m_playerMoving = false;
	float m_energyXsize = 10;
	float m_energyYsize = 10;
	bool playerOnesTurn = false;
	bool playerTwoTurn = false;
	bool playerThreeTurn = false;
	bool playerFourTurn = false;

	Entity();
	~Entity();

};

