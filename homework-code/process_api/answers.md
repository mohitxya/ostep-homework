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
* fork() creates a new child process.
* exec() replaces the child process with a new process.
* This new process inherits the PID of the old one.
* Has new memory space.

5. **wait() in the child process**:
* wait outputs the PID of child process when parent executes it.
* wait outputs -1 if no child process remains.

6. **using waitpid()**:
* waitpid allows us to wait for a specific process, instead of any child.
* usage: waitpid(pid_of_child, exit_value, {0: default, i.e. blocks until child exits}) 

7. **Closes STDOUT_FILENO**:
* Closing the file descriptor 1: STDOUT_FILENO causes the child's print statement to not work.
* Similarly, we could also closea STDERR_FILENO.

8. **Connects standard output of one to standard input of the other using pipe()**:
* using pipe we can communicate between two processes.
* ```int fd[2]: treat 0 as read and 1 as write ```
* We close read while writing and close write while reading.
* ```write(fd[1],message,size(message)) and read(fd[0],buffer,sizeof(buffer))```
