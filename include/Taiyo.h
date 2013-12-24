#ifndef TAIYO_H
#define TAIYO_H

#include <WalkingCharacter.h>

class Taiyo : public WalkingCharacter {
private:
	void inputControl();
	void jump();
public:
	Taiyo();
	void animate(const sf::Time& elapsed);
};

#endif // TAIYO_H