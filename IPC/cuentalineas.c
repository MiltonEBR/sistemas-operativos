#include <unistd.h>
#include <ctype.h>
#include <stdio.h>

int main(){
    
    char minC;
    int count=0;


    while(read(0,&minC,1)){
        if(minC=='\n'){
            count++;
        }
    }

    if(minC!='\n'){
        count++;
    }

    printf("%d\n",count);
    
    return 0;
}