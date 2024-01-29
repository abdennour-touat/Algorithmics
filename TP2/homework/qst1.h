#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#ifndef qst1
#define qst1
noeud *randlist(int n)
{
    // definir la tete
    // noeud *tete = creer_noeud();
    noeud *tete = (noeud *)malloc(sizeof(noeud));
    tete->val = 1;
    // le suivant pour ne perde pas la tete
    noeud *suivant;
    suivant = tete;
    // boucler n-1 fois
    for (int i = 2; i <= n; i++)
    {
        // creer nouveau noeud
        // noeud *temp = creer_noeud();
        noeud *temp;
        temp = (noeud *)malloc(sizeof(noeud));
        // utiliser la fonctin rand() pour generer des nombres alleatoires et on utilise le quotient par n
        temp->val = rand() % 100;
        suivant->suiv = temp;
        suivant = suivant->suiv;
    }
    return tete;
}

#endif