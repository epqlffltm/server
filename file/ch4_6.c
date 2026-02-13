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
  mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

  fd = open("linux.txt", flags, mode);
  if(fd == -1)
  {
    perror("open error");
    exit(1);
  }

  start = lseek(fd, 0, SEEK_CUR);
  n = read(fd, buf, (sizeof(buf)-1));
  buf[n] = '\0';
  printf("start: %ld, read string: %s, n: %d\n", start, buf, n);

  cur = lseek(fd, 0, SEEK_CUR);
  printf("current offset: %ld\n", cur);

  start = lseek(fd, 0, SEEK_SET);
  n = read(fd, buf, (sizeof(buf)-1));
  buf[n] = '\0';
  printf("start: %ld, read string: %s, n: %d\n", start, buf, n);

  return 0;
}