#include "Entity.h"
// the movement for the players
void Entity::movement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (playerOnesTurn == true)
		{
			spriteVector.at(0).move(-1, 0);
		}
		else if (playerTwoTurn == true)
		{
			spriteVector.at(1).move(-1, 0);
		}
		else if (playerThreeTurn == true)
		{
			spriteVector.at(2).move(-1, 0);
		}
		else if (playerFourTurn == true)
		{
			spriteVector.at(3).move(-1, 0);
		}
	
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (playerOnesTurn == true)
		{
			spriteVector.at(0).move(1, 0);
		}
		else if (playerTwoTurn == true)
		{
			spriteVector.at(1).move(1, 0);
		}
		else if (playerThreeTurn == true)
		{
			spriteVector.at(2).move(1, 0);
		}
		else if (playerFourTurn == true)
		{
			spriteVector.at(3).move(1, 0);
		}
		
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (playerOnesTurn == true)
		{
			spriteVector.at(0).move(0, -1);
		}
		else if (playerTwoTurn == true)
		{
			spriteVector.at(1).move(0, -1);
		}
		else if (playerThreeTurn == true)
		{
			spriteVector.at(2).move(0, -1);
		}
		else if (playerFourTurn == true)
		{
			spriteVector.at(3).move(0, -1);
		}

		
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (playerOnesTurn == true)
		{
			spriteVector.at(0).move(0, 1);
		}
		else if (playerTwoTurn == true)
		{
			spriteVector.at(1).move(0, 1);
		}
		else if (playerThreeTurn == true)
		{
			spriteVector.at(2).move(0, 1);
		}
		else if (playerFourTurn == true)
		{
			spriteVector.at(3).move(0, 1);
		}

	}
	
}
// the players energy bar
void Entity::energyBar()
{
	
	
}

void Entity::update(double dt)
{
	energyBar();
	movement();
	//handles teh switching between the players
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		playerOnesTurn = true;
		playerTwoTurn = false;
		playerThreeTurn = false;
		playerFourTurn = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{

		playerOnesTurn = false;
		playerTwoTurn = true;
		playerThreeTurn = false;
		playerFourTurn = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{

		playerOnesTurn = false;
		playerTwoTurn = false;
		playerThreeTurn = true;
		playerFourTurn = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{

		playerOnesTurn = false;
		playerTwoTurn = false;
		playerThreeTurn = false;
		playerFourTurn = true;
	}
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
