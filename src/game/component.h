#ifndef GAME_COMPONENT_H
#define GAME_COMPONENT_H

class GameObject;
class Component{
	public:
	virtual ~Component() {};
	virtual void Update(GameObject& obj) = 0;
	virtual void Message(int message) = 0;
};

#endif // GAME_COMPONENT_H
