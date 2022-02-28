#ifndef _DIJKSTRA_H_
#define _DIJKSTRA_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "graphe.h"
#include "tas.h"
#include "tas_fibonacci.h"
#include "etat.h"


void dijkstra_tas(GRAPHE* graphe, int sommet_src, int* predecesseur, double* poids);
void dijkstra_tas_fib(GRAPHE* graphe, int sommet_src, int* predec, double* poids);

#endif
