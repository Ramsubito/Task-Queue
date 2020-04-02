#include "j1App.h"
#include "j1Entity.h"
#include "j1Input.h"
#include "j1TaskQueue.h"



bool Left::Movement()
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

bool Right::Movement()
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

bool Up::Movement()
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

bool Down::Movement()
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
		
		if (Task_temp == nullptr && TaskQueue.size() != 0)
		{
			//TODO 4: Assign the first element of the queue to the auxiliar_task, call InitTask function for auxiliar_task and make a pop of the queue.
			
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
	//TODO 1: Add a task to the Queue
	

	return true;
}

bool j1TaskQueue::DoTasks()
{
	
	if (Task_temp != nullptr)
	{
		
		if (Task_temp->Action())
		{
			if (TaskQueue.size() != 0)
			{
				//TODO 2: Assign the first element of the queue to the auxiliar_task, call InitTask function for auxiliar_task and make a pop of the queue.
				
				
				
			}
			else 
				Task_temp = nullptr;

		}
	}
	return true;
}
