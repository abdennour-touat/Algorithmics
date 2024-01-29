#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 256
long long int cmp;

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

int partition2modifie(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low - 1, j = high + 1;

    while (1)
    {

        do
        {
            cmp++;
            i++;
        } while (arr[i] < pivot);

        do
        {
            cmp++;
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int partition_rmodifie(int arr[], int low, int high)
{
    srand(time(0));
    int random = low + rand() % (high - low);

    int temp = arr[random];
    arr[random] = arr[low];
    arr[low] = temp;

    return partition2modifie(arr, low, high);
}

void quickSortmodifie(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition_rmodifie(arr, low, high);

        quickSortmodifie(arr, low, pi);
        quickSortmodifie(arr, pi + 1, high);
    }
}

int main()
{
    printf("the start of the execution");
    FILE *f;
    f = fopen("result.txt", "w");
    unsigned long long size = 50000;
    int *arr;
    long long cmp;

    printf("\ntri rapide H: \n");
    arr = (int *)malloc(size * sizeof(int));
    generer_list("5x10^4asc.txt", arr, size);
    cmp = 0;
    quickSortmodifie(arr, 0, size);
    printf("asc: %lld\n", cmp);
    int *arr1 = (int *)malloc(size * sizeof(int));
    generer_list("5x10^4desc.txt", arr1, size);
    cmp = 0;
    quickSortmodifie(arr1, 0, size);
    printf("desc: %lld\n", cmp);
    int *arr2 = (int *)malloc(size * sizeof(int));
    generer_list("5x10^4rand.txt", arr2, size);
    cmp = 0;
    quickSortmodifie(arr2, 0, size);
    printf("rand: %lld\n", cmp);
    free(arr);
    free(arr1);
    free(arr2);

    size = 100000;
    arr = (int *)malloc(size * sizeof(int));
    printf("10^5\n");
    generer_list("10^5asc.txt", arr, size);

    cmp = 0;
    quickSortmodifie(arr, 0, size - 1);
    printf("asc: %lld\n", cmp);

    int *arr3 = (int *)malloc(size * sizeof(int));
    generer_list("10^5desc.txt", arr3, size);
    cmp = 0;
    quickSortmodifie(arr1, 0, size);
    printf("desc: %lld\n", cmp);
    int *arr2 = (int *)malloc(size * sizeof(int));
    generer_list("10^5rand.txt", arr2, size);
    cmp = 0;
    quickSortmodifie(arr2, 0, size);
    printf("rand: %lld\n", cmp);
    free(arr);
    free(arr1);
    free(arr2);

    size = 500000;
    printf("5*10^5\n");
    int *arr = (int *)malloc(size * sizeof(int));
    generer_list("5x10^5asc.txt", arr, size);
    cmp = 0;
    quickSortmodifie(arr, 0, size);
    printf("asc: %lld\n", cmp);

    int *arr2 = (int *)malloc(size * sizeof(int));
    generer_list("5x10^5rand.txt", arr2, size);
    int cmp6 = 0;
    quickSortmodifie(arr2, 0, size);
    printf("rand: %lld\n", cmp6);
    free(arr2);
    free(arr);

    size = 1000000;
    printf("10^6\n");
    int *arr6 = (int *)malloc(size * sizeof(int));
    generer_list("10^6asc.txt", arr6, size);
    cmp = 0;
    quickSortmodifie(arr, 0, size);
    printf("asc: %lld\n", cmp);

    int *arr2 = (int *)malloc(size * sizeof(int));
    generer_list("10^6rand.txt", arr2, size);
    cmp = 0;
    quickSortmodifie(arr2, 0, size);
    printf("rand: %lld\n", cmp6);
    free(arr2);
    free(arr);

    size = 5000000;
    printf("5*10^6\n");
    int *arr = (int *)malloc(size * sizeof(int));
    generer_list("5x10^6asc.txt", arr, size);
    cmp = 0;
    quickSortmodifie(arr, 0, size);
    printf("asc: %lld\n", cmp);

    int *arr2 = (int *)malloc(size * sizeof(int));
    generer_list("5x10^6rand.txt", arr2, size);
    cmp = 0;
    quickSortmodifie(arr2, 0, size);
    printf("rand: %lld\n", cmp);
    free(arr2);
    free(arr);

    size = 10000000;
    printf("10^7\n");
    int *arr = (int *)malloc(size * sizeof(int));
    generer_list("10^7asc.txt", arr, size);
    cmp = 0;
    quickSortmodifie(arr, 0, size);
    printf("asc: %lld\n", cmp);
    int *arr14 = (int *)malloc(size * sizeof(int));
    generer_list("10^7rand.txt", arr14, size);
    cmp = 0;
    quickSortmodifie(arr2, 0, size);
    printf("rand: %lld\n", cmp);
    free(arr2);
    free(arr);

    fclose(f);
    return 0;
}