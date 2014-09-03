#ifndef LUX_TAIYO_GRAPHICS_COMPONENT_H
#define LUX_TAIYO_GRAPHICS_COMPONENT_H

#include "GraphicsComponent.h"

namespace Lux {
class TaiyoGraphicsComponent : public GraphicsComponent 
{
private:
	sf::Sprite m_sprite;

public:
	TaiyoGraphicsComponent();
	void update(const GameObject& gameObject, const sf::Time&, sf::RenderWindow&) override;
};
}

#endif // LUX_TAIYO_GRAPHICS_COMPONENT_H