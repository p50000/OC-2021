#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

int main(){
    char line[256];
    while(1){
        fgets(line, sizeof(line), stdin);
        system(line);
    }
}