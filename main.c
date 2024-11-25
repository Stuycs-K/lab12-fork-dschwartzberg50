#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  printf("%d about to create 2 child processes\n", getpid());
  pid_t p;
  p = fork();
  if(p<0){
    perror("fork fail");//output to stderr instead of stdout
    exit(1);
  } else if ( p == 0){
      printf("Hello from Child!\n");
  }else{
      printf("Hello from Parent!\n");
      p = fork();
      if(p<0){
        perror("fork fail");//output to stderr instead of stdout
        exit(1);
      } else if ( p == 0){
          printf("Hello from Child!\n");
      }else{
          printf("Hello from Parent!\n");
      }
  }
  return 0;
}
