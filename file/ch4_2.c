/*
2026-02-13
O_EXCL 플래그 사용하기
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

  fd = open("test2.txt", O_CREAT | O_EXCL, 0644);

  if(fd == -1
  {
    perror("open error");
    exit(1);
  }

  close(fd);

  return 0;
}