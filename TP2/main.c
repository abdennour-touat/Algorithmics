#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "tri_fct.h"
// #include "best_tri_ta3_abdennour.h"
#include "fct_cmpt.h"
#define max 256
// long long cmp = 0;

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
    printf("the start of the execution\n");
    FILE *f;
    f = fopen("result.txt", "w");
    unsigned long long size = 50000;
    int *arr;

    printf("5x10^4:\n");
    arr = (int *)malloc(size * sizeof(int));
    generer_list("5x10^4asc.txt", arr, size);
    // // for (size_t i = 0; i < size; i++)
    // // {
    // //     printf("%d, ", arr[i]);
    // // }
    // printf("\n\n\n");
    // printf("\ntri bulle: \n");
    // cmp = 0;
    long long int res = triFusionmodifie(arr, 0, size - 1);

    // printf("10^5\n");
    printf("asc: %lld\n", res);
    int *arr1 = (int *)malloc(size * sizeof(int));
    size = 100000;
    generer_list("10^5desc.txt", arr1, size);
    // for (size_t i = 0; i < size; i++)
    // {
    //     printf("%d, ", arr1[i]);
    // }
    // printf("\n\n\n");
    cmp = 0;

    cmp = Tri_insertionmodifie(arr1, size);
    printf("desc insertion: %lld\n", cmp);
    int *arr2 = (int *)malloc(size * sizeof(int));
    generer_list("10^5rand.txt", arr2, size);
    // for (size_t i = 0; i < size; i++)
    // {
    //     printf("%d, ", arr2[i]);
    // }
    printf("\n\n\n");
    cmp = 0;
    cmp = triFusionmodifie(arr2, 0, size - 1);
    printf("rand: %lld\n", cmp);
    free(arr);
    free(arr1);
    free(arr2);

    size = 500000;
    printf("the selection sort\n");
    int *arr3 = (int *)malloc(size * sizeof(int));
    generer_list("5x10^5asc.txt", arr3, size);
    cmp = 0;
    quickSortmodifie(arr3, 0, size - 1);
    printf("5*10^5\n");
    printf("asc: %lld\n", cmp);
    int *arr4 = (int *)malloc(size * sizeof(int));
    generer_list("5x10^5desc.txt", arr4, size);
    cmp = 0;
    quickSortmodifie(arr4, 0, size - 1);
    printf("desc: %lld\n", cmp);
    int *arr5 = (int *)malloc(size * sizeof(int));
    generer_list("5x10^5rand.txt", arr5, size);
    cmp = 0;
    quickSortmodifie(arr5, 0, size - 1);
    printf("rand: %lld\n", cmp);
    free(arr3);
    free(arr4);
    free(arr5);

    size = 1000000;
    printf("the selection sort\n");
    int *arr6 = (int *)malloc(size * sizeof(int));
    generer_list("10^6asc.txt", arr6, size);
    cmp = 0;
    quickSortmodifie(arr6, 0, size - 1);
    printf("10^6\n");
    printf("asc: %lld\n", cmp);
    int *arr7 = (int *)malloc(size * sizeof(int));
    generer_list("10^6desc.txt", arr7, size);
    cmp = 0;
    quickSortmodifie(arr7, 0, size - 1);
    printf("desc: %lld\n", cmp);
    int *arr8 = (int *)malloc(size * sizeof(int));
    generer_list("10^6rand.txt", arr8, size);
    cmp = 0;
    quickSortmodifie(arr8, 0, size - 1);
    printf("rand: %lld\n", cmp);
    free(arr6);
    free(arr7);
    free(arr8);

    size = 5000000;
    printf("the bubble sort\n");
    int *arr9 = (int *)malloc(size * sizeof(int));
    generer_list("5x10^6asc.txt", arr9, size);
    cmp = 0;
    quickSortmodifie(arr9, 0, size - 1);
    printf("5*10^6\n");
    printf("asc: %lld\n", cmp);
    int *arr10 = (int *)malloc(size * sizeof(int));
    generer_list("5x10^6desc.txt", arr10, size);
    cmp = 0;
    quickSortmodifie(arr10, 0, size - 1);
    printf("desc: %lld\n", cmp);
    int *arr11 = (int *)malloc(size * sizeof(int));
    generer_list("5x10^6rand.txt", arr11, size);
    cmp = 0;
    quickSortmodifie(arr11, 0, size - 1);
    printf("rand: %lld\n", cmp);
    free(arr9);
    free(arr10);
    free(arr11);

    size = 10000000;
    printf("the bubble sort\n");
    int *arr12 = (int *)malloc(size * sizeof(int));
    generer_list("10^7asc.txt", arr12, size);
    cmp = 0;
    quickSortmodifie(arr12, 0, size - 1);
    printf("10^7\n");
    printf("asc: %lld\n", cmp);
    int *arr13 = (int *)malloc(size * sizeof(int));
    generer_list("10^7desc.txt", arr13, size);
    cmp = 0;
    quickSortmodifie(arr13, 0, size - 1);
    printf("desc: %lld\n", cmp);
    int *arr14 = (int *)malloc(size * sizeof(int));
    generer_list("10^7rand.txt", arr14, size);
    cmp = 0;
    quickSortmodifie(arr14, 0, size - 1);
    printf("rand: %lld\n", cmp);
    free(arr12);
    free(arr13);
    free(arr14);

    // size = 50000000;
    // printf("the bubble sort\n");
    // int *arr15 = (int *)malloc(size * sizeof(int));
    // generer_list("5x10^7asc.txt", arr15, size);
    // long long int cmp16 = 0;
    // cmp16 = quickSortmodifie(arr15, size);
    // printf("5*10^7\n");
    // printf("asc: %lld\n", cmp16);
    // int *arr16 = (int *)malloc(size * sizeof(int));
    // generer_list("5x10^7desc.txt", arr16, size);
    // long long int cmp17 = 0;
    // cmp17 = quickSortmodifie(arr16, size);
    // printf("desc: %lld\n", cmp17);
    // int *arr17 = (int *)malloc(size * sizeof(int));
    // generer_list("5x10^7rand.txt", arr17, size);
    // long long int cmp18 = 0;
    // cmp18 = quickSortmodifie(arr17, size);
    // printf("rand: %lld\n", cmp18);
    // free(arr15);
    // free(arr16);
    // free(arr17);
    fclose(f);
    return 0;
}