#include "Enemy.h"

void Enemy::setupSprite()
{
}

void Enemy::movement()
{
}

void Enemy::setEnergy(int t_energy)
{
	m_energy = t_energy;
}

bool Enemy::getAlive()
{
	return m_alive;
}

int Enemy::GetEnergy()
{
	return m_energy;
}

sf::Sprite Enemy::GetSprite()
{
    return m_sprite;
}

void Enemy::update(double dt)
{
}

void Enemy::moveUp()
{
	m_sprite.move(0, -1);
	m_energy--;
}

void Enemy::moveDown()
{
	m_sprite.move(0, 1);
	m_energy--;
}

void Enemy::moveRight()
{
	m_sprite.setScale(1, 1);
	m_sprite.move(1, 0);
	m_energy--;
}

void Enemy::moveLeft()
{
	m_sprite.setScale(-1, 1);
	m_sprite.move(-1, 0);
	m_energy--;
}

Enemy::Enemy()
{
	if (!m_texture.loadFromFile("images/bosses-pixel-art-game-assets-pack/PNG/Boss1/Anger3.png"))
	{
		std::cout << "cant load sprite" << std::endl;

	}
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(600, 600);
}
