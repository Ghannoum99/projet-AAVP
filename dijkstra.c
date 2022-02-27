#include "dijkstra.h"
#include <limits.h>
#define DEBUG 0

void dijkstra_tas(GRAPHE* graphe, int sommet_src, int* predecesseur,double* poids)
{
	int u, v, n;
	double dist;
	TAS tas;
	ELEMENT_TAS tmp;
	LISTE_ADJACENCE_NOEUD* arete;
	ETAT* etat = initialiser_etat(graphe);
	
	tas.nombre_elements = 0;
	tas.elements = NULL;
	
	
	for (int i = 0; i < graphe->nombre_elements; i++)
	{
		if (i != sommet_src)
			poids[i] = -1;
		else
			poids[i] = 0;
			
		predecesseur[i] = INT_MAX;
		
		//ajouter le à la file de priorité
		tmp.u = i;
		tmp.distance = poids[i];
		ajouter_element_tas(&tas, tmp);
		
	}
	
	while (!tas_est_vide(&tas))
	{
		tmp = extraire_min_tas(&tas);
		u = tmp.u;
		marquer_noeud(etat,u, VISITE);
		
		//verifier tous les arcs sortant de u
		n = graphe->LISTE_ADJACENCE[u].nombre_elements;
		arete = graphe->LISTE_ADJACENCE[u].racine;
		
		for (int i = 0; i < n; i++)
		{
			v = arete->noeud;
			if (!get_etat(etat, v, VISITE))
			{
				dist = poids[u] + arete->poids;
				if (dist < poids[v])
				{
					poids[v] = dist;
					predecesseur[v] = u;
					tmp.u = v;
					tmp.poids = dist;
					mise_a_jour_tas(&tas, tmp);
				}
			}
			
			arete = arete->suivant;
		}
	}
	
	desallouer_etat(etat);
	free(tas.elements);
	
	
}
