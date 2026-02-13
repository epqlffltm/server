/*
2026-02-13
fcnfl()함수로 파일 기술자 제어하기
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>

int main(void)
{
  int fd = -1, flags = O_RDWR;
  
  mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
  
  fd = open("linux.txt", flags, mode);
  if(fd == -1)
  {
    perror("open error");
    exit(1);
  }

  if((flags = fcntl(fd, F_GETFL)) == -1)
  {
    perror("fcntl F_GETFL error");
    exit(1);
  }

  flags |= O_APPEND;

  if(fcntl(fd, F_SETFL, flags) == -1)
  {
    perror("fcntl F_SETFL error");
    exit(1);
  }

  if(write(fd, "Hello Linux\n", 15) != 15)
  {
    perror("write error");
    exit(1);
  }

  close(fd);

  return 0;
}