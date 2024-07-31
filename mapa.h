#ifndef MAPA_H
    #define MAPA_H
    
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

#endif