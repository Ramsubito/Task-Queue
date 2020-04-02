#ifndef _TASKQUEUE_H__
#define _TASKQUEUE_H__

#include "p2Point.h"
#include <queue>
#include "j1Module.h"
#include "j1Entity.h"



class Task {

public:
	Task(Entity* ent) : entity(ent) {};
	~Task() {};
	Entity* entity;
	virtual bool Action() { return true; };
	virtual void InitTask() {};
};

class j1TaskQueue: public j1Module
{
public:
	j1TaskQueue() {};
	virtual ~j1TaskQueue() {};


	bool Update(float dt);
	bool CleanUp();

	bool EnqueueTask(Task* task);
	bool DoTasks();

private:

	std::queue<Task*> TaskQueue;
	
public:
	Task* auxiliar_task = nullptr;
};

//moving to diferent directions as different tasks.

class Left : public Task
{
public:
	Left(Entity* entity) : Task(entity) {};
	~Left() {};

	bool Movement();
	iPoint Final_Position;
	void StartTask() { Final_Position.x = entity->pos.x - entity->rect.w; };
};


class Right : public Task
{
public:
	Right(Entity* entity) : Task(entity) {};
	~Right() {};

	bool Movement();
	iPoint Final_Position;
	void StartTask() { Final_Position.x = entity->pos.x + entity->rect.w; };
};

class Up : public Task
{
public:
	Up(Entity* entity) : Task(entity) {};
	~Up() {};

	bool Movement();
	iPoint Final_Position;
	void StartTask() { Final_Position.y = entity->pos.y - entity->rect.h; };
};

class Down : public Task
{
public:
	Down(Entity* entity) : Task(entity) { };
	~Down() {};

	bool Movement();
	iPoint Final_Position;
	void StartTask() {Final_Position.y = entity->pos.y + entity->rect.h;};
};
#endif // !_TASKMANAGER_H__

