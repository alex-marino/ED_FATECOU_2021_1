#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node* next;
} Node;

typedef struct cLinkedList {
    Node* firstNode;
    Node* lastNode;
    int listSize;
} CLinkedList;

Node* createNode (int);

CLinkedList* CLcreateEmpty (); //criar uma linked list vazia

void CLaddEnd (CLinkedList*, int val); //adicionar um no node no fim da circular linked list

CLinkedList* chargeList(int M); //monta a lista circular com M judeus

Node* delNode(CLinkedList*, Node*, Node*);

void pointLastToFirst(CLinkedList* ll);

void massada(int M, int P, int N);

int main() {
    int M, P, N;
    while(scanf("%d %d %d", &M, &P, &N) != EOF){
        massada(M, P, N);
    }
    return 0;
}

void massada(int M, int P, int N){
    int i, counter=0;
    CLinkedList* judeus = chargeList(M);
    Node* curr = judeus->firstNode; //judeu com a faca - primeiro da lista
    Node* prev = judeus->lastNode;  //ultimo judeu da lista - anterior ao primeiro
    for (i=0; i<P-1; i++){ //colocar a faca na mao de Josefo
        prev=curr;
        curr=curr->next;
    }
    while (judeus->listSize!=1){
    	//Aqui nesse laço deve ocorrer a mágica :-P
    	//Basicaente deve programar:
	//	1 - encontrar o judeu que vai morrer -> posicionar o node
        //	2 - matar o judeu -> libebrar o node
	//      OBS : seria interessante usar a função delNode
    }    
    if (judeus->firstNode->info==P){ // Verifica se Josefo sobreviveu
        printf("VIVO\n");
    } else {
        printf("MORTO %d\n", judeus->firstNode->info);
    }

}
/*
 * Esta função delNode recebe como argumentos:
 *     1 - CLinkedList* cl -> A lista de judeus
 *     2 - Node* curr -> o nó corrente (aquele que deve ser morto/excluido)
 *     3 - Node* prev -> o nó anterior ao corrente (pois é preciso após excluir o curr e apontar o prev->next para o node seguinte ao cur
 * E retorna Node*:
 *     1 - retorna o nó seguinte ao que foi excluido
 */
Node* delNode(CLinkedList* cl, Node* curr, Node* prev) {
    if (curr==cl->firstNode){
        cl->lastNode->next=curr->next;
        cl->firstNode=curr->next;
    }
    if (curr==cl->lastNode){
        cl->lastNode=prev;
        prev->next=cl->firstNode;
    }
    if (curr!=cl->lastNode && curr!=cl->firstNode){
        prev->next=curr->next;
    }
    cl->listSize--;
    free(curr);
    return prev->next;
}

CLinkedList* chargeList(int M){
    CLinkedList* c = CLcreateEmpty();
    int i;
    for(i=0; i<M; i++){
        CLaddEnd(c, i+1);
    }
    return c;
}

Node* createNode(int v){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->info = v;
    newNode->next = NULL;
    return newNode;
}


CLinkedList* CLcreateEmpty () {
    CLinkedList* ll = (CLinkedList*) malloc(sizeof(CLinkedList));
    ll->firstNode=NULL;
    ll->listSize=0;
    ll->lastNode=NULL;
    return ll;
}

void pointLastToFirst(CLinkedList* ll){
    ll->lastNode->next=ll->firstNode;
}

void CLaddEnd (CLinkedList* ll, int val) {
    Node* lastNode = ll->lastNode;
    Node* newNode = createNode(val);
    if (ll->listSize==0){
        ll->firstNode=newNode;
        ll->lastNode=newNode;
    } else {
        lastNode->next=newNode;
        ll->lastNode=newNode;
    }
    ll->listSize++;
    pointLastToFirst(ll);
}

