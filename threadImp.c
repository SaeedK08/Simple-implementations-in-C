#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define BSIZE 16
#define NTHREADS 4 

typedef struct {
    unsigned char *buffer;
    int thread_id;
    int length;
} Buffer;

void *doClear(void *vargp)
{
    // int counter = 0;
    Buffer *piece = (Buffer *) vargp;
        printf("Working on %p\n" ,piece);
        for (int i = 0; i < piece->length; i++)
        {
            *(piece->buffer) = '*';
            piece->buffer ++;
        }
    // while (1)
    // {
    //     // sleep(1);
    //     // printf("thread %d is working\n" ,(piece->thread_id));
    //     // counter ++;
    //     // if (counter >= 5) break;
        
    // }
    return (void*) vargp;
}

void clearBuffer(unsigned char *p, int length)
{
    pthread_t wt[NTHREADS];
    Buffer pieces[NTHREADS];
    for (int i = 0; i < NTHREADS; i++)
    {
        pieces[i].buffer = p + i * (length / 4);
        pieces[i].length = length / 4;
        pieces[i].thread_id = i;
        pthread_create(&wt[i], NULL, doClear, (void *)&pieces[i]);
        // pthread_join(wt[i], NULL);
    }
    
    for (int i = 0; i < NTHREADS; i++)
    {
        pthread_join(wt[i], NULL);
    }
}

int main() {
    unsigned char buffer[BSIZE] = {'\0'};
    clearBuffer(buffer, BSIZE);
    for (int i = 0; i < BSIZE ; i++)
    {
        printf("%c" ,buffer[i]);
    }
    printf("\nDone!\n");
    
    
    
    return 0;
}