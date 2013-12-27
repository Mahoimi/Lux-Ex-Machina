#ifndef FLYINGTAIYO_H
#define FLYINGTAIYO_H

#include <FlyingCharacter.h>

class FlyingTaiyo : public FlyingCharacter {
private:
	void inputControl();
	void physics();
public:
	FlyingTaiyo();
	void animate(const sf::Time& elapsed);
};

#endif // TAIYO_H