#include <WalkingCharacter.h>

WalkingCharacter::WalkingCharacter(const sf::Vector2f& size, const std::string& texturePath, float movingSpeed, float jumpingHeight):
	Character(size,texturePath),
	m_movingSpeed(movingSpeed),
	m_jumpingHeight(jumpingHeight){

}

void WalkingCharacter::moveLeft(){
	if (m_facingPosition != FacingPosition::LEFT) {
		m_facingPosition = FacingPosition::LEFT;
		m_sprite.setScale(sf::Vector2f(-1.f,1));
	}
	m_sprite.move(-m_movingSpeed,0);
}

void WalkingCharacter::moveRight(){
	if (m_facingPosition != FacingPosition::RIGHT) {
		m_facingPosition = FacingPosition::RIGHT;
		m_sprite.setScale(sf::Vector2f(1.f,1));
	}
	m_sprite.move(m_movingSpeed,0);
}

void WalkingCharacter::jump(){

}