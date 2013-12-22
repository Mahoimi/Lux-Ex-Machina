#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML\Graphics.hpp>

enum ActionState {
	ATTACK,
	HIJACK
};

enum PassiveState {
	HIT,
	LOWBATTERY,
	DIED
};

enum MovingState {
	IDLE,
	RUNNING,
	JUMPING,
	SWIMING,
	FLYING
};

class Character {
private:
	sf::Texture m_texture;
	std::string m_texturePath;
	ActionState m_actionState;
	PassiveState m_passiveState;
	MovingState m_movingState;

public:
	sf::RectangleShape m_sprite;
	Character(const sf::Vector2f& size, const std::string& texturePath);
	void animate();
};

#endif // CHARACTER_H