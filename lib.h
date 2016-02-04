#ifndef LIB_H
#define LIB_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

int global_port_send = 0;
int global_port_recv = 0;
int choose_port(int port1, int port2){
	global_port_send = port1;
	global_port_recv = port2;
}

int SEND(int s, const void *buf, int len, int flags){
	struct sockaddr_in tcpd;
	tcpd.sin_family = AF_INET;
	tcpd.sin_port = htons(global_port_send);
	tcpd.sin_addr.s_addr = inet_addr("127.0.0.1");
	// either "buf" or "&buf" or "*buf"
	if(sendto(s, buf, len, flags, (struct sockaddr *)&tcpd, sizeof(tcpd)) < 0) {
        perror("Error sending datagram message");
        exit(1);
    }
}

int RECV(int s, void *buf, int len, int flags){
	struct sockaddr_in tcpd;
	socklen_t fromlen;
	char ipstr[INET6_ADDRSTRLEN];
	struct sockaddr_in my_addr;
	my_addr.sin_family = AF_INET;
    my_addr.sin_addr.s_addr = inet_addr("127.0.0.1");           //Listen to any IP address
    my_addr.sin_port = htons(global_port_recv);
	
	// either "buf" or "&buf" or "*buf"
	fromlen = sizeof(my_addr);
	if(recvfrom(s, buf, len, flags,(struct sockaddr *)&my_addr, &fromlen) < 0) {
        perror("Error sending datagram message");
        exit(1);
    }
    
}
#endif