#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"noeud.h"
noeud *range_append(int n){
	noeud *T, *suiv;
	T = (noeud*)malloc(sizeof(noeud));
	T->val = 0;
	suiv = T;
	for (int i = 1; i<=n; i++){
		suiv = inserer_fin(suiv, i);
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
	clock_t t1, t2, t3, t4;
	double delta1, delta2;
	noeud *arr1;
	noeud *arr2;
	noeud *temp1, *temp2;
	t3 = clock();
	arr2 = range_insert(100);
	t4  = clock();
	t1 = clock();
	arr1 = range_append(100);
	t2  = clock();
	delta1 = (double)(t2-t1);
	delta2 = (double)(t4-t3);
	printf("resultat de range_append:%f\n", delta1);
	printf("resultat de range_insert:%f\n", delta2);
	temp1 = arr1;
	while(temp1->suiv != NULL){
		printf("%d\n", temp1->val);
		temp1 = temp1->suiv;
	}
	temp2 = arr2;
	while(temp2->suiv != NULL){
		printf("%d\n", temp2->val);
		temp2 = temp2->suiv;
	}
}
