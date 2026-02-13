/*
  2026-02-13
  파일 기술자 복사하기
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(void)
{
  int fd = -1, fd_copy = -1;
  int flags = O_CREAT | O_WRONLY | O_TRUNC;
  mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

  fd = open("tem.aaa", flags, mode);
  if(fd == -1)
  {
    perror("open error");
    exit(1);
  }
  close(1);

  fd_copy = dup(fd);
  if(fd_copy == -1)
  {
    perror("dup error");
    exit(1);
  }

  printf("DUP FD: %d\n", fd_copy);
  
  close(fd);
  close(fd_copy);
  
  return 0;
}