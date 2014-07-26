#ifndef TAIYOGRAPHICSCOMPONENT_H
#define TAIYOGRAPHICSCOMPONENT_H

#include <GraphicsComponent.h>

class TaiyoGraphicsComponent : public GraphicsComponent {
public:
	TaiyoGraphicsComponent();
	void update(GameObject& gameObject, const sf::Time& elapsed);

};

#endif // TAIYOGRAPHICSCOMPONENT_H