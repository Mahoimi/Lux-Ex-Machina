#include <GameObject.h>
#include <GraphicsComponent.h>
#include <AIComponent.h>

GameObject::GameObject(float positionX, float positionY, GraphicsComponent* graphics, AIComponent* ai)
	:	m_positionX(positionX),
		m_positionY(positionY),
		m_graphics(graphics),
		m_ai(ai)
{

}

GameObject::~GameObject()
{
	if(m_ai)
		delete m_ai;

	if(m_graphics)
		delete m_graphics;
}

void GameObject::draw(sf::RenderWindow& window) const {
		if (m_graphics) 
			m_graphics->draw(window);
}

void GameObject::update(const sf::Time& elapsed){
	if (m_ai) 
		m_ai->update(*this);

	if (m_graphics) 
		m_graphics->update(*this, elapsed);
}