/*
NBO(네트워크 바이트 순서) -> BHO(호스트 바이트 순서)로 변환
*/

#include<stdio.h>
#include<netdb.h>

int main(void)
{
  struct servent *port;
  setservent(0);

  for(int i = 0; i < 5; i++)
  {
    port = getservent();
    printf("name = %s\n port = %d\n", port -> s_name, ntohs(port -> s_port));
  }

  endservent();

  return 0;
}
