# Makefile for client and server

CC = gcc
OBJCLI = client.c 
OBJSRV = server.c
OBJCLIT = tcpd_server.c
OBJSRVT = tcpd_client.c
CFLAGS = 
# setup for system
LIBS =

all: ftpc ftps tcpds tcpdc

ftpc:	$(OBJCLI)
	$(CC) $(CFLAGS) -o $@ $(OBJCLI) $(LIBS)

ftps:	$(OBJSRV)
	$(CC) $(CFLAGS) -o $@ $(OBJSRV) $(LIBS)

tcpds:	$(OBJSRVT)
	$(CC) $(CFLAGS) -o tcpds $(OBJSRVT) $(LIBS)

tcpdc:	$(OBJCLIT)
	$(CC) $(CFLAGS) -o tcpdc $(OBJCLIT) $(LIBS)

clean:
	rm ftps ftpc tcpds tcpdc
