#include<stdio.h>
#include<stdlib.h>
#include"qst1.h"
#include<time.h>
#include"noeud.h"

int main(){
	FILE *f;
	f = fopen("resultat_inserer_debut.csv", "w+");
	fprintf(f, "valeur, temps");
	clock_t t1, t2;
	double delta = 0;
	noeud *test ;
	noeud **lists = NULL;
	**lists = (noeud**)malloc(sizeof(noeud*));	
	for(int i = 1; i<= 1000; i++){
		t1 = clock();
		list[i] = range_insert(i);
		t2 = clock();
		delta = (double)(t2 - t1)/CLOCKS_PER_SEC;
		fprintf(f, "%i, %f",i, delta);
	}

	
}

