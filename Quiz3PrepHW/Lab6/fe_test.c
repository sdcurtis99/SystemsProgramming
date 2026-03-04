// like f_test but uses an exec systems call to execute program in task2
// parent fork two child processes.
// One exec the odds and the other the even.
// Parent must wait for both children to termiante

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {return 1;}
    pid_t pidt;
    if ( (pidt = fork()) < 0) {printf("Unable to fork c1\n");}
    else if (pidt == 0) {
        execl("/Users/shannoncurtis/Desktop/Cal Poly/Winter 26/CSC_357/Labs/Lab6/odds", "odds", argv[1], NULL);
        perror("Unable to print using odds executable");
        exit(0);
    }
    else {
        //parent fork another child
        if ((pidt = fork()) < 0) {printf("Unable to fork c2\n");}
        else if (pidt == 0) {
            execl("/Users/shannoncurtis/Desktop/Cal Poly/Winter 26/CSC_357/Labs/Lab6/evens", "evens", argv[1], NULL);
            perror("Unable to print using evens executable");
            exit(0);
        } else {
            // parent
            wait(NULL);
            wait(NULL);
            }
        }
    }

