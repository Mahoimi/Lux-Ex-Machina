#include <Character.h>
#include <iostream>

Character::Character(const sf::Vector2f& size, const std::string& texturePath):
			m_sprite(size),
			m_texturePath(texturePath),
			m_facingPosition(FacingPosition::RIGHT),
			m_actionState(ActionState::IDLE),
			m_movingState(MovingState::IDLE),
			m_passiveState(PassiveState::IDLE),
			m_movingSpeed(4.f),
			m_jumpingHeight(4.f)
{
	if (!m_texture.loadFromFile(m_texturePath)){
		m_sprite.setFillColor(sf::Color::White);
		std::cout << "nope" << std::endl;
	}
	else{
		m_sprite.setTexture(&m_texture);
		m_sprite.setTextureRect(sf::IntRect(320, 15, 36, 39));
	}
	m_sprite.setOrigin(sf::Vector2f(size.x/2,size.y/2));
	m_sprite.setPosition(sf::Vector2f(size.x/2,size.y/2));
}

void Character::animate(const sf::Time& elapsed){
	// For each MovingState, ActionState ... we'll change the IntRect to display the correct version of the character
	// m_sprite.setTextureRect()
	m_animationTime += elapsed;
	if (m_animationTime.asMilliseconds() < 6100 && m_animationTime.asMilliseconds() >= 6000){
		m_sprite.setTextureRect(sf::IntRect(354,15,36,39));
	}
	else if (m_animationTime.asMilliseconds() < 6200 && m_animationTime.asMilliseconds() >= 6100){
		m_sprite.setTextureRect(sf::IntRect(388,15,36,39));
	}
	else if (m_animationTime.asMilliseconds() >= 6200){
		m_sprite.setTextureRect(sf::IntRect(320, 15, 36, 39));
		m_animationTime = sf::milliseconds(0);
	}
}

void Character::moveLeft(){
	if (m_facingPosition != FacingPosition::LEFT) {
		m_facingPosition = FacingPosition::LEFT;
		m_sprite.setScale(sf::Vector2f(-1.f,1));
	}
	m_sprite.move(-m_movingSpeed,0);
}

void Character::moveRight(){
	if (m_facingPosition != FacingPosition::RIGHT) {
		m_facingPosition = FacingPosition::RIGHT;
		m_sprite.setScale(sf::Vector2f(1.f,1));
	}
	m_sprite.move(m_movingSpeed,0);
}

void Character::jump(){

}