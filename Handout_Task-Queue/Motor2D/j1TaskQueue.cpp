#include "j1App.h"
#include "j1Entity.h"
#include "j1Input.h"
#include "j1TaskQueue.h"




bool j1TaskQueue::Update(float dt)
{
	bool ret = false;
	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN)
	{

		if (Temp_Task == nullptr && TaskQueue.size() != 0)
		{
			//TODO 4: Assign the first element of the queue to the auxiliar_task, call InitTask function for auxiliar_task and make a pop of the queue.
			Temp_Task = TaskQueue.front();
			Temp_Task->InitTask();
			TaskQueue.pop();
		}
	}

	ret = Do_Tasks();

	return ret;
}

bool j1TaskQueue::CleanUp()
{
	while (TaskQueue.size() != 0)
	{
		//TODO 3: Pop queue tasks
		TaskQueue.pop();

	}
	return true;
}

bool j1TaskQueue::Enqueue(Task* task)
{
	//TODO 1 Add task to the queue
	TaskQueue.push(task);

	return true;
}

bool j1TaskQueue::Do_Tasks()
{
	if (Temp_Task != nullptr)
	{

		if (Temp_Task->Action())
		{
			if (TaskQueue.size() != 0)
			{
				//TODO 2: Assign the first element of the queue to the auxiliar_task, call InitTask function for auxiliar_task and make a pop of the queue.
				Temp_Task = TaskQueue.front();
				Temp_Task->InitTask();
				TaskQueue.pop();


			}
			else
				Temp_Task = nullptr;

		}
	}
	return true;
}

//Movement methods already done
bool Go_Right::Action()
{
	bool ret = true;

	if (entity->pos.x >= Final_Position.x) {
		entity->pos.x = Final_Position.x;
		ret = true;
	}
	else {
		entity->pos.x += entity->speed.x;
	}
	return ret;
}

bool Go_Left::Action()
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
bool Go_Up::Action()
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
bool Go_Down::Action()
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