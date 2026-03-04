

int main(int argc, char* argv[]) {
    if (argc != 3) {return 1;}
    int fd1 = open(argv[1], O_RDONLY);
    if (fd1 < 0) {return 1;}
    int fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0754);
    if (fd2 < 0) {return 1;}

    if (dup2(fd2, STDOUT_FILENO) < 0) {return 1;}

    //read form first file then print it to stdout
    char buffer[1048];
    ssize_t bytes_read = 0;
    while ((bytes_read = read(fd1, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes_read] = '\0';
        printf("%s", buffer);
    }
    close(fd1);
    close(fd2);
    return 0;
}
