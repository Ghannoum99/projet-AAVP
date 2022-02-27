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
		marquer_noeud(etat,u, DEJA_VISITE);
		
		//verifier tous les arcs sortant de u
		n = graphe->LISTE_ADJACENCE[u].nombre_elements;
		arete = graphe->LISTE_ADJACENCE[u].racine;
		
		for (int i = 0; i < n; i++)
		{
			v = arete->noeud;
			if (!get_etat(etat, v, DEJA_VISITE))
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
	desallouer_tas(tas);
	
}


void dijkstra_tas_fib(GRAPHE* graphe, int sommet_src, int* predec, doouble* poids)
{
	LISTE_ADJACENCE_NOEUD* arete;
	ELEMENT_TAS_FIBONACCI* tmp;
	TAS_FIBONACCI* tas_fib = creer_tas_fibonacci();
	double dist;
	int u, v, n, x;
	ETAT* etat = initialiser_etat(graphe);
	
	
	for (int i = 0; i < graphe->nombre_elements; i++)
	{
		if (i != sommet_src)
			poids[i] = -1;
		else
			poids[i] = 0;
			
		predec[i] = INT_MAX;
	}
	
	marquer_noeud(etat,u, DEJA_VISITE);
	
	//ajouter les noeuds dest de tous les arcs sortant de sommet_src au tas de fib
	arete = graphe->LISTE_ADJACENCE[sommet_src].racine;
	n = graphe->LISTE_ADJACENCE[sommet_src].nombre_elements;
	
	for (int i = 0; i < n; i++)
	{
		dist = poids[sommet_src] + rete->poids;
		v = arete->noeud;
		inserer_tas_fib(tas_fib, nouvel_element_tas_fib(dist, sommet_src, v));
		
		arete = arete->suivant;
	}
	
	while (! tas_fib_est_vide(tas_fib))
	{
		tmp = extraire_min_tas_fib(tas_fib);
		
		u = tmp->from;
		v = tmp->to;
		dist = tmp->cle;
		
		if (!get_etat(etat, v, DEJA_VISITE)
		{
			poids[v] = dist;
			predec[v] = u;
			marquer_noeud(etat, v, DEJA_VISITE);
			
			arete = graphe->LISTE_ADJACENCE[v].racine;
			n = graphe->LISTE_ADJACENCE[v].nombre_elements;
			
			for (int i = 0; i < n; i++)
			{
				x = arete->noeud;
				dist = poids[v] + arete->poids;
				inserer_tas_fib(tas_fib, nouvel_element_tas_fib(dist, v, x);
				
				arete = arete->suivant;
			}
			
		}
	}
	
	desallouer_etat(etat);
	desallouer_tas_fib(tas_fib);
	
}
