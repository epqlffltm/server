/*
2026-02-13
호스트명 읽어오기
*/

#include<stdio.h>
#include<netdb.h>

int main(void)
{
  struct hostent *hent;

  sethostent(0);

  while((hent = gethostent()) != NULL)
  {
    printf("hostname: %s\n", hent->h_name);
  }
  endhostent();

  return 0;
}