/*
2026-02-13
fock()함수로 프로세스 생성하기
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(void)
{
  pid_t pid;

  switch (pid = fork())
  {
  case -1:
    perror("fork() error");
    exit(1);
    break;

  case 0:
    printf("Child Process: my pid=%d, parent pid=%d\n", getpid(), getppid());
    break;
  
  default:
    printf("Parent Process: my pid=%d, child pid=%d\n, PID=%d\n", getpid(), getppid(), pid);
    break;
  }

  return 0;
}