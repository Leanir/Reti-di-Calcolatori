/*
 *   codice per il client della nostra applicazione UDP
 *   per natura di UDP tecnicamente non ci frega di aprire prima il server,
 *   però sai non è poi una brutta idea dato che poi ci serve farlo per TCP
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// libreria che serve a richiamare le socket, funziona su linux
#include <arpa/inet.h>
// <winsock2.h> è la libreria di windows

int main(int argc, char **argv)
{
    int sockfd;
    struct sockaddr_in dest_addr; // viene da <arpa/inet.h>
    char buffer[100];

    if (argc < 3)
    {
        printf("Errore! inserisci IP e port\n");
        return -1;
    }

    sockfd = socket(PF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        printf("Errore nell'apertura della socket\n");
        return -1;
    }
    // ^^^ si poteva scrivere come
    // if( (sockfd = socket(PF_INET, SOCK_DGRAM, 0)) < 0 ){...}

    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &(dest_addr.sin_addr));
    dest_addr.sin_port = htons(atoi(argv[2]));

    // inviamo 10 pacchetti
    for (int i = 0; i < 10; i++)
    {
        sprintf(buffer, "%d", i);
        sendto(
            sockfd,
            buffer,
            sizeof(buffer),
            (struct sockaddr *)&dest_addr,
            sizeof(dest_addr));
    }

    close(sockfd);

    return 0;
}
