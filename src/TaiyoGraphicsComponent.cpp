#include <TaiyoGraphicsComponent.h>
#include <GameObject.h>

TaiyoGraphicsComponent::TaiyoGraphicsComponent()
	:	GraphicsComponent("img/megaman.png", sf::IntRect(320, 15, 36, 39))
{

}

void TaiyoGraphicsComponent::update(GameObject& gameObject, const sf::Time& elapsed)
{
	m_animationTime += elapsed;
	m_sprite.setPosition(sf::Vector2f(gameObject.posX(), gameObject.posY()));
}