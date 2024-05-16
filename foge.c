#include <stdio.h>
#include <stdlib.h>

char** mapa; // +1 para o '\0'
int linhas;
int colunas;

int main(){

    FILE *f;
    f = fopen("mapa.txt", "r"); //abrindo arquivo para leitura
    if(f == NULL){
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }

//lendo o tamanho do mapa, em tempo de execução
    fscanf(f, "%d %d", &linhas, &colunas);
    printf("linhas: %d colunas: %d\n", linhas, colunas);


    mapa = malloc(sizeof(char) * linhas); //alocando inteiros * quantidade que quereomos alocar
    for(int i = 0; i < linhas; i++){
        mapa[i] =  malloc(sizeof(char) * (colunas + 1)); //colunas +1 porque temos o \0 no final de cada linha
    }
    //printf("inteiro alocado %d\n", *v);

    for(int i = 0; i < 5; i++){
        fscanf(f, "%s", mapa[i]);
    }
    
    for(int i = 0; i < 5; i++){
        printf("%s\n", mapa[i]);
    }
    fclose(f);

    for(int i = 0; i < 5; i++){
        free(mapa[i]);
    }
    free (mapa);
    
}

//criaremos dinamicamente uma matriz