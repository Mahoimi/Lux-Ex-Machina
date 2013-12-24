#ifndef FLYINGCHARACTER_H
#define FLYINGCHARACTER_H

#include <Character.h>

class FlyingCharacter : public Character {
protected:
	float m_flyingSpeed;

public:
	FlyingCharacter(const sf::Vector2f& size, const std::string& texturePath, float flyingSpeed);

	virtual void animate(const sf::Time& elapsed) = 0;

	virtual void moveRight();
	virtual void moveLeft();
	void flyUp();
	void flyDown();
};

#endif // FLYINGCHARACTER_H