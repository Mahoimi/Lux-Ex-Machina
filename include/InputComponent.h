#ifndef LUX_INPUT_COMPONENT_H
#define LUX_INPUT_COMPONENT_H

#include "AIComponent.h"

namespace Lux {
class InputComponent : public AIComponent {
public:
	InputComponent();
	~InputComponent();
	void update(GameObject&) override;
};
}

#endif // LUX_INPUT_COMPONENT_H