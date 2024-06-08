#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    // %% 1. socket
    int sockfd, newsockfd, n;
    struct sockaddr_in
        local_addr,
        remote_addr;
    socklen_t len = sizeof(struct sockaddr_in);
    char msg[1000];

    if (argc != 2)
    {
        printf("Errore! Inserisci numero port\n");
        return -1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
    {
        printf("Errore nell'apertura di socket\n");
        return -1;
    }

    memset(&local_addr, 0, len);
    local_addr.sin_family = AF_INET;
    local_addr.sin_addr.s_addr = htonl(INADDR_ANY); // = metti come IP quello locale della macchina
    local_addr.sin_port = htons(atoi(argv[1]));

    // %% 2. bind
    if (bind(sockfd, (struct sockaddr *)&local_addr, len) < 0)
    {
        printf("Errore nella bind\n");
        return -1;
    }

    // %% 3. listen
    listen(sockfd, 5);

    // %% 4. accept
    for (;;)
    {
        newsockfd = accept(sockfd,
                           (struct sockaddr *)&remote_addr,
                           &len);
        if (fork() == 0)
        {
            // processo figlio
            close(sockfd); // al processo figlio non interessa la sockfd vecchia

            for (;;)
            {
                n = recv(sockfd, msg, 999, 0);
                msg[n] = 0;

                printf("IP %s, P %d, msg %s\n",
                       inet_ntoa(remote_addr.sin_addr),
                       ntohs(remote_addr.sin_port),
                       msg);

                send(newsockfd, msg, n, 0);

                if (stcmp(msg, "fine\n") == 0)
                {
                    printf("Fine\n");
                    break;
                }
            }

            close(newsockfd);
            return 0;
        }
        else
        {
            // processo padre
            close(newsockfd); // al padre non interessa del figlio :C
        }
    }
}