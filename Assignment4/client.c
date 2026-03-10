#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>

#define PORT 6165

#define MIN_ARGS 2
#define MAX_ARGS 2
#define SERVER_ARG_IDX 1

#define USAGE_STRING "usage: %s <server address>\n"

void validate_arguments(int argc, char *argv[])
{
    if (argc < MIN_ARGS || argc > MAX_ARGS)
    {
        fprintf(stderr, USAGE_STRING, argv[0]);
        exit(EXIT_FAILURE);
    }
}

void send_request(int fd)
{
    char *line = NULL;
    size_t size = 0;
    ssize_t num;

    if ((num = getline(&line, &size, stdin)) > 0)
    {
        write(fd, line, num);
        char buf[4096];
        ssize_t r;
        while ((r = read(fd, buf, sizeof(buf))) > 0)
            write(STDOUT_FILENO, buf, r);
    }
    free(line);
}

int connect_to_server(struct hostent *host_entry)
{
    int fd;
    struct sockaddr_in their_addr;

    if ((fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        return -1;

    their_addr.sin_family = AF_INET;
    their_addr.sin_port = htons(PORT);
    their_addr.sin_addr = *((struct in_addr *)host_entry->h_addr);
    memset(&(their_addr.sin_zero), 0, 8);

    if (connect(fd, (struct sockaddr *)&their_addr,
                sizeof(their_addr)) == -1)
    {
        close(fd);
        return -1;
    }

    return fd;
}

int main(int argc, char *argv[])
{
    validate_arguments(argc, argv);

    struct hostent *host_entry = gethostbyname(argv[SERVER_ARG_IDX]);
    if (!host_entry)
    {
        herror("gethostbyname");
        exit(1);
    }

    int fd = connect_to_server(host_entry);
    if (fd == -1)
    {
        perror("connect");
        exit(1);
    }

    send_request(fd);
    close(fd);
    return 0;
}