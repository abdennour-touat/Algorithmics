
// declaration de pile
typedef struct ListePile
{
    int debut;
    int *T;
} Pile;

void push(Pile *p, int a)
{
    p->debut++;
    p->T[p->debut] = a;
}
int pop(Pile *p)
{
    int supp_element = 0;
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
void init(Pile *p, int n, bool c)
{
    p->T = (int *)malloc(sizeof(int) * n);
    p->debut = -1;
    if (c)
    {
        for (int i = n; i > 0; i--)
        {

            push(p, i);
        }
    }
}
