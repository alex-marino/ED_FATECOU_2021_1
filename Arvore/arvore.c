//
// Created by alexm on 08/07/2020.
//
#include <stdlib.h>
#include "arvore.h"



void arv_imprime (Arv* a){
    if (!arv_vazia(a)){
        printf("<%c ", a->info); //mostra raiz
        arv_imprime(a->esq);    //mostra SAE
        arv_imprime(a->dir);    //mostra SAD
        printf(">");
    }
}
void arv_print_pre (Arv* a){
    if (!arv_vazia(a)){
        printf("<%c ", a->info); //mostra raiz
        arv_imprime(a->esq);    //mostra SAE
        arv_imprime(a->dir);    //mostra SAD
        printf(">");
    }
}
void arv_print_sim (Arv* a){
    if (!arv_vazia(a)){
        arv_imprime(a->esq);    //mostra SAE
        printf("<%c ", a->info); //mostra raiz
        arv_imprime(a->dir);    //mostra SAD
        printf(">");
    }
}

void arv_print_pos (Arv* a){
    if (!arv_vazia(a)){
        arv_imprime(a->esq);    //mostra SAE
        arv_imprime(a->dir);    //mostra SAD
        printf("<%c ", a->info); //mostra raiz
        printf(">");
    }
}


int arv_pertence (Arv* a, char c){
    if (arv_vazia(a))
        return 0; /* árvore vazia: não encontrou */
    else
        return a->info==c ||
               arv_pertence(a->esq,c) ||
               arv_pertence(a->dir,c);
}

int arv_vazia (Arv* a){
    return a==NULL;
}

Arv* arv_libera (Arv* a){
    if (!arv_vazia(a)){
        arv_libera(a->esq); //libera SAE
        arv_libera(a->dir); //libera SAD
        free(a);            // libera árvore
    }
    return NULL;
}

Arv* arv_cria (char c, Arv* sae, Arv* sad){
    Arv* p=(Arv*)malloc(sizeof(Arv));
    p->info = c;
    p->esq = sae;
    p->dir = sad;
    return p;
}

Arv* arv_criavazia (void){
    return NULL;
}



