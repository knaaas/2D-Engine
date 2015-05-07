#include "game_object.h"

GameObject::GameObject()
{
	for(auto* component : p_component)
		component = nullptr;
}

GameObject::~GameObject()
{
	for(auto* component : p_component){
		if(component)
			delete component;
	}
}

void GameObject::SetComponent(ComponentType type, Component* component)
{
	p_component[type] = component;
}

void GameObject::Update()
{
	for(auto* component : p_component){
		if(component)
			component->Update(*this);
	}
}

void GameObject::Send(ComponentType index, int message)
{
    if (p_component[index])
        p_component[index]->Message(message);
}
