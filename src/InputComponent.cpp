#include "InputComponent.h"

#include "GameObject.h"
#include "SFML/Window/Keyboard.hpp"

namespace Lux {
InputComponent::InputComponent()
{

}

InputComponent::~InputComponent()
{

}

void InputComponent::update(GameObject& gameObject) 
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) != sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
		{
			gameObject.m_positionX -= 4.f;
			gameObject.m_facingPosition = FacingPosition::RIGHT;
			gameObject.m_movingState = MovingState::RUNNING;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
		{
			gameObject.m_positionX += 4.f;
			gameObject.m_facingPosition = FacingPosition::LEFT;
			gameObject.m_movingState = MovingState::RUNNING;
		}
	}
	else
	{
		gameObject.m_movingState = MovingState::IDLE;
	}
}
} // ns Lux