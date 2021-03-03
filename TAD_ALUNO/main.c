#include <stdio.h>
#include <stdlib.h>

struct aluno {
    int mat;
    char nome[81];
    char end[121];
    char tel[21];
};

typedef struct aluno Aluno;
#define MAX 100
Aluno* tab[MAX];

void preenche (int n, Aluno** tab, int i);

void inicializa (int n, Aluno** tab);

void retira (int n, Aluno** tab, int i);

void retira (int n, Aluno** tab, int i);

void imprime (int n, Aluno** tab, int i);

void imprime_tudo (int n, Aluno** tab);

int main() {
    Aluno* tab[10];
    inicializa(10,tab);
    preenche(10,tab,0);
//    preenche(10,tab,1);
//    preenche(10,tab,2);
    imprime_tudo(10,tab);
    retira(10,tab,0);
    retira(10,tab,1);
    retira(10,tab,2);
    return 0;
}


void inicializa (int n, Aluno** tab){
    int i;
    for (i=0; i<n; i++)
        tab[i] = NULL;
}

void preenche (int n, Aluno** tab, int i) {
    if (i < 0 || i >= n) {
        printf("Indice fora do limite do vetor\n");
        exit(1); /* aborta o programa */
    }
    if (tab[i] == NULL)
        tab[i] = (Aluno *) malloc(sizeof(Aluno));
    printf("==================================================================\n");
    printf("Informe a matricula\t: ");
    scanf("%d", &tab[i]->mat);
    scanf("%*c");
    printf("Informe o nome\t\t: " );
    scanf("%*[^\n]", &tab[i]->nome);
    scanf("%*c");
    printf("Informe o endereco\t: ");
    scanf("%*[^\n]", &tab[i]->end);
    scanf("%*c");
    printf("Informe o telefone\t: ");
    scanf("%d", &tab[i]->tel);
}

void retira (int n, Aluno** tab, int i){
    if (i<0 || i>=n) {
        printf("Indice fora do limite do vetor\n");
        exit(1); /* aborta o programa */
    }
    if (tab[i] != NULL){
        free(tab[i]);
        tab[i] = NULL; /* indica que na posiçãoo não possui mais aluno */
    }
}

void imprime (int n, Aluno** tab, int i){
    if (i<0 || i>=n) {
        printf("Indice fora do limite do vetor\n");
        exit(1); /* aborta o programa */
    }
    if (tab[i] != NULL){
        printf("Matricula: %d\n" , tab[i]->mat);
        printf("Nome: %s\n", tab[i]->nome);
        printf("Endereco: %s\n" , tab[i]->end);
        printf("Telefone: %s\n" , tab[i]->tel);
    }
}

void imprime_tudo (int n, Aluno** tab){
    int i;
    for (i=0; i<n; i++)
        imprime(n,tab,i);
}