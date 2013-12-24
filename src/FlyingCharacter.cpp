#include <FlyingCharacter.h>

FlyingCharacter::FlyingCharacter(const sf::Vector2f& size, const sf::IntRect& textureZone, const std::string& texturePath, float flyingSpeed):
	Character(size, textureZone, texturePath),
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