#ifndef __J1ENTITY_H__
#define __J1ENTITY_H__

#include "j1App.h"
#include "j1Module.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "SDL/include/SDL.h"

#include <list>
#include <queue>


class SDL_Texture;

enum ENTITY_TYPES
{
	NO_TYPE,
	PLAYER,
	
};

class Entity {
public:

	Entity(int x, int y, ENTITY_TYPES type) {}
	
	virtual void Walk(float dt) {};

public:
	iPoint pos;
	iPoint speed;
	ENTITY_TYPES type;
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
	

	Entity* AddEntity(int x, int y, ENTITY_TYPES type);
	
	SDL_Texture* sprite;
	SDL_Texture* goku_sprite;

	Animation* Current_Animation;
	Animation idle;
	Animation punch;
	Animation kame;
	Animation charge_ki;
	Animation kick;
};



#endif // !__ENTITIES_H__