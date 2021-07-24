#include "MainMenu.h"

void MainMenu::setupText()
{
	menuText.setFont(m_font);
	menuText.setString(" GAME ");
	menuText.setPosition(100, 100);
	menuText.setCharacterSize(75u);
	menuText.setFillColor(sf::Color::Green);

	creditsText.setFont(m_font);
	creditsText.setString(" credits ");
	creditsText.setPosition(100, 550);
	creditsText.setCharacterSize(75u);
	creditsText.setFillColor(sf::Color::Cyan);

	instructionsText.setFont(m_font);
	instructionsText.setString(" INSTRUCTIONS ");
	instructionsText.setPosition(100, 250);
	instructionsText.setCharacterSize(65u);
	instructionsText.setFillColor(sf::Color::Cyan);

	mapControlText.setFont(m_font);
	mapControlText.setString(" MAP ");
	mapControlText.setPosition(100, 400);
	mapControlText.setCharacterSize(75u);
	mapControlText.setFillColor(sf::Color::Green);
}

void MainMenu::sceneMove()
{
	
	//269 371
	sf::Vector2i m_mouse = sf::Mouse::getPosition();
	//std::cout << "xpos " << m_mouse.x << " , " << " ypos " << m_mouse.y << std::endl;
	//switch to gameplay
	if (m_mouse.x > 466 && m_mouse.x<766)
	{
		if (m_mouse.y > 269 && m_mouse.y < 371)
		{
			std::cout << "Game" << std::endl;
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				scenes = sceneSwicther{ sceneSwicther::GamePlay };
			     switchToGamePlay = true;
			}
		}
	}
	//switch to instructions
	if (m_mouse.x > 466 && m_mouse.x < 766)
	{
		if (m_mouse.y > 420 && m_mouse.y < 522)
		{
			std::cout << "instructions" << std::endl;
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				scenes = sceneSwicther{ sceneSwicther::instructions };
			}
		}
	}
	//switch to mapControl
	if (m_mouse.x > 466 && m_mouse.x < 766)
	{
		if (m_mouse.y > 570 && m_mouse.y < 671)
		{
			std::cout << "mapControl" << std::endl;
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				scenes = sceneSwicther{ sceneSwicther::mapControl };
			}
		}
	}
	//switch to credits
	if (m_mouse.x > 466 && m_mouse.x < 766)
	{
		if (m_mouse.y > 720 && m_mouse.y < 821)
		{
			std::cout << "credits" << std::endl;
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				scenes = sceneSwicther{ sceneSwicther::credits };
			}
		}
	}
}

void MainMenu::render(sf::RenderWindow& t_window)
{
	if (scenes == sceneSwicther::mainScreen)
	{
		for (int i = 0; i < MAX_RECTS; i++)
		{
			t_window.draw(m_rectangles[i]);
		}
		t_window.draw(menuText);
		t_window.draw(creditsText);
		t_window.draw(mapControlText);
		t_window.draw(instructionsText);
	}
	else if (scenes == sceneSwicther::credits)
	{

	}
	else if (scenes == sceneSwicther::instructions)
	{

	}
	else if (scenes == sceneSwicther::mapControl)
	{

	}
}

void MainMenu::update(double dt)
{
	sceneMove();
}

MainMenu::MainMenu()
{
	setupText();
	for (int i = 0; i < MAX_RECTS; i++) {
		m_rectangles[i].setSize(sf::Vector2f{ 300,100 });
		if (i % 2 == 0)
		{
			m_rectangles[i].setFillColor(sf::Color::Red);

		}
		else
		{
			m_rectangles[i].setFillColor(sf::Color::Blue);
		}
		m_rectangles[i].setPosition(100, m_rectYpos);
		m_rectYpos += 150;
	}
	if (!m_font.loadFromFile("rescources/fonts/BebasNeue.otf"))
	{
		std::cout << "cant load font" << std::endl;
	
	}

}

MainMenu::~MainMenu()
{
}
