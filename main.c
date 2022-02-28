#include <stdio.h>
#include "graphe.h"
#include "dijkstra.h"


GRAPHE* creer_graphe_a_partir_fichier(FILE* f)
{
	int noeuds;
	double poids;
	int i = 0;
	char* t;
	int arete[2];
	char ligns[1024];
	
}


int main()
{
	GRAPHE* graphe = 
	double* poids = (double*) malloc(sizeof(double)*graphe->nombre_noeuds);
	int sommet_src = 0;
	int* predec = (int*) malloc(sizeof(int)*graphe->nombre_noeuds);
	
	//tas
	dijkstra_tas(graphe, sommet_src, predec, poids);
	
	//tas_fib
	dijkstra_tas_fib(graphe, sommet_src, predec, poids);
	
  
	desallouer_graphe(graphe);
	free(poids);
	free(predec);
	
	return 0;
}
