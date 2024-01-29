typedef struct tuple
{
    char cle;
    int dist;
} tuple;

typedef struct table_de_hashage
{
    char cle;
    bool visite;
    tuple *list_adjc;
    int index;
    struct table_de_hashage *next;
} table_de_hashage;

int fct_hashage(char cle, int n)
{
    return ((cle - '0') % n);
}

int checkPrime(int n)
{
    int i;
    if (n == 1 || n == 0)
    {
        return 0;
    }
    for (i = 2; i < n / 2; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int getPrime(int n)
{
    if (n % 2 == 0)
    {
        n++;
    }
    while (!checkPrime(n))
    {
        n += 2;
    }
    return n;
}

table_de_hashage *init_hash_table(int n)
{
    int capacity = getPrime(n);
    table_de_hashage *tb = (table_de_hashage *)malloc(capacity * sizeof(table_de_hashage));
    for (int i = 0; i < capacity; i++)
    {
        tb[i].cle = '0';
        tb[i].visite = false;
        tb[i].list_adjc = (tuple *)malloc(sizeof(tuple) * capacity);
        tb[i].index = 0;
        tb[i].next = (table_de_hashage *)malloc(sizeof(table_de_hashage));
        tb[i].next->cle = '0';
        for (int j = 0; j < capacity; j++)
        {
            tb[i].list_adjc[j].cle = '0';
            // printf("%c\n", tb[i].list_adjc[j].cle);
            tb[i].list_adjc[j].dist = 0;
        }
    }

    return tb;
}
void inserer(table_de_hashage *tb, char cle, char dest, int dist, int n)
{
    int idx = fct_hashage(cle, n);
    tuple *t = (tuple *)malloc(sizeof(tuple));
    t->cle = dest;
    t->dist = dist;
    if (tb[idx].cle == '0')
    {
        tb[idx].cle = cle;
        tb[idx].list_adjc[tb[idx].index] = *t;
        tb[idx].index++;
    }
    else if (tb[idx].cle == cle)
    {
        tb[idx].list_adjc[tb[idx].index] = *t;
        tb[idx].index++;
    }
    else
    {
        printf("collisiont\n");
        table_de_hashage *temp = tb[idx].next;
        bool found = false;
        if (tb[idx].next->cle != '0')
        {
            while (temp != NULL && !found)
            {
                if (temp->cle == cle)
                {
                    // printf("i'm here\n");
                    found = true;
                }
                else
                {

                    temp = temp->next;
                }
            }
            if (found)
            {
                temp->list_adjc[temp->index] = *t;
                temp->index++;
            }
            else
            {
                temp = (table_de_hashage *)malloc(sizeof(table_de_hashage));
                temp->cle = cle;
                temp->index = 0;
                temp->list_adjc = (tuple *)malloc(sizeof(tuple) * getPrime(n));
                temp->list_adjc[temp->index] = *t;
                temp->index++;
                temp->next = (table_de_hashage *)malloc(sizeof(table_de_hashage));
            }

            // printf("%c, %c\n", tb[idx].next->cle, tb[idx].cle);
        }
        else
        {
            // tb[idx].next = (table_de_hashage *)malloc(sizeof(table_de_hashage));
            tb[idx].next->cle = cle;
            tb[idx].next->index = 0;
            tb[idx].next->list_adjc = (tuple *)malloc(sizeof(tuple) * getPrime(n));
            tb[idx].next->list_adjc[temp->index] = *t;
            tb[idx].next->index++;
            tb[idx].next->next = (table_de_hashage *)malloc(sizeof(table_de_hashage));
            // printf(" %c\n", tb[idx].next->cle);

            // tb[idx].next = temp;
        }
    }
    free(t);
}

void display(table_de_hashage *tb, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (tb[i].cle == '0')
        {
            // printf("table de hashage : %c\n", tb[i].cle);
            printf("\n");
        }
        else
        {
            printf("table de hasahge cle : %c adjacent avec :  \n ", tb[i].cle);
            for (int j = 0; j < tb[i].index; j++)
            {
                printf("cle : %c, distance : %i \n", tb[i].list_adjc[j].cle, tb[i].list_adjc[j].dist);
            }
            printf("\n");
            table_de_hashage *temp = tb[i].next;
            if (temp == NULL)
            {
                /* code */
                printf("ayo");
            }

            while (temp->next != NULL)
            {
                printf("table de hasahge cle : %c adjacent avec :  \n ", temp->cle);
                for (int j = 0; j < temp->index; j++)
                {
                    printf("cle : %c, distance : %i \n", temp->list_adjc[j].cle, temp->list_adjc[j].dist);
                }
                temp = temp->next;
                printf("\n");
            }
        }
    }
}