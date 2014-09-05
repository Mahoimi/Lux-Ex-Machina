#include "TaiyoGraphicsComponent.h"

#include "GameObject.h"

namespace Lux {
TaiyoGraphicsComponent::TaiyoGraphicsComponent()
{
	if (m_texture.loadFromFile("img/megaman.png")){
		// Set StandingSprite
		m_sprite.setTexture(m_texture);
		m_sprite.setTextureRect(sf::IntRect(320, 15, 36, 39));
		m_sprite.setOrigin(m_sprite.getLocalBounds().width/2, m_sprite.getLocalBounds().height/2);
	}
}

void TaiyoGraphicsComponent::update(const GameObject& gameObject, const sf::Time& elapsed, sf::RenderWindow& window)
{
	int animDelay = 100;

	// Displaying action
	switch (gameObject.m_movingState){
		case MovingState::IDLE:
			// std::cout << "IDLE" << std::endl;
			if (m_animationTime.asMilliseconds() < 6000){
				m_sprite.setTextureRect(sf::IntRect(320, 15, 36, 39));
			}
			else if (m_animationTime.asMilliseconds() < 6100 && m_animationTime.asMilliseconds() >= 6000){
				m_sprite.setTextureRect(sf::IntRect(354,15,36,39));
			}
			else if (m_animationTime.asMilliseconds() < 6200 && m_animationTime.asMilliseconds() >= 6100){
				m_sprite.setTextureRect(sf::IntRect(388,15,36,39));
			}
			else if (m_animationTime.asMilliseconds() >= 6200){
				m_sprite.setTextureRect(sf::IntRect(320, 15, 36, 39));
				m_animationTime = sf::milliseconds(0);
			}
			break;
		case MovingState::RUNNING:
			// std::cout << "RUNNING" << std::endl;
			if (m_animationTime.asMilliseconds() < animDelay){
				m_sprite.setTextureRect(sf::IntRect(104,104,32,38));
			}
			else if (m_animationTime.asMilliseconds() < 2*animDelay && m_animationTime.asMilliseconds() >= animDelay){
				m_sprite.setTextureRect(sf::IntRect(136,104,21,38));
			}
			else if (m_animationTime.asMilliseconds() < 3*animDelay && m_animationTime.asMilliseconds() >= 2*animDelay){
				m_sprite.setTextureRect(sf::IntRect(157,104,24,38));
			}
			else if (m_animationTime.asMilliseconds() < 4*animDelay && m_animationTime.asMilliseconds() >= 3*animDelay){
				m_sprite.setTextureRect(sf::IntRect(181,104,31,38));
			}
			else if (m_animationTime.asMilliseconds() < 5*animDelay && m_animationTime.asMilliseconds() >= 4*animDelay){
				m_sprite.setTextureRect(sf::IntRect(212,104,34,38));
			}
			else if (m_animationTime.asMilliseconds() < 6*animDelay && m_animationTime.asMilliseconds() >= 5*animDelay){
				m_sprite.setTextureRect(sf::IntRect(246,104,27,38));
			}
			else if (m_animationTime.asMilliseconds() < 7*animDelay && m_animationTime.asMilliseconds() >= 6*animDelay){
				m_sprite.setTextureRect(sf::IntRect(273,104,25,38));
			}
			else if (m_animationTime.asMilliseconds() < 8*animDelay && m_animationTime.asMilliseconds() >= 7*animDelay){
				m_sprite.setTextureRect(sf::IntRect(298,104,25,38));
			}
			else if (m_animationTime.asMilliseconds() < 9*animDelay && m_animationTime.asMilliseconds() >= 8*animDelay){
				m_sprite.setTextureRect(sf::IntRect(323,104,33,38));
			}
			else if (m_animationTime.asMilliseconds() < 10*animDelay && m_animationTime.asMilliseconds() >= 9*animDelay){
				m_sprite.setTextureRect(sf::IntRect(356,104,35,38));
			}
			else if (m_animationTime.asMilliseconds() < 11*animDelay && m_animationTime.asMilliseconds() >= 10*animDelay){
				m_sprite.setTextureRect(sf::IntRect(391,104,29,38));
			}
			else if (m_animationTime.asMilliseconds() >= 11*animDelay){
				m_sprite.setTextureRect(sf::IntRect(136,104,21,38));
				m_animationTime = sf::milliseconds(animDelay);
			}
			break;
		case MovingState::JUMPING:
			// std::cout << "JUMPING" << std::endl;
			break;
		case MovingState::FALLING:
			// std::cout << "FALLING" << std::endl;
			break;
	}

	// Set sprite to the correct facing position
	if((gameObject.m_facingPosition == FacingPosition::LEFT && m_sprite.getScale().x < 0)
		||	(gameObject.m_facingPosition == FacingPosition::RIGHT && m_sprite.getScale().x > 0))
	{
		m_sprite.setScale(-m_sprite.getScale().x, m_sprite.getScale().y);
	}

	m_animationTime += elapsed;
	m_sprite.setPosition(sf::Vector2f(gameObject.position()[0], gameObject.position()[1]));

	window.draw(m_sprite);
}
}