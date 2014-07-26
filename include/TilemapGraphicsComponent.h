#ifndef TILEMAP_GRAPHICS_COMPONENT_H
#define TILEMAP_GRAPHICS_COMPONENT_H

#include "GraphicsComponent.h"
#include "Tilemap.h"

class TilemapGraphicsComponent : public GraphicsComponent
{
private:
	Tilemap m_tilemap;

public:
	TilemapGraphicsComponent(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);
	~TilemapGraphicsComponent();

	void update(const GameObject&, const sf::Time&, sf::RenderWindow&) override;
};

#endif // TILEMAP_GRAPHICS_COMPONENT_H

