/*
2026-02-14
인터넷 소켓 서버
*/

#include<iostream>
#include<cstdlib>
#include<string>
#include<cstring>
#include<vector>
#include<unistd.h>
#include<sys/un.h>
#include<sys/socket.h>
#include<arpa/inet.h>

int main(void)
{
  const std::string portnumber = "9000";
  std::vector<char>buf(256);
  int sd;
  struct sockaddr_in sin;

  if((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
  {
    std::cerr << "socket error" << std::endl;
    exit(1);
  }

  memset((char *)&sin, 0, sizeof(sin));
  sin.sin_family = AF_INET;
  sin.sin_addr.s_addr = htonl(portnumber);
  sin.sin_port = inet_addr("192.168.147.129");

  if(connect(sd, (struct sockaddr *)&sin, sizeof(sin)) < 0)
  {
    std::cerr << "connect error" << std::endl;
    exit(1);
  }

  if(recv(sd, buf.data(), sizeof(buf), 0) == -1)
  {
    std::cerr << "recv error" << std::endl;
    exit(1);
  }

  close(sd);
  std::cout << "received message: " << buf.data() << std::endl;

  return 0;
}