#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <linux/input-event-codes.h>

#define N 3

void addToQueue(int value, int* queue, int size){
    for(int i=1;i<size;i++){
        queue[i-1]=queue[i];
    }
    queue[size-1]=value;
}

// shortcuts PE, CAP, AOA
int main(void)
{
    char* dev_dir = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    int shortcut_code_queue[N]={0,0,0};
    const int codes[3][N] = 
    {
        {0,25,18},
        {46,30,25},
        {30,24,30}
    };
    int fd = open(dev_dir, O_RDONLY);
    if (fd < 0) {
        return EXIT_FAILURE;
    }
    struct input_event evt;
    while(1)
    {
        ssize_t b = read(fd, &evt, sizeof(evt));
        if(evt.type ==EV_KEY)
        {
            if(evt.value == 1) 
            { 
                addToQueue(evt.code, shortcut_code_queue, N);
            }
            else {
                continue;
            }
            for(int i=0;i<3;i++)
            {
                int flag = 1;
                for(int j=0;j<3;j++)
                {
                    if(codes[i][j]==0) 
                    {
                        continue;
                    }
                    if(shortcut_code_queue[j] != codes[i][j])
                    {
                        flag = 0;
                        break;
                    }
                }
                if(flag)
                {
                    switch(i)
                    {
                        case 0:
                            printf("\nI passed the Exam!\n");
                            break;
                        case 1:
                            printf("\nGet some cappuccino!\n");
                            break;
                        case 2:
                            printf("\nAAAOOOOOAAAA!\n");
                            break;
                    }
                    break;
                }
            }
            fflush(stdout);
        }
    }
    return EXIT_SUCCESS;
}