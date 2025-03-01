# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
int main(void)
{
	FILE *f;
	f=fopen("test.txt","wb");
	if(f==NULL)
	{
		printf("Error while opening the file. \n");
		return 1;
	}
	printf("Before fork: (PID: %d)\n",getpid());
        fflush(f);
	int rx=fork();

	if(rx==0)
	{
		if(f!=NULL)
		{
			printf("Child: Can access the file descriptor.\n");
			fprintf(f, "Message from CHILD (PID: %d)\n", getpid());
	                fflush(f);
		}
		else 
		{
			printf("Can't access the file descriptor.\n");
		}

		printf("Child process: (PID: %d, Parent PID: %d)\n",getpid(),getppid());
		fclose(f);
	}
	else if (rx<0)
	{
		printf("Child creation failed! \n");
	}
	else
	{
		if(f!=NULL)
		{
			printf("Parent: Can access the file descriptor.\n");
			fprintf(f, "Message from PARENT (PID: %d)\n", getpid());
			fflush(f);
		}
		else
		{
			printf("Can't access the file descriptor.\n");
		}
		printf("Parent process: (PID: %d, Child PID: %d)\n",getpid(),rx);
		wait(NULL);
		printf("Child has finished it's process. \n");
		fclose(f);
	}

}
