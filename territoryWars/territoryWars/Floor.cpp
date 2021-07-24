#include "Floor.h"

void Floor::createTile()
{
    m_tile.setSize(sf::Vector2f{ 100,20 });
    m_tile.setFillColor(sf::Color::Magenta);
    for (int i = 0; i < MAX_TILES; i++)
    {
        m_floors.push_back(m_tile);
    }
}

void Floor::tileSpacing()
{
    srand(time(nullptr));
  
    for (int i = 0; i < MAX_TILES; i++)
    {
        m_floors.at(i).setPosition(rand() % ScreenSize::m_width - 100 , rand() % ScreenSize::m_height - 20);
      
    }
}

Floor::Floor()
{
    createTile();
    tileSpacing();
}

Floor::~Floor()
{
}

std::vector<sf::RectangleShape> Floor::getFloor()
{
    return m_floors;
}

void Floor::update(double dt)
{
}

void Floor::render(sf::RenderWindow& t_window)
{
    for (int i = 0; i < MAX_TILES; i++)
    {
        t_window.draw(m_floors.at(i));
    }
   
}
