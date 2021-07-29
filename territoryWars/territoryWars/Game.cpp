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
		theflooring.update(dt);
		playerTransition.update(dt);
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
		
	}
	else if (m_states == gameStates::lossState)
	{

	}
	else if (m_states == gameStates::winState)
	{

	}
	
	

	m_window.display();
};





