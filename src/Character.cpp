#include <Character.h>

Character::Character(const sf::Vector2f& position, const sf::IntRect& textureZone, const std::string& texturePath):
			m_sprite(),
			m_facingPosition(FacingPosition::RIGHT),
			m_actionState(ActionState::IDLE),
			m_movingState(MovingState::IDLE),
			m_passiveState(PassiveState::IDLE)
{
	if (m_texture.loadFromFile(texturePath)){
		m_sprite.setTexture(m_texture);
		m_sprite.setTextureRect(textureZone);
	}
	m_sprite.setOrigin(m_sprite.getLocalBounds().width/2, m_sprite.getLocalBounds().height/2);
	m_sprite.setPosition(position);
}