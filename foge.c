#include <stdio.h>
#include <stdlib.h>
#include "foge.h"
#include "mapa.h"

MAPA m;
POSICAO pos; //guarda a posicao atual do @

int acabou(){ //funcao acabou - falta ser implementada
    return 0;
}

void move(char direcao){

    if(direcao != 'a' && direcao != 'w' && direcao != 's' && direcao != 'd'){
        return; //terminando a funcao, se um char não esperado for digitado
    }

    int prox_x = pos.x;
    int prox_y = pos.y;



    switch(direcao){ // movendo o @ de acordo com seu respectivo comando
        case 'a':
            //m.matriz[pos.x][pos.y-1] = '@';
            //pos.y--; // varia posicao -> deslocou pra esquerda
            prox_y--;
            break;
        case 'w':
            // m.matriz[pos.x-1][pos.y] = '@';
            // pos.x--; // varia posicao -> deslocou pra baixo
            prox_x--;
            break;
        case 's':
            // m.matriz[pos.x+1][pos.y] = '@';
            // pos.x++; // varia posicao -> deslocou pra direita
            prox_x++;
            break;
        case 'd':
            // m.matriz[pos.x][pos.y+1] = '@';
            // pos.y++;
            prox_y++;
            break; // varia posicao -> deslocou pra cima
    }
    if(prox_x >= m.linhas) // maior que a quantidade de linhas (não existe)
        return;
    if(prox_y >= m.colunas) // maior que a quantidade de colunas (não existe)
        return;
    if(m.matriz[prox_x][prox_y] != '.') // se não for um '.' não 'anda'
        return;
    
    //agora pode andar, apenas podemos onde existir '.'
    m.matriz[prox_x][prox_y] = '@';
    m.matriz[pos.x][pos.y] = '.';
    pos.x = prox_x;
    pos.y = prox_y;
}

int main(){

    le_mapa(&m);
    encontra_mapa(&m, &pos, '@');

    do{
        imprime_mapa(&m);
        char comando;
        scanf(" %c", &comando); //lendo a entrada atual

        move(comando);

    }while(!acabou()); //enquando o jogo nao acabar...

    libera_mapa(&m);

}

//" %c" -> com espaço porque o espaço ajuda a ler o anterior enter e nao causar mais problemas
