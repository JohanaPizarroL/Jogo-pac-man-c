#ifndef MAPA_H
    #define MAPA_H

    #define HEROI '@'
    #define VAZIO '.'
    #define PAREDE_VERTICAL '|'
    #define PARECE_HORIZONTAL '-'

    
    typedef struct mapa MAPA;
    typedef struct posicao POSICAO;

    struct mapa {
        char** matriz;
        int linhas;
        int colunas;
    };

    struct posicao {
        int x;
        int y;
    };

    void libera_mapa(MAPA* m);
    void aloca_mapa(MAPA* m);
    void le_mapa(MAPA* m);
    void imprime_mapa(MAPA* m);
    void encontra_mapa(MAPA* m, POSICAO* pos, char c);
    int pertence_mapa(MAPA* M, int x, int y);
    int espaco_livre(MAPA* m, int x, int y);
    void anda_no_mapa(MAPA* m, int x_org, int y_org, int x_dest, int y_dest);

#endif