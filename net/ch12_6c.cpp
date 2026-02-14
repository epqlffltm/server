/*
2026-02-14
유닉스 도메인 클라이언트
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
  struct sockaddr_un ser;
  int sd = -1;
  
  if ((sd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1)
  {
    std::cerr << "socket error" << std::endl;
    exit(1);
  }

  memset((char *)&ser, 0, sizeof(ser));

  ser.sun_family = AF_UNIX;
  strcpy(ser.sun_path, socket_name.c_str());
  int len = sizeof(ser.sun_family) + strlen(ser.sun_path);

  if((connect(sd, (struct sockaddr *)&ser, len)) < 0)
  {
    std::cerr << "connect error" << std::endl;
    exit(1);
  }

  strcpy(buf, "unix domain socket test message");
  if(send(sd, buf, sizeof(buf), 0) == -1)
  {
    std::cerr << "send error" << std::endl;
    exit(1);
  }

  close(sd);

  return 0;
}