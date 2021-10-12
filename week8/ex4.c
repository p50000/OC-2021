#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MB (1000000)

int main() 
{
    struct rusage usage;
    
    size_t i = 0;
    for (i = 0; i < 10; ++i) 
    {
        void* mem = malloc(MB * 10);
        memset(mem, 0, MB * 10);
        getrusage(RUSAGE_SELF, &usage);
        printf("mem_usage: %ld\n",usage.ru_maxrss);
        sleep(1);
    }
    return 0;
}