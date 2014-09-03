#ifndef LUX_STATES_H
#define LUX_STATES_H

namespace Lux {

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

}

#endif // LUX_STATES_H