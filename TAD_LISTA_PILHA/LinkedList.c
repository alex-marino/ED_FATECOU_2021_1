//
// Created by alex on 26/03/2021.
//
#include <stdio.h>
#include "Node.h"
#include "LinkedList.h"


LinkedList* LLcreateEmpty () {
    LinkedList* ll = (LinkedList*) malloc(sizeof(LinkedList));
    ll->firstNode=NULL;
    ll->isEmpty=1;
    ll->listSize=0;
    ll->lastNode=NULL;
    return ll;
}

void LLaddBegin (LinkedList* ll, int val) {
    Node* firstNode = ll->firstNode;
    Node* newNode = createNode(val);
    if (ll->listSize==0){
        ll->firstNode=newNode;
        ll->lastNode=newNode;
        ll->listSize++;
    } else {
        newNode->next=ll->firstNode;
        ll->firstNode=newNode;
        ll->listSize++;
    }
}

void LLaddEnd (LinkedList* ll, int val) {
    Node* lastNode = ll->lastNode;
    Node* newNode = createNode(val);
    if (ll->listSize==0){
        ll->firstNode=newNode;
        ll->lastNode=newNode;
        ll->listSize++;
    } else {
        lastNode->next=newNode;
        ll->lastNode=newNode;
        ll->listSize++;
    }
}

void LLdeleteByIdx (LinkedList* ll, int idx){
    Node* prev;
    Node* curr = ll->firstNode;
    if (idx==0){
        ll->firstNode=curr->next;
        dropNode(curr);
        ll->listSize--;
    } else{
        int i;
        prev=curr;
        curr=curr->next;
        for(i=1; i<ll->listSize; curr=curr->next){
            if (idx==i){
                if (curr==ll->lastNode){
                    prev->next=NULL;
                    ll->lastNode=prev;
                    dropNode(curr);
                    ll->listSize--;
                    break;
                } else{
                    prev->next=curr->next;
                    dropNode(curr);
                    ll->listSize--;
                    break;
                }
            }
            i++;
        }
    }
}

void LLdeleteByVal (LinkedList* ll, int val) {
    Node* prev;
    Node* curr = ll->firstNode;
    if (curr->info==val){
        ll->firstNode=curr->next;
        dropNode(curr);
        ll->listSize--;
    } else{
        int i;
        prev=curr;
        curr=curr->next;
        for(i=1; i<ll->listSize; curr=curr->next){
            if (curr->info==val){
                if (ll->lastNode==curr){
                    prev->next=NULL;
                    ll->lastNode=prev;
                    dropNode(curr);
                    ll->listSize--;
                    break;
                } else{
                    prev->next=curr->next;
                    dropNode(curr);
                    ll->listSize--;
                    break;
                }
            }
            prev=curr;
        }
    }

}

void LLdrop (LinkedList* ll) {
    Node* curr = ll->firstNode;
    Node* aux;
    while (curr->next!=NULL){
        aux=curr;
        curr=curr->next;
        free(aux);
    }
    free(ll);
}

void LLprintAll (LinkedList* ll) {
    printf("%d ", ll->firstNode->info);
    Node* curr = ll->firstNode->next;
    while (curr!=ll->lastNode){
        printf("- %d ", curr->info);
        curr=curr->next;
    }
    printf("- %d #SIZE=%d\n", curr->info, ll->listSize);
}

