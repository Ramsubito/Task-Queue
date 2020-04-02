#include "j1Player.h"
#include "j1Render.h"
#include "j1App.h"
#include "j1Input.h"
#include "j1Scene.h"
#include "j1Map.h"
#include "j1Entity.h"
#include "j1TaskQueue.h"

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

void j1Player::Move(float dt)
{
	//TODO 5: Add a new movement task to the queue for each key pressed for the four directions.(With W,A,S,D)
	//Movement methods already added.As Up, Down, Left, Right. Check j1TaskQueue.h.
	


}


bool j1Player::CleanUp()
{
	
	
	return true;
}



