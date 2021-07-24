#pragma once
#include <list>
#include <queue>
#include"SFML/Graphics.hpp"
#include "Entity.h"
class SwitchPlayer
{
	Entity m_entity;
	std::vector<Entity> m_characters;
	std::queue<std::vector<Entity>> entityQueue;
public:
	SwitchPlayer();
	~SwitchPlayer();
	void update(double dt);
	void render(sf::RenderWindow& t_window);
	std::queue<std::vector<Entity>> getQueue();
};

