#pragma once

#include <SFML/Graphics.hpp>
#include "MainMenu.h"
#include "ScreenSize.h"
#include "Entity.h"
#include "Floor.h"
#include "SwitchPlayer.h"
enum class gameStates
{
	menuState,
	gamePlayeState,
	winState,
	lossState
};

class Game
{
public:
	
	Game();
	SwitchPlayer playerTransition;
	void run();
	Floor theflooring;
	MainMenu m_menu;
	gameStates m_states{ gameStates::menuState };
	Entity entity;
protected:
	
	
	void update(double dt);
	
	void render();

	sf::RenderWindow m_window;
	void processEvents();
	

 

	void processGameEvents(sf::Event&);



};