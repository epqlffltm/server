/*
2026-02-13
문자기반 입풀력 함수 사용하기
*/
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
  FILE *rfp = NULL, *wfp = NULL;
  int n = -1;

  if((rfp = fopen("linux.txt", "r")) == NULL)
  {
    perror("fopen: linux.txt error");
    exit(1);
  }

  if ((wfp = fopen("linux.out", "w")) == NULL)
  {
    perror("fopen: linux.out error");
    exit(1);
  }

  while((n = fgetc(rfp)) != EOF)
  {
    fputc(n, wfp);
  }

  fclose(rfp);
  fclose(wfp);

  return 0;
}