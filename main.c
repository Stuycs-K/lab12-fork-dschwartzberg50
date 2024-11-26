#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

int main() {
  int ppid = getpid();
  printf("%d about to create 2 child processes\n", ppid);
  pid_t p;
  p = fork();
  if (p == -1) {
    perror("Failed to fork");
    exit(1);
  } else if (p == 0) {
    pid_t pid1 = getpid();
    srand(pid1);
    unsigned int time1 = (rand()%5)+1;
    printf("%d: %d sec\n", pid1, time1);
    sleep(time1);
    printf("%d finished after %d sec\n", pid1, time1);
  } else {
    p = fork();
    if (p == -1) {
      perror("Failed to fork");
      exit(1);
    } else if (p == 0) {
      pid_t pid2 = getpid();
      srand(pid2);
      unsigned int time2 = (rand()%5)+1;
      printf("%d: %d sec\n", pid2, time2);
      sleep(time2);
      printf("%d finished after %d sec\n", pid2, time2);
    } else {
      int status;
      wait(&status);
      printf("main program here\n");
      printf("WEXITSTATUS: %d\n", WEXITSTATUS(status));
      printf("WIFEXITED: %d\n", WIFEXITED(status));
      printf("WIFSIGNALED: %d\n", WIFSIGNALED(status));
      printf("WTERMSIG: %d\n", WTERMSIG(status));
      printf("Main Process %d is done. Child _EXITING_CHILD_PID_ slept for _SEC_ sec", getpid());
    }
  }



  return 0;
}
