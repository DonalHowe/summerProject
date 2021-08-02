#pragma once
#include <iostream>
#include "Enemy.h"
#include "Entity.h"
#include <queue>
class Transition
{
	std::queue<Enemy> m_enemyQ;
	std::queue<std::vector<Entity>> m_PlayerQ;
public:
	void switchTeams();
	void setupQueue(std::vector<Entity> t_entityVector, Enemy t_enemy);
	Transition();
};

