# About Me
I'm Marc Ramos, a second year student of the backelor's degree in VideoGames by UPC at CITM. This content is generated for the second year 's subject Project 2, under supervision of lecturer.
### Portfolio
https://github.com/Ramsubito

https://www.artstation.com/ramsubo

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
![Push](https://github.com/Ramsubito/Task-Queue/blob/master/Wiki%20Images/Captura.PNG)

### Pull queues
pull() function is used to remove an element from the front of the queue(oldest element in the queue). The element is removed to the queue container and the size of the queue is decreased by 1.
![Pull](https://github.com/Ramsubito/Task-Queue/blob/master/Wiki%20Images/Captura2.PNG)

### Front
Access next element. Returns a reference to the next element in the queue.The next element is the "oldest" element in the queue and the same element that is popped out from the queue when queue::pop is called.

This member function effectively calls member front of the underlying container object.

# Exercices
There is a handout with an entity requesting multiple task to do.The main goal is to add tasks to a queue and then activate those tasks to perform in the order we have called them. Before doing the exercises check queues and push, pull and front information.
### TODO 1
There is a queue of tasks already created, add a task to that queue.
## TODO 2
We need to asign the first element of the queue to an auxiliar temporal task, and execute that task. Then pop the task queue.
## TODO 3
On the cleanup,  we will need to Pop the task queue when it's still not empty.
## TODO 4
On this to do we will start executing the tasks. When we press a key we will need to execute the task. Adding the task to our auxiliar task and then doing a pop to that  task.
## TODO 5
Finally we will need the player to move to check if it's working. Movement methods are already done you'll just need to call them when pressing the key you choose.

# Interesting extra information
### More about task Queues concept
https://www.youtube.com/watch?v=22n06z0rq4c

### Videogames examples
https://gameprogrammingpatterns.com/event-queue.html
https://www.youtube.com/watch?v=TBWukQAhrBk
https://www.youtube.com/watch?v=dmebSeDIMts

# Commands
Arrow to move camera.

W,S,D,A to choose the moves the player will move(Only on solution)

Space to execute tasks(Only on solution)
