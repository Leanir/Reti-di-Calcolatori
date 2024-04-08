/*
 *   codice per il server della nostra applicazione UDP
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
    int sockfd;
    struct sockaddr_in
        local_addr,
        remote_addr;
    socklen_t len = sizeof(struct sockaddr_in);
    char buffer[100];

    if (argc < 2)
    {
        printf("Errore! Inserisci il numero di port\n");
        return -1;
    }

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        printf("Errore nell'apertura del socket\n");
        return -1;
    }

    memset(&local_addr, 0, len);
    local_addr.sin_family = AF_INET;
    local_addr.sin_port = htons(atoi(argv[1]));

    if (bind(sockfd, (struct sockaddr *)&local_addr) < 0)
    {
        printf("Errore! Inserisci un numero di porta differente!");
        return -1;
    }

    for (;;)
    {
        recvfrom(sockfd, buffer, 99, 0,
                 (struct sockaddr *)&remote_addr,
                 &len);
        printf("IP = %s, port = %d, message = %s\n",
               inet_ntoa(remote_addr.sin_addr),
               ntohs(remote_addr.sin_port),
               buffer);
    }

    return 0;
}