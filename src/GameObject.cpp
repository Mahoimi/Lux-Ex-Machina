#include "GameObject.h"

#include "GraphicsComponent.h"
#include "AIComponent.h"
#include "PhysicsComponent.h"

namespace Lux {

GameObject::GameObject(float positionX, float positionY, GraphicsComponent* graphics, AIComponent* ai, PhysicsComponent* physics)
	:	m_positionX(positionX),
		m_positionY(positionY),
		m_graphics(graphics),
		m_ai(ai),
		m_physics(physics),
		m_facingPosition(FacingPosition::RIGHT),
		m_movingState(MovingState::IDLE),
		m_actionState(ActionState::IDLE),
		m_passiveState(PassiveState::IDLE)
{

}

GameObject::~GameObject()
{
	
}

void GameObject::update(const sf::Time& elapsed, sf::RenderWindow& window){
	if (m_ai) 
		m_ai->update(*this);

	//if (m_physics) 
		// m_physics->update(*this, tilemap);

	if (m_graphics) 
		m_graphics->update(*this, elapsed, window);
	
}
} // ns Lux