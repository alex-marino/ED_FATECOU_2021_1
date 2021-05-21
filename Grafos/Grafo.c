//
// Created by alex on 19/05/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"



Grafo* criaGrafo (int nroVert, int GMAX, int ehPonderado) {
    Grafo *gr;
    gr = (Grafo*) malloc(sizeof(Grafo));
    if (gr != NULL){
        int i;
        gr->nroVert = nroVert;
        gr->GMAX = GMAX;
        gr->ehPonderado = (ehPonderado!=0)?1:0;
        gr->grau=(int*) calloc(nroVert, sizeof(int));
        gr->arestas=(int**) malloc(nroVert*sizeof(int*));
        for (i=0; i<nroVert; i++){
            gr->arestas[i]= (int*) malloc(sizeof(int)*GMAX);
        }
        if (gr->ehPonderado){
            gr->pesos=(float**) malloc(nroVert*sizeof(float*));
            for (i=0; i<nroVert; i++){
                gr->pesos[i]=(float*) malloc(GMAX*sizeof(float));
            }
        }
    }
    return gr;
}

void liberaGrafo (Grafo* gr) {
    if (gr != NULL){
        int i;
        for(i=0; i<gr->nroVert; i++){
            free(gr->arestas[i]);
        }
        free(gr->arestas);
        if (gr->ehPonderado){
            for(i=0; i<gr->nroVert; i++){
                free(gr->pesos[i]);
            }
            free(gr->pesos);
        }
        free(gr->grau);
        free(gr);
    }
}

int insereAresta(Grafo* gr, int orig, int dest, int digrafo, float peso) {
    if (gr==NULL){
        return 0;
    }
    if (orig < 0 || orig >= gr->nroVert){
        return 0;
    }
    if (dest < 0 || dest >= gr->nroVert){
        return 0;
    }
    gr->arestas[orig][gr->grau[orig]]=dest;
    if (gr->ehPonderado){
        gr->pesos[orig][gr->grau[orig]]=peso;
    }
    gr->grau[orig]++;
    if (digrafo==0){
        insereAresta(gr, dest, orig, 1, peso);
    }
    return 1;
}

int removeAresta (Grafo* gr, int orig, int dest, int ehDigrafo){
    if (gr==NULL){
        return 0;
    }
    if (orig<0 || orig >= gr->nroVert){
        return 0;
    }
    if (dest<0 || dest >= gr->nroVert){
        return 0;
    }
    int i=0;

    while (i<gr->grau[orig] && gr->arestas[orig][i]!=dest){
        i++;
    }
    if (i==gr->grau[orig]){
        return 0;
    }
    gr->grau[orig]--;
    gr->arestas[orig][i]=gr->arestas[orig][gr->grau[orig]];
    if (gr->ehPonderado){
        gr->pesos[orig][i]=gr->pesos[orig][gr->grau[orig]];
    }
    if (ehDigrafo){
        removeAresta(gr, dest, orig, 1);
    }
    return 1;
}


