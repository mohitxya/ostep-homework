## todo
* Measure the cost of system call
* Measure the cost of context switch

```c

 pipe(pipe1);  // Parent writes, child reads
    pipe(pipe2);  // Child writes, parent reads

    if ((pid = fork()) == 0) {
        // Child process
        bind_to_cpu(0);  // Ensure same CPU
        char msg = 'X';
        for (int i = 0; i < ITERATIONS; i++) {
            read(pipe1[0], &msg, 1);
            write(pipe2[1], &msg, 1);
        }
        exit(0);
    }

    // Parent process
    bind_to_cpu(0);
    char msg = 'X';

    gettimeofday(&start, NULL);
    for (int i = 0; i < ITERATIONS; i++) {
        write(pipe1[1], &msg, 1);
        read(pipe2[0], &msg, 1);
    }
    gettimeofday(&end, NULL);


```
## Explanation:
- The parent writes to pipe 1 and child reads from it and vice-versa. 
- If in our child process there is nothing to read, the OS puts the process in blocked mode.
- OS thus switches to parent process, this back and forth is known as "Context switching".
- The bind to CPU function makes sure that the process executes on a particular core of the processor. 




