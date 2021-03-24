#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

void signalHandler(int sig){
	int pidHijo=wait(NULL);
    printf("Mi hijo terminó %d\n",pidHijo);
}

int main(){

    signal(17,signalHandler);
    int pid=fork();

    if(pid==0){
        //Proceso hijo
        printf("Soy el proceso hijo\n");
    }else{
        //Proceso padre
        printf("Soy el proceso padre y mi hijo es %d\n",pid);

        while(1){
            printf("Trabajando\n");
            sleep(1);
        }

    }

    printf("Terminando\n");
    return 0;
}