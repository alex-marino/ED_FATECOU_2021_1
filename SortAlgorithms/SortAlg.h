//
// Created by alexmarino on 26/03/2020.
//

#ifndef SORTALGORITHMS_SORTALG_H
#define SORTALGORITHMS_SORTALG_H

#define runtime_diff_ms(c1,c0) = (((c1 - c0)*1000)/CLOCKS_PER_SEC)

void shell_sort(int v[], int n) ;

void select_sort(int vet[], int n);

void counting_sort(int v[], int tamanho);

void radix_sort(int v[], int tamanho);

void quick_sort(int v[], int p, int r) ;

void intercalar(int v[], int x) ;

void insert_sort (int vet[], int n);

void heap(int v[], int n, int i);

void heap_sort(int v[], int n);

void bubble_sort (int v[], int n) ;

void bucket_sort(int v[], int tamanho);

#endif //SORTALGORITHMS_SORTALG_H
