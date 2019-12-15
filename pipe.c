#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	char file[30],n[30];
	scanf("%s",file);
	//printf("%s\n",file);
	int fd[2],c;
	pid_t pid,pid1;
	pipe(fd);
	pid=fork();
	if(pid==0) //figlio
	{
		close(fd[0]);
		close(1);
		dup(fd[1]);
		close(fd[1]);
		execlp("cat", "cat", file, (char*) 0);
	}
	//else if(pid)//figlio
	else
	{
		//pid1=fork();
		//if(pid1==0)
		//{
			close(fd[1]);
			close(0);
			dup(fd[0]);
			close(fd[0]);
			execlp("more","more",(char*)0);
		}
		/*else if(pid1)
		{
		close(fd[0]);
		close(fd[1]);
		wait(NULL);
		wait(NULL);
		}
	}*/
	exit(0);
}
