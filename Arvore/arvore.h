//
// Created by alexm on 08/07/2020.
//

#ifndef ARVORE_ARVORE_H
#define ARVORE_ARVORE_H
struct arv {
    char info;
    struct arv* esq;
    struct arv* dir;
};


typedef struct arv Arv;

Arv* arv_criavazia (void);
Arv* arv_cria (char c, Arv* e, Arv* d);
Arv* arv_libera (Arv* a);
int arv_vazia (Arv* a);
int arv_pertence (Arv* a, char c);
void arv_imprime (Arv* a);
void arv_print_pre (Arv* a);
void arv_print_sim (Arv* a);
void arv_print_pos (Arv* a);

#endif //ARVORE_ARVORE_H
