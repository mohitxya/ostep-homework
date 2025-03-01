#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main() {
    printf("Before fork (should be visible)\n");

    int pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid == 0) {  // Child process
        close(STDOUT_FILENO);  // Close standard output
        close(STDERR_FILENO);
        printf("This should NOT be visible!\n");  // Won't print
        perror("perror output (should also not be visible)");  // Also won't print
        exit(0);
    } else {  // Parent process
        wait(NULL);  // Give child time to execute
        printf("Parent process: Still working!\n");
    }

    return 0;
}
