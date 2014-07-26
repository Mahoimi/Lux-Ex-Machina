#include "TaiyoGraphicsComponent.h"
#include "GameObject.h"

TaiyoGraphicsComponent::TaiyoGraphicsComponent()
{
	if (m_texture.loadFromFile("img/megaman.png")){
		// Set StandingSprite
		m_standingSprite.setTexture(m_texture);
		m_standingSprite.setTextureRect(sf::IntRect(320, 15, 36, 39));
		m_standingSprite.setOrigin(m_standingSprite.getLocalBounds().width/2, m_standingSprite.getLocalBounds().height/2);

		// Set RunningSprite

	}
}

void TaiyoGraphicsComponent::update(const GameObject& gameObject, const sf::Time& elapsed, sf::RenderWindow& window)
{
	sf::Sprite* sprite = &m_standingSprite;

	m_animationTime += elapsed;
	sprite->setPosition(sf::Vector2f(gameObject.posX(), gameObject.posY()));

	window.draw(*sprite);
}