#include <stdio.h>
#include <stdlib.h>
#include "foge.h"
#include "mapa.h"

MAPA m;
POSICAO pos; //guarda a posicao atual do @

int acabou(){ //funcao acabou - falta ser implementada
    return 0;
}

int direcao_valida(char direcao) { // verifica se é uma direcao(char) esperada
    return direcao == 'a' || direcao == 'w' || direcao == 's' || direcao == 'd';
}


void move(char direcao){

    if(!direcao_valida){
        return; //a direção não é valida
    }

    int prox_x = pos.x;
    int prox_y = pos.y;



    switch(direcao){ // movendo o @ de acordo com seu respectivo comando
        case ESQUERDA:
            prox_y--;
            break;
        case CIMA:
            prox_x--;
            break;
        case BAIXO:
            prox_x++;
            break;
        case DIREITA:
            prox_y++;
            break; // varia posicao -> deslocou pra cima
    }

    if(!pertence_mapa(&m, prox_x, prox_y)) // verifica se a área pertence ao mapa
        return;
    
    if(!espaco_livre(&m, prox_x, prox_y)) // verifica se pode andar (não é parede)
        return;
    
    anda_no_mapa(&m, pos.x, pos.y, prox_x, prox_y);
    pos.x = prox_x;
    pos.y = prox_y;


}

int main(){

    le_mapa(&m);
    encontra_mapa(&m, &pos, HEROI);

    do{
        imprime_mapa(&m);
        char comando;
        scanf(" %c", &comando); //lendo a entrada atual

        move(comando);

    }while(!acabou()); //enquando o jogo nao acabar...

    libera_mapa(&m);
    

}

//" %c" -> com espaço porque o espaço ajuda a ler o anterior enter e nao causar mais problemas