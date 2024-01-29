#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "qst1.h"

noeud **liste_de_listes()
{
    noeud **tete;
    tete = (noeud **)malloc(100 * sizeof(noeud *));
    for (size_t i = 1; i <= 100; i++)
    {
        tete[i] = randlist(10 + i);
    }

    return tete;
}
