#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(int arguments, char **argv){
    char *path=argv[1];
    char *newName=argv[2];
    struct stat sb;
    if(stat(path, &sb)==-1){
        printf("Error: El archivo no existe\n");
        return -1;
    };

    if(S_ISDIR(sb.st_mode)){
        printf("Es un directirio\n");
    }
    if(S_ISREG(sb.st_mode)){
        printf("Es un archivo normal\n");
    }

    return 1;
}