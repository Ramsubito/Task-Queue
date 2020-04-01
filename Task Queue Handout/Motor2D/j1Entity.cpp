#include "j1Player.h"
#include "j1Entity.h"
#include "j1Render.h"
#include "p2Log.h"


j1Entity::j1Entity() : j1Module()
{
	name.create("entity");
}

j1Entity::~j1Entity()
{
}

bool j1Entity::Awake()
{

	return true;
}

bool j1Entity::Start()
{
	//Load sprite
	sprite = App->tex->Load("textures/johnny.png");
	
	return true;
}

bool j1Entity::PreUpdate() 
{
	return true;
}


bool j1Entity::Update(float dt)
{
	std::list<Entity*>::iterator iterator = entities.begin();

	for (iterator; iterator != entities.end(); iterator++)
	{
		if((*iterator)->type == PLAYER)
		{ 
			
			App->render->Blit(sprite, (*iterator)->pos.x, (*iterator)->pos.y);
		}

		(*iterator)->Walk(dt);
	}



	return true;
}

bool j1Entity::CleanUp()
{
	for (std::list<Entity*>::iterator iterator = entities.begin(); iterator == entities.end(); iterator++)
	{
		delete *iterator;
	}
	entities.clear();
	return true;
}


Entity* j1Entity::AddEntity(int pos_x, int pos_y, ENTITY_TYPES type)
{
	Entity* ent = nullptr;

	if (type == PLAYER) {
		ent = new j1Player(pos_x, pos_y, type);
	}
	ent->type = type;
	ent->pos = { pos_x, pos_y };
	ent->speed.x = 4;
	ent->speed.y = 4;
	ent->rect = { pos_x, pos_y, 40, 40 };

	entities.push_back(ent);

	return ent;
}


