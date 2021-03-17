#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int runProg=1;

void signalHandler(int sig){
	runProg=0;
}

int main(){
	signal(2,signalHandler);
	while(runProg){
		printf("Trabajando\n");
		sleep(1);
	}
	printf("\n");
}