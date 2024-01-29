#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "tri_fct.h"
// #include "best_tri_ta3_abdennour.h"
#include "fct_cmpt.h"
#define max 256

void generer_list(char *file_name, int unsigned *list, long taille)
{
    FILE *ptr;
    char ch[max];
    char c;
    ptr = fopen(file_name, "r");

    if (NULL == ptr)
    {
        printf("file can't be opened \n");
    }

    fscanf(ptr, "%[^\n]", ch);
    int cpt = 0;
    while (c != EOF && cpt < taille)
    {
        fscanf(ptr, "%[^\n]", ch);
        list[cpt] = atoi(ch);
        cpt++;
        c = fgetc(ptr);
    };
    fclose(ptr);
}
int main()
{
    printf("the start of the execution");
    FILE *f;
    f = fopen("result.txt", "w");
    unsigned long long size = 50000;
    int *arr;
    long long cmp;

    printf("the bubble sort\n");
    arr = (int *)malloc(size * sizeof(int));
    generer_list("5x10^4asc.txt", arr, size);
    printf("\n\n");
    printf("\ntri bulle: \n");
    cmp = Tri_bulle_modifie(arr, size);
    printf("5x10^4\n");
    printf("asc: %lld\n", cmp);
    int *arr1 = (int *)malloc(size * sizeof(int));
    generer_list("5x10^4desc.txt", arr1, size);
    printf("\n\n\n");
    long long int cmp1 = 0;
    cmp1 = Tri_bulle_modifie(arr1, size);
    printf("desc: %lld\n", cmp1);
    int *arr2 = (int *)malloc(size * sizeof(int));
    generer_list("5x10^4rand.txt", arr2, size);
    long long int cmp2 = 0;
    cmp2 = Tri_bulle_modifie(arr2, size);
    printf("rand: %lld\n", cmp2);
    free(arr);
    free(arr1);
    free(arr2);

    size = 10000;
    printf("the selection sort\n");
    int *arr3 = (int *)malloc(size * sizeof(int));
    generer_list("10^4asc.txt", arr3, size);
    long long int cmp3 = 0;
    cmp3 = Tri_bulle_modifie(arr3, size);
    printf("10^4\n");
    printf("asc: %lld\n", cmp3);
    int *arr4 = (int *)malloc(size * sizeof(int));
    generer_list("10^4desc.txt", arr4, size);
    long long int cmp5 = 0;
    cmp5 = Tri_bulle_modifie(arr4, size);
    printf("desc: %lld\n", cmp5);
    int *arr5 = (int *)malloc(size * sizeof(int));
    generer_list("10^4rand.txt", arr5, size);
    long long int cmp6 = 0;
    cmp6 = Tri_bulle_modifie(arr5, size);
    printf("rand: %lld\n", cmp6);
    free(arr3);
    free(arr4);
    free(arr5);

    // size = 1000000;
    // printf("the selection sort\n");
    // int *arr6 = (int *)malloc(size * sizeof(int));
    // generer_list("10^6asc.txt", arr6, size);
    // unsigned long long int cmp7 = 0;
    // cmp7 = Tri_bulle_modifie(arr6, size);
    // printf("10^6\n");
    // printf("asc: %lld\n", cmp7);
    // int *arr7 = (int *)malloc(size * sizeof(int));
    // generer_list("10^6desc.txt", arr7, size);
    // long long int cmp8 = 0;
    // cmp8 = Tri_bulle_modifie(arr7, size);
    // printf("desc: %lld\n", cmp8);
    // int *arr8 = (int *)malloc(size * sizeof(int));
    // generer_list("10^6rand.txt", arr8, size);
    // unsigned long long int cmp9 = 0;
    // cmp9 = Tri_bulle_modifie(arr8, size);
    // printf("rand: %lld\n", cmp9);
    // free(arr6);
    // // free(arr7);
    // free(arr8);

    fclose(f);
    return 0;
}
