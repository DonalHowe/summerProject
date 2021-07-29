#include "Entity.h"

void Entity::movement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		spriteVector.at(0).move(-1,0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		spriteVector.at(0).move(1, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		spriteVector.at(0).move(0, -1);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		spriteVector.at(0).move(0, 1);
	}
	
}

void Entity::energyBar()
{
	
	
}

void Entity::update(double dt)
{
	energyBar();
	movement();
	
}

void Entity::render(sf::RenderWindow& t_window)
{

	
	for (int i = 0; i < 4; i++)
	{
		t_window.draw(spriteVector.at(i));
	}
}

Entity::Entity()
{
	if (!m_playerTexture.loadFromFile("images/Bear/Walk3.png"))
	{
		std::cout << "cant load sprite" << std::endl;

	}
	m_playerSprites.setTexture(m_playerTexture);
	for (int i = 0; i < 4; i++)
	{
		spriteVector.push_back(m_playerSprites);
	}

	
}

Entity::~Entity()
{
}
