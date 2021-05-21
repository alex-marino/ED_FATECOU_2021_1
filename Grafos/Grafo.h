//
// Created by alex on 19/05/2021.
//

#ifndef GRAFOS_GRAFO_H
#define GRAFOS_GRAFO_H

struct grafo {
    int ehPonderado;
    int nroVert;
    int GMAX;
    int** arestas;
    float** pesos;
    int* grau;
};


typedef struct grafo Grafo;

Grafo* criaGrafo (int nroVert, int GMAX, int ehPonderado);

void liberaGrafo (Grafo* gr);

int insereAresta(Grafo* rg, int orig, int dest, int digrafo, float peso);

int removeAresta (Grafo* gr, int orig, int dest, int digrafo);

#endif //GRAFOS_GRAFO_H
