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
	virtual void StartTask() {};
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
	Task* Task_temp = nullptr;
};

//moving to diferent directions as different tasks.

class Punch : public Task
{
public:
	Punch(Entity* entity) : Task(entity) {};
	~Punch() {};

	bool Attack();
	iPoint Final_Position;
	void StartTask() { Final_Position.x = entity->pos.x - entity->rect.w; };
};


class Kick : public Task
{
public:
	Kick(Entity* entity) : Task(entity) {};
	~Kick() {};

	bool Attack();
	iPoint Final_Position;
	void StartTask() { Final_Position.x = entity->pos.x + entity->rect.w; };
};

class Kame : public Task
{
public:
	Kame(Entity* entity) : Task(entity) {};
	~Kame() {};

	bool Attack();
	iPoint Final_Position;
	void StartTask() { Final_Position.y = entity->pos.y - entity->rect.h; };
};

class Charge_Ki : public Task
{
public:
	Charge_Ki(Entity* entity) : Task(entity) { };
	~Charge_Ki() {};

	bool Attack();
	iPoint Final_Position;
	void StartTask() {Final_Position.y = entity->pos.y + entity->rect.h;};
};
#endif // !_TASKMANAGER_H__

