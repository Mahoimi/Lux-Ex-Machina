#include "InputComponent.h"

#include "Controller.h"
#include "GameObject.h"

namespace Lux {
InputComponent::InputComponent()
{

}

InputComponent::~InputComponent()
{

}

void InputComponent::update(GameObject& gameObject) 
{
    bool leftPressed = Controller::isPressed(Controller::Left);
    bool rightPressed = Controller::isPressed(Controller::Right);
    bool jumpPressed = Controller::isPressed(Controller::Jump);

    switch (gameObject.m_movingState)
    {
    case MovingState::IDLE:
    case MovingState::RUNNING:
        {
            if (leftPressed != rightPressed) 
	        {
		        if (leftPressed) 
		        {
			        gameObject.m_vel[0] = -100.f;
			        gameObject.m_facingPosition = FacingPosition::RIGHT;
			        gameObject.m_movingState = MovingState::RUNNING;
		        }
		        if (rightPressed) 
		        {
			        gameObject.m_vel[0] = 100.f;
			        gameObject.m_facingPosition = FacingPosition::LEFT;
			        gameObject.m_movingState = MovingState::RUNNING;
		        }
	        }
	        else
	        {
		        gameObject.m_movingState = MovingState::IDLE;
	        }
        }
        break;
    case MovingState::JUMPING:
        break;
    case MovingState::FALLING:
        break;
    }
}
} // ns Lux