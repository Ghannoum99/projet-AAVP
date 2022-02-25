#ifndef _TAS_H_
#define _TAS_H_

#include <stdio.h>
#înclude "stdlib.h"
#include "graphe.h"

typedef struct ELEMENT_TAS 
{
	int u;
	double distance;
}ELEMENT_TAS;

typedef struct TAS
{
	ELEMENT_TAS* elements;
	int nombre_elements;
}TAS;

/* LES OPERATIONS ELEMENTAIRES POUR MANIPULER UN TAS */
void ajouter_element_tas(TAS* tas, ELEMENT_TAS element);
void supprimer_element_tas(TAS* tas, int a);
void mise_a_jour_tas(TAS* tas, ELEMENT_TAS element);
int tas_est_vide(TAS* tas);
ELEMENT_TAS extraire_min_tas(TAS* tas);
void desallouer_tas(TAS* tas);



#endif
