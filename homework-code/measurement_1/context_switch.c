#define _GNU_SOURCE  // Needed for sched_setaffinity
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sched.h>

#define ITERATIONS 100000

void bind_to_cpu(int cpu) {
    cpu_set_t mask;
    CPU_ZERO(&mask);
    CPU_SET(cpu, &mask);
    sched_setaffinity(0, sizeof(mask), &mask);
}

int main() {
    int pipe1[2], pipe2[2];
    pid_t pid;
    struct timeval start, end;

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

    long elapsed = (end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);
    double avg_time = (double)elapsed / (ITERATIONS * 2);  // Two switches per iteration

    printf("Total time: %ld microseconds\n", elapsed);
    printf("Average context switch time: %.6f microseconds\n", avg_time);

    return 0;
}
