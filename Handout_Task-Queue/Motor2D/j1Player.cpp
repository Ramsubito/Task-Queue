#include "j1Player.h"
#include "j1Render.h"
#include "j1App.h"
#include "j1Input.h"
#include "j1Scene.h"
#include "j1Map.h"
#include "j1Entity.h"
#include "j1TaskQueue.h"

#include"SDL_image/include/SDL_image.h"



j1Player::j1Player(int x, int y, ENTITY_TYPES type) : Entity(x, y, type)
{
	
}

j1Player::~j1Player()
{
}

bool j1Player::Awake()
{
	
	return true;
}

bool j1Player::Start()
{


	return true;
}

bool j1Player::PreUpdate()
{
	return true;
}

void j1Player::Action(float dt)
{
	//TODO 5: Add a new attack/action task to the queue for a key pressed.(kick, punch, charge_ki, kame)
	//Action methods already added.As Up, Down, Left, Right. Check j1TaskQueue.h.
	if (App->input->GetKey(SDL_SCANCODE_W) == KEY_DOWN)
	{
		App->task->EnqueueTask(new Punch(this));
	}
	if (App->input->GetKey(SDL_SCANCODE_A) == KEY_DOWN)
	{
		App->task->EnqueueTask(new Kick(this));
	}
	if (App->input->GetKey(SDL_SCANCODE_S) == KEY_DOWN)
	{
		App->task->EnqueueTask(new Kame(this));
	}
	if (App->input->GetKey(SDL_SCANCODE_D) == KEY_DOWN)
	{
		App->task->EnqueueTask(new Charge_Ki(this));
	}

}


bool j1Player::CleanUp()
{
	
	
	return true;
}



