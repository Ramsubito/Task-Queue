#include "j1Player.h"
#include "j1Entity.h"
#include "j1Render.h"
#include "p2Log.h"


j1Entity::j1Entity() : j1Module()
{
	name.create("entity");
	idle.PushBack({433, 470 , 39 , 86});
	

	punch.PushBack({355, 10 , 50 , 76});
	punch.PushBack({ 412, 9 , 50 , 76 });
	punch.PushBack({468 , 13 , 59 , 69});
	punch.PushBack({533 , 9 , 71 , 74});
	punch.speed = 0.15f;
	
	kick.PushBack({355, 10, 50, 76});
	kick.PushBack({70 , 484, 37, 64});
	kick.PushBack({612, 481, 78, 73});
	kick.PushBack({702, 92, 39, 70});
	kick.speed = 0.1;
	
	charge_ki.PushBack({3 , 355 , 63 , 101});
	charge_ki.PushBack({69, 351, 57, 105});
	charge_ki.PushBack({129, 353, 57, 100});
	charge_ki.PushBack({ 3 , 355 , 63 , 101 });
	charge_ki.PushBack({ 69, 351, 57, 105 });
	charge_ki.PushBack({ 129, 353, 57, 100 });
	charge_ki.speed = 0.3f;

	kame.PushBack({355, 10, 50, 76});
	kame.PushBack({654, 279, 54, 68});
	kame.PushBack({ 654, 279, 54, 68 });
	kame.PushBack({ 654, 279, 54, 68 });
	kame.PushBack({110, 479, 57, 74});
	kame.PushBack({ 110, 479, 57, 74 });
	kame.PushBack({ 110, 479, 57, 74 });
	kame.speed = 0.1;

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
	//sprite = App->tex->Load("textures/rsz_test.png");
	goku_sprite = App->tex->Load("textures/GokuSpritesheet.png");
	Current_Animation = &kick;
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
			
			//App->render->Blit(goku_sprite, (*iterator)->pos.x, (*iterator)->pos.y);
			App->render->Blit(goku_sprite, (*iterator)->pos.x, (*iterator)->pos.y, &Current_Animation->GetCurrentFrame(), 1.0f, NULL, NULL, NULL);
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


