#include <InputComponent.h>
#include <GameObject.h>
#include <SFML/Window/Keyboard.hpp>

InputComponent::InputComponent()
{

}

InputComponent::~InputComponent()
{

}

void InputComponent::update(GameObject& gameObject) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			gameObject.m_positionX -= 4.f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			gameObject.m_positionX += 4.f;
		}
	}
}