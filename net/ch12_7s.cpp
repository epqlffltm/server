/*
2026-02-14
인터넷 소켓 서버
*/

#include<iostream>
#include<cstdlib>
#include<string>
#include <cstring>
#include<vector>
#include<unistd.h>
#include<sys/un.h>
#include<sys/socket.h>
#include<arpa/inet.h>

int main(void)
{
  const std::string portnumber = "9000";
  std::vector<char>buf(256);
  struct sockaddr_in ser, cli;
  int sd = -1, ns = -1; 
  socklen_t clientlen = sizeof(cli);
  
  if((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
  {
    std::cerr << "socket error" << std::endl;
    exit(1);
  }

  memset((char *)&ser, 0, sizeof(ser));
  ser.sin_family = AF_INET;
  ser.sin_addr.s_addr = inet_addr(INADDR_ANY);
  ser.sin_port = htons(atoi(portnumber.c_str()));

  if (bind(sd, (struct sockaddr *)&ser, sizeof(ser)) == -1)
  {
    std::cerr << "bind error" << std::endl;
    exit(1);
  }

  if(listen(sd, 5) == -1)
  {
    std::cerr << "listen error" << std::endl;
    exit(1);
  }

  if((ns = accept(sd, (struct sockaddr *)&cli, &clientlen)) == -1)
  {
    std::cerr << "accept error" << std::endl;
    exit(1);
  }

  std::string msg = "your ip address is " + std::string(inet_ntoa(cli.sin_addr));
  if (send(ns, msg.c_str(), msg.length(), 0) == -1)
  {
    std::cerr << "send error" << std::endl;
    exit(1);
  }

  //unlink(socket_name.c_str());
  close(ns);
  close(sd);

  return 0;
}