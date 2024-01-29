#include<stdio.h>
#include<stdlib.h>

typedef struct noeud{
	int val;
	struct noeud *suiv;
}noeud;

noeud *inserer_debut(noeud *T, int val){
	noeud *new = (noeud*)malloc(sizeof(noeud));
	new->val = val;
	new->suiv = T;
	T = new;	
	return T;
}
noeud *inserer_fin(noeud *pred, int val){
	noeud *new = (noeud*)malloc(sizeof(noeud));
	new->val = val;
	pred->suiv = new;
	return new;
}
