#include "Transition.h"

void Transition::switchTeams()
{
	int i = 0;
	// seting up to transition between teams
	for (int i = 0; i < 4; i++)
	{
		if (m_PlayerQ.front().at(i).energy == 0)
		{
			std::cout << "no energy" << std::endl;
		}
	}
}
// using this funtion to setup the queues
void Transition::setupQueue(std::vector<Entity> t_entityVector, Enemy t_enemy)
{
	
    m_PlayerQ.push(t_entityVector);
	
	
	
}

Transition::Transition()
{
	
	
}
