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

class j1TaskQueue : public j1Module
{
public:
	j1TaskQueue() {};
	virtual ~j1TaskQueue() {};


	bool Update(float dt);
	bool CleanUp();

	bool Enqueue(Task* task);
	bool Do_Tasks();

private:

	std::queue<Task*> TaskQueue;

public:
	Task* auxiliar_task = nullptr;
};



class MoveLeft : public Task
{
public:
	MoveLeft(Entity* entity) : Task(entity) {};
	~MoveLeft() {};

	bool Action();
	iPoint finalpos;
	void InitTask() { finalpos.x = entity->pos.x - 100; };
};


class MoveRight : public Task
{
public:
	MoveRight(Entity* entity) : Task(entity) {};
	~MoveRight() {};

	bool Action();
	iPoint finalpos;
	void InitTask() { finalpos.x = entity->pos.x + 100; };
};

class MoveUp : public Task
{
public:
	MoveUp(Entity* entity) : Task(entity) {};
	~MoveUp() {};

	bool Action();
	iPoint finalpos;
	void InitTask() { finalpos.y = entity->pos.y - 100; };
};

class MoveDown : public Task
{
public:
	MoveDown(Entity* entity) : Task(entity) { };
	~MoveDown() {};

	bool Action();
	iPoint finalpos;
	void InitTask() { finalpos.y = entity->pos.y +100; };
};
#endif // !_TASKMANAGER_H__

