#ifndef TILEMAP_H
#define TILEMAP_H

#include <SFML\Graphics.hpp>

class Tilemap : public sf::Drawable, public sf::Transformable {
private:
	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    bool load(const std::string& tileset, unsigned int tileWidth, unsigned int tileHeight, const int* tiles, unsigned int width, unsigned int height);

};

#endif // TILEMAP_H