#pragma once

#include <SFML/Graphics.hpp>
#include "MainMenu.h"
#include "ScreenSize.h"
#include "Entity.h"
#include "Floor.h"
#include "SwitchPlayer.h"
#include "Enemy.h"
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
	Enemy m_enemy;
	SwitchPlayer playerTransition;
	void run();
	Floor theflooring;
	MainMenu m_menu;
	gameStates m_states{ gameStates::menuState };
	Entity entity;
	std::vector<Entity> m_playerObjects;
	sf::Texture m_backgroundTexture;
	sf::Sprite m_backgroundSprite;
	bool enemyTurn = false;
	bool playerTurn = true;
	void playerOneMovement();
	void enemymovement();
protected:
	
	
	void update(double dt);
	
	void render();

	sf::RenderWindow m_window;
	void processEvents();
	

 

	void processGameEvents(sf::Event&);



};
