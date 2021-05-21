#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

int main() {
    int ehDigrafo=1;
    Grafo* gr = criaGrafo(5, 5, 0);
    insereAresta(gr, 0, 1, ehDigrafo, 0);
    insereAresta(gr, 1, 3, ehDigrafo, 0);
    insereAresta(gr, 1, 2, ehDigrafo, 0);
    insereAresta(gr, 2, 4, ehDigrafo, 0);
    insereAresta(gr, 3, 0, ehDigrafo, 0);
    insereAresta(gr, 3, 4, ehDigrafo, 0);
    insereAresta(gr, 4, 1, ehDigrafo, 0);

    //Proceder busca

    liberaGrafo(gr);
    return 0;
}


