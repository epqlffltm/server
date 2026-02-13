/*
2026-02-13
dup2() 함수로 파일 기술자 복사하기
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(void)
{
  int fd = -1;

  int flags = O_CREAT | O_WRONLY | O_TRUNC;
  mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

  fd = open("tmp.bbb", flags, mode);
  if(fd == -1)
  {
    perror("open error");
    exit(1);
  }

  dup2(fd, 1);
  printf("DUP2 FD: %d\n", fd);

  close(fd);

  return 0;
}