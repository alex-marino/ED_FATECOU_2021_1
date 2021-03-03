//
// Created by alexm on 09/09/2020.
//
#include <stdlib.h>
#include "Ponto.h"
#include "Circulo.h"
#define PI 3.14159

struct circulo {
    Ponto* p;
    float r;
};

Circulo* circ_cria (float x, float y, float r){
    Circulo* c = (Circulo*)malloc(sizeof(Circulo));
    c->p = pto_cria(x,y);
    c->r = r;
}

void circ_libera (Circulo* c){
    pto_libera(c->p); free(c);
}

float circ_area (Circulo* c){
    return PI*c->r*c->r;
}

int circ_interior (Circulo* c, Ponto* p){
    float d = pto_distancia(c->p,p); return (d<c->r);
}
