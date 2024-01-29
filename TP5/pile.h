
// declaration de pile
typedef struct ListePile
{
    int debut;
    tuple *T;
} Pile;

void push(Pile *p, tuple a)
{
    p->debut++;
    p->T[p->debut] = a;
    // printf("%i", p->debut);
}
tuple pop(Pile *p)
{
    tuple supp_element;
    supp_element.cle = '0';
    supp_element.dist = 0;
    if (p->debut > -1)
    {
        supp_element = p->T[p->debut];
        p->debut--;
    }
    return supp_element;
}
int empty(Pile *p)
{
    return p->debut == -1;
}
void init(Pile *p, int n)
{
    p->T = (tuple *)malloc(sizeof(tuple) * n);
    p->debut = -1;
}

bool in(Pile *p, char x)
{
    for (int i = 0; i < p->debut + 1; i++)
    {
        if (p->T[i].cle == x)
        {

            return true;
        }
    }
    return false;
}