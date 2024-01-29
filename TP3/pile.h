#ifndef pile_h
#define pile_h

#ifndef sommet_H
#ifndef idk_H
#ifndef idktoo_H
#define MAX 500

typedef int Element;

#endif
#endif
#endif

// declaration de pile
typedef struct pile
{
    BTree items[MAX];
    int top;
    int taille;
} pile;

// creer nouvelle pile
void initPile(pile *p)
{
    p->top = -1;
    p->taille = 0;
}
// verifier si la pile est vide
int pileVide(pile *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}
// verifier si une pile est pleine
int pilePleine(pile *s)
{
    if (s->top == MAX - 1)
        return 1;
    else
        return 0;
}
// empiler un element:
void empiler(pile *p, BTree newitem)
{
    if (pilePleine(p))
    {
        printf("la pile est pleine");
    }
    else
    {
        p->top++;
        p->items[p->top] = newitem;
    }
    p->taille++;
}
// depiler le sommet
BTree depiler(pile *p)
{
    if (pileVide(p))
        return NULL;
    p->taille--;
    BTree val = p->items[p->top];
    p->top--;
    return val;
}

#endif