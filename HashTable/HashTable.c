#include <stdlib.h>
#include <string.h>
//
// Created by alex on 28/04/2021.
//

#include "HashTable.h"

struct hash{
    int qtd, TABLE_SIZE;
    Aluno** itens;
};


Hash* criaHash (int size) {
    Hash* ha = (Hash*) malloc(sizeof(Hash));
    if (ha!=NULL){
        ha->TABLE_SIZE = size;
        ha->itens = (Aluno**) malloc(size * sizeof(Aluno*) );
        if(ha->itens==NULL){
            free(ha);
            return NULL;
        }
        ha->qtd = 0;
        int i;
        for(i=0; i<ha->TABLE_SIZE; i++){
            ha->itens[i] = NULL;
        }
    }
    return ha;
}

void liberaHash(Hash* ha) {
    if (ha != NULL){
        int i;
        for(i=0; i<ha->TABLE_SIZE; i++){
            if(ha->itens[i]!=NULL){
                free(ha->itens[i]);
            }
            free(ha->itens);
            free(ha);
        }
    }
}

int chaveDivisao (int chave, int size){
    return (chave & 0x7FFFFFFF)%size;
}

int chaveMultiplicacao (int chave, int size){
    float A = 0.6180339887; //constante 0 < A < 1
    float val = chave*A;
    val = val - (int) val;
    return (int) (size*val);
}

int chaveDobra (int chave, int size){
    int num_bits = 10;
    int parte1 = chave >> num_bits;
    int parte2 = chave & (size-1);
    return (parte1 ^ parte2);
}

int valrString (char* str){
    int i, valor=7;
    int tam = strlen(str);
    for (i=0; i<tam; i++){
        valor = 31 * valor + (int) str[i];
    }
    return valor;
}

int insere_SemColisao (Hash* ha, Aluno al){
    if (ha==NULL || ha->qtd == ha->TABLE_SIZE){
        return 0;
    }
    int chave = al.matricula;
    //int chave = valorString(al->nome);
    int pos = chaveDivisao(chave, ha->TABLE_SIZE);
    Aluno* novo;
    novo = (Aluno*) malloc(sizeof(Aluno));
    if (novo==NULL){
        return 0;
    }
    *novo = al;
    ha->itens[pos] = novo;
    ha->qtd++;
    return 1;
}

int buscaHash_semColisao(Hash* ha, int mat, Aluno* al){
    if (ha==NULL){
        return 0;
    }
    int pos = chaveDivisao(mat, ha->TABLE_SIZE);
    if (ha->itens[pos]==NULL){
        return 0;
    }
    *al = *(ha->itens[pos]);
    return 1;
}

int sondagemLinear(int pos, int i, int TABLE_SIZE){
    return ((pos+i) & 0x7FFFFFFF)%TABLE_SIZE;
}

int songademQuadratica(int pos, int i, int TABLE_SIZE){
    pos = pos + 2*i+5*i*i;
    return ((pos+i) & 0x7FFFFFFF)%TABLE_SIZE;
}

int duploHash(int H1, int chave, int i, int TABLE_SIZE) {
    int H2 = chaveDivisao(chave, TABLE_SIZE-1)+1;
    return ((H1+i*H2) & 0x7FFFFFFF)%TABLE_SIZE;
}

int insereHash_EnderecoAberto(Hash* ha, Aluno al){
    if (ha == NULL || ha->qtd == ha->TABLE_SIZE){
        return 0;
    }
    int chave = al.matricula;
    //int chave = valString(al.nome);
    int i, pos, newPos;
    pos = chaveDivisao(chave, ha->TABLE_SIZE);
    for (i=0; i<ha->TABLE_SIZE; i++) {
        newPos = sondagemLinear(pos, i, ha->TABLE_SIZE);
        //newPos = songademQuadratica(pos, i, ha->TABLE_SIZE);
        //newPos = duploHash(pos, chave, i, ha->TABLE_SIZE);
        if (ha->itens[newPos]==NULL){
            Aluno* novo;
            novo = (Aluno*) malloc(sizeof(Aluno));
            if(novo==NULL){
                return 0;
            }
            *novo = al;
            ha->itens[newPos] = novo;
            ha->qtd++;
            return 1;
        }
    }
    return 0;
}

int buscaHash_EnderecoAberto (Hash* ha, int mat, Aluno* al){
    if (ha == NULL){
        return 0;
    }
    int i, pos, newPos;
    pos = chaveDivisao(mat,  ha->TABLE_SIZE);
    for (i=0; i<ha->TABLE_SIZE; i++){
        newPos = sondagemLinear(pos, i, ha->TABLE_SIZE);
        //newPos = sondagemQuadratica(pos, i, ha->TABLE_SIZE);
        //newPos = duploHash(pos, mat, i, ha->TABLE_SIZE);
        if (ha->itens[newPos]==NULL){
            return 0;
        }
        if (ha->itens[newPos]->matricula == mat){
            *al = *(ha->itens[newPos]);
            return 1;
        }
    }
}