//
// Created by alex on 30/04/2021.
//

#include "minhaString.h"
int comprimento (char* s) {
    int i;
    for (i=0; s[i]!='\0'; i++){}
    return i;
}

int copia (char* d, char* o) {
    int i;
    for(i=0; o[i]!='\0'; i++){
        d[i]=o[i];
    }
    d[i]=o[i];
}

void concatena (char* dest, char* orig){
    int i = 0;
    int j;
    /* ice usado na cadeia destino, inicializado
    /* ice usado na cadeia origem */
    /* acha o final da cadeia destino */
    i = 0;
    while (dest[i] != '\0')
        i++;
    /* copia elementos da origem para o final do destino */
    for (j=0; orig[j] != '\0'; j++){
        dest[i] = orig[j]; i++;
    }
    /* fecha cadeia destino */
    dest[i] = '\0';
}


int compara (char* s1, char* s2){
    int i;
    /* compara caractere por caractere */
    for (i=0; s1[i]!='\0' && s2[i]!='\0'; i++) {
        if (s1[i] < s2[i])
            return -1;
        else if (s1[i] > s2[i])
            return 1;
    }
    /* compara se cadeias to mesmo comprimento */
    if (s1[i]==s2[i])
    /* cadeias iguais */
        return 0;
    else if (s2[i]!= '\0')
    /* s1 enor, pois tem menos caracteres */
        return -1;
    else
    /* s2 enor, pois tem menos caracteres */
        return 1;
}
