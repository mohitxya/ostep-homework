## Explanation for the programs:

1. Child gets a copy of the parent's address space. The key word here is 'copy', i.e. They don't share an address space. 
* So editing the variable value in child doesn't affect the parent't variable value.

2. 
> Before fork: (PID: 4344)
Parent: Can access the file descriptor.
Parent process: (PID: 4344, Child PID: 4345)
Child: Can access the file descriptor.
Child process: (PID: 4345, Parent PID: 4344)

* Child can access the file descriptor.


> Before fork: (PID: 4863)
Parent: Can access the file descriptor.
Parent process: (PID: 4863, Child PID: 4864)
Child: Can access the file descriptor.
Child process: (PID: 4864, Parent PID: 4863)
Child has finished it's process.

* The wait(NULL) command forces parent to wait till child finishes it's execution.

3. "hello" and "goodbye": ensure child always prints first

* One way to do this is by adding a wait statement before the parent starts it's execution.
* **_without wait()_**: shared memory space to use a variable as flag, add delay in parent process using usleep(1000); //1 ms delay

4. **fork the exec:** 
5. **wait() in the child process**:
6. **using waitpid()**:
7. **Closes STDOUT_FILENO**:
8. **Connects standard output of one to standard input of the other using pipe()**:
