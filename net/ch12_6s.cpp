/*
2026-02-14
유닉스 도메인 서버
*/

#include<iostream>
#include<cstdlib>
#include<string>
#include <cstring>
#include<unistd.h>
#include<sys/un.h>
#include<sys/socket.h>

int main(void)
{
  const std::string socket_name = "hbsocket";
  char buf[256];
  struct sockaddr_un ser, cli;
  int sd, nsd, len;
  socklen_t clen;

  if((sd = socket(AF_UNIX, SOCK_STREAM, 0)) ==-1)
  {
    std::cerr << "socket error" << std::endl;
    exit(1);
  }

  memset((char *)&ser, 0, sizeof(struct sockaddr_un));
  ser.sun_family = AF_UNIX;
  strcpy(ser.sun_path, socket_name.c_str());
  len = sizeof(ser.sun_family) + strlen(ser.sun_path);

  unlink(socket_name.c_str());

  if(bind(sd, (struct sockaddr *)&ser, len) == -1)
  {
    std::cerr << "bind error" << std::endl;
    exit(1);
  }

  if(listen(sd, 5)< 0)
  {
    std::cerr << "listen error" << std::endl;
    exit(1);
  }

  std::cout << "Waiting for a client..." << std::endl;

  clen = sizeof(cli);

  if((nsd = accept(sd, (struct sockaddr *)&cli, &clen)) == -1)
  {
    std::cerr << "accept error" << std::endl;
    exit(1);
  }

  if(recv(nsd, buf, sizeof(buf), 0) == -1)
  {
    std::cerr << "recv error" << std::endl;
    exit(1);
  }

  std::cout << "received message: "<<buf << std::endl;

  unlink(socket_name.c_str());
  close(nsd);
  close(sd);

  return 0;
}