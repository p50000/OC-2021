
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <linux/input-event-codes.h>

int main(void) {
    char* dev_dir = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    
    int fd = open(dev_dir, O_RDONLY);
    if (fd < 0) 
    {
        return EXIT_FAILURE;
    }
    struct input_event evt;
    while (1)
    {
        ssize_t b = read(fd, &evt, sizeof(evt));
        if (evt.type == EV_KEY && evt.value != 2) 
        {
            if (evt.value) 
            {
                printf("PRESSED %x (%d)\n", evt.code, evt.code);
            } else {
                printf("RELEASED %x (%d)\n", evt.code, evt.code);
            }
            fflush(stdout);
        }
    }
    return EXIT_SUCCESS;
    
}
