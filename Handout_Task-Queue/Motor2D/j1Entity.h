#ifndef __J1ENTITY_H__
#define __J1ENTITY_H__

#include "j1App.h"
#include "j1Module.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "SDL/include/SDL.h"

#include <list>
#include <queue>

#define MAX_ENEMIES 5


class SDL_Texture;

enum entity_type
{
	NO_TYPE,
	PLAYER,

};

class Entity {
public:

	Entity(int x, int y, entity_type type) {}
	
	virtual void Move(float dt) {};

public:
	
	iPoint pos;
	iPoint speed;
	entity_type type;
	SDL_Rect rect;


};

class j1Entity : public j1Module {
private:

	std::list<Entity*> entities;

public:
	j1Entity();
	virtual ~j1Entity();

public:
	bool Awake();
	bool Start();
	bool PreUpdate();
	bool Update(float dt);
	bool CleanUp();


	Entity* AddEntity(int x, int y, entity_type type);

	SDL_Texture* test;
};



#endif // !__ENTITIES_H__