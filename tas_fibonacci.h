#ifndef _TAS_FIBONACCI_H_
#define _TAS_FIBONACCI_H_

#define NIL -1

typedef struct ELEMENT_TAS_FIBONACCI
{
	int degree;
	float cle;
	struct ELEMENT_TAS_FIBONACCI * pere;
	struct ELEMENT_TAS_FIBONACCI * fils;
	struct ELEMENT_TAS_FIBONACCI * droite;
	struct ELEMENT_TAS_FIBONACCI * gauche;
	
	
	 int from;
	 int to;
	 
	 
}ELEMENT_TAS_FIBONACCI;

typedef struct TAS_FIBONACCI
{
	int nombre_noeuds;
	ELEMENT_TAS_FIBONACCI * min;
	ELEMENT_TAS_FIBONACCI * racine;
	
}TAS_FIBONACCI;
 
/* LES OPERATIONS ELEMENTAIRES POUR MANIPULER UN TAS DE FIBONACCI */
TAS_FIBONACCI* creer_tas_fibonacci();
ELEMENT_TAS_FIBONACCI* get_min_tas_fib(TAS_FIBONACCI* tas_fib);
void ajouter_racine_tas_fib(TAS_FIBONACCI* tas_fib, ELEMENT_TAS_FIBONACCI* noeud, int count);
void supprimer_racine_tas_fib(TAS_FIBONACCI* tas_fib, ELEMENT_TAS_FIBONACCI* noeud, int count);
void inserer_tas_fib(TAS_FIBONACCI* tas_fib, ELEMENT_TAS_FIBONACCI* element);
ELEMENT_TAS_FIBONACCI* extraire_min_tas_fib(TAS_FIBONACCI* tas_fib, ELEMENT_TAS_FIBONACCI* element);
int tas_fib_est_vide(TAS_FIBONACCI* tas_fib);
ELEMENT_TAS_FIBONACCI* nouvel_element_tas_fib(float cle, int from, int to);
void desallouer_tas_fib(TAS_FIBONACCI* tas_fib);

#endif

