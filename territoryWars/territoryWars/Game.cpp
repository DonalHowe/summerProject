#include "Game.h"



// Updates per milliseconds
static double const MS_PER_UPDATE = 10.0;




Game::Game() : m_window(sf::VideoMode(ScreenSize::m_width, ScreenSize::m_height, 32), "SFML Playground", sf::Style::Default)
{
	m_window.setVerticalSyncEnabled(true);
	if (!m_backgroundTexture.loadFromFile("images/game_background_1/game_background_1.png"))
	{
		std::cout << "cant load sprite" << std::endl;
	}
	m_backgroundSprite.setTexture(m_backgroundTexture);
	m_backgroundSprite.setScale(.33, .5);
	// putting entities into a vector
	for (int i = 0; i < 4; i++)
	{
		m_playerObjects.push_back(entity);
	}
	m_transition.setupQueue(m_playerObjects, m_enemy);
}

////////////////////////////////////////////////////////////
void Game::run()
{
	sf::Clock clock;
	sf::Int32 lag = 0;

	while (m_window.isOpen())
	{
		sf::Time dt = clock.restart();

		lag += dt.asMilliseconds();

		processEvents();

		while (lag > MS_PER_UPDATE)
		{
			update(lag);
			lag -= MS_PER_UPDATE;
		}
		update(lag);

		render();
	}
}

////////////////////////////////////////////////////////////
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
		processGameEvents(event);
	}
}


////////////////////////////////////////////////////////////
void Game::processGameEvents(sf::Event& event)
{
	// check if the event is a a mouse button release
	if (sf::Event::KeyPressed == event.type)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::Escape:
			m_window.close();
			break;

		case sf::Keyboard::Space:

			
			break;
		
		default:
			break;
		}
	}
}

// the player movement includes jumping 
void Game::playerOneMovement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (entity.playerOnesTurn == true && m_playerObjects.at(0).energy > 0 && playerTurn == true)
		{
			m_playerObjects.at(0).moveLeft();
			
		}
		else if (entity.playerTwoTurn == true && m_playerObjects.at(1).energy > 0 && playerTurn == true)
		{
			m_playerObjects.at(1).moveLeft();
		}
		else if (entity.playerThreeTurn == true && m_playerObjects.at(2).energy > 0 && playerTurn == true)
		{
			m_playerObjects.at(2).moveLeft();
		}
		else if (entity.playerFourTurn == true && m_playerObjects.at(3).energy > 0 && playerTurn == true)
		{
			m_playerObjects.at(3).moveLeft();
		}

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (entity.playerOnesTurn == true && m_playerObjects.at(0).energy > 0 && playerTurn == true)
		{
			m_playerObjects.at(0).moveRight();
		}
		else if (entity.playerTwoTurn == true && m_playerObjects.at(1).energy > 0 && playerTurn == true)
		{
			m_playerObjects.at(1).moveRight();
		}
		else if (entity.playerThreeTurn == true && m_playerObjects.at(2).energy > 0 && playerTurn == true)
		{
			m_playerObjects.at(2).moveRight();
		}
		else if (entity.playerFourTurn == true && m_playerObjects.at(3).energy > 0 && playerTurn == true)
		{
			m_playerObjects.at(3).moveRight();
		}

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (entity.playerOnesTurn == true&&m_playerObjects.at(0).energy>0 && playerTurn == true)
		{
			m_playerObjects.at(0).moveUP();
		}
		else if (entity.playerTwoTurn == true&&m_playerObjects.at(1).energy > 0 && playerTurn == true)
		{
			m_playerObjects.at(1).moveUP();
		}
		else if (entity.playerThreeTurn == true&& m_playerObjects.at(2).energy > 0 && playerTurn == true)
		{
			m_playerObjects.at(2).moveUP();
		}
		else if (entity.playerFourTurn == true && m_playerObjects.at(3).energy > 0 && playerTurn == true)
		{
			m_playerObjects.at(3).moveUP();
		}


	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (entity.playerOnesTurn == true && m_playerObjects.at(0).energy > 0 && playerTurn == true)
		{
			m_playerObjects.at(0).moveDown();
	
		}
		else if (entity.playerTwoTurn == true && m_playerObjects.at(1).energy > 0 && playerTurn == true)
		{
			m_playerObjects.at(1).moveDown();
		}
		else if (entity.playerThreeTurn == true && m_playerObjects.at(2).energy > 0 && playerTurn == true)
		{
			m_playerObjects.at(2).moveDown();
		}
		else if (entity.playerFourTurn == true && m_playerObjects.at(3).energy > 0 && playerTurn == true)
		{
			m_playerObjects.at(3).moveDown();
		}

	}
	// if the players is out of energy
	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			if (entity.playerOnesTurn == true && m_playerObjects.at(0).energy > 0&&playerTurn==true)
			{
				m_playerObjects.at(0).jumpForward();
			
			}
			else if (entity.playerTwoTurn == true && m_playerObjects.at(1).energy > 0 && playerTurn == true)
			{
				m_playerObjects.at(1).jumpForward();
				
			}
			else if (entity.playerThreeTurn == true && m_playerObjects.at(2).energy > 0 && playerTurn == true)
			{
				m_playerObjects.at(2).jumpForward();
				
			}
			else if (entity.playerFourTurn == true && m_playerObjects.at(3).energy > 0 && playerTurn == true)
			{
				m_playerObjects.at(3).jumpForward();
				
			}
		}
	
}

void Game::enemymovement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_enemy.moveLeft();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_enemy.moveRight();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_enemy.moveUp();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_enemy.moveDown();
	}
}

////////////////////////////////////////////////////////////
void Game::update(double dt)
{
	if (m_menu.switchToGamePlay == true)
	{
		m_states = gameStates::gamePlayeState;
		
	}

	if (m_states == gameStates::menuState)
	{
		m_menu.update(dt);
	}
	else if (m_states == gameStates::gamePlayeState)
	{
		entity.update(dt);
		m_enemy.update(dt);
		theflooring.update(dt);
		playerTransition.update(dt);
		if (m_playerObjects.at(0).energy == 0 && m_playerObjects.at(1).energy == 0 && m_playerObjects.at(2).energy == 0 && m_playerObjects.at(3).energy == 0)
		{
			//std::cout << "all players out of energy" << std::endl;;
			enemyTurn = true;
			playerTurn = false;
		}
		//m_transition.switchTeams();
		if (playerTurn == true)
		{
			playerOneMovement();
		}
		else if (enemyTurn == true)
		{
			enemymovement();
		}
		
	
	}
	else if (m_states == gameStates::lossState)
	{

	}
	else if (m_states == gameStates::winState)
	{

	}

	

}


////////////////////////////////////////////////////////////
void Game::render()
{
	m_window.clear(sf::Color(0, 0, 0, 0));

	if (m_states == gameStates::menuState)
	{
		m_menu.render(m_window);
	}
	else if (m_states == gameStates::gamePlayeState)
	{
		m_window.draw(m_backgroundSprite);
		entity.render(m_window);
		theflooring.render(m_window);
		playerTransition.render(m_window);
		for (int i = 0; i < 4; i++)
		{
			m_window.draw(m_playerObjects.at(i).m_playerSprites);
		}
		m_window.draw(m_enemy.GetSprite());
	}
	else if (m_states == gameStates::lossState)
	{

	}
	else if (m_states == gameStates::winState)
	{

	}
	
	

	m_window.display();
};





