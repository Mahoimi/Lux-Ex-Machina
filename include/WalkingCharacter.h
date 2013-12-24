#ifndef WALKINGCHARACTER_H
#define WALKINGCHARACTER_H

#include <Character.h>

class WalkingCharacter : public Character {
protected:
	float m_movingSpeed;
	float m_jumpingHeight;

public:
	WalkingCharacter(const sf::Vector2f& size, const std::string& texturePath, float movingSpeed, float jumpingHeight);

	virtual void animate(const sf::Time& elapsed) = 0;

	virtual void moveRight();
	virtual void moveLeft();
	void jump();

};

#endif // WALKINGCHARACTER_H