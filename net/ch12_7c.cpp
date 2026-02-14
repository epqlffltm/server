/*
2026-02-14
인터넷 소켓 클라이언트
*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(void)
{
    const int PORT = 9000;
    const char* SERVER_IP = "127.0.0.1";
    std::vector<char> buf(256);
    int sd;
    struct sockaddr_in sin;

    // 소켓 생성
    if ((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        std::cerr << "socket error" << std::endl;
        exit(1);
    }

    // 서버 주소 설정
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(SERVER_IP);
    sin.sin_port = htons(PORT);
    
    // 서버 연결
    if (connect(sd, (struct sockaddr *)&sin, sizeof(sin)) < 0)
    {
        std::cerr << "connect error" << std::endl;
        close(sd);
        exit(1);
    }

    std::cout << "Connected to server" << std::endl;

    // 메시지 수신
    memset(buf.data(), 0, buf.size());
    int n = recv(sd, buf.data(), buf.size() - 1, 0);
    if (n == -1)
    {
        std::cerr << "recv error" << std::endl;
        close(sd);
        exit(1);
    } else if (n == 0) {
        std::cout << "Server closed connection" << std::endl;
    } else {
        buf[n] = '\0';
        std::cout << "Received: " << buf.data() << std::endl;
    }

    close(sd);

    return 0;
}