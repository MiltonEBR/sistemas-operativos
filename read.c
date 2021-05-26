#include "./student.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argnum, char **argv){
    char *original = argv[1];
    int x = atoi(argv[2]);
    STUDENT newstudent;

    FILE *foriginal;
    foriginal=fopen(original,"rb");
    int cont=0;
    while(fread(&newstudent,sizeof(newstudent),1,foriginal) && cont<x){
        printf("Nombre: %s Apellido: %s ID: %d Semestre: %d\n",newstudent.name,newstudent.lastname,newstudent.id,newstudent.semestre);
        cont++;
    }

    fclose(foriginal);

    return 0;
}