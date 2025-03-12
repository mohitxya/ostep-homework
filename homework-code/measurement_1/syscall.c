#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/time.h>


int main(void)
{
        struct timeval start, end;

	gettimeofday(&start, NULL);
	for(int i=0; i<20; i++)
	{
	read(0,NULL,0);
	}
	gettimeofday(&end, NULL);

        long elapsed = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
	
	printf("time: %ld\n", elapsed);
}
