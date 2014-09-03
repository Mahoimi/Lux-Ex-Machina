#ifndef LUX_PHYSICS_COMPONENT_H
#define LUX_PHYSICS_COMPONENT_H

namespace Lux {

class GameObject;
class Tilemap;

class PhysicsComponent {
public:
	virtual ~PhysicsComponent(){}
	virtual void update(GameObject&, const Tilemap&) = 0;
	
};
}

#endif // LUX_PHYSICS_COMPONENT_H