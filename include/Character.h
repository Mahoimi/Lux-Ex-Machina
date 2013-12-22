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
private:
	// Sprite parameters
	sf::Texture m_texture;
	std::string m_texturePath;
	sf::Time m_animationTime;

	// State flags
	FacingPosition m_facingPosition;
	ActionState m_actionState;
	PassiveState m_passiveState;
	MovingState m_movingState;

	// Moving parameters
	float m_movingSpeed;
	float m_jumpingHeight;

public:
	sf::RectangleShape m_sprite;
	Character(const sf::Vector2f& size, const std::string& texturePath);
	void animate(const sf::Time& elapsed);
	void moveRight();
	void moveLeft();
	void jump();
};

#endif // CHARACTER_H