#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>
#include "ScreenSize.h"
class Floor
{
	const static int MAX_TILES = 5;
	sf::Sprite m_tiles;
	sf::Texture tTexture;
	std::vector<sf::Sprite> m_floors;
	void createTile();
	void tileSpacing();
public:
	Floor();
	~Floor();
	std::vector<sf::Sprite> getFloor();
	void update(double dt);
	void render(sf::RenderWindow& t_window);

};

