#include "TilemapGraphicsComponent.h"
#include "GameObject.h"

TilemapGraphicsComponent::TilemapGraphicsComponent(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height)
{
	m_tilemap.load(tileset, tileSize, tiles, width, height);
}

TilemapGraphicsComponent::~TilemapGraphicsComponent()
{
	
}

void TilemapGraphicsComponent::update(const GameObject& gameObject, const sf::Time& elapsed, sf::RenderWindow& window)
{
	m_animationTime += elapsed;
	m_tilemap.setPosition(gameObject.posX(), gameObject.posY());
	window.draw(m_tilemap);
}