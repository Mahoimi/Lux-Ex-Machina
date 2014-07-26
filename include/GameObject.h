#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>

class GraphicsComponent;
class AIComponent;

class GameObject {
private:
	GraphicsComponent* m_graphics;
	AIComponent* m_ai;
	// PhysicsComponent

public:
	float m_positionX;
	float m_positionY;
	float dx, dy;

	explicit GameObject(float positionX, float positionY, GraphicsComponent* = nullptr, AIComponent* = nullptr);
	~GameObject();

	float posX() const
	{
		return m_positionX;
	}

	float posY() const
	{
		return m_positionY;
	}

	void update(const sf::Time&, sf::RenderWindow&);

};

#endif // GAMEOBJECT_H