#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/wait.h>


/*
 * Overarching task
 * Write a program which will uses multiple processes to download a collection of files.
 * Process a file containing url's, use the curl program to download the files.
 *
 * curl -m <seconds> -o <filename> -s <url>
 * -m <seconds> — This option limits the download time to the specified number of seconds.
 * -o <filename> — This option specifies the name of the output file to which the contents of the download file will be written.
 * -s — This option silences the progress meter typically printed by curl.
 * <url> — This is the url of the file to download.
 *
 * 1) Takes two cml, the file and an int to indicate the max number of downloading processes executing at a single time
 * 2) Each line of the provided file will contain the info needed:
 *      Output file name, the url, and max number of secs for download, seperated by ws delimiter
 *      Assume each line of the file has a valid url to download from
 * 3) Spawn a single process per download request, but only up to the max number fo child processes that may exist at a single time
 * 4) The parent should print when a download request is starting. and the output must refer to each download
 *    request by the line number in the provided file and the child processes
 * 5) The program should properly manage resources to avoid running out of processes
 *
 */

int main(int argc, char* argv[]) {

    int cur_proc = 0;
    uint32_t max_dwld_proc = 0;
    int line_number = 0;

    if (argc != 3) {return 1;}
    FILE* fp = fopen(argv[1], "r");
    if (!fp) {return 1;}
    char* endptr = NULL;
    long val = strtol(argv[2], &endptr, 10);
    if (*endptr != '\0' || val < 1) {return 1;}
    max_dwld_proc = (uint32_t) val;

    char* buf = NULL;
    size_t bufSize = 0;

    while (getline(&buf, &bufSize, fp) != -1) {
        line_number++;
        char* argStr[3] = {NULL, NULL, NULL};
        int count = 0;
        char* tkn = strtok(buf, " \n");
        while (tkn != NULL && count < 3) {
            argStr[count++] = tkn;
            tkn = strtok(NULL, " \n");
        }
        char *curl_args[8];
        int idx = 0;
        curl_args[idx++] = "curl";
        if (count == 3) {
            curl_args[idx++] = "-m";
            curl_args[idx++] = argStr[2];
        }
        curl_args[idx++] = "-o";
        curl_args[idx++] = argStr[0];
        curl_args[idx++] = "-s";
        curl_args[idx++] = argStr[1];
        curl_args[idx] = NULL;

        if (cur_proc >= max_dwld_proc) {
            wait(NULL);
            cur_proc--;
        }
        pid_t pid = fork();
        if (pid < 0) {perror ("fork failed"); free(buf); exit(1);}
        else if (pid == 0) {
            execvp("curl", curl_args);
            perror("execvp failed");
            free(buf);
            exit(1);
        } else {
            printf("process %d processing line #%d\n", pid, line_number);
            cur_proc++;
        }
    }
    while (cur_proc > 0) {
        wait(NULL);
        cur_proc--;
    }
    fclose(fp);
    free(buf);
}



