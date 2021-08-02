#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
class Enemy
{
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	
	
	int m_hp;
	sf::Vector2f m_position;
	void setupSprite();
	void movement();
	
public:
	sf::Sprite GetSprite();
	void update(double dt);
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	Enemy();
};

