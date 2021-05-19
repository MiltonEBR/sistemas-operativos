#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argnum, char **argv){
    char *original = argv[1];
    char *destino = argv[2];
    char buffer;

    FILE *foriginal, *fdestino;
    foriginal = fopen(original,"r");
    fdestino = fopen(destino,"w");
    int size=0;
    while(fread(&buffer,sizeof(char),1,foriginal)){
        if(buffer=='\n'){
            size+=1;
            fseek(foriginal, -size, SEEK_CUR);
            char *linea = (char *) calloc(size,sizeof(char));
            fread(linea,sizeof(char),size,foriginal);
            if(strstr(linea,"hola")==NULL){
                fwrite(linea,sizeof(char),size,fdestino);
            }
            size=0;
        }else{
            size+=1;
        }
    }
    if(size>0){
        size+=1;
        fseek(foriginal, -size, SEEK_CUR);
        char *linea = (char *) calloc(size,sizeof(char));
        fread(linea,sizeof(char),size,foriginal);
        if(strstr(linea,"hola")==NULL){
            fwrite(linea,sizeof(char),size,fdestino);
        }
    }
    

    fclose(foriginal);
    fclose(fdestino);

    return 0;
}