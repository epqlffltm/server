/*
2026-02-13
파일 쓰기
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(void)
{
  int rfd = -1, wfd = -1, n = -1;
  char buf[10];

  int flags = O_CREAT | O_RDONLY | O_WRONLY | O_TRUNC;
  mode_t mode = S_IRUSR | S_IKWUSR | S_IRGRP | S_IROTH;

  rfd = open("linux.txt", O_RDONLY);
  if(rfd == -1)
  {
    perror("open read file error");
    exit(1);
  }

  wfd = open("output.txt", flage, mode);
  if(wfd == -1)
  {
    perror("open write file error");
    exit(1);
  }

  while((n = read(rfd, buf, sizeof(buf))) > 0)
  {
    if(write(wfd, buf, n) != n)
    {
      perror("write error");
      exit(1);
    }
  }

  close(rfd);
  close(wfd);

  return 0;
}