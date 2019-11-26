/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  printf("Turing was right!\n\n");
  //exit(1); //exit after printing
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM

  while(1){
    alarm(1);
    sleep(1);
  }

  return 0; //never reached
}
