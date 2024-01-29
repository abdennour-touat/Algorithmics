#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"algos.h"
#include<time.h>

int main (){

	clock_t t1, t2;
	double delta;

   //10 nombres avec des tailles differentes
	long long nombres_premiers[] = {  
	100123456789,
	9000000001,
	2459868287,
	1057438801,
	1000000009,
	22616281,
	1618033,
}; 

for (int i = 0; i< sizeof(nombres_premiers)/sizeof(long long) ; i++){
	printf("temps d'execution pour le numero %lld\n", nombres_premiers[i]);
	printf("Algorithme 1\n");
	t1 =clock();
	A1(nombres_premiers[i]);
	t2 = clock();
	 delta = (double)(t2-t1)/CLOCKS_PER_SEC;
	printf("%F\n",delta);	
	
	printf("Algorithme 2\n");
	t1 =clock();
	A2(nombres_premiers[i]);
	t2 = clock();
	delta = (double)(t2-t1)/CLOCKS_PER_SEC;
	printf("%F\n",delta);	

	printf("Algorithme 3\n");
	t1 =clock();
	A3(nombres_premiers[i]);
	t2 = clock();
	delta = (double)(t2-t1)/CLOCKS_PER_SEC;
	printf("%F\n",delta);	

	printf("Algorithme 4\n");
	t1 =clock();
	A4(nombres_premiers[i]);
	t2 = clock();
	delta = (double)(t2-t1)/CLOCKS_PER_SEC;
	printf("%F\n",delta);	

	printf("Algorithme 5\n");
	t1 =clock();
	A5(nombres_premiers[i]);
	t2 = clock();
	delta = (double)(t2-t1)/CLOCKS_PER_SEC;
	printf("%F\n",delta);	

	printf("Algorithme 6\n");
	t1 =clock();
	A6(nombres_premiers[i]);
	t2 = clock();
	delta = (double)(t2-t1)/CLOCKS_PER_SEC;
	printf("%F\n",delta);	
	}

    return 0;

}