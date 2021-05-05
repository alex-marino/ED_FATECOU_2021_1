//
// Created by alexm on 25/06/2020.
//

#include "Sort.h"


/* Função de ordenação de um array usando o método de inserção*/
void insertionSort(int* arr, int n){
    int i, chave, j;
    for (i = 1; i < n; i++) {
        chave = arr[i];
        j = i - 1;
        /* Mover os elementos od arr[0..i-1], que são
        maiores que a chave, para uma posição a frente 
        a frente de sua atual posição */
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = chave;
    }
}



void selectionSort(int* arr, int n)
{
    int i, j, min;

    // Mover um a um do segmento não ordenado
    for (i = 0; i < n-1; i++)
    {

        // Buscar o menor elemento no segmento não ordenado
        min = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min])
                min = j;

        // trocar a posição do menor com o primeiro elemento
        troca(&arr[min], &arr[i]);
    }
}


/* Esta função implementa o quick sort
 arr[] --> Array a ser ordenado,
  low  --> indice inicial,
  high  --> índice final */
void quickSort(int* arr, int low, int high)
{
    if (low < high)
    {
        /* pi é o índice da partição, arr[p] está á direita */
        int pi = partition(arr, low, high);

        // Separadamente:
        // ordena os elementos da partição anterior
        // ordena os elementos da partição posterior
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* Esta função toma o último elemento como pivô, posiciona
 * o elemento pivô na posição correta no array ordenado,
 * e posiciona todos elementos menores que o pivô à esquerda
 * do pivô e todos elementos maiores que o povô à sua diretia
 */
int partition (int* arr, int low, int high)
{
    int pivot = arr[high];    // pivô
    int i = (low - 1);  // ìndice do menor elemento

    for (int j = low; j <= high- 1; j++)
    {
        // Se o elemento corrente é menor que o pivô
        if (arr[j] < pivot)
        {
            i++;    // incrementa o índice do menor elemento
            troca(&arr[i], &arr[j]);
        }
    }
    troca(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void qs(char *item, int esq, int dir) {
    int e, d; char elem, y;
    e = esq; d = dir;
    elem = item[(esq+dir)/2];
    do {
        while(item[e]<elem)
            e++;
        while(elem<item[d])
            d--;
        if(e<=d) {
            y = item[e];
            item[e] = item[d];
            item[d] = y;
            e++; d--;
        }
    } while(e<d);
    if(esq<d) qs(item, esq, d);
    if(e<dir) qs(item, e, dir);
}

void shellSort(int *vet, int size) {
    int i , j , value;
    int h = 1;
    while(h < size) {
        h = 3*h+1;
    }
    while (h > 0) {
        for(i = h; i < size; i++) {
            value = vet[i];
            j = i;
            while (j > h-1 && value <= vet[j - h]) {
                vet[j] = vet [j - h];
                j = j - h;
            }
            vet [j] = value;
        }
        h = h/3;
    }
}

void radixsort(int vetor[], int tamanho) {
    int i;
    int *b;
    int maior = vetor[0];
    int exp = 1;

    b = (int *)calloc(tamanho, sizeof(int));

    for (i = 0; i < tamanho; i++) {
        if (vetor[i] > maior)
            maior = vetor[i];
    }

    while (maior/exp > 0) {
        int bucket[10] = { 0 };
        for (i = 0; i < tamanho; i++)
            bucket[(vetor[i] / exp) % 10]++;
        for (i = 1; i < 10; i++)
            bucket[i] += bucket[i - 1];
        for (i = tamanho - 1; i >= 0; i--)
            b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
        for (i = 0; i < tamanho; i++)
            vetor[i] = b[i];
        exp *= 10;
    }

    free(b);
}

void troca (int* a, int* b){
    int aux=0;
    aux = *a;
    *a = *b;
    *b = aux;
}

void printArray(int* arr, int n){
    int i;
    printf("%d", arr[0]);
    for(i=1; i<n; i++){
        printf(" - %d", arr[i]);
    }
    printf("\n");
}
