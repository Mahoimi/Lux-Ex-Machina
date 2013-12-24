#include <Character.h>

Character::Character(const sf::Vector2f& size, const sf::IntRect& textureZone, const std::string& texturePath):
			m_sprite(size),
			m_facingPosition(FacingPosition::RIGHT),
			m_actionState(ActionState::IDLE),
			m_movingState(MovingState::IDLE),
			m_passiveState(PassiveState::IDLE)
{
	if (!m_texture.loadFromFile(texturePath)){
		m_sprite.setFillColor(sf::Color::White);
	}
	else{
		m_sprite.setTexture(&m_texture);
		m_sprite.setTextureRect(textureZone);
	}
	m_sprite.setOrigin(sf::Vector2f(size.x/2,size.y/2));
	m_sprite.setPosition(sf::Vector2f(size.x/2,size.y/2));
}