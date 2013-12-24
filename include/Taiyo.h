#ifndef TAIYO_H
#define TAIYO_H

#include <WalkingCharacter.h>

class Taiyo : public WalkingCharacter {
private:
public:
	Taiyo();
	void animate(const sf::Time& elapsed);
};

#endif // TAIYO_H