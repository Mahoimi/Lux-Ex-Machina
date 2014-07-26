#ifndef AICOMPONENT_H
#define AICOMPONENT_H

class GameObject;

class AIComponent {
public:
	AIComponent(){}

	virtual void update(GameObject&) = 0;
	virtual ~AIComponent(){}
};

#endif // AICOMPONENT_H