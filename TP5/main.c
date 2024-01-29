#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 500
#include "graphe.h"
#include "pile.h"

void dfs(table_de_hashage *t, char debut, char fin, int n, Pile *path)
{
    if (path->debut + 1 == n)
    {
        int ix = fct_hashage(path->T[path->debut].cle, n);
        Pile *p = (Pile *)malloc(sizeof(Pile));
        init(p, n);
        for (int i = 0; i < t[ix].index; i++)
        {
            push(p, t[ix].list_adjc[i]);
        }
        if (in(p, fin))
        {
            int cout = 0;
            for (int i = 0; i < n; i++)
            {
                if (path->T[i].cle != fin)
                {
                    cout += path->T[i].dist;
                    printf("%c ->", path->T[i].cle);
                    /* code */
                }
            }
            printf(" cout : %i", cout);
            printf("\n");
            return;
        }
    }
    int idx = fct_hashage(debut, n);

    for (int i = 0; i < t[idx].index; i++)
    {
        int id = fct_hashage(t[idx].list_adjc[i].cle, n);
        if (!t[id].visite)
        {
            t[id].visite = true;
            push(path, t[idx].list_adjc[i]);
            dfs(t, t[id].cle, fin, n, path);
            t[id].visite = false;
            pop(path);
        }
    }
}

int main()
{
    table_de_hashage *tb = init_hash_table(9);
    // A
    inserer(tb, 'A', 'B', 10, 9);
    inserer(tb, 'A', 'H', 50, 9);
    inserer(tb, 'A', 'm', 15, 9);
    // // B
    inserer(tb, 'B', 'A', 10, 9);
    inserer(tb, 'B', 'm', 20, 9);
    inserer(tb, 'B', 'D', 10, 9);
    inserer(tb, 'B', 'C', 15, 9);
    // C
    inserer(tb, 'C', 'B', 15, 9);
    inserer(tb, 'C', 'D', 10, 9);
    inserer(tb, 'C', 'E', 10, 9);
    inserer(tb, 'C', 'F', 20, 9);
    // D
    inserer(tb, 'D', 'B', 10, 9);
    inserer(tb, 'D', 'C', 10, 9);
    inserer(tb, 'D', 'E', 15, 9);
    inserer(tb, 'D', 'G', 10, 9);
    inserer(tb, 'D', 'm', 30, 9);
    // E
    inserer(tb, 'E', 'C', 10, 9);
    inserer(tb, 'E', 'F', 10, 9);
    inserer(tb, 'E', 'D', 15, 9);
    // F
    inserer(tb, 'F', 'E', 10, 9);
    inserer(tb, 'F', 'C', 20, 9);
    inserer(tb, 'F', 'G', 10, 9);
    inserer(tb, 'F', 'H', 20, 9);
    // G
    inserer(tb, 'G', 'D', 10, 9);
    inserer(tb, 'G', 'F', 10, 9);
    inserer(tb, 'G', 'H', 15, 9);
    // H
    inserer(tb, 'H', 'F', 20, 9);
    inserer(tb, 'H', 'G', 15, 9);
    inserer(tb, 'H', 'A', 50, 9);
    inserer(tb, 'H', 'm', 20, 9);
    // M
    inserer(tb, 'm', 'A', 15, 9);
    inserer(tb, 'm', 'B', 20, 9);
    inserer(tb, 'm', 'D', 30, 9);
    inserer(tb, 'm', 'H', 20, 9);

    int idx = fct_hashage('D', 9);
    // display(tb, 9);

    Pile *p = (Pile *)malloc(sizeof(Pile));
    init(p, 9);

    dfs(tb, 'm', 'm', 9, p);

    return 0;
}