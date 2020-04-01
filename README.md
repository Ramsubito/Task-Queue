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
 
 For that we need lists for the tasks.
 ![Lists](https://github.com/Ramsubito/Task-Queue/blob/master/Wiki%20Images/code%20example.PNG)

## Types of task queues
Queue are a type of container adaptors which operate in a first in first out (FIFO) type of arrangement. Elements are inserted at the back (end) and are deleted from the front.
### Push queues
push() function is used to insert an element at the back of the queue. The element is added to the queue container and the size of the queue is increased by 1.
### Pull queues
pull() function is used to remove an element from the front of the queue(oldest element in the queue). The element is removed to the queue container and the size of the queue is decreased by 1.

## Command Pattern
The fact of encapsulating the function and all the variables it need to be performed it's known as Command pattern.
When we want to do a task from an input we usually call a function when the key is pressed, but there's a problem with that because the keys are blinded to what the programmer decides in the code. But if we want the user to be able to change the key bindings we must use  some kind of method that allows us to swap those function calls. We will turn our functions into objects using tasks.

First we must define the functions we want to active as objects.
