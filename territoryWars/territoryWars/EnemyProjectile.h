#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

class EnemyProjectile
{
	void movement();
	sf::Sprite m_sprite;
	sf::Texture m_texture;

public:
	sf::Sprite m_getSprite();
	EnemyProjectile();
	void update(double dt);

};

