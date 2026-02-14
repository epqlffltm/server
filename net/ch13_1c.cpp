/*
2026-02-14
반복 실행 서버(클라이언트)
*/

#include<iostream>
#include<cstdlib>
#include<string.h>
#include<cstring>
#include<unistd.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<netdb.h>
#include<sys/socket.h>

int main(void)
{
  const std::string port_number = "9001";
  int sd = -1;
  char buf[256];
  struct sockaddr_in sin;

  memset((char *)&sin, '\0',sizeof(sin));
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port_number);
  sin.sin_addr.s_addr = inet_addr(INADDR_ANY);

  if((sd = socket(AF_INET, SOCK_STREAM,0)) == -1)
  {
    std::cerr << "socket error" << std::endl;
    exit(1);
  }

  if(connect(sd,(struct sockaddr *)&sin,sizeof(sin)))
  {
    std::cerr << "connect" << std::endl;
    exit(1);
  }

  std::cout << "from server: " << buf <<std::endl;

  strcpy(buf, "i want a http service");
  if(send(sd, buf, sizeof(buf)+1,0) == -1)
  {
    std::cerr << "send error" << std::end;
    exit(1);
  }

  close(sd);

  return 0;
}
