#include "GameObject.h"

#include "GraphicsComponent.h"
#include "AIComponent.h"
#include "PhysicsComponent.h"

namespace Lux {

GameObject::GameObject(float positionX, float positionY, GraphicsComponent* graphics, AIComponent* ai, PhysicsComponent* physics)
	:   m_graphics(graphics),
		m_ai(ai),
		m_physics(physics),
        m_mass(1.f),
		m_facingPosition(FacingPosition::RIGHT),
		m_movingState(MovingState::IDLE),
		m_actionState(ActionState::IDLE),
		m_passiveState(PassiveState::IDLE)
{
    m_position[0] = positionX;
    m_position[1] = positionY;
        
    for (std::size_t i = 0; i < 2; ++i)
    {
        m_vel[i] = 0.f;
        m_accel[i] = 0.f;
        m_force[i] = 0.f;
    }
}

GameObject::~GameObject()
{
	
}

void GameObject::update(const sf::Time& elapsed, sf::RenderWindow& window){
	if (m_ai) 
		m_ai->update(*this);

	if (m_physics) 
		m_physics->update(*this, elapsed);

	if (m_graphics) 
		m_graphics->update(*this, elapsed, window);
	
}
} // ns Lux