#include <stdio.h>
#include <stdlib.h>
#include "foge.h"

char** mapa;
int linhas;
int colunas;

void aloca_mapa(){
    mapa = malloc(sizeof(char*) * linhas); //alocando inteiros * quantidade que quereomos alocar
    for(int i = 0; i < linhas; i++){
        mapa[i] =  malloc(sizeof(char) * (colunas + 1)); //colunas +1 porque temos o \0 no final de cada linha
    }
}
void le_mapa(){
    FILE *f;
    f = fopen("mapa.txt", "r"); //abrindo arquivo para leitura
    if(f == NULL){
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }

//lendo o tamanho do mapa, em tempo de execução
    fscanf(f, "%d %d", &linhas, &colunas);
    aloca_mapa();

    for(int i = 0; i < 5; i++){
        fscanf(f, "%s", mapa[i]);
    }
    fclose(f);
}

void libera_mapa(){
    for(int i = 0; i < linhas; i++){
        free(mapa[i]);
    }
    free(mapa);
}

void imprime_mapa(){
    for(int i = 0; i < linhas; i++){
        printf("%s\n", mapa[i]);
    }
}

int acabou(){
    return 0;
}

void move(char direcao){
    //primeiro precisamos localizar onde está o carinha do nosso jogo
    int x, y;
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            if(mapa[i][j] == '@'){
                x = i;
                y =j;
                break;
            }
        }
    }
// movendo o @ de acordo com seu respectivo comando
    switch(direcao){
        case 'a':
            mapa[x][y-1] = '@'; //x = linha y = colunas
            break;
        case 'w':
            mapa[x-1][y] = '@';
            break;
        case 's':
            mapa[x+1][y] = '@';
            break;
        case 'd':
            mapa[x][y+1] = '@';
            break;
    }
    mapa[x][y] = '.'; 
    //tirando o pacman da posicao atual, colocando . no lugar
}   



int main(){

    le_mapa();
    do{
        imprime_mapa();
        char comando;
        scanf(" %c", &comando);
        move(comando);
    }while(!acabou());

    libera_mapa();
}
