/*
2026-02-14
인터넷 소켓 서버
*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(void)
{
    const int PORT = 9000;
    struct sockaddr_in ser, cli;
    int sd = -1, ns = -1; 
    socklen_t clientlen = sizeof(cli);
    
    // 소켓 생성
    if ((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        std::cerr << "socket error" << std::endl;
        exit(1);
    }

    // SO_REUSEADDR 옵션
    int opt = 1;
    if (setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1)
    {
        std::cerr << "setsockopt error" << std::endl;
        close(sd);
        exit(1);
    }

    // 서버 주소 설정
    memset(&ser, 0, sizeof(ser));
    ser.sin_family = AF_INET;
    ser.sin_addr.s_addr = htonl(INADDR_ANY);
    ser.sin_port = htons(PORT);

    // bind
    if (bind(sd, (struct sockaddr *)&ser, sizeof(ser)) == -1)
    {
        std::cerr << "bind error" << std::endl;
        close(sd);
        exit(1);
    }

    // listen
    if (listen(sd, 5) == -1)
    {
        std::cerr << "listen error" << std::endl;
        close(sd);
        exit(1);
    }

    std::cout << "Server listening on port " << PORT << "..." << std::endl;

    // accept
    if ((ns = accept(sd, (struct sockaddr *)&cli, &clientlen)) == -1)
    {
        std::cerr << "accept error" << std::endl;
        close(sd);
        exit(1);
    }

    std::cout << "Client connected from " << inet_ntoa(cli.sin_addr) << std::endl;

    // 메시지 생성 (C++ 방식)
    std::string msg = "Your IP address is " + std::string(inet_ntoa(cli.sin_addr));
    
    // 전송
    if (send(ns, msg.c_str(), msg.length(), 0) == -1)
    {
        std::cerr << "send error" << std::endl;
    }

    close(ns);
    close(sd);

    return 0;
}