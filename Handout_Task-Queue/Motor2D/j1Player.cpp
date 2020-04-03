#include "j1Player.h"
#include "j1Render.h"
#include "j1App.h"
#include "j1Input.h"
#include "j1Scene.h"
#include "j1Map.h"
#include "j1Entity.h"
#include "j1TaskQueue.h"

j1Player::j1Player(int x, int y, entity_type type) : Entity(x, y, type)
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

void j1Player::Move(float dt)
{
	//TODO 5: Asign keys to the task(W,S,A,D). Movement methods already done, check j1TaskQueue.h.Go_Up, Go_Down, Go_Left,Go_Right. Arrows are used for the camera movement.

}


bool j1Player::CleanUp()
{


	return true;
}




