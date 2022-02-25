#ifndef _ETAT_H
#define _ETAT_H
#include "graphe.h"

// Cette structure a pour but d'identifier l'etat de chaque noeud

typedef enum ENUM_ETAT
{
	NON_VISITE,
	EN_COURS,
	DEJA_VISITE
	
}ENUM_ETAT;

typedef struct ETAT
{
	ENUM_ETAT* etat;
	int nombre_elements;
	
}


ETAT* initialiser_etat(GRAPHE* graphe);
void marquer_noeud(ETAT* etat, int noeud, ENUM_ETAT enum_etat);
int get_etat(ETAT* etat, int noeud, ENUM_ETAT enum_etat);
void desallouer_etat(ETAT* etat);

#endif
