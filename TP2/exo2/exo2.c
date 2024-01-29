#include<stdio.h>
#include<stdlib.h>
#include<time.h>

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


noeud *range_append(int n){
	noeud *T, *suiv;
	T = (noeud*)malloc(sizeof(noeud));
	T->val = 0;
	suiv = T;
	for (int i = 1; i<=n; i++){
		suiv = inserer_fin(suiv, n-i-1);
	}	
	return T;
}


noeud *range_insert(int n){
	noeud *T;
	T = (noeud*)malloc(sizeof(noeud));
	T->val = n -1;
	for (int i = n-1; i>=0; i--){
		T =inserer_debut(T, i);
	}	
	return T;
}
int main(){
	FILE *f,*f2;
	f = fopen("resultat_range_insert.csv", "w+");
	f2 = fopen("resultat_range_append.csv", "w+");
	fprintf(f, "valeur, temps\n");
	fprintf(f2, "valeur, temps\n");
	clock_t t1, t2;
	double delta = 0;
	noeud **lists = NULL;
	lists = (noeud**)malloc(sizeof(noeud*));	
	for(int i = 1; i<= 10000; i++){
		t1 = clock();
		lists[i] = range_insert(i);
		t2 = clock();
		delta = (double)(t2 - t1);
		fprintf(f, "%i, %f\n",i, delta);
	}

	noeud **lists2 = NULL;
	lists2 = (noeud**)malloc(sizeof(noeud*));	
	for(int i = 1; i<= 10000; i++){
		t1 = clock();
		lists2[i] = range_append(i);
		t2 = clock();
		delta = (double)(t2 - t1);
		fprintf(f2, "%i, %f\n",i, delta);
	}
	
}

