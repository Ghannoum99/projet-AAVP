#ifndef _GRAPHE_H8
#define _GRAPHE_H_

#include <stdbool.h>
#include "etat.h"

// represente les aretes entre les noeuds
typedef struct LISTE_ADJACENCE_NOEUD 
{
	int noeud;
	struct LISTE_ADJACENCE_NOEUD* suivant;
	double poids;
	
}LISTE_ADJACENCE_NOEUD;

//represente un noeud
typedef struct LISTE_ADJACENCE
{
	int nombre_elements;
	LISTE_ADJACENCE_NOEUD* racine;
	
}LISTE_ADJACENCE;

typedef struct GRAPHE
{
	int nombre_noeuds;
	LISTE_ADJACENCE* liste_adjacence;
	
}GRAPHE;


typedef struct ETAT;

/* LES OPERATIONS ELEMENTAIRES POUR MANIPULER UN GRAPHE */
GRAPHE creer_graphe(int nombre_noeuds);
void ajouter_arc(GRAPHE* graphe, int sommet_src, int sommet_dest, double poids);
int* get_noeuds(GRAPHE* graphe);
void desallouer_graphe(GRAPHE* graphe);


#endif
