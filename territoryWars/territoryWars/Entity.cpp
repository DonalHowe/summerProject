#include "Entity.h"
// the movement for the players
void Entity::movement()
{
	
	
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

}
// for the character to jump
void Entity::jumpForward()
{
	// this is for the player to jump forward
	jumpVector.x,jumpVector.y=m_playerSprites.getPosition().x, m_playerSprites.getPosition().y;
	jumpVector.x=jumpVector.x+3;
	jumpVector.y += jumpVector.y * cos(-30);
	m_playerSprites.setPosition(jumpVector);
	energy--;

}

void Entity::moveRight()
{
	m_playerSprites.setScale(1, 1);
	m_playerSprites.move(1, 0);
	energy--;
}

void Entity::moveLeft()
{
	m_playerSprites.setScale(-1,1);
	m_playerSprites.move(-1, 0);
	energy--;
}

void Entity::moveUP()
{
	m_playerSprites.move(0,-1);
	energy--;
}

void Entity::moveDown()
{
	m_playerSprites.move(0, 1);
	energy--;
}





Entity::Entity()
{
	if (!m_playerTexture.loadFromFile("images/Bear/Walk3.png"))
	{
		std::cout << "cant load sprite" << std::endl;

	}
	m_playerSprites.setTexture(m_playerTexture);
	

	
}

Entity::~Entity()
{
}
