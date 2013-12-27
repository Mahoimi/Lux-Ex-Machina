#include <FlyingCharacter.h>

float FlyingCharacter::m_maxFlyingSpeed = 20.f;

FlyingCharacter::FlyingCharacter(const sf::Vector2f& position, const sf::IntRect& textureZone, const std::string& texturePath, float flyingSpeed):
	Character(position, textureZone, texturePath),
	m_flyingSpeed(flyingSpeed),
	m_dx(0.f),
	m_dy(0.f){

}

void FlyingCharacter::flyLeft(){
	if (m_facingPosition != FacingPosition::LEFT) {
		m_facingPosition = FacingPosition::LEFT;
		flipSprite();
	}
	if(m_movingState == MovingState::IDLE) setMovingState(MovingState::FLYING);
	if(abs(m_dx - m_flyingSpeed) < m_maxFlyingSpeed){
		m_dx -= m_flyingSpeed;
	}
}

void FlyingCharacter::flyRight(){
	if (m_facingPosition != FacingPosition::RIGHT) {
		m_facingPosition = FacingPosition::RIGHT;
		flipSprite();
	}
	if(m_movingState == MovingState::IDLE) setMovingState(MovingState::FLYING);
	if(m_dx + m_flyingSpeed < m_maxFlyingSpeed){
		m_dx += m_flyingSpeed;
	}
}

void FlyingCharacter::flyUp(){
	if(m_movingState == MovingState::IDLE) setMovingState(MovingState::FLYING);
	if(abs(m_dy - m_flyingSpeed) < m_maxFlyingSpeed){
		m_dy -= m_flyingSpeed;
	}
}

void FlyingCharacter::flyDown(){
	if(m_movingState == MovingState::IDLE) setMovingState(MovingState::FLYING);
	if(m_dy + m_flyingSpeed < m_maxFlyingSpeed){
		m_dy += m_flyingSpeed;
	}
}