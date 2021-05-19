#include <stdio.h>

int main(int argnum, char **argv){
    char *original = argv[1];
    char *destino = argv[2];
    char buffer;

    FILE *foriginal, *fdestino;
    foriginal=fopen(original,"rb");
    fdestino=fopen(destino,"wb");
    while(fread(&buffer,sizeof(char),1,foriginal)){
        fwrite(&buffer,sizeof(char),1,fdestino);
    }

    fclose(foriginal);
    fclose(fdestino);

    return 0;
}