 #### Solutions:

Q.1) 
- The race condition occurred at line 8 and line 15, as illustrated by the `helgrind` output. 
- Additionally the program identified the variable name, Threads involved, Status of locks, & Call Stack for each thread. 

Q.2)
- `helgrind` reported that while main thread's access was now protected, the worker threads access was still unprotected. 
- After adding locking mechanism to both the worker and main thread. `helgrind` reported 0 errors. 

Q.3)
- thread 0 tries to lock m1 then m2, while thread 1 tries to lock m2 then m1. 
- Creating a thread doesn't guarantee immediate execution, it merely schedules execution. 
- So a thread may try to lock an already locked resource resulting in deadlock. 

Q.4)
- Helgrind expects threads to acquire m1 before m2. It reports "lock order violation".
- It tracks lock acquisition order across all threads. 
- Fix: Always acquire locks in the same order in all threads. 

Q.5)
- thread 0 locks g, thread 1 tries to lock g but it's blocked, thread 0 locks m1->m2 safely, thread 1 acquires g, then m2->m1.
- Deadlock becomes impossible now. 
- Helgrind still reports "lock order violation"

Q.6)
- Here we are using a global variable instead of a condition variable. 
- So a lot of CPU cycles are used up in checking the condition. 
- Condition variables use mutex + wait/signal mechanism.
- So, the while loop does not looping continuously. 
- wait() releases the mutex lock and puts the thread to sleep. 
- At this point the thread is not executing the loop. It's completely off the CPU. 
- The OS won't schedule it until `pthread_cond_signal()` is called. 

Q.7)
- Helgrind detected 2 data races on the shared variable `done`.
- Reading and writing, with no locks held. 

Q.8)
- Every access to done is guarded by lock. 
- We use wait/signal pattern to avoid wastage of the CPU cycles. 
- It is both correct and efficient. 

Q.9)
- Helgrind shows 0 errors. 
