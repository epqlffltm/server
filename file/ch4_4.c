/*
2026-02-13
파일 읽기
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(void)
{
  int fd = -1 , n = -1;
  char buf[100];

  int flags = O_RDWR | O_CREAT;
  mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;//파일 권한 0644

  fd = open("linux.txt", flags, mode);//파일 열기
  if (fd == -1)
  {
    perror("open error");
    exit(1);
  }

  n = read(fd, buf, 5);
  if(n == -1)
  {
    perror("read error");
    exit(1);
  }

  buf[n] = '\0';

  printf("read data: %s\n", buf);

  close(fd);

  return 0;
}