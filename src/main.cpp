#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#include "tcp.hpp"

int main(int argc, char** argv) {
    std::string message = "HTTP/1.1 200 OK\r\nContent-Length: 7\r\n\r\nhello11";
    char message_in_bytes[message.length()]; 
    strcpy(message_in_bytes, message.c_str());

    TcpListener* listener = new TcpListener(8000);

    while (true) {
        std::cout << "listening on port " << listener->m_port << std::endl;

        int socket = listener->listen();
        if (socket < 0) {
            std::cerr << "cannot accept connection" << std::endl;
            return -1;
        }

        char buffer[1024] = { 0 };
        recv(socket, buffer, 1024, 0);
        std::cout << buffer << std::endl;

        // sleep(5);

        send(socket, message_in_bytes, strlen(message_in_bytes) + 1, MSG_OOB);
        std::cout << "message sent" << std::endl;

        shutdown(socket, SHUT_RDWR);
    }
}
