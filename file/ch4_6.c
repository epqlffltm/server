/*
2026-02-13
파일 오프셋
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>

int main(void)
{
  int fd = -1, n = -1;
  off_t start, cur;
  char buf[256];

  int flags = O_CREAT | O_WRONLY | O_TRUNC;
  mode_t mode = S_IRUSR | S_IWUSRF | S_IRGRP | S_IROTH;

  fd = open("tmp.aaa", flags, mode);
  if(fd == -1)
  {
    perror("open error");
    exit(1);
  }
  close(1);

  fd1 = dup(df);
  if(fd1 == -1)
  {
    perror("dup error");
    exit(1);
  }

  printf("DUP FD = %d\n",fd1);
  printf("Hello World!!\n");

  close(fd);

  return 0;
}