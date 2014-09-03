#ifndef LUX_GAMEOBJECT_H
#define LUX_GAMEOBJECT_H

#include <memory>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>

#include "States.h"

namespace Lux {

class GraphicsComponent;
class AIComponent;
class PhysicsComponent;

class GameObject {

private:
	std::unique_ptr<GraphicsComponent> m_graphics;
	std::unique_ptr<AIComponent> m_ai;
	std::unique_ptr<PhysicsComponent> m_physics;

public:
	float m_positionX;
	float m_positionY;
	float dx, dy;
	FacingPosition m_facingPosition;
	MovingState m_movingState;
	ActionState m_actionState;
	PassiveState m_passiveState;

    GameObject(float positionX, float positionY, GraphicsComponent* = nullptr, AIComponent* = nullptr, PhysicsComponent* = nullptr);
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
}

#endif // LUX_GAMEOBJECT_H