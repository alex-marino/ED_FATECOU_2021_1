//
// Created by alex on 19/05/2021.
//

#include "BuscaGrafo.h"

void buscaProfundidade(Grafo *gr, int ini, int *visitado, int cont){
    int i;
    visitado[ini]=cont;
    for (i=0; i<gr->grau[ini]; i++){
        if(!visitado[gr->arestas[ini][i]]){
            buscaProfundidade(gr, gr->arestas[ini][i], visitado, cont+1);
        }
    }
}

void buscaProfundidadeGrafo(Grafo *gr, int ini, int *visitado){
    int i, cont=1;
    for(i=0; i<gr->nroVert; i++){
        visitado[i] = 0;
    }
    buscaProfundidade(gr, ini, visitado, cont);
}
