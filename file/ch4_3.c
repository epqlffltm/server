/*
2026-02-13
파일 기술자 할당
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(void)
{
  int fd = -1;

  close(0);

  fd = open("text.txt", O_RDWR);
  if(fd == -1)
  {
    perror("open error");
    exit(1);
  }
  printf("text.txt fd: %d\n", fd);

  clode(fd);

  return 0;
}