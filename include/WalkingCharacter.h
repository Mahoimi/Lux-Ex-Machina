#ifndef WALKINGCHARACTER_H
#define WALKINGCHARACTER_H

#include <Character.h>

class WalkingCharacter : public Character {
protected:
	static float m_gravity;
	static float m_maxFallingSpeed;
	float m_jumpingVelocity;
	float m_dx;
	float m_dy;
	void moveRight();
	void moveLeft();
	void jump();
	
	virtual void physics();
public:
	WalkingCharacter(const sf::Vector2f& position, const sf::IntRect& textureZone, const std::string& texturePath, float movingSpeed, float jumpingHeight);
	virtual void animate(const sf::Time& elapsed) = 0;
};

#endif // WALKINGCHARACTER_H