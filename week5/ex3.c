#include <stdio.h>
#include <pthread.h>
#include <stdint.h>

int consumer_asleep, producer_asleep;
int counter;
int nums[7];

void *Consumer(void* data)
{
    while(1) 
    {
        if(!consumer_asleep) 
        {
            if(counter == 0)
            {
                consumer_asleep = 1;
                producer_asleep = 0;
            }
            if(counter == 7) 
            {
                for (int i = 0; i < counter; i++) 
                {
                    printf("Consume number %d \n", nums[i]);
                }
                counter = 0;
                consumer_asleep = 1;
                producer_asleep = 0;
            } 
        }
    }
}

void *Producer(void* data)
{
    while(1) 
    {
        if (!producer_asleep)
        {
            if (counter != 7)
            {
                consumer_asleep = 0;
                nums[counter] = counter;
                printf("Produce number %d\n", nums[counter++]);
            }
            else
            {
                printf("Produced all numbers\n");
                producer_asleep = 1;
            }
        }
    }
}

int main()
{
    pthread_t threadProducer, threadConsumer;
    void *data;
    counter = 0;
    consumer_asleep = 0;
    producer_asleep = 1;

    pthread_create(&threadConsumer, NULL, Producer, data);
    pthread_create(&threadProducer, NULL, Consumer, data);

    pthread_join(threadProducer, NULL);
    pthread_join(threadConsumer, NULL);

    return 0;
}