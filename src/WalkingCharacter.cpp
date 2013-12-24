#include <WalkingCharacter.h>

float WalkingCharacter::m_gravity = 0.5f;

WalkingCharacter::WalkingCharacter(const sf::Vector2f& size, const sf::IntRect& textureZone, const std::string& texturePath, float movingSpeed, float jumpingHeight):
	Character(size,textureZone, texturePath),
	m_movingSpeed(movingSpeed),
	m_jumpingHeight(jumpingHeight),
	m_fallingSpeed(0.f){

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
	if (m_movingState == MovingState::IDLE){
		m_movingState = MovingState::JUMPING;
		m_fallingSpeed = - m_jumpingHeight;
	}
}

void WalkingCharacter::physics(){
	if (m_sprite.getPosition().y < 800.f || m_movingState == MovingState::JUMPING){
		
		m_fallingSpeed += m_gravity;
		m_sprite.move(0,m_fallingSpeed);

		if (m_fallingSpeed > 0){
			if (m_movingState != MovingState::FALLING) m_movingState=MovingState::FALLING;

			if (m_sprite.getPosition().y + m_fallingSpeed >= 800.f){
				m_fallingSpeed = 0.f;
				m_movingState=MovingState::IDLE;
				m_sprite.setPosition(m_sprite.getPosition().x, 800.f);
			}
		}
	}
}