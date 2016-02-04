/*
  This is separate library file which contains Wrapping functions
  for sending and receiving files.Also This file has ACCEPT and 
  CONNECT functions which are NULL functions.
*/
#ifndef LIB_H
#define LIB_H

/*
  Include all the files required for compilation
*/
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

/*
  Global integer variables to hold send and receive port values for 
  Client and Server
*/
int global_port_send = 0;
int global_port_recv = 0;

/*
  Initializing port values which we get while running server and client 
  programs.
*/
int choose_port(int port1, int port2){
	global_port_send = port1;
	global_port_recv = port2;
}

/* 
   Send function to send data to tcpd (client for lab3)
*/
int SEND(int sock, const void *buf, size_t len, int flags){
	struct sockaddr_in tcpd;
	tcpd.sin_family = AF_INET;
	tcpd.sin_port = htons(global_port_send);
	tcpd.sin_addr.s_addr = inet_addr("127.0.0.1");
	if(sendto(sock, buf, len, flags, (struct sockaddr *)&tcpd, sizeof(tcpd)) < 0) {
        perror("Error sending datagram message");
        exit(1);
    }
}

/* 
   Receive function to send data from tcpd (server for lab3)
*/
int RECV(int s, void *buf, size_t len, int flags){
	struct sockaddr_in tcpd;
	socklen_t fromlen;
	char ipstr[INET6_ADDRSTRLEN];
	struct sockaddr_in my_addr;
	my_addr.sin_family = AF_INET;
    my_addr.sin_addr.s_addr = inet_addr("127.0.0.1");           //Listen to any IP address
    my_addr.sin_port = htons(global_port_recv);
	fromlen = sizeof(my_addr);
	if(recvfrom(s, buf, len, flags,(struct sockaddr *)&my_addr, &fromlen) < 0) {
        perror("Error sending datagram message");
        exit(1);
    }
}

/* 
   Empty accept function
*/
int ACCEPT(int s, const void *buf, int len){
}

/* 
   Empty connect function
*/
int CONNECT(int s, const void *buf, int len){
}

#endif