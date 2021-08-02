#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include "ScreenSize.h"
class Entity
{
	void movement();
	void energyBar();


	sf::Texture m_playerTexture;
public:
	void update(double dt);
	void render(sf::RenderWindow & t_window);
	int energy = 1000;
	void jumpForward();
	void moveRight();
	void moveLeft();
	void moveUP();
	void moveDown();
	sf::Vector2f jumpVector;
	sf::Sprite m_playerSprites;
	
	bool playerOnesTurn = false;
	bool playerTwoTurn = false;
	bool playerThreeTurn = false;
	bool playerFourTurn = false;
	

	Entity();
	~Entity();

};

