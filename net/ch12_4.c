/*
BHO(호스트 바이트 순서) -> NBO(네트워크 바이트 순서) 로 변환
*/

#include<stdio.h>
#include<netdb.h>

int main(void)
{
  struct servent *port;
  setservent(0);

  port = getservbyname("hhs", "tcp");
  printf("name = %s\n port = %d\n", port -> s_name, htons(port -> s_port));

  port = getservbyname("htons(21)", "tcp");
  printf("name = %s\n port = %d\n", port -> s_name, htons(port -> s_port));

  port = getservbyname("http", "tcp");
  printf("name = %s\n port = %d\n", port -> s_name, htons(port -> s_port));

  endservent();

  return 0;
}