# Task-Queue
 Task queue is a mechanism to distribute a sequence of tasks among parallel threads of execution. The main problem is broken down into tasks and the tasks are enqueued onto the queue. So, parallel threads of execution pull tasks from the queue and execute computations on the tasks.
 
 A task can be defined as an encapsulation of a function inside an object, so when we use tasks we want to transform our methods into classes, that way we can use object operators with them.
We want to call the function we encapsulated in DoTask() method, so we can access the function and use it as an object. Check example.

![Task class](https://github.com/Ramsubito/Task-Queue/blob/master/Wiki%20Images/TaskClass.PNG)

## Task queue in videogames
Imagine you want a task to be done after a certain condition, that's when queued tasks come in.

Your player is requesting a task. And you make him do a task, and then another, but if he has not finished the first task the next one will be queued until the condition is done. Imagine you ask the player to clean up the floor like in this example, and then yo make him move to another spot, the task of moving will be queued, and will execute once he has cleaned the prevoious task.
![Task request](https://github.com/Ramsubito/Task-Queue/blob/master/Wiki%20Images/Request%20next%20task.PNG)
![Task in process](https://github.com/Ramsubito/Task-Queue/blob/master/Wiki%20Images/task%20request1.PNG)

We will select the tasks we want to do and enqueue them. Once the first one called is done, the next will execute and so one.


## Types of task queues
Queue are a type of container adaptors which operate in a first in first out (FIFO) type of arrangement. Elements are inserted at the back (end) and are deleted from the front.A task queue must be created firts.
### Push queues
push() function is used to insert an element at the back of the queue. The element is added to the queue container and the size of the queue is increased by 1.

### Pull queues
pull() function is used to remove an element from the front of the queue(oldest element in the queue). The element is removed to the queue container and the size of the queue is decreased by 1.

