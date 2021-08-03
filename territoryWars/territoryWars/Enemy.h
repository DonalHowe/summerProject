#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
class Enemy
{
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	
	int m_energy;
	int m_hp=10;
	bool m_alive = true;
	sf::Vector2f m_position;
	void setupSprite();
	void movement();
	
public:
	void setEnergy(int t_energy);
	bool getAlive();
	int GetEnergy();
	sf::Sprite GetSprite();
	void update(double dt);
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	Enemy();
};

