#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
//#include<sys/wait.h>
int main()
{
  char file[30];
  char n[30];
  scanf("%s",file);
  int fd[2];
  pid_t pid;
  pipe(fd);
  pid=fork();
  if(pid>0) //padre
  {
    close(fd[0]);
    write(fd[1],file,30);
  }
  else //figlio
  {
    close(fd[1]);
    int c=read(fd[0],n,30);
    write(STDOUT_FILENO,n,c);
  }
  return 0;
}
