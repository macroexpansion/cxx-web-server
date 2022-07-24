#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#include "tcp.hpp"

TcpListener::TcpListener(int port) : m_port(port) {
    /* create a socket */
    m_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (m_socket_fd == 0) {
        std::cerr << "cannot create socket" << std::endl;
    }

    /* bind ip and port */
    m_addr.sin_family = AF_INET;
    m_addr.sin_port = htons(m_port);
    m_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    m_addr_length = sizeof(m_addr);

    int bound = bind(m_socket_fd, (sockaddr*)&m_addr, sizeof(m_addr));
    if (bound < 0) {
        std::cerr << "cannot bound socket to address and port" << std::endl;
    }

    /* listen */
    int listened = ::listen(m_socket_fd, SOMAXCONN);
    if (listened < 0) {
        std::cerr << "cannot listen" << std::endl;
    }
}

TcpListener::~TcpListener() {
    std::cout << "called destructor" << std::endl;
}

int TcpListener::listen() {
    int socket = accept(m_socket_fd, (sockaddr*)&m_addr, (socklen_t*)&m_addr_length);
    return socket;
}
