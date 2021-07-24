#include "SwitchPlayer.h"

SwitchPlayer::SwitchPlayer()
{
    for (int i = 0; i < 4; i++)
    {
        m_characters.push_back(m_entity);
        m_characters.at(0).m_player.setPosition(100, 100);
       
    }
    int i = 0;
}

SwitchPlayer::~SwitchPlayer()
{
}

void SwitchPlayer::update(double dt)
{
    for (int i = 0; i < 4; i++)
    {
        entityQueue.push(m_characters);
    }
    int i = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        
        int i = 0;
       // m_characters.at(0).m_player.move(1, 0);
    }
}

void SwitchPlayer::render(sf::RenderWindow& t_window)
{

    for (int i = 0; i < m_characters.size(); i++)
    {
        t_window.draw(m_characters.at(i).m_player);
    }
}

std::queue<std::vector<Entity>> SwitchPlayer::getQueue()
{
    return entityQueue;
}
