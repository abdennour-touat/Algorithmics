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
    unsigned long long size = 100000;
    int *arr;
    long long cmp;

    printf("the merge sort\n");
    arr = (int *)malloc(size * sizeof(int));
    generer_list("10^5asc.txt", arr, size);
    // for (size_t i = 0; i < size; i++)
    // {
    //     printf("%d, ", arr[i]);
    // }
    printf("\n\n\n");
    printf("\ntri fusion: \n");
    cmp = triFusionmodifie(arr, 0, size - 1);

    printf("10^5\n");
    printf("asc: %lld\n", cmp);
    int *arr1 = (int *)malloc(size * sizeof(int));
    generer_list("10^5desc.txt", arr1, size);
    // for (size_t i = 0; i < size; i++)
    // {
    //     printf("%d, ", arr1[i]);
    // }
    // printf("\n\n\n");
    long long int cmp1 = 0;
    int *arr2 = (int *)malloc(size * sizeof(int));
    cmp1 = triFusionmodifie(arr2, 0, size - 1);
    printf("desc: %lld\n", cmp1);
    int *arr3 = (int *)malloc(size * sizeof(int));
    generer_list("10^5rand.txt", arr3, size);
    // // for (size_t i = 0; i < size; i++)
    // // {
    // //     printf("%d, ", arr2[i]);
    // // }
    // printf("\n\n\n");
    long long int cmp2 = 0;
    cmp2 = triFusionmodifie(arr3, 0, size - 1);
    printf("rand: %lld\n", cmp2);
    free(arr);
    free(arr3);
    free(arr2);

    size = 500000;
    printf("the fusion sort\n");
    int *arrx = (int *)malloc(size * sizeof(int));
    generer_list("5x10^5asc.txt", arrx, size);
    long long int cmp3 = 0;
    cmp3 = triFusionmodifie(arrx, 0, size - 1);
    printf("5*10^5\n");
    printf("asc: %lld\n", cmp3);
    int *arr4 = (int *)malloc(size * sizeof(int));
    generer_list("5x10^5desc.txt", arr4, size);
    long long int cmp5 = 0;
    cmp5 = triFusionmodifie(arr4, 0, size - 1);
    printf("desc: %lld\n", cmp5);
    int *arr5 = (int *)malloc(size * sizeof(int));
    generer_list("5x10^5rand.txt", arr5, size);
    long long int cmp6 = 0;
    cmp6 = triFusionmodifie(arr5, 0, size - 1);
    printf("rand: %lld\n", cmp6);
    free(arrx);
    free(arr4);
    free(arr5);

    size = 1000000;
    printf("the merge sort\n");
    int *arr6 = (int *)malloc(size * sizeof(int));
    generer_list("10^6asc.txt", arr6, size);
    long long int cmp7 = 0;
    cmp7 = triFusionmodifie(arr6, 0, size - 1);
    printf("10^6\n");
    printf("asc: %lld\n", cmp7);
    int *arr7 = (int *)malloc(size * sizeof(int));
    generer_list("10^6desc.txt", arr7, size);
    long long int cmp8 = 0;
    cmp8 = triFusionmodifie(arr7, 0, size - 1);
    printf("desc: %lld\n", cmp8);
    int *arr8 = (int *)malloc(size * sizeof(int));
    generer_list("10^6rand.txt", arr8, size);
    long long int cmp9 = 0;
    cmp9 = triFusionmodifie(arr8, 0, size - 1);
    printf("rand: %lld\n", cmp9);
    free(arr6);
    // free(arr7);
    free(arr8);

    size = 5000000;
    printf("the merge sort\n");
    int *arr9 = (int *)calloc(size, sizeof(int));
    generer_list("5x10^6asc.txt", arr9, size);
    long long int cmp10 = 0;
    cmp10 = triFusionmodifie(arr9, 0, size - 1);
    printf("5*10^6\n");
    printf("asc: %lld\n", cmp10);
    int *arr10 = (int *)calloc(size, sizeof(int));
    generer_list("5x10^6desc.txt", arr10, size);
    long long int cmp11 = 0;
    cmp11 = triFusionmodifie(arr10, 0, size - 1);
    printf("desc: %lld\n", cmp11);
    int *arr11 = (int *)malloc(size * sizeof(int));
    generer_list("5x10^6rand.txt", arr11, size);
    long long int cmp12 = 0;
    cmp12 = triFusionmodifie(arr11, 0, size - 1);
    printf("rand: %lld\n", cmp12);
    free(arr9);
    // free(arr10);
    free(arr11);

    size = 10000000;
    printf("the merge sort\n");
    int *arr12 = (int *)malloc(size * sizeof(int));
    generer_list("10^7asc.txt", arr12, size);
    long long int cmp13 = 0;
    cmp13 = triFusionmodifie(arr12, 0, size - 1);
    printf("10^7\n");
    printf("asc: %lld\n", cmp13);
    // int *arr13 = (int *)malloc(size * sizeof(int));
    // generer_list("10^7desc.txt", arr13, size);
    // long long int cmp14 = 0;
    // cmp14 = triFusionmodifie(arr13, size);
    // printf("desc: %lld\n", cmp14);
    int *arr14 = (int *)malloc(size * sizeof(int));
    generer_list("10^7rand.txt", arr14, size);
    long long int cmp15 = 0;
    cmp15 = triFusionmodifie(arr14, 0, size - 1);
    printf("rand: %lld\n", cmp15);
    free(arr12);
    // free(arr13);
    free(arr14);

    size = 50000000;
    printf("the merge sort\n");
    int *arr15 = (int *)malloc(size * sizeof(int));
    generer_list("5x10^7asc.txt", arr15, size);
    long long int cmp16 = 0;
    cmp16 = triFusionmodifie(arr15, 0, size - 1);
    printf("5*10^7\n");
    printf("asc: %lld\n", cmp16);
    // int *arr16 = (int *)malloc(size * sizeof(int));
    // generer_list("5x10^7desc.txt", arr16, size);
    // long long int cmp17 = 0;
    // cmp17 = triFusionmodifie(arr16, size);
    // printf("desc: %lld\n", cmp17);
    int *arr17 = (int *)malloc(size * sizeof(int));
    generer_list("5x10^7rand.txt", arr17, size);
    long long int cmp18 = 0;
    cmp18 = triFusionmodifie(arr17, 0, size - 1);
    printf("rand: %lld\n", cmp18);
    free(arr15);
    // free(arr16);
    free(arr17);
    fclose(f);
    return 0;
}