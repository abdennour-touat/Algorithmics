#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "algos.h"
int main()
{
    clock_t t1, t2;
    double delta;
    long long nombres_premiers[] = {
        1000000009,
        1000000021,
        1000000087,
        1000000181,
        1000000861,
        2232232273,
        2233777723,
        2236133941,
        2245849783,
        2282113373,
        2319131071,
        2588244151,
        2589767209,
        2595860413,
        2599291451,
        2627282963,
        8192454631,
        8278487999,
        8332512563,
    };
    for (int i = 0; i < sizeof(nombres_premiers) / sizeof(long long); i++)
    {
        printf("temps d'execution pour le numero %lld\n", nombres_premiers[i]);
        printf("Algorithme 1\n");
        t1 = clock();
        A1(nombres_premiers[i]);
        t2 = clock();
        delta = (double)(t2 - t1) / CLOCKS_PER_SEC;
        printf("%F\n", delta);

        printf("Algorithme 2\n");
        t1 = clock();
        A2(nombres_premiers[i]);
        t2 = clock();
        delta = (double)(t2 - t1) / CLOCKS_PER_SEC;
        printf("%F\n", delta);

        printf("Algorithme 3\n");
        t1 = clock();
        A3(nombres_premiers[i]);
        t2 = clock();
        delta = (double)(t2 - t1) / CLOCKS_PER_SEC;
        printf("%F\n", delta);

        printf("Algorithme 4\n");
        t1 = clock();
        A4(nombres_premiers[i]);
        t2 = clock();
        delta = (double)(t2 - t1) / CLOCKS_PER_SEC;
        printf("%F\n", delta);

        printf("Algorithme 5\n");
        t1 = clock();
        A5(nombres_premiers[i]);
        t2 = clock();
        delta = (double)(t2 - t1) / CLOCKS_PER_SEC;
        printf("%F\n", delta);

        printf("Algorithme 6\n");
        t1 = clock();
        A6(nombres_premiers[i]);
        t2 = clock();
        delta = (double)(t2 - t1) / CLOCKS_PER_SEC;
        printf("%F\n", delta);
    }
    return 0;
}