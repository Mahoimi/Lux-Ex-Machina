#ifndef INPUT_COMPONENT_H
#define INPUT_COMPONENT_H

#include <AIComponent.h>

class InputComponent : public AIComponent {
public:
	InputComponent();
	~InputComponent();
	void update(GameObject&);
	
};

#endif // INPUTCOMPONENT_H