#include <Character.h>
#include <iostream>

Character::Character(const sf::Vector2f& size, const std::string& texturePath):
			m_sprite(size),
			m_facingPosition(FacingPosition::RIGHT),
			m_actionState(ActionState::IDLE),
			m_movingState(MovingState::IDLE),
			m_passiveState(PassiveState::IDLE)
{
	if (!m_texture.loadFromFile(texturePath)){
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

