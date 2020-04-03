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
public:
	Task* Temp_Task = nullptr;

private:
	std::queue<Task*> TaskQueue;
};

//Movement methods already added 
class Go_Right : public Task
{
public:
	Go_Right(Entity* entity) : Task(entity) {};
	~Go_Right() {};

public:
	iPoint Final_Position;
	virtual void InitTask() {Final_Position.x = entity->pos.x + 100;};
	bool Action();
	
};

class Go_Left : public Task
{
public:
	Go_Left(Entity* entity) : Task(entity) {};
	~Go_Left() {};

public:
	iPoint Final_Position;
	virtual void InitTask() { Final_Position.x = entity->pos.x - 100; };
	bool Action();

};
class Go_Up : public Task
{
public:
	Go_Up(Entity* entity) : Task(entity) {};
	~Go_Up() {};

public:
	iPoint Final_Position;
	virtual void InitTask() { Final_Position.y = entity->pos.y - 100; };
	bool Action();

};

class Go_Down : public Task
{
public:
	Go_Down(Entity* entity) : Task(entity) { };
	~Go_Down() {};

public:
	iPoint Final_Position;
	virtual void InitTask() { Final_Position.y = entity->pos.y +100; };
	bool Action();
	
};
#endif // !_TASKMANAGER_H__

