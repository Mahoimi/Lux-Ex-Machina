#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML\Graphics.hpp>

enum class FacingPosition {
	RIGHT,
	LEFT
};

enum class ActionState {
	IDLE,
	ATTACK,
	HIJACK
};

enum class PassiveState {
	IDLE,
	HIT,
	LOWBATTERY,
	DIED
};

enum class MovingState {
	IDLE,
	RUNNING,
	JUMPING,
	SWIMING,
	FLYING
};

class Character {
protected:
	// Sprite parameters
	sf::RectangleShape m_sprite;
	sf::Texture m_texture;
	sf::Time m_animationTime;

	// State flags
	FacingPosition m_facingPosition;
	ActionState m_actionState;
	PassiveState m_passiveState;
	MovingState m_movingState;

public:
	Character(const sf::Vector2f& size, const std::string& texturePath);
	inline const sf::RectangleShape& getSprite() const {
		return m_sprite;
	}
	virtual void animate(const sf::Time& elapsed) = 0;
	virtual void moveRight() = 0;
	virtual void moveLeft() = 0;
	//virtual void moveToPosition(const sf::Vector2f& position) = 0;
};

#endif // CHARACTER_H