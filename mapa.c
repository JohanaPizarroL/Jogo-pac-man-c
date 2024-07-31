#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"

void aloca_mapa(MAPA* m){
    m->matriz = malloc(sizeof(char*) * (m->linhas)); //alocando ponteiros * quantidade que quereomos alocar
    for(int i = 0; i < m->linhas; i++){
        m->matriz[i] =  malloc(sizeof(char) * (m->colunas + 1)); //colunas +1 porque temos o \0 no final de cada linha
    }
}

void le_mapa(MAPA* m){

    FILE* f;
    f = fopen("mapa.txt", "r"); //abrindo arquivo para leitura
    if(f == NULL){
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }
    fscanf(f, "%d %d", &(m->linhas), &(m->colunas)); //lendo o tamanho do mapa, em tempo de execução
    aloca_mapa(m);

    for(int i = 0; i < m->linhas; i++){
        fscanf(f, "%s", m->matriz[i]); // linhas
    }
    fclose(f);
}

void imprime_mapa(MAPA* m){
    for(int i = 0; i < m->linhas; i++){
        printf("%s\n", m->matriz[i]);
    }
}

void encontra_mapa(MAPA* m, POSICAO* pos, char c){ //c = char buscado(@)

    for(int i = 0; i < m->linhas; i++){
        for(int j = 0; j < m->colunas; j++){
            if(m->matriz[i][j] == c ){
                pos->x = i;
                pos->y = j;
                break;
            }
        }
    }

}

void libera_mapa(MAPA* m){
    for(int i = 0; i < m->linhas; i++){
        free(m->matriz[i]);
    }
    free(m->matriz);
}