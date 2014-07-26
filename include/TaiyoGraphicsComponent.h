#ifndef TAIYO_GRAPHICS_COMPONENT_H
#define TAIYO_GRAPHICS_COMPONENT_H

#include <GraphicsComponent.h>

class TaiyoGraphicsComponent : public GraphicsComponent 
{
private:
	sf::Sprite m_standingSprite;
	sf::Sprite m_jumpingSprite;
	sf::Sprite m_runningSprite;

public:
	TaiyoGraphicsComponent();
	void update(const GameObject& gameObject, const sf::Time&, sf::RenderWindow&) override;
};

#endif // TAIYO_GRAPHICS_COMPONENT_H