#include "j1App.h"
#include "j1Entity.h"
#include "j1Input.h"
#include "j1TaskQueue.h"



bool Left::Action()
{
	bool ret = false;
	if (entity->pos.x <= Final_Position.x) {
		entity->pos.x = Final_Position.x;
		ret = true;
	}
	else {
		entity->pos.x -= entity->speed.x;
	}

	return ret;
}

bool Right::Action()
{
	bool ret = false;
	if (entity->pos.x >= Final_Position.x) {
		entity->pos.x = Final_Position.x;
		ret = true;
	}
	else {
		entity->pos.x += entity->speed.x;
	}

	
	
	return ret;
}

bool Up::Action()
{
	bool ret = false;
	if (entity->pos.y <= Final_Position.y) {
		entity->pos.y = Final_Position.y;
		ret = true;
	}
	else {
		entity->pos.y -= entity->speed.y;
	}
	
	
	return ret;
}

bool Down::Action()
{
	bool ret = false;
	if (entity->pos.y >= Final_Position.y) {
		entity->pos.y = Final_Position.y;
		ret = true;
	}
	else {
		entity->pos.y += entity->speed.y;
	}
	
	
	return ret;
}

bool j1TaskQueue::Update(float dt)
{
	bool ret = false; 
	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN)
	{
		
		if (auxiliar_task == nullptr && TaskQueue.size() != 0)
		{
			//TODO 5: Assign the first element of the queue to the auxiliar_task, call InitTask function for auxiliar_task and make a pop of the queue.
			
		}
	}

	ret = DoTasks();

	return ret;
}

bool j1TaskQueue::CleanUp()
{
	//TODO 3: Pop queue tasks
	
	return true;
}

bool j1TaskQueue::EnqueueTask(Task* task)
{
	//TODO 1: Add task to Queue
	

	return true;
}

bool j1TaskQueue::DoTasks()
{
	
	if (auxiliar_task != nullptr)
	{
		
		if (auxiliar_task->Action())
		{
			if (TaskQueue.size() != 0)
			{
				//TODO 2: Assign the first element of the queue to the auxiliar_task, call InitTask function for auxiliar_task and make a pop of the queue.
				
				
				
			}
			else 
				auxiliar_task = nullptr;

		}
	}
	return true;
}
