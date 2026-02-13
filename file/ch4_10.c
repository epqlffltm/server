/*
2026-02-13
remove() 함수로 파일 삭제하기
*/

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
  int ret = -1;

  ret = remove("tmp.bbb");
  if(ret == -1)
  {
    perror("remove error");
    exit(1);
  }
  printf("File deleted successfully.\n");

  return 0;
}