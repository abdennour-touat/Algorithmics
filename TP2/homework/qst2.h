
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int chercheMax(noeud *nd)
{
    int max = nd->val;
    noeud *temp = nd->suiv;
    while (temp != NULL)
    {
        if (max < temp->val)
        {
            max = temp->val;
        }
        temp = temp->suiv;
    }
    return max;
}
