//
// Created by alexmarino on 08/03/2020.
//
#include <stdio.h>
#include "MyRecFunctions.h"


long long fatorial (int n){
    int i;
    long res=1;
    for (i=1; i<=n; i++){
        res*=i;
    }
    return res;
}

long long fatorialRec(int n) {
    if (n==0){ //teste do caso base
        return 1L;
    } else {
        return n*fatorialRec(n-1); // passo de recursao ou passo indutivo
    }
}




void drawRuller(int nInches, int majorLength) {
    drawLine(majorLength, 0);
    int j;
    for (j=1; j<=nInches; j++){
        drawInterval(majorLength-1);
        drawLine(majorLength, j);
    }
}

void drawInterval(int centralLength) {
    if (centralLength >= 1){
        drawInterval(centralLength-1);
        drawLineOnly(centralLength);
        drawInterval(centralLength-1);
    }
}

void drawLine(int tickLength, int tickLabel) {
    int j;
    for (j=0; j<tickLength; j++){
        printf("-");
    }
    if (tickLabel >= 0){
        printf(" %d", tickLabel);
    }
    printf("\n");

}

void drawLineOnly(int tickLength) {
    drawLine(tickLength, -1);
}

int binarySearch(int *data, int target, int low, int high) {
    if (low>high){
        return 0;
    } else {
        int mid = (low+high)/2;
        if (target==data[mid]) {
            return 1;
        } else if(target < data[mid]){
            return binarySearch(data, target, low, mid-1);
        } else{
            return binarySearch(data, target, mid+1, high);
        }
    }
}



