#include <Tilemap.h>

 void Tilemap::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	// apply the transform
	states.transform *= getTransform();

	// apply the tileset texture
	states.texture = &m_tileset;

	// draw the vertex array
	target.draw(m_vertices, states);
}

bool Tilemap::load(const std::string& tileset, unsigned int tileWidth, unsigned int tileHeight, const int* tiles, unsigned int width, unsigned int height) {
    // load the tileset texture
    if (!m_tileset.loadFromFile(tileset))
        return false;

    // resize the vertex array to fit the level size
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(width * height * 4);

    // populate the vertex array, with one quad per tile
    for (unsigned int i = 0; i < width; ++i) {
        for (unsigned int j = 0; j < height; ++j) {
            // get the current tile number
            int tileNumber = tiles[i + j * width];

            // find its position in the tileset texture
            int tu = tileNumber % (m_tileset.getSize().x / tileWidth);
            int tv = tileNumber / (m_tileset.getSize().x / tileWidth);

            // get a pointer to the current tile's quad
            sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

            // define its 4 corners
            quad[0].position = sf::Vector2f(static_cast<float>(i * tileWidth), static_cast<float>(j * tileHeight));
            quad[1].position = sf::Vector2f(static_cast<float>((i + 1) * tileWidth), static_cast<float>(j * tileHeight));
            quad[2].position = sf::Vector2f(static_cast<float>((i + 1) * tileWidth), static_cast<float>((j + 1) * tileHeight));
            quad[3].position = sf::Vector2f(static_cast<float>(i * tileWidth), static_cast<float>((j + 1) * tileHeight));

            // define its 4 texture coordinates
            quad[0].texCoords = sf::Vector2f(static_cast<float>(tu * tileWidth), static_cast<float>(tv * tileHeight));
            quad[1].texCoords = sf::Vector2f(static_cast<float>((tu + 1) * tileWidth), static_cast<float>(tv * tileHeight));
            quad[2].texCoords = sf::Vector2f(static_cast<float>((tu + 1) * tileWidth), static_cast<float>((tv + 1) * tileHeight));
            quad[3].texCoords = sf::Vector2f(static_cast<float>(tu * tileWidth), static_cast<float>((tv + 1) * tileHeight));
        }
	}

    return true;
}