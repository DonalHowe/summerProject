#include "Entity.h"

void Entity::movement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_playerMoving = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_player.move(1, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_player.move(0, -1);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_player.move(0, 1);
	}
	else
	{
		m_playerMoving = false;
	}
}

void Entity::energyBar()
{
	if (m_playerMoving == true)
	{
		m_energy.setSize(sf::Vector2f{ m_energyXsize,m_energyYsize });

		m_energyXsize += 2.9;
		if (m_energyXsize > 200)
		{
			m_energyXsize = 10;
		}
	}
	
}

void Entity::update(double dt)
{
	energyBar();
	movement();
}

void Entity::render(sf::RenderWindow& t_window)
{

	t_window.draw(m_energy);
}

Entity::Entity()
{
	m_energy.setFillColor(sf::Color::Blue);
	m_energy.setPosition(50, 600);
	m_player.setSize(sf::Vector2f{ 50,50 });
	m_player.setFillColor(sf::Color::Red);
	m_player.setPosition(ScreenSize::m_width / 2, ScreenSize::m_height / 2);
}

Entity::~Entity()
{
}
