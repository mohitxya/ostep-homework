# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>


global int f=0;

int main(void)
{
	printf("Before fork: (PID: %d)\n",getpid());
	int rx=fork();
	if(rx==0)
	{
	//	printf("Child process: (PID: %d, Parent PID: %d)\n",getpid(),getppid());
		printf("hello\n");
		f=1;
	}
	else if (rx<0)
	{
		printf("Child creation failed! \n");
	}
	else
	{
	//	printf("Parent process: (PID: %d, Child PID: %d)\n",getpid(),rx);
		if(f==1){	
		printf("Goodbye\n");
		}
	}

}
