#include "Floor.h"

void Floor::createTile()
{
    if (!tTexture.loadFromFile("images/dungeon-platformer-pixel-art-tileset-2/PNG/Tiles_rock/tile27.png"))
    {
        std::cout << "cant load sprite" << std::endl;

    }
    m_tiles.setTexture(tTexture);
    m_tiles.setScale(1.5, 1.5);
    for (int i = 0; i < MAX_TILES; i++)
    {
        m_floors.push_back(m_tiles);
    }
}

void Floor::tileSpacing()
{
    srand(time(nullptr));
  
    for (int i = 0; i < MAX_TILES; i++)
    {
        m_floors.at(i).setPosition(rand() % ScreenSize::m_width - 300 , rand() % ScreenSize::m_height - 200);
        if (m_floors.at(i).getGlobalBounds().intersects(m_floors.at(i).getGlobalBounds()))
        {
            m_floors.at(i).setPosition(rand() % ScreenSize::m_width - 100, rand() % ScreenSize::m_height - 20);
      }
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

std::vector<sf::Sprite> Floor::getFloor()
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
