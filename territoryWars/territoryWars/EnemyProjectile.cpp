#include "EnemyProjectile.h"

void EnemyProjectile::movement()
{
}

sf::Sprite EnemyProjectile::m_getSprite()
{
    return m_sprite;
}

EnemyProjectile::EnemyProjectile()
{
	if (!m_texture.loadFromFile("images/10-magic-effects-pixel-art-pack/PNG/gypno/spiral11.png"))
	{
		std::cout << "cant load sprite" << std::endl;

	}
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(400, 400);
}

void EnemyProjectile::update(double dt)
{
}
