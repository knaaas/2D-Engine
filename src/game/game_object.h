#ifndef GAME_GAME_OBJECT_H
#define GAME_GAME_OBJECT_H

#include "component.h"

class GameObject {
		
public:
	enum ComponentType{
		MOVEMENT = 0,
        PHYSICS,
		RENDER,
		SIZE
	};

    GameObject();
	~GameObject();
	void Send(ComponentType index, int message);
	void SetComponent(const ComponentType type, Component* component);
	void Update();

private:
	Component* p_component[SIZE];
};

#endif // GAME_GAME_OBJECT_H
