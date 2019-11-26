/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

// global vars
int msec = 0;
//get the start time
clock_t start;


void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  printf("Turing was right!\n\n");
  //exit(1); //exit after printing
}

void exitHandler(int num){
  double diff = (double) clock() - start/ (double) CLOCKS_PER_SEC;

  
  printf("Program has been running for %f seconds.\n", diff/1000);
  
}

int main(int argc, char * argv[])
{
  
  start = clock();
  signal(SIGALRM,handler); //register handler to handle SIGALRM

  // create a handler to handle exit event
  signal(SIGINT, exitHandler);

  while(1){
    alarm(1);
    sleep(1);
  }

  return 0; //never reached
}
