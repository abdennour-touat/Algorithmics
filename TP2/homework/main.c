#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "qst1.h"
#include "qst2.h"
#include "qst3.h"

int main()

{
    noeud *list = randlist(33);
    noeud *temp = list;
    while (temp != NULL)
    {
        printf("%d\n", temp->val);
        temp = temp->suiv;
    }
    int result = chercheMax(list);
    printf("le max est : %d\n", result);
    noeud **test = liste_de_listes();
    for (size_t j = 0; j < 100; j++)
    {
        noeud *temp = test[j];
        printf("list #%ld:\n", j);
        while (temp != NULL)
        {
            printf("%d\n", temp->val);
            temp = temp->suiv;
        }
    }

    return 0;
}
