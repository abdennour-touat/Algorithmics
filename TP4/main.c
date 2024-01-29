#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pile.h"
#include "hanoi_iterative.h"
#include "hanoi_recursive.h"
bool verification(Pile *a, Pile *b, Pile *c, int n)
{
    int i = 1;
    while (!empty(c) && pop(c) == i)
        i++;
    return (i - 1 == n) && empty(a) && empty(b);
}

int main(int argc, char const *argv[])
{
    int taille = 35;
    Pile *A = (Pile *)malloc(sizeof(Pile));
    Pile *B = (Pile *)malloc(sizeof(Pile));
    Pile *C = (Pile *)malloc(sizeof(Pile));
    init(A, taille, true);
    init(B, taille, false);
    init(C, taille, false);
    tour_hanoi_recursive(taille, A, C, B, 'a', 'c', 'b');
    printf("\\\\\\ \n");
    Pile *Ai = (Pile *)malloc(sizeof(Pile));
    Pile *Bi = (Pile *)malloc(sizeof(Pile));
    Pile *Ci = (Pile *)malloc(sizeof(Pile));
    init(Ai, taille, true);
    init(Bi, taille, false);
    init(Ci, taille, false);
    tour_hanoi_iterative(taille, Ai, Ci, Bi);
    bool result = verification(Ai, Bi, Ci, taille);
    printf("etat apres: %i \n", result);
    return 0;
}
