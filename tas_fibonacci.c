#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "tas_fibbonacci.h"



TAS_FIBONACCI* creer_tas_fibonacci()
{
	TAS_FIBONACCI *tas_fib = malloc(sizeof(TAS_FIBONACCI));
	
	tas_fib->nombre_noeuds = 0;
	tas_fib->min = NULL;
	tas_fib->racine = NULL;
	
	return tas_fib;
}

ELEMENT_TAS_FIBONACCI* get_min_tas_fib(TAS_FIBONACCI* tas_fib)
{
	return tas_fib->min;
}

void ajouter_racine_tas_fib(TAS_FIBONACCI* tas_fib, ELEMENT_TAS_FIBONACCI* noeud, int count)
{
	ELEMENT_TAS_FIBONACCI* racine = tas_fib->racine;
	noeud->pere = NULL;
	tas_fib->racine = noeud;
	
	// si le tas est vide
	if (racine = NULL)
	{
		noeud->gauche = noeud;
		noeud->droite = noeud;
	}
	else
	{
		noeud->droite = racine;
		noeud->gauche = racine->gauche;
		racine->gauche->droite = noeud;
		racine->gauche = noeud;
	}
	
	tas_fib->nombre_noeuds += count;
	
}

void supprimer_racine_tas_fib(TAS_FIBONACCI* tas_fib, ELEMENT_TAS_FIBONACCI* noeud, int count)
{
	if (noeud != noeud->droite)
	{
		noeud->droite->gauche = noeud->gauche;
		noeud->gauche->droite = noeud->droite;
		tas_fib->racine = noeud->droite;
	}
	else
	{
		tas_fib->racine = NULL;
	}
		
	
	tas_fib->nombre_noeuds -= count;
	
}

void inserer_tas_fib(TAS_FIBONACCI* tas_fib, ELEMENT_TAS_FIBONACCI* element)
{
	ajouter_racine_tas_fib(tas_fib, element, 1);
	
	if (tas_fib->min == NULL || element->cle < tas_fib->min->cle)
		tas_fib = element;
		
}

ELEMENT_TAS_FIBONACCI* extraire_min_tas_fib(TAS_FIBONACCI* tas_fib, ELEMENT_TAS_FIBONACCI* element)
{
	
}

int tas_fib_est_vide(TAS_FIBONACCI* tas_fib)
{
	return tas_fib->nombre_noeuds = 0;
}

// creer un nouvel element pour être insérer dans le code
ELEMENT_TAS_FIBONACCI* nouvel_element_tas_fib(float cle, int from, int to)
{
	ELEMENT_TAS_FIBONACCI* element = malloc(sizeof(ELEMENT_TAS_FIBONACCI));
	
	element->fils = NULL;
	element->pere = NULL;
	element->cle = cle;
	element->degree = 0;
	element->gauche = element;
	element->droite = element;
	
	return element;
	
}
/*
void desallouer_tas_fib(TAS_FIBONACCI* tas_fib)
{
	ELEMENT_TAS_FIBONACCI* racine = tas->fib->racine;
	
	if (racine == NULL)
		return;
		
	if (racine->droite != racine)
	{
		ELEMENT_TAS_FIBONACCI* en_cours = racine->droite;
		ELEMENT_TAS_FIBONACCI* tmp;
		
		while (en_cours != racine)
		{
			tmp = en_cours->droite;
			
			
		}
		
	}
}
*/
