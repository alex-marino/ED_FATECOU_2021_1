#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main() {
    printf("Árvores binárias!\n");
    //Exemplo de árvore
    // <c <a> <d>>
//    Arv* c = arv_cria('c', arv_cria('a', arv_criavazia(), arv_criavazia()), arv_cria('d', arv_criavazia(), arv_cria('G', NULL, NULL)));
//    arv_imprime(c);
//    arv_libera(c);

    //<a <b <> <d <><>>> <c <e <><>> <f <><> >>>
    //sub-arvore 'd'
    Arv* a1 = arv_cria('d', arv_criavazia(), arv_criavazia());

    //sub-arvore 'd'
    Arv* a2 = arv_cria('b', arv_criavazia(), a1);

    //sub-arvore 'e'
    Arv* a3 = arv_cria('e', arv_criavazia(), arv_criavazia());

    //sub-arvore 'f'
    Arv* a4 = arv_cria('f', arv_criavazia(), arv_criavazia());

    //sub-arvore 'c'
    Arv* a5 = arv_cria('c', a3, a4);

    //sub-arvore 'a'
    Arv* a = arv_cria('a', a2, a5);

    arv_imprime(a);
    printf("\n");
    arv_print_pre(a);
    printf("\n");
    arv_print_sim(a);
    printf("\n");
    arv_print_pos(a);
    printf("\n");
    //Acrescentar um nó 'x' em a->esq->esq, ou seja, em 'b'
    a->esq->esq =
            arv_cria('x',
                    arv_cria('y',
                            arv_criavazia(),
                            arv_criavazia()
                            ),
                    arv_cria('z',
                            arv_criavazia(),
                            arv_criavazia())
                    );

    arv_imprime(a);
    printf("\n");
    //Libera nós
    a->dir->esq = arv_libera(a->dir->esq);
    arv_imprime(a);
    printf("\n");


    Arv* A = arv_cria('A',
                arv_cria('B',
                        arv_criavazia(),
                        arv_cria('D', arv_criavazia(), arv_criavazia())
                        ),
                arv_cria('C',
                        arv_cria('E', arv_criavazia(), arv_criavazia()),
                        arv_cria('F', arv_criavazia(), arv_criavazia())
                        )
            );
    arv_imprime(A);
    printf("\n");

    return 0;
}
