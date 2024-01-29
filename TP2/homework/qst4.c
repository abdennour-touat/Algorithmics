#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "qst2.h"
#include "qst1.h"
#include "qst3.h"
#include <time.h>

double mesure_temps_execution(noeud *list)
{

    clock_t t1, t2;
    double delta = 0;
    // int res = chercheMax(list);
    // printf("max = %d\n", res);
    for (size_t i = 0; i < 5000; i++)
    {
        t1 = clock();
        chercheMax(list);
        t2 = clock();
        delta = delta + (double)(t2 - t1);
    }
    return delta / 5000;
}

int main()
{
    noeud **test_list = liste_de_listes();
    FILE *ptr;
    ptr = fopen("results.csv", "w+");
    fprintf(ptr, "taille, temps\n");
    for (size_t i = 1; i <= 100; i++)
    {
        // printf("list #%ld:\n", i);
        // double temps = mesure_temps_execution(test_list[i]);
        // printf("%F\n", temps);
        //	if(i*10 % 100 == 0 || i*10 %50 == 0){
        fprintf(ptr, "%ld ,%f\n", i * 10, mesure_temps_execution(test_list[i]));
        //	}
    }
    // double test = mesure_temps_execution(1222222, 10000);
    // printf("%f", test);
}
