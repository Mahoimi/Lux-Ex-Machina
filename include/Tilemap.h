#ifndef LUX_TILEMAP_H
#define LUX_TILEMAP_H

#include <SFML\Graphics\Drawable.hpp>
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>
#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Transformable.hpp>
#include <SFML\Graphics\VertexArray.hpp>

namespace Lux {
class Tilemap : public sf::Drawable, public sf::Transformable {
private:
	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    bool load(const std::string& tileset, unsigned int tileWidth, unsigned int tileHeight, const int* tiles, unsigned int width, unsigned int height);

};
}

#endif // LUX_TILEMAP_H