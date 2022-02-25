#include <stdio.h>
#include <stdlib.h>
#include "tas.h"


void ajouter_element_tas(TAS* tas, ELEMENT_TAS element)
{
	tas->nombre_elements++;
	tas->elements = (ELEMENT_TAS*) realloc(tas->elements, sizeof(ELEMENT_TAS)*tas->nombre_elements);
	
	tas->elements[tas->nombre_elements-1] = element;
}

void supprimer_element_tas(TAS* tas, int a)
{
	tas->nombre_elements--;
	
	for (int i = a; i < tas->nombre_elements; i++)
		tas->elements[i] = tas->elements[i+1];
		
	if (tas->nombre_elements != 0)
		tas->elements = (ELEMENT_TAS*) realloc(tas->elements, sizeof(ELEMENT_TAS)*tas->nombre_elements);
	else	
		tas = NULL;

}

void mise_a_jour_tas(TAS* tas, ELEMENT_TAS element)
{
	int noeud = element.noeud
	float dist = element.distance;
	
	for(int i = 0; i < tas->nombre_elements; i++)
	{
		if (tas->elements[i].noeud == noeud)
		{
			tas->elements[i].distance = dist;
			return;
		}
	}
	
	fprintf(stderr, "noeud %d n'est pas dans le tas\n", noeud);
	
}

int tas_est_vide(TAS* tas)
{
	return tas->nombre_elements == 0;
}

ELEMENT_TAS extraire_min_tas(TAS* tas)
{
	
}
void desallouer_tas(TAS* tas)
{
	free(tas->elements);
	free(tas);
}
