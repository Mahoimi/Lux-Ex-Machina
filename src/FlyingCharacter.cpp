#include <FlyingCharacter.h>

FlyingCharacter::FlyingCharacter(const sf::Vector2f& position, const sf::IntRect& textureZone, const std::string& texturePath, float flyingSpeed):
	Character(position, textureZone, texturePath),
	m_flyingSpeed(flyingSpeed){

}

void FlyingCharacter::flyLeft(){

}

void FlyingCharacter::flyRight(){

}

void FlyingCharacter::flyUp(){

}

void FlyingCharacter::flyDown(){

}