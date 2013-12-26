#ifndef TAIYO_H
#define TAIYO_H

#include <WalkingCharacter.h>

class Taiyo : public WalkingCharacter {
private:
	bool m_hasJumped;
	float m_totalHeight;
	void inputControl();
	void physics();
public:
	Taiyo();
	void animate(const sf::Time& elapsed);
	
};

#endif // TAIYO_H