/**
 * @file simulator_socket.h
 * @author Sebastien CAUX (sebcaux)
 * @copyright Robotips 2016
 *
 * @date November 3, 2016, 22:44 PM
 *
 * @brief Communication by sockets for testing purpose (windows and linux cross-platforms)
 *
 * Widely inspired by http://broux.developpez.com/articles/c/sockets/
 */

#ifndef SIMULATOR_SOCKET_H
#define SIMULATOR_SOCKET_H

#ifdef WIN32

  #include <winsock2.h>

#elif defined (linux) || defined (unix)

  #include <sys/types.h>
  #include <sys/socket.h>
  #include <netinet/in.h>
  #include <arpa/inet.h>
  #include <unistd.h>
  #include <stdio.h>
  #include <stdlib.h>

  #define INVALID_SOCKET -1
  #define SOCKET_ERROR -1
  #define closesocket(param) close(param)

  typedef int SOCKET;
  typedef struct sockaddr_in SOCKADDR_IN;
  typedef struct sockaddr SOCKADDR;

#else

  #error socket not supported for your platform

#endif

#define SIM_SOCKET_PORT 1064

void simulator_socket_init();
void simulator_socket_end();
void simulator_socket_send(char *data, size_t size);

#endif // SIMULATOR_SOCKET_H