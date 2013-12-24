#ifndef WALKINGCHARACTER_H
#define WALKINGCHARACTER_H

#include <Character.h>

class WalkingCharacter : public Character {
protected:
	static float m_gravity;
	float m_movingSpeed;
	float m_jumpingHeight;
	float m_fallingSpeed;
	void moveRight();
	void moveLeft();
	void physics();

	virtual void jump();
public:
	WalkingCharacter(const sf::Vector2f& size, const sf::IntRect& textureZone, const std::string& texturePath, float movingSpeed, float jumpingHeight);
	virtual void animate(const sf::Time& elapsed) = 0;
};

#endif // WALKINGCHARACTER_H