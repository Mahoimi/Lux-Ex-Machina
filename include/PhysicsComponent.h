#ifndef LUX_PHYSICS_COMPONENT_H
#define LUX_PHYSICS_COMPONENT_H

#include <SFML/System/Time.hpp>

namespace Lux {

class GameObject;
class Tilemap;

class PhysicsComponent {
public:
    PhysicsComponent(){}
	virtual ~PhysicsComponent(){}
	void update(GameObject& gameObject, const sf::Time& elapsed);
};
}

#endif // LUX_PHYSICS_COMPONENT_H