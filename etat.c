#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "etat.h"


ETAT* initialiser_etat(GRAPHE* graphe)
{
	ETAT* etat = (ETAT *) malloc(sizeof(ETAT));
	
	if (ETAT == NULL)
	{
		fprintf(stderr, "Unable to allocate memory...\n");
		return;
	}
	
	etat->nombre_elements = graphe->nombre_noeuds
	etat->etat = malloc(sizeof(ENUM_ETAT) * etat->nombre_elements);
	
	if(etat->etat == NULL)
	{
		fprintf(stderr, "Unable to allocate memory...\n");
		return;
	}
	
	for (size_t i = 0; i < etat->nombre_elements; i++)
		etat->etat[i] = NON_VISITE;
		
	return etat;
	
}

void marquer_noeud(ETAT* etat, int noeud, ENUM_ETAT enum_etat)
{
	etat->etat[noeud] = enum_etat;
}

int get_etat(ETAT* etat, int noeud, ENUM_ETAT enum_etat)
{
	return (etat->etat[v] == enum_etat);
}

void desallouer_etat(ETAT* etat)
{
	free(etat->etat);
	free(etat);
}
