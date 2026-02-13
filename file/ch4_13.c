/*
2026-02-13
fread() 함수로 파일 읽기
*/

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
  FILE *rfp = NULL;
  char buf[BUFSIZ];
  int n = 0;

  if((rfp = fopen("linux.txt","r")) == NULL)
  {
    perror("fopen: linux.txt error");
    exit(1);
  }

  while((n=fread(buf, sizeof(char)*1,4,rfp))> 0 )
  {
    buf[n] = '\0';
    printf("read %d bytes: %s\n", n, buf);
  }

  fclose(rfp);

  return 0;
}