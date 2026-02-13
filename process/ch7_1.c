/*
2026-02-13
system()함수로 프로그램 실행하기
*/

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
  int ret = system("ps -ef | grep sshd > sshd.txt");
  if(ret == -1)
  {
    perror("system() error");
    exit(1);
  }

  printf("%d\n", ret);

  return 0;
}