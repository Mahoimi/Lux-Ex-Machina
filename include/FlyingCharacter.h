#ifndef FLYINGCHARACTER_H
#define FLYINGCHARACTER_H

#include <Character.h>

class FlyingCharacter : public Character {
protected:
	float m_flyingSpeed;
	void flyUp();
	void flyDown();
	void flyRight();
	void flyLeft();

public:
	FlyingCharacter(const sf::Vector2f& size, const sf::IntRect& textureZone, const std::string& texturePath, float flyingSpeed);
	virtual void animate(const sf::Time& elapsed) = 0;
};

#endif // FLYINGCHARACTER_H