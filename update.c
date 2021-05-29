#include "./student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argnum, char **argv){
    char *original = argv[1];
    char *name = argv[2];
    char *valor = argv[3];
    char *reemplazo=argv[4];

    STUDENT newstudent;
    FILE *foriginal;
    foriginal=fopen(original,"r+b");

    while(fread(&newstudent,sizeof(newstudent),1,foriginal)){
        if(strcmp(name,"nombre")==0){
            if(strcmp(newstudent.name,valor)==0){
                strcpy(newstudent.name,reemplazo);
                fseek(foriginal,-sizeof(newstudent),SEEK_CUR);
                fwrite(&newstudent,sizeof(newstudent),1,foriginal);
                fclose(foriginal);
                return 0;
            }

        }else if(strcmp(name,"apellido")==0){
            if(strcmp(newstudent.lastname,valor)==0){
                strcpy(newstudent.lastname,reemplazo);
                fseek(foriginal,-sizeof(newstudent),SEEK_CUR);
                fwrite(&newstudent,sizeof(newstudent),1,foriginal);
                fclose(foriginal);
                return 0;
            }

        }else if(strcmp(name,"id")==0){
            if(newstudent.id==atoi(valor)){
                newstudent.id=atoi(reemplazo);
                fseek(foriginal,-sizeof(newstudent),SEEK_CUR);
                fwrite(&newstudent,sizeof(newstudent),1,foriginal);
                fclose(foriginal);
                return 0;
            }

        }else if(strcmp(name,"semestre")==0){
            if(newstudent.semestre==atoi(valor)){
                newstudent.semestre=atoi(reemplazo);
                fseek(foriginal,-sizeof(newstudent),SEEK_CUR);
                fwrite(&newstudent,sizeof(newstudent),1,foriginal);
                fclose(foriginal);
                return 0;
            }

        }else{
            return -1;
        }
        
    }

    fclose(foriginal);

    return 0;
}