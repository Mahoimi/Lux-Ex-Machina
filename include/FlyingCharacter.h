#ifndef FLYINGCHARACTER_H
#define FLYINGCHARACTER_H

#include <Character.h>

class FlyingCharacter : public Character {
protected:
	static float m_maxFlyingSpeed;
	float m_flyingSpeed;
	float m_dx;
	float m_dy;
	void flyUp();
	void flyDown();
	void flyRight();
	void flyLeft();

public:
	FlyingCharacter(const sf::Vector2f& position, const sf::IntRect& textureZone, const std::string& texturePath, float flyingSpeed);
	virtual void animate(const sf::Time& elapsed) = 0;
};

#endif // FLYINGCHARACTER_H