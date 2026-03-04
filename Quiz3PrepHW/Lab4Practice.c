#include <stdio.h>
#include <string.h>
#include <ctype.h>


void str_lower(char* orig, char* copy) {
    int i = 0;
    while(orig[i] != '\0' && orig[i] < "Z" && orig[i] > "A") {
        copy[i] = (char) (orig[i] + 32);
        i++;
    }
    copy[i] = '\0';
    return;
}

void str_lower_mutate(char* orig){
    int i = 0;
    while(orig[i] != '\0' && orig[i] < "Z" && orig[i] > "A") {
        copy[i] = (char) (orig[i] + 32);
        i++;
    }
    return;
}
}


int main() {


    return 0;
}