#include "./student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argnum, char **argv){
    char *original = argv[1];
    char *name = argv[2];
    char *valor = argv[3];
    STUDENT newstudent;
    FILE *foriginal;
    foriginal=fopen(original,"rb");
    while(fread(&newstudent,sizeof(newstudent),1,foriginal)){

        if(strcmp(name,"nombre")==0){
            if(strcmp(newstudent.name,valor)==0){
                printf("Nombre: %s Apellido: %s ID: %d Semestre: %d\n",newstudent.name,newstudent.lastname,newstudent.id,newstudent.semestre);
            }
        }else if(strcmp(name,"apellido")==0){
            if(strcmp(newstudent.lastname,valor)==0){
                printf("Nombre: %s Apellido: %s ID: %d Semestre: %d\n",newstudent.name,newstudent.lastname,newstudent.id,newstudent.semestre);
            }
        }else{
            return -1;
        }
        
    }

    fclose(foriginal);

    return 0;
}