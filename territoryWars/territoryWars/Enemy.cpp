#include "Enemy.h"

void Enemy::setupSprite()
{
}

void Enemy::movement()
{
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
}

void Enemy::moveDown()
{
	m_sprite.move(0, 1);
}

void Enemy::moveRight()
{
	m_sprite.setScale(1, 1);
	m_sprite.move(1, 0);
}

void Enemy::moveLeft()
{
	m_sprite.setScale(-1, 1);
	m_sprite.move(-1, 0);
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
