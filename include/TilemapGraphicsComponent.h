#ifndef LUX_TILEMAP_GRAPHICS_COMPONENT_H
#define LUX_TILEMAP_GRAPHICS_COMPONENT_H

#include "GraphicsComponent.h"
#include "Tilemap.h"

namespace Lux {
class TilemapGraphicsComponent : public GraphicsComponent
{
private:
	Tilemap m_tilemap;

public:
	TilemapGraphicsComponent(const std::string& tileset, unsigned int tileWidth, unsigned int tileHeight, const int* tiles, unsigned int width, unsigned int height);
	~TilemapGraphicsComponent();

	void update(const GameObject&, const sf::Time&, sf::RenderWindow&) override;
};
}

#endif // TILEMAP_GRAPHICS_COMPONENT_H

