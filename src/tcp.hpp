#pragma once

#ifndef TCP_HPP
#define TCP_HPP

#include <netinet/in.h>

class TcpListener {
    public:
        int m_port;
        int m_socket_fd;
        int m_addr_length;
        sockaddr_in m_addr;

        TcpListener(int port);
        int listen();
};

#endif
