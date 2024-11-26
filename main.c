#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {
  printf("%d about to create 2 child processes\n", getpid());
  pid_t p;
  p = fork();
  if (p == -1) {
    perror("Failed to fork");
    exit(1);
  } else if (p == 0) {
    pid_t pid1 = getpid();
    srand(pid1);
    int time1 = (rand()%4)+1;
    printf("%d: %d sec\n", pid1, time1);
  } else {
    printf("Hello from Parent!\n");
    p = fork();
    if (p == -1) {
      perror("Failed to fork");
      exit(1);
    } else if (p == 0) {
      pid_t pid2 = getpid();
      srand(pid2);
      int time2 = (rand()%4)+1;
      printf("%d: %d sec\n", pid2, time2);
    }
  }



  return 0;
}
