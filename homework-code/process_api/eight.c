#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd[2];  // File descriptors for pipe
    char buffer[100];

    if (pipe(fd) == -1) {  // Create a pipe
        perror("Pipe failed");
        exit(1);
    }
    // the pipe term needs an array of two integers.
// 0 is read and 1 is write. 
    //  pid 1: we close read and just use write.
    //  pid 2: we close write and just use read.
    pid_t pid1 = fork();  // First child
    if (pid1 == 0) {
        close(fd[0]);  // Close unused read end
        char message[] = "Hello from Child 1!";
        write(fd[1], message, sizeof(message));  // Write to pipe
        close(fd[1]);  // Close write end
        exit(0);
    }

    pid_t pid2 = fork();  // Second child
    if (pid2 == 0) {
        close(fd[1]);  // Close unused write end
        read(fd[0], buffer, sizeof(buffer));  // Read from pipe
        printf("Child 2 received: %s\n", buffer);  // Print message
        close(fd[0]);  // Close read end
        exit(0);
    }

    // Parent closes pipe and waits for both children
    close(fd[0]);
    close(fd[1]);
    wait(NULL);
    wait(NULL);

    return 0;
}
