#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "EnemyProjectile.h"
class Enemy
{
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	EnemyProjectile m_projectile;
	int m_energy;
	int m_hp=10;
	bool m_alive = true;
	sf::Vector2f m_position;
	void setupSprite();
	void movement();
	bool hasShot = false;
public:
	void setBulletShot(bool t_hasShot);
	bool getHasShot();
	EnemyProjectile getProjectile();
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

