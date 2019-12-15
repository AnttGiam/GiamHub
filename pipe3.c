
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
int fd[2],fd2[2],c;
int num1,num2,res;
char op;
pid_t pid;
pipe(fd);
pipe(fd2);
pid=fork();
if(pid==0) //figlio
{
  close(fd[0]);
  close(fd2[1]);
  read(fd2[0],&num1,sizeof(num1));
  read(fd2[0],&num2,sizeof(num2));
  read(fd2[0],&op,sizeof(op));
  if(op=='+') res=num1+num2;
  else if(op=='-') res=num1-num2;
  else if(op=='*') res=num1*num2;
  else if(op=='/') res=num1/num2;
  else printf("ERROR\n");
  write(fd[1],&res,sizeof(res));
}
else //padre
{
    close(fd[1]);
    close(fd2[0]);
    printf("Inserisci primo operando: ");
    scanf("%d",&num1);
    write(fd2[1],&num1,sizeof(num1));
    printf("Inserisci secondo operando: ");
    scanf("%d",&num2);
    write(fd2[1],&num2,sizeof(num2));
    fflush(stdin);
    printf("Inserisci operatore: ");
    scanf("%c",&op);
    write(fd2[1],&op,sizeof(op));
    read(fd[0],&res,sizeof(res));
    printf("Il risultato è: %d\n",res);
  }
exit(0);
}
