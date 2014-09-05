#include "PhysicsComponent.h"

#include "GameObject.h"

namespace Lux {

float GRAVITY_CONST = 100.f;

void PhysicsComponent::update(GameObject& gameObject, const sf::Time& elapsed)
{
     // If standing
    if(gameObject.m_position[1] >= 400.f)
    {
        gameObject.m_accel[1] = 0.f;
        gameObject.m_vel[1] = 0.f;

        float friction = 10.f;

        if(gameObject.m_vel[0] > 1.f)
            gameObject.m_vel[0] -= friction;
        else if (gameObject.m_vel[0] < -1.f)
            gameObject.m_vel[0] += friction;
        else
            gameObject.m_vel[0] = 0.f;
    }
    else // If falling
    {
        if (gameObject.m_accel[1] < 500.f)
            gameObject.m_accel[1] += GRAVITY_CONST;
    }

    for(size_t i = 0; i < 2; ++i)
    {
        gameObject.m_accel[i] += gameObject.m_force[i] / gameObject.m_mass; 
        gameObject.m_vel[i] += gameObject.m_accel[i] * elapsed.asSeconds();
        gameObject.m_position[i] += gameObject.m_vel[i] * elapsed.asSeconds();

        gameObject.m_force[i] = 0.f;

    }
}
}