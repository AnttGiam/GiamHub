#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>

void figlio(int);
int main(int argc, char* argv[])
{
  pid_t pid;
  struct stat buf;
  pid=fork();
  if(pid==0) // figlio
  {
    signal(SIGALRM,figlio);
    if(lstat(argv[1],&buf)<0)
      printf("Impossibile Aprire File\n");
    pause();
  }
  else //padre
  {
    if(lstat(argv[1],&buf)!=-1){
    if(S_ISREG(buf.st_mode)){
      printf("Regular File\n");
      printf("%lld bytes\n",buf.st_size);}
      else if(S_ISDIR(buf.st_mode)) printf("Directory File\n");
      else if(S_ISCHR(buf.st_mode)) printf("Charachter Special File\n");
      else if(S_ISBLK(buf.st_mode)) printf("Block File\n");
      else if(S_ISLNK(buf.st_mode)) printf("Symbolic Link File\n");
    printf("%d UserID\n",buf.st_uid);
    printf("PERMISSIONS %d \n",buf.st_mode& (S_IRWXU | S_IRWXG | S_IRWXO));
    //execlp("ls","ls","-l",argv[1],(char*)0);
    kill(pid,SIGALRM);
  }
}
}


void figlio(int signo)
{
  printf("Sono il Figlio...\n");
}
