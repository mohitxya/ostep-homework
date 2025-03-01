#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {  // Child process
        char *args[] = {"ls", "-l", NULL};
        
        // Uncomment one at a time to test different exec() variants:
	//execl("/bin/ls", "ls", "-l", NULL);       // Uses absolute path, separate args
        execle("/bin/ls", "ls", "-l", NULL, env); // Uses absolute path, custom env
        // execlp("ls", "ls", "-l", NULL);           // Searches PATH, separate args
        // execv("/bin/ls", args);                   // Uses absolute path, array args
       // execvp("ls", args);                          // Searches PATH, array args
        // execvpe("ls", args, env);                 // PATH + custom env
        
        perror("exec failed"); // Only prints if exec() fails
        exit(1);
    } 
    else if (pid > 0) { // Parent process
        wait(NULL); // Wait for child to finish
        printf("Parent process completed.\n");
    } 
    else {
        perror("fork failed");
        exit(1);
    }

    return 0;
}

