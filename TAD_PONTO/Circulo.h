//
// Created by alexm on 09/09/2020.
//

#ifndef TAD_PONTO_CIRCULO_H
#define TAD_PONTO_CIRCULO_H

/* TAD: Círculo */
/* Dependência de modulos */
#include "Ponto.h"
/* Tipo exportado */
typedef struct circulo Circulo;
/* Funções exportadas */
/* Função cria - Aloca e retorna um círculo com centro (x,y) e raio r */
Circulo* circ_cria (float x, float y, float r);

/* Funçãao libera - Libera a memória de um círculo previamente criado */
void circ_libera (Circulo* c);

/* Função area - Retorna o valor da área do círculo */
float circ_area (Circulo* c);

/* Função interior - Verifica se um dado ponto p está dentro do círculo */
int circ_interior (Circulo* c, Ponto* p);

#endif //TAD_PONTO_CIRCULO_H
