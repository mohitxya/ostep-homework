# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
int main(void)
{
	int x;
	x=100;
	printf("Before fork: x=%d (PID: %d)\n",x,getpid());

	int rx=fork();

	if(rx==0)
	{
		x+=200;
		printf("Child process: x=%d (PID: %d, Parent PID: %d)\n",x,getpid(),getppid());
	}
	else if (rx<0)
	{
		printf("Child creation failed! \n");
	}
	else
	{
		x=300;
		printf("Parent process: x=%d (PID: %d, Child PID: %d)\n",x,getpid(),rx);
		wait(NULL);
	}

}
