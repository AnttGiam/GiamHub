
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>

int main()
{
int fd[2];
char file1[30],file2[30];
pid_t pid;
pipe(fd);
pid=fork();
if(pid==0) //figlio
{
  int fdout;
  close(fd[1]);
  read(fd[0],file1,sizeof(file1));
  read(fd[0],file2,sizeof(file2));
  fdout=open(file2,O_WRONLY | O_CREAT);
  if(fdout==-1)
  {
    printf("ERROR OPEN FILE\n");
    exit(-1);
  }
  printf("%d",fdout);
  close(1);
  dup(fdout);
  execlp("sort","sort",file1,NULL);
  exit(0);
}
else //padre
{
    close(fd[0]);
    printf("Inserisci il nome del primo file: ");
    scanf("%s",file1);
    write(fd[1],&file1,sizeof(file1));
    printf("Inserisci il nome del secondo file: ");
    scanf("%s",file2);
    write(fd[1],&file2,sizeof(file2));
  }
exit(0);
}
