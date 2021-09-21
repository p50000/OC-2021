#include <stdio.h>
#include <pthread.h>

void *printing_thread(void *id) {
    printf("Hello from thread %d \n", (*(int*) id));
    pthread_exit(0);
}

int main() {
    for (int i = 0; i < 4; i++) {
        pthread_t current_thread;
        int* id = &i;
        printf("Creating thread %d \n", i);
        pthread_create(&current_thread, NULL, printing_thread, id);
        pthread_join(current_thread, NULL);
    }
    return 0;
}