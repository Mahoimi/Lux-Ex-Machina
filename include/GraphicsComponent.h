#ifndef GRAPHICSCOMPONENT_H
#define GRAPHICSCOMPONENT_H

class GameObject;

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>

class GraphicsComponent {
protected:
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::Time m_animationTime;

public:
	explicit GraphicsComponent(const std::string& texturePath, const sf::IntRect& textureZone){
		if (m_texture.loadFromFile(texturePath)){
			m_sprite.setTexture(m_texture);
			m_sprite.setTextureRect(textureZone);
			m_sprite.setOrigin(m_sprite.getLocalBounds().width/2, m_sprite.getLocalBounds().height/2);
		}
	}

	virtual ~GraphicsComponent(){}

	void draw(sf::RenderWindow& window) const{
		window.draw(m_sprite);
	}

	virtual void update(GameObject&, const sf::Time&) = 0;
	
};

#endif // GRAPHICSCOMPONENT_H