#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct lista {
    char info;
    struct lista *prox;
};

typedef struct lista Lista;

struct pilha {
    Lista* prim;
};

typedef struct pilha Pilha;

struct node {
    char data;
    struct node *left, *right;
};

typedef struct node Node;

Lista *lst_insere(Lista *l, char i);
Pilha* pilha_cria (void);
void pilha_push (Pilha*, char );
char  pilha_pop (Pilha*);
int pilha_vazia (Pilha*);
void pilha_libera (Pilha*);
char  pilha_top (Pilha* P);
void processa(char* str);
Node* newNode(char);
void preOrder(Node*);
void postOrder(Node*);
void simOrder(Node*);
int sumRigth(Node*);
int sumLeft(Node*);
int size(Node*);
int maxDepth(Node*);
int getIdx(char*, int, int);
Node* getTreeFromString(char*, int, int);



int main() {
    char str[300];
    int N, i;
    scanf("%d", &N);
    for (i=0; i<N; i++){
        scanf("%s", str);
        processa(str);
    }
    return 0;
}


void processa(char* str) {
    /*
     * Implementar a rotina de processamento da resposta ao caso de teste
     */
    printf("SUA RESPOSTA");
}

Node *newNode(char data) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

void preOrder(Node *node) {
    /*
     * Implementar sua rotina de pre ordem
     */
}

void postOrder(Node* node){
    /*
     * Implementar sua rotina de pos ordem
     */
}

void simOrder(Node* node){
    /*
     * Implementar sua rotina de ordem simétrica
     */
}

int sumRigth(Node *node) {
    /*
     * Implementar sua rotina de soma dos nós a direita
     */
    return 0;
}

int sumLeft(Node *node) {
    /*
     * Implementar sua rotina de soma dos nós a esquerda
     */
    return 0;
}

int size(Node* node) {
    /*
     * Implementar sua rotina de contagem dos nós (Q)
     */
    return 0;
}

int maxDepth(Node* node) {
    /*
     * Implementar sua rotina para determinar a altura (H)
     */
    return 0;
}

Pilha *pilha_cria(void) {
    Pilha *p = (Pilha *) malloc(sizeof(Pilha));
    p->prim = NULL;
    return p;
}

char pilha_pop(Pilha *p) {
    Lista *t;
    float v;
    if (pilha_vazia(p)) {
        printf("Pilha vazia.\n");
        /* aborta programa */
        exit(1);
    }
    t = p->prim;
    v = t->info;
    p->prim = t->prox;
    free(t);
    return v;
}

void pilha_libera(Pilha *p) {
    Lista *q = p->prim;
    while (q != NULL) {
        Lista *t = q->prox;
        free(q);
        q = t;
    }
    free(p);
}

void pilha_push(Pilha *p, char v) {
    p->prim = lst_insere(p->prim, v);
}

int pilha_vazia(Pilha *P) {
    return (P->prim == NULL);
}

char pilha_top(Pilha *P) {
    if (!pilha_vazia(P)) {
        return P->prim->info;
    } else {
        exit(1);
    }

}

Lista *lst_insere(Lista *l, char i) {
    Lista *novo = (Lista *) malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;
    return novo;
}

int getIdx(char *str, int si, int ei) {
    if (si > ei)
        return -1;
    Pilha *s = pilha_cria();

    for (int i = si; i <= ei; i++) {
        if (str[i] == '(')
            pilha_push(s, str[i]);
        else if (str[i] == ')') {
            if (pilha_top(s) == '(') {
                pilha_pop(s);
                if (pilha_vazia(s)){
                    pilha_libera(s);
                    return i;
                }
            }
        }
    }
    pilha_libera(s);
    return -1;
}

Node* getTreeFromString(char *str, int si, int ei) {
    if (si > ei)
        return NULL;
    Node *root = newNode(str[si]);
    int index = -1;
    if (si + 1 <= ei && str[si + 1] == '(')
        index = getIdx(str, si + 1, ei);
    if (index != -1) {
        root->left = getTreeFromString(str, si + 2, index - 1);
        root->right = getTreeFromString(str, index + 2, ei - 1);
    }
    return root;
}

