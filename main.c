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
    return time1;
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
      return time2;
    } else {
      int status;
      int child_pid = wait(&status);
      printf("Main Process %d is done. Child %d slept for %d sec\n", getpid(), child_pid, WEXITSTATUS(status));
      return 0;
    }
  }

  return 0;
}
