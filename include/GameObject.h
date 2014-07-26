#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>

enum class FacingPosition {
	RIGHT,
	LEFT
};

enum class ActionState {
	IDLE,
	ATTACK,
	HIJACK
};

enum class PassiveState {
	IDLE,
	HIT,
	LOWBATTERY,
	DIED
};

enum class MovingState {
	IDLE,
	RUNNING,
	FALLING,
	JUMPING,
	SWIMING,
	FLYING
};


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
	FacingPosition m_facingPosition;
	MovingState m_movingState;
	ActionState m_actionState;
	PassiveState m_passiveState;

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