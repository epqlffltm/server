/*
2026-02-14
반복 실행 서버
*/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>
#include<sys/socket.h>

int main(void)
{
  const int port_number = 9001;
  char buf[256];
  struct sockaddr_in sin, cli;
  int sd  = -1, ns = -1;
  unsigned int clientlen = sizeof(cli); 

  memset((char *)&sin, '\0', sizeof(sin));
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port_number);
  sin.sin_addr.s_addr = htonl(INADDR_ANY);
  
  if((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
  {
    std::cerr << "socket error" << std::endl;
    exit(1);
  }

  if(bind(sd,(struct sockaddr *)&sin, sizeof(sin)))
  {
    std::cerr << "bind" << std::endl;
    exit(1);
  }

  if(listen(sd, 5))
  {
    std::cerr << "listen error" << std::endl;
    exit(1);
  }

  while(true)
  {
    if((ns = accept(sd, (struct sockaddr *)&cli, &clientlen)) == -1)
    {
      std::cerr << "accept error" << std::endl;
      exit(1);
    }
    sprintf(buf, "%s", inet_ntoa(cli.sin_addr));
    std::cout << "message : " << buf << std::endl;

    strcpy(buf, "welcome to network server");
    if(send(ns, buf, strlen(buf) + 1,0) == -1)
    {
      std::cerr << "send error" << std::endl;
      exit(1);
    }

    if(recv(ns,buf,sizeof(buf),0) == -1)
    {
      std::cerr << "recv error" << std::endl;
      exit(1);
    }
    std::cout << "from client : " << buf << std::endl;
    close(ns);
  }
  close(sd);

  return 0;
}