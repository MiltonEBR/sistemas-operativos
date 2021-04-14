#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#define NUMTHREADS 1000
int total=0;
pthread_mutex_t lock;
void *suma(void *datos) { 
    printf("Hello world desde un hilo %d\n",*(int *)datos);
    pthread_mutex_lock(&lock);
    total+=100;
    pthread_mutex_unlock(&lock);
    pthread_exit(NULL); 
};

int main() { 
    pthread_t myThread[NUMTHREADS];
    int t_Ids[NUMTHREADS];
    pthread_mutex_init(&lock,NULL);
    pthread_mutex_unlock(&lock);

    for(int i=0;i<NUMTHREADS;i++){
        t_Ids[i]=i;
        pthread_create(&myThread[i],NULL,suma,&t_Ids[i]);
    }
    for(int i=0;i<NUMTHREADS;i++){
        t_Ids[i]=i;
        pthread_join(myThread[i],NULL);
    }
    printf("Total %d\n",total);
    pthread_exit(NULL);

}
