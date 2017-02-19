# Project 1 Questions:
- Brandon Tarney
- Date: 2/18/2017

## How would you create an environment to run the five philsophers? Could all five run in a single threaded process? Five separate processes? Other ways?

Briefly, it would seem the obvious options are to run all 5 philsophers in single, non-threaded, program which wouldn't allow for anything close to true concurrency and thus may defeat some of the problem. 

Alternatively, we could spawn 1 thread for each philosopher so that they would appear to be running concurrently and thus truly competing for forks. Additionally, shared process memory would allow easy access to semaphores for the five philosopher threads. 

Finally, we could also develop an executable which shares memory (perhaps a file) and run 5 instances of it to simulate 5 philosophers. This would have the most ideal concurrency conflicts we can generate (could potentially run all 5 programs on separate cores) however it would be the most difficult to implement, especially given the framework of code provided.

For the reasons provided above I will implement the dining philosophers problem using threads.


## The semaphore 'mutex' is used to protect critical regions: Describe how each of these regions is critical - that is, clearly describe the problems that could arise if these regions were note protected by the mutex semaphore. 

The critical region is the part of a program which accesses a shared resource, which is ideally protected, in this case, by a semaphore 'mutex'. The shared resource that is accessed in this example is a fork and thus the semaphore protect the regions of the code which access the fork: namely take_forks() and put_forks(). If there is no protection on these methods then fundamental problems may arise. First of all forks may be taken in a sub-optimal manner. This could mean each philsopher gets 1 fork, but none get 2, resulting in all the processes in deadlock and unable to continue. Alternatively, one process could grab 2 forks but the rest could grab just 1 resulting in only 1 philosopher eating at a time, which is suboptimal use of the forks. A separate problem could arise as well: depending on how your resources are allocated/protected, multiple processes could grab the same resource, believing they alone posess it. In the context of this analogy, imagine two philosophers fighting over a fork...or better yet, imagine the two using the same fork, both thinking they will get a bite, only for one of them to see the food dissapear right as they take a bite. Clearly, the philosophers need a way of knowing who has a fork, who needs a fork, and when a fork is available all of which a semaphore (mutex) can provide.
