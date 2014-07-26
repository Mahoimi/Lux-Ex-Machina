#ifndef INPUTCOMPONENT_H
#define INPUTCOMPONENT_H

#include <AIComponent.h>

class InputComponent : public AIComponent {
public:
	InputComponent();
	~InputComponent();
	void update(GameObject&);
	
};

#endif // INPUTCOMPONENT_H