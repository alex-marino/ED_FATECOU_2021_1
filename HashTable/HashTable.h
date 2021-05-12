//
// Created by alex on 28/04/2021.
//

#ifndef HASHTABLE_HASHTABLE_H
#define HASHTABLE_HASHTABLE_H
typedef struct aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;
} Aluno;
typedef struct hash Hash;

Hash* criaHash (int size);
void liberaHash(Hash* ha);
int valorString(char* str);
int insereSemColisao(Hash* ha, Aluno* al);
int buscaSemColisao(Hash* ha, int mat, Aluno* al);
int insereEndAberto(Hash* ha, Aluno* al);
int buscaEndeAberto(Hash* ha, int mat, Aluno* al);
#endif //HASHTABLE_HASHTABLE_H
