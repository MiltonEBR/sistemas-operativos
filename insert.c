#include "./student.h"
#include <stdio.h>

int main(int argc,char **argv){
    char *filename=argv[1];
    FILE *fdestino;
    fdestino = fopen(filename,"wb");
    int cuantos;
    printf("Cuántos alumnos insertar?:\n");
    scanf("%d",&cuantos);
    for(int i=0;i<cuantos;i++){
        STUDENT newstudent;
        printf("Nombre: ");
        scanf("%s",newstudent.name);
        printf("Apellido: ");
        scanf("%s",newstudent.lastname);
        printf("ID: ");
        scanf("%d",&newstudent.id);
        printf("Semestre: ");
        scanf("%d",&newstudent.semestre);
        
        fwrite(&newstudent,sizeof(newstudent),1,fdestino);
        //printf("%s %s %d %d \n",newstudent.name,newstudent.lastname,newstudent.id,newstudent.semestre);

    }
    fclose(fdestino);
}