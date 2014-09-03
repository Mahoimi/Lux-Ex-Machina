#ifndef LUX_AICOMPONENT_H
#define LUX_AICOMPONENT_H

namespace Lux {
class GameObject;

class AIComponent {
public:
	virtual ~AIComponent(){}
	virtual void update(GameObject&) = 0;
};
}

#endif // LUX_AICOMPONENT_H