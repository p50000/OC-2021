#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int n;
    int pid = fork();
    if (pid == 0) 
    {
        printf("Hello from child [%d - %d]\n", getpid(), n);
    }
    else if (pid > 0)
    {
        printf("Hello from child [%d - %d]\n", getpid(), n);
    }
}