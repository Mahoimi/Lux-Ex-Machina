#ifndef GRAPHICSCOMPONENT_H
#define GRAPHICSCOMPONENT_H

class GameObject;

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>

class GraphicsComponent {
protected:
	sf::Texture m_texture;
	sf::Time m_animationTime;

public:
	virtual ~GraphicsComponent(){}
	virtual void update(const GameObject&, const sf::Time&, sf::RenderWindow&) = 0;
	
};

#endif // GRAPHICSCOMPONENT_H