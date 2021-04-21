#include <semaphore.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

#define MAX_RECORDS 20

int buffer[MAX_RECORDS];

sem_t empty;
sem_t fill;

void* producer(void *d){
    int pos=0;
    while(1){
        sem_wait(&empty);
        buffer[pos]=pos;
        pos=((pos+1)%MAX_RECORDS);
        sleep(2);
        sem_post(&fill);
    }
    pthread_exit(NULL);
}

void* consumer(void *d){
    int pos=0;
    int valor;
    while(1){
        sem_wait(&fill);
        valor=buffer[pos];
        pos=((pos+1)%MAX_RECORDS);
        sleep(3);
        printf("Valor: %d\n",valor);
        sem_post(&empty);
    }
    pthread_exit(NULL);
}


int main(){
    sem_init(&empty,0,MAX_RECORDS);
    sem_init(&fill,0,0);

    pthread_t producerT, consumerT;

    pthread_create(&producerT,NULL,producer,NULL);
    pthread_create(&consumerT,NULL,consumer,NULL);

    pthread_exit(NULL);

    return 0;
}