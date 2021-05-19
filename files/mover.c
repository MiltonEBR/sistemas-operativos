#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

//int link(const char *oldpath, const char *newpath);
//int unlink(const char *pathname);

int main(int arguments, char **argv){
    char *file1=argv[1];
    char *file2=argv[2];
    struct stat sb1;
    struct stat sb2;
    if(stat(file1, &sb1)==-1){
        printf("Error: El archivo objetivo no existe\n");
        return -1;
    };

    if(stat(file2, &sb2)==-1){
        //Archivo destino no existe
        link(file1,file2);
        unlink(file1);
        return 0;
    }

    if(S_ISDIR(sb1.st_mode)){
        printf("El destino no es un archivo\n");
        return -1;
    }

    if(S_ISREG(sb1.st_mode)){

        if(S_ISREG(sb2.st_mode)){
            //Archivo
            printf("El archivo destino está ocupado\n");
            return -1;
        }else if(S_ISDIR(sb2.st_mode)){
            //Directorio
            char dir[100];
            char *slash="/";
            strcpy(dir,file2);
            strcat(dir,slash);
            strcat(dir,file1);
            link(file1,dir);
            unlink(file1);
        }
    }

    return 1;
}