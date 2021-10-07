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
    int isEmpty;
} CLinkedList;

Node* createNode (int);

void dropNode(Node*);


CLinkedList* CLcreateEmpty (); //criar uma linked list vazia

void CLaddEnd (CLinkedList*, int val); //adicionar um no node no fim da circular linked list

void CLdeleteByIdx (CLinkedList*, int idx); //deletar um node dada sua posiçao

CLinkedList* chargeList(int M); //monta a lista circular com M judeus

Node* delNode(CLinkedList*, Node*, Node*); //mata o judeu e entrega a faca para o próximo

void pointLastToFirst(CLinkedList* ll); //Atualiza o primeiro e ultimo ponteiro da lista circular


int main() {
    int i, counter=0, M, P, N;
    scanf("%d %d %d", &M, &P, &N);
    CLinkedList* judeus = chargeList(M); //criar a lista circular com M judeus
    Node* curr = judeus->firstNode; 
    Node* prev = judeus->lastNode; 
    for (i=0; i<P-1; i++){ //colocar a faca na mao de Josefo
        prev=curr;
        curr=curr=curr->next;
    }
    while (judeus->listSize!=1){
    	//Aqui nesse laço deve ocorrer a mágica :-P
    	//Basicaente deve programar:
	//	1 - encontrar o judeu que vai morrer -> posicionar o node
        //	2 - matar o judeu -> libebrar o node
    }
    if (judeus->firstNode->info==P){
        printf("VIVO\n");
    } else {
        printf("Morto %d\n", judeus->firstNode->info);
    }
    return 0;
}


Node* delNode(CLinkedList* cl, Node* curr, Node* prev) {
    if (curr==cl->firstNode){
        cl->lastNode->next=curr->next;
        cl->firstNode=curr->next;
    }
    if (curr==cl->lastNode){
        cl->lastNode=prev;
        prev->next=cl->firstNode;
    }
    if (curr!=cl->firstNode && curr!=cl->firstNode){
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

void dropNode(Node* n){
    free(n);
}

CLinkedList* CLcreateEmpty () {
    CLinkedList* ll = (CLinkedList*) malloc(sizeof(CLinkedList));
    ll->firstNode=NULL;
    ll->isEmpty=1;
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

void CLdeleteByIdx (CLinkedList* ll, int idx){
    Node* prev = ll->lastNode;
    Node* curr = ll->firstNode;
    int i=0;
    while(curr->next!=ll->firstNode){
        if (idx==i){
            prev->next=curr->next;
            if(idx==0){
                ll->firstNode=prev->next;
            }
            if (idx==ll->listSize){
                ll->lastNode==prev;
            }
            free(curr);
            ll->listSize--;
            break;
        } else {
            prev=curr;
            curr=curr->next;
            i++;
        }

    }
    pointLastToFirst(ll);
}



