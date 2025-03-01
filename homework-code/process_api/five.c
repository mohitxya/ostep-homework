# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>



int main(void)
{
	printf("Before fork: (PID: %d)\n",getpid());
	int rx=fork();
	if(rx==0)
	{
		printf("Child process: (PID: %d, Parent PID: %d)\n",getpid(),getppid());
		printf("hello\n");
	}
	else if (rx<0)
	{
		printf("Child creation failed! \n");
	}
	else
	{
		int k = waitpid(rx,NULL,0);
		printf("Parent process: (PID: %d, Child PID: %d)\n",getpid(),rx);
		printf("Goodbye %d\n",k);
	}

}
