#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "etat.h"
#include "graphe.h"


GRAPHE creer_graphe(int nombre_noeuds)
{
	GRAPHE* graphe = (GRAPHE*) malloc(sizeof(GRAPHE));
	
	graphe->nombre_noeuds = nombre_noeuds;
	
	// tableau d'une liste d'adjacence
	graphe->liste_adjacence = (LISTE_ADJACENCE*) malloc(nombre_noeuds*sizeof(LISTE_ADJACENCE));
	
	for (int i = 0; i < nombre_noeuds; i++)
	{
		graphe->liste_adjacence[i].racine = NULL;
		graphe->liste_adjacence[i].nombre_elements = 0;
	}
	
	return graphe;
}

void ajouter_arc(GRAPHE* graphe, int sommet_src, int sommet_dest, double poids)
{
	LISTE_ADJACENCE_NOEUD* nouveau_noeud = (LISTE_ADJACENCE_NOEUD*) malloc(sizeof(LISTE_ADJACENCE_NOEUD));
	nouveau_noeud->noeud = sommet_dest;
	nouveau_noeud->poids = poids;
	nouveau_noeud->suivant = graphe->LISTE_ADJACENCE[sommet_src].racine;
	
	graphe->liste_adjacence[sommet_src].racine = nouveau_noeud;
	graphe_>liste_adjacence[sommet_src].nombre_elements++;
	
}

int* get_noeuds(GRAPHE* graphe)
{
	int* noeuds = malloc(sizeof(int)*graphe->nombre_noeuds);
	
	for (int i = 0; i < graphe->nombre_noeuds; i++)
		noeuds[i] = i;
		
	return noeuds;
}

