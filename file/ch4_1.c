/*
2026-02-13
새파일 생성학습
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(void)
{
  int fd = 0;
  mode_t mode;

  mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;//파일 권한 0677

  fd = open("text.txt", O_CREAT, mode);//파일 생성

  if (fd == -1)
  {
    perror("open error");
    exit(1);
  }

  printf("text.txt fd: %d\n", fd);

  close(fd);

  return 0;
}