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
	FALLING,
	JUMPING,
	SWIMING,
	FLYING
};

class Character {
protected:
	// Sprite parameters
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::Time m_animationTime;

	// State flags
	FacingPosition m_facingPosition;
	ActionState m_actionState;
	MovingState m_movingState;
	PassiveState m_passiveState;

	inline void setActionState(const ActionState& newState){
		if (m_actionState != newState){
			m_actionState = newState;
			m_animationTime = sf::milliseconds(0);
		}
	}
	inline void setMovingState(const MovingState& newState){
		if (m_movingState != newState){
			m_movingState = newState;
			m_animationTime = sf::milliseconds(0);
		}
	}
	inline void setPassiveState(const PassiveState& newState){
		if (m_passiveState != newState){
			m_passiveState = newState;
			m_animationTime = sf::milliseconds(0);
		}
	}
	inline void flipSprite(){
		m_sprite.setScale(-m_sprite.getScale().x, m_sprite.getScale().y);
	}

public:
	Character(const sf::Vector2f& position, const sf::IntRect& textureZone, const std::string& texturePath);
	inline const sf::Sprite& getSprite() const {
		return m_sprite;
	}
	virtual void animate(const sf::Time& elapsed) = 0;
};

#endif // CHARACTER_H