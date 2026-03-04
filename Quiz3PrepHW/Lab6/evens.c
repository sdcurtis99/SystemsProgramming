#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

    if (argc != 2) {return 0;}
    //endptr points to the first char not converted
    char* endptr;
    long N = strtol(argv[1], &endptr, 10);
    for (long i = 2; i <= N; i += 2) {
        printf("\t%d\n", (int) i);
    }
    return 0;
}