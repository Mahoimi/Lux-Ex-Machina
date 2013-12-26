#include <WalkingCharacter.h>

float WalkingCharacter::m_gravity = 2.f;
float WalkingCharacter::m_maxFallingSpeed = 40.f;

WalkingCharacter::WalkingCharacter(const sf::Vector2f& position, const sf::IntRect& textureZone, const std::string& texturePath, float movingSpeed, float jumpingVelocity):
	Character(position,textureZone, texturePath),
	m_dx(movingSpeed),
	m_dy(0.f),
	m_jumpingVelocity(jumpingVelocity)
	{

}

void WalkingCharacter::moveLeft(){
	if (m_facingPosition != FacingPosition::LEFT) {
		m_facingPosition = FacingPosition::LEFT;
		flipSprite();
	}
	if(m_movingState == MovingState::IDLE) setMovingState(MovingState::RUNNING);
	m_sprite.move(-m_dx,0);
}

void WalkingCharacter::moveRight(){
	if (m_facingPosition != FacingPosition::RIGHT) {
		m_facingPosition = FacingPosition::RIGHT;
		flipSprite();
	}
	if(m_movingState == MovingState::IDLE) setMovingState(MovingState::RUNNING);
	m_sprite.move(m_dx,0);
}

void WalkingCharacter::jump(){
	if (m_movingState == MovingState::IDLE || m_movingState == MovingState::RUNNING){
		setMovingState(MovingState::JUMPING);
		m_dy = - m_jumpingVelocity;
	}
}

void WalkingCharacter::physics(){
	if (m_sprite.getPosition().y < 800.f || m_movingState == MovingState::JUMPING){
		if (m_dy + m_gravity < m_maxFallingSpeed){
			m_dy += m_gravity;
		}
		m_sprite.move(0,m_dy);

		if (m_dy > 0){
			if (m_movingState != MovingState::FALLING) setMovingState(MovingState::FALLING);

			if (m_sprite.getPosition().y + m_dy >= 800.f){
				m_dy = 0.f;
				setMovingState(MovingState::IDLE);
				m_sprite.setPosition(m_sprite.getPosition().x, 800.f);
			}
		}
	}
}