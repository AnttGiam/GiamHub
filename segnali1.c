#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void controlc(int);

int main()
{
  signal(SIGINT,controlc);
  for(; ;)
    pause();
  exit(1);
}

void controlc(int signalcode)
{
    printf("Hai premuto CTRL+C\n");
}
