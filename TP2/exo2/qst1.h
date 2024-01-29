#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include"noeud.h"
#ifndef qst1
#define qst1 

noeud *range_append(int n){
	noeud *T, *suiv;
	T = (noeud*)malloc(sizeof(noeud));
	T->val = 0;
	suiv = T;
	for (int i = 1; i<n; i++){
		suiv = inserer_fin(suiv, n-i-1);
	}	
	return T;
}


noeud *range_insert(int n){
	noeud *T;
	T = (noeud*)malloc(sizeof(noeud));
	T->val = n -1;
	for (int i = n-2; i>0; i--){
		T =inserer_debut(T, i);
	}	
	return T;
}
#endif
